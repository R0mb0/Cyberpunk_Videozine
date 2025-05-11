{.PW132}
{.HE HYPE.PAS                                        Page # }
{$R+,V-}
PROGRAM HyperText ;

(* Copyright 1987 - Knowledge Garden Inc.
                    473A Malden Bridge Rd.
                    R.D. 2
                    Nassau, NY 12123       *)


(* This program implements the hypertext technique described in the
   AI apprentice column in August 1987 issue of AI Expert Magazine.

   This program has been tested using Turbo ver 3.01A on an IBM PC/AT and
   two PC clones. It has  been run under both DOS 3.2 and Concurrent 5.0 .

   We would be pleased to hear your comments, good or bad, or any applications
   and modifications of the program. Contact us at:

     AI Expert
     Miller Freeman Publications
     500 Howard Street
     San Francisco, CA 94105

   or on the AI Expert BBS. Our id is BillandBev Thompson ,[76703,4324].
   You can also contact us on BIX, our id is bbt.

   Bill and Bev Thompson    *)


 CONST
  color_base = $B800 ;   (* Location of PC color screen memory map *)
  mono_base = $B000 ;    (* Location of PC mono screen memory map *)
  esc = #27 ;      (* These rest of these constants could have been defined in *)
  F10 = #68 ;      (* process_file, but we put them here for convenience *)
  left_arrow = #75 ;
  right_arrow = #77 ;
  PgUp = #73 ;
  PgDn = #81 ;
  mark_char = '\' ;
  enter = #13 ;
  def_window_size_x = 65 ;
  def_window_size_y = 12 ;
  def_fore_color = white ;
  def_back_color = red ;


 TYPE
  counter = 0 .. maxint ;
  text_file = text[2048] ;
  string255 = string[255] ;
  string80 = string[80] ;
  char_ptr = ^char ;
  col_pos = 1 .. 80 ;      (* The PC screen is 80 by 25 *)
  row_pos = 1 .. 25 ;
  color = 0 .. 31 ;
  window_pos = RECORD           (* cursor location on screen *)
                x : col_pos ;
                y : row_pos ;
               END ;
  window_ptr = ^window_desc ;
  window_desc = RECORD                        (* Basic window description *)
                 next_window : window_ptr ;   (* windows are linked lists of *)
                 prev_window : window_ptr ;   (* these descriptors *)
                 abs_org     : window_pos ;   (* origin relative to upper left *)
                 window_size : window_pos ;   (* rows and columns in window *)
                 cursor_pos  : window_pos ;   (* saves current cursor location *)
                 has_frame   : boolean ;      (* size and org do not include frame *)
                 fore_color  : color ;
                 back_color  : color ;
                 scrn_area   : char_ptr ;      (* pointer to actual window data *)
                END ;
  string_ptr = ^string255 ;   (* we don't actually allocate space for 255 chars *)
  line_ptr = ^line_desc ;
  line_desc = RECORD                 (* text is stored as a linked list *)
               next_line : line_ptr ;
               prev_line : line_ptr ;
               txt       : string_ptr ; (* points to actual text data *)
              END ;
  mark_ptr = ^mark_desc ;
  mark_desc = RECORD                   (* marked text is also a linked list *)
               next_mark : mark_ptr ;
               prev_mark : mark_ptr ;
               mark_pos  : window_pos ;  (* location of start of mark in window *)
               mark_text : string_ptr ;  (* actual marked text *)
              END ;
  dos_rec = RECORD                       (* used for low-level functions *)
             CASE boolean OF
              true  : (ax,bx,cx,dx,bp,si,di,ds,es,flags : integer) ;
              false : (al,ah,bl,bh,cl,ch,dl,dh          : byte) ;
             END ;
  monitor_type = (color_monitor,mono_monitor,ega_monitor) ;


 VAR
  window_list,main_window,message_window,last_window : window_ptr ;
  screen_base : char_ptr ;
  monitor_kind : monitor_type ;
  main_file : text_file ;
  button_fore,button_back : color ;

(* Important variables:
   window_list - points to a linked list of window descriptors,
                 the top window is the currently active window.
                 To write in a window, bring it to the front of the list.
   last_window - points to end of window list
   main_window - the big window, that text initially appears in
   message_window - 2 line area at the bottom of the screen, available keys,
                    commands etc. appear here
   screen_base - points to actual memory location of screen, either
                 mono_base or color_base
   main_file - the original text file, the one we start the program with
   button_fore,
   button_back - the button is the large cursor which moves from mark to mark
                 on a color screen it is yellow on black, on a mono screen
                 the text is underlined. *)


 (* Note - In most cases this program uses the Turbo standard string
           functions. You can probably get better performance by turning
           off range checking and accessing the strings directly, but
           we didn't want to make this program even less portable than it
           already is. *)

(* \\\\\\\\\\\\\ Basic Utility Routines  \\\\\\\\\\\\\\\\\\\\\\ *)

 FUNCTION min(x,y : integer) : integer ;
  BEGIN
   IF x <= y
    THEN min := x
    ELSE min := y ;
  END ; (* min *)


 FUNCTION max(x,y : integer) : integer ;
  BEGIN
   IF x >= y
    THEN max := x
    ELSE max := y ;
  END ; (* max *)


 PROCEDURE makestr(VAR s : string255 ; len : byte) ;
  (* Fixes string "s" to length "len" - pads with blanks if necessary. *)
  VAR
   old_length : byte ;
  BEGIN
   old_length := length(s) ;
   (*$R- *)
   s[0] := chr(len) ;
   (*$R+ *)
   IF old_length < len
    THEN fillchar(s[old_length+1],len - old_length,' ') ;
  END ; (* makestr *)


 FUNCTION toupper(s : string255) : string255 ;
  (* converts a string to uppercase *)
  VAR
   i : byte ;
  BEGIN
   IF length(s) > 0
    THEN
     FOR i := 1 TO length(s) DO
      s[i] := upcase(s[i]) ;
   toupper := s ;
  END ; (* toupper *)


 PROCEDURE strip_leading_blanks(VAR s : string255) ;
  (* Trim the leading blanks from a string *)
  BEGIN
   IF length(s) > 0
    THEN
     IF s[1] = ' '
      THEN
       BEGIN
        delete(s,1,1) ;
        strip_leading_blanks(s) ;
       END ;
  END ; (* strip_leading_blanks *)


 PROCEDURE strip_trailing_blanks(VAR s : string255) ;
  (* Trim the trailing blanks from a string *)
  BEGIN
   IF length(s) > 0
    THEN
     IF s[length(s)] = ' '
      THEN
       BEGIN
        delete(s,length(s),1) ;
        strip_trailing_blanks(s) ;
       END ;
  END ; (* strip_trailing_blanks *)


 FUNCTION tointeger(s : string255) : integer ;
  (* converts a string to an integer. Returns 0 for non-numeric strings *)
  VAR
   num : real ;
   code : integer ;
  BEGIN
   strip_trailing_blanks(s) ;
   strip_leading_blanks(s) ;
   val(s,num,code) ;
   IF code = 0
    THEN
     IF (num < -32768.0) OR (num > 32767.0)
      THEN tointeger := 0
      ELSE tointeger := trunc(num)
    ELSE tointeger := 0 ;
  END ; (* tointeger *)


 FUNCTION open(VAR f : text_file ; f_name : string80) : boolean ;
  (* Open a text file and return true if file can be opened *)
  BEGIN
   assign(f,f_name) ;
   (*$I- *)
   reset(f) ;
   (*$I+ *)
   open := (ioresult = 0) ;
  END ; (* open *)


(* \\\\\\\\\\\\\\\\\\\ Window Routines \\\\\\\\\\\\\\\\\\\\ *)

 PROCEDURE draw_frame(x1,y1,x2,y2 : counter ; title : string80 ;
                      frame_color : color) ;
  (* Draw a frame on the screen at absolute screen positions *)
  (* x1,y1 - upper left corner *)
  (* x2,y2 - lower right corner *)
  CONST
   bar = #196 ;
   vert_bar = #179 ;
   upper_lf = #218 ;
   upper_rt = #191 ;
   lower_lf = #192 ;
   lower_rt = #217 ;
  VAR
   i : 1 .. 25 ;
   border : string80 ;

  PROCEDURE get_frame_co_ords ;
   BEGIN
    x1 := min(max(1,x1),78) ;
    y1 := min(max(1,y1),23) ;
    x2 := min(max(3,x2),80) ;
    y2 := min(max(3,y2),25) ;
   END ; (* get_frame_co_ords *)

  PROCEDURE write_title ;
   BEGIN
    IF length(title) > (x2 - x1 - 1)
     THEN title := copy(title,1,x2 - x1 - 1) ;
    write(title) ;
    write(copy(border,1,length(border) - length(title))) ;
   END ; (* write_title *)

  BEGIN
   get_frame_co_ords ;
   window(1,1,80,25) ;
   border := '' ;
   makestr(border,x2 - x1 - 1) ;
   fillchar(border[1],x2 - x1 - 1,bar) ;
   gotoxy(x1,y1) ;
   textcolor(frame_color) ;
   textbackground(black) ;
   write(upper_lf) ;
   write_title ;
   write(upper_rt) ;
   FOR i := y1 + 1 TO y2 - 1  DO
    BEGIN
     gotoxy(x1,i) ;
     write(vert_bar) ;
     gotoxy(x2,i) ;
     write(vert_bar) ;
    END ;
   gotoxy(x1,y2) ;
   write(lower_lf) ;
   write(border) ;
   IF (wherex = 80) AND (wherey = 25)
    THEN
     BEGIN
      mem[seg(screen_base^) : 3998] := ord(lower_rt) ;
      mem[seg(screen_base^) : 3999] := (black SHL 4) + frame_color ;
     END
    ELSE write(lower_rt) ;
  END ; (* draw_frame *)


 PROCEDURE retrace_wait ;
  (* This routine is a delay to prevent snow on a CGA screen *)
  (* It is unecessary for mono and EGA. It watches the color status reg *)
  (* until the horizontal retrace is finished. On CGA clones it may not *)
  (* be needed, so try removing the calls to it and see if you get snow. *)
  CONST
   color_status_reg = $3DA ;
  BEGIN
   IF monitor_kind = color_monitor
    THEN WHILE (port[color_status_reg] AND $08) = 0 DO ;
  END ; (* retrace_wait *)


 PROCEDURE get_monitor_type ;
  (* find out what kind of display we are using *)
  (* A hercules card is a mono card *)
  VAR
   regs : dos_rec ;
  BEGIN
   WITH regs DO
    BEGIN
     ah := $12 ;
     bh := $03 ;
     bl := $10 ;
    END ;
   intr($10,regs) ;
   IF regs.bh < 2
    THEN
     BEGIN
      monitor_kind := ega_monitor ;
      screen_base := ptr(color_base,0) ;
     END
    ELSE
     BEGIN
      regs.ax := $0F00 ;
      intr($10,regs) ;
      IF regs.al < 7
       THEN
        BEGIN
         monitor_kind := color_monitor ;
         screen_base := ptr(color_base,0) ;
        END
       ELSE
        BEGIN
         monitor_kind := mono_monitor ;
         screen_base := ptr(mono_base,0) ;
        END
     END ;
  END ; (* get_monitor_type *)


 PROCEDURE move_from_scrn(save_org,save_size : window_pos ;
                          save_scrn : char_ptr) ;
  (* Move data from physical screen memory-map area to save_scrn *)
  (* i.e. reads the the screen *)
  (* It moves characters and attributes starting at location given by *)
  (* save_org. It copies save_size.x cols by save_size.y rows *)
  (* Copy is performed on row at a time *)
  (* This routine is extremely machine specific *)
  VAR
   physical_scrn : char_ptr ;
   i : row_pos ;
  BEGIN
   physical_scrn := ptr(seg(screen_base^),ofs(screen_base^) +
                        ((save_org.y - 1) * 80 + (save_org.x - 1)) * 2) ;
   FOR i := 1 TO save_size.y DO
    BEGIN
     retrace_wait ;
     move(physical_scrn^,save_scrn^,save_size.x * 2) ;
     physical_scrn := ptr(seg(physical_scrn^),ofs(physical_scrn^) + 160) ;
     save_scrn := ptr(seg(save_scrn^),ofs(save_scrn^) + save_size.x * 2) ;
    END ;
  END ; (* move_from_scrn *)


 PROCEDURE move_to_scrn(save_org,save_size : window_pos ;
                        save_scrn : char_ptr) ;
  (* Move data from save_scrn to physical screen memory-map area, *)
  (* i.e. displays data on the screen *)
  (* It moves characters and attributes starting at location given by *)
  (* save_org. It copies save_size.x cols by save_size.y rows *)
  (* Copy is performed on row at a time *)
  (* This routine is extremely machine specific *)
  VAR
   physical_scrn : char_ptr ;
   i : row_pos ;
  BEGIN
   physical_scrn := ptr(seg(screen_base^),ofs(screen_base^) +
                        ((save_org.y - 1) * 80 + (save_org.x - 1)) * 2) ;
   FOR i := 1 TO save_size.y DO
    BEGIN
     retrace_wait ;
     move(save_scrn^,physical_scrn^,save_size.x * 2) ;
     physical_scrn := ptr(seg(physical_scrn^),ofs(physical_scrn^) + 160) ;
     save_scrn := ptr(seg(save_scrn^),ofs(save_scrn^) + save_size.x * 2) ;
    END ;
  END ; (* move_to_scrn *)


 PROCEDURE window_reverse ;
  (* After this routine is called all text written to current window will be *)
  (* displayed in reverse video *)
  BEGIN
   WITH window_list^ DO
    BEGIN
     textcolor(back_color) ;
     textbackground(fore_color) ;
    END ;
  END ; (* window_reverse *)


 PROCEDURE window_normal ;
  (* returns to normal colors *)
  (* After this routine is called all text written to current window will be *)
  (* displayed in the colors declared when the window was opened *)
  BEGIN
   WITH window_list^ DO
    BEGIN
     textcolor(fore_color) ;
     textbackground(back_color) ;
    END ;
  END ; (* window_normal *)


 PROCEDURE window_write(s : string80) ;
  (* Write a string to the window at the current cursor position in the *)
  (* window described by the first item on the window list *)
  (* Strings too long for the window are truncated at the right edge of *)
  (* the window. All of the fooling around in last row is to prevent *)
  (* the window from scrollong when you write to the lower left corner. *)
  VAR
   y_pos : byte ;

  PROCEDURE last_row ;
   VAR
    x_pos,i : byte ;
    done : boolean ;

   PROCEDURE handle_last ;
    (* This routine makes sonme BIOS calls to get the current screen *)
    (* attribute and then pokes the character into the lower right hand *)
    (* corner. There's probably better ways to do this. *)
    VAR
     attrib : byte ;
     last_pos : counter ;
     regs : dos_rec ;
    BEGIN
     WITH window_list^ DO
      BEGIN
       regs.ax := $0F00 ;
       intr($10,regs) ;
       regs.ax := $0200 ;
       regs.dh := (abs_org.y - 1) + (y_pos - 1) ;
       regs.dl := (abs_org.x - 1) + (x_pos - 2) ;
       intr($10,regs) ;
       regs.ax := $0800 ;
       intr($10,regs) ;
       attrib := regs.ah ;
       last_pos := (((abs_org.y - 1) + (y_pos - 1)) * 80
                   + (abs_org.x - 1) + (x_pos - 1)) * 2 ;
       mem[seg(screen_base^) : last_pos] := ord(s[i]) ;
       mem[seg(screen_base^) : last_pos + 1] := attrib ;
       gotoxy(window_size.x,y_pos) ;
       done := true ;
      END ;
    END ; (* handle_last *)

   BEGIN
    WITH window_list^ DO
     BEGIN
      i := 1 ;
      done := false ;
      WHILE (i <= length(s)) AND (NOT done) DO
       BEGIN
        x_pos := wherex ;
        IF (x_pos = window_size.x) AND (y_pos = window_size.y)
         THEN handle_last
        ELSE IF x_pos = window_size.x
         THEN
          BEGIN
           write(s[i]) ;
           gotoxy(window_size.x,y_pos) ;
           done := true ;
          END
        ELSE write(s[i]) ;
        i := i + 1 ;
       END ;
     END ;
   END ; (* last_row *)

  BEGIN
   y_pos := wherey ;
   WITH window_list^ DO
    IF y_pos = window_size.y
     THEN last_row
     ELSE
      BEGIN
       write(copy(s,1,min(length(s),window_size.x - wherex + 1))) ;
       IF wherey <> y_pos
        THEN gotoxy(window_size.x,y_pos) ;
      END ;
  END ; (* window_write *)


 PROCEDURE window_writeln(s : string80) ;
  (* write a string to the current window and the move cursor to *)
  (* start of the next line *)
  BEGIN
   window_write(s) ;
   IF wherey < window_list^.window_size.y
    THEN gotoxy(1,wherey + 1) ;
  END ; (* window_writeln *)


 PROCEDURE get_window_co_ords(s_ptr : window_ptr ;
                            VAR act_org,act_size : window_pos) ;
  (* Get the actual origin and size of the window described by *)
  (* s_ptr. The physical size of the window includes the frame. The *)
  (* size and origin in the descriptor do not. *)
  BEGIN
   WITH s_ptr^ DO
    IF has_frame
     THEN
      BEGIN
       act_org.x := min(max(abs_org.x - 1,1),80) ;
       act_org.y := min(max(abs_org.y - 1,1),25) ;
       act_size.x := max(min(window_size.x + 2,81 - act_org.x),1) ;
       act_size.y := max(min(window_size.y + 2,26 - act_org.y),1) ;
      END
     ELSE
      BEGIN
       act_org := abs_org ;
       act_size.x := max(min(window_size.x,81 - act_org.x),1) ;
       act_size.y := max(min(window_size.y,26 - act_org.y),1) ;
      END ;
  END ; (* get_window_co_ords *)


 PROCEDURE save_window ;
  (* save the date from the current window in the windows save area *)
  (* If the window doesn't have a save area yet, allocate one for it *)
  (* We don't allocate any storage for data for the window until it *)
  (* is switched out *)
  (* move_from_screen does the actual move from the screen *)
  VAR
   save_size,save_org : window_pos ;
  BEGIN
   IF window_list <> NIL
    THEN
     WITH window_list^ DO
      BEGIN
       cursor_pos.x := wherex ;
       cursor_pos.y := wherey ;
       get_window_co_ords(window_list,save_org,save_size) ;
       IF scrn_area = NIL
        THEN getmem(scrn_area,2 * save_size.x * save_size.y) ;
       move_from_scrn(save_org,save_size,scrn_area) ;
      END ;
  END ; (* save_window *)


 PROCEDURE ins_desc(p : window_ptr) ;
  (* Insert a window descriptor at the front of the window list *)
  BEGIN
   p^.next_window :=window_list ;
   IF window_list = NIL
    THEN last_window := p
    ELSE window_list^.prev_window := p ;
   p^.prev_window := NIL ;
   window_list := p ;
  END ; (* ins_desc *)


 PROCEDURE del_desc(del_ptr : window_ptr) ;
  (* delete a descriptor from the window list *)
  BEGIN
   IF del_ptr = window_list
    THEN
     BEGIN
      window_list := del_ptr^.next_window ;
      window_list^.prev_window := NIL ;
     END
    ELSE
     BEGIN
      del_ptr^.prev_window^.next_window := del_ptr^.next_window ;
      IF del_ptr^.next_window <> NIL
       THEN del_ptr^.next_window^.prev_window := del_ptr^.prev_window ;
     END ;
   IF window_list = NIL
    THEN last_window := NIL
   ELSE IF del_ptr = last_window
    THEN last_window := del_ptr^.prev_window ;
  END ; (* scrn_del_desc *)


 FUNCTION open_window(org_x : col_pos ; org_y : row_pos ; size_x : col_pos ;
                      size_y : row_pos ; use_frame : boolean ; title : string80 ;
                      f_color,b_color,frame_color : color) : window_ptr ;
   (* Create a new window and place it at front of the window list *)
   (* This window becomes the current window and is displayed on the screen *)
   (* The old window is saved and can be restored *)
   (* Returns a pointer to the descriptor of the new window *)
   (* org_x,org_y - the upper left hand corner of the window on the PC *)
   (*               screen. Co-ordinates are measured from (1,1). The frame *)
   (*               is not part of the window, it is outside. *)
   (* size_x,size_y - the number of columns and rows in the window. The *)
   (*                 frame is not included *)
   (* use_frame - true if you want a frame around the window. If use_frame *)
   (*             is false, title and frame_color are ignored *)
   (* title - string printed on top line of frame *)
   (* f_color - the text color *)
   (* b_color - the background color *)
   (* frame_color - color of the frame, if present *)

  PROCEDURE create_descriptor ;
   (* create a window descriptor and insert it in the window list *)
   VAR
    p : window_ptr ;
   BEGIN
    getmem(p,sizeof(window_desc)) ;
    WITH p^ DO
     BEGIN
      abs_org.x := org_x ;
      abs_org.y := org_y ;
      window_size.x := min(size_x,81 - abs_org.x) ;
      window_size.y := min(max(2,size_y),26 - abs_org.y) ;
      cursor_pos.x := 1 ;
      cursor_pos.y := 1 ;
      has_frame := use_frame ;
      fore_color := f_color ;
      back_color := b_color ;
      scrn_area := NIL ;
      ins_desc(p) ;
     END ;
   END ; (* create_descriptor *)

  BEGIN
   IF window_list <> NIL
    THEN save_window ;
   create_descriptor ;
   WITH window_list^ DO
    BEGIN
     IF use_frame
      THEN draw_frame(abs_org.x - 1,abs_org.y - 1,abs_org.x + window_size.x,
                      abs_org.y + window_size.y,title,frame_color) ;
     window(abs_org.x,abs_org.y,abs_org.x + window_size.x - 1,
            abs_org.y + window_size.y - 1) ;
     textcolor(fore_color) ;
     textbackground(back_color) ;
     clrscr ;
    END ;
   open_window := window_list ;
  END ; (* open_window *)


 PROCEDURE display_window(win_ptr : window_ptr) ;
  (* display the window whose descriptor is win_ptr on the screen *)
  (* this routine is called by other routines and shouldn't be called *)
  (* directly. Use use_window instead *)
  VAR
   save_size,save_org : window_pos ;
  BEGIN
   WITH win_ptr^ DO
    BEGIN
     get_window_co_ords(win_ptr,save_org,save_size) ;
     move_to_scrn(save_org,save_size,scrn_area) ;
    END ;
  END ; (* display_window *)


 PROCEDURE use_window(win_ptr : window_ptr) ;
  (* make win_ptr the current window, display it and restore cursor *)
  (* to its original position. The old window is saved and becomes the *)
  (* second window on the list *)
  BEGIN
   IF win_ptr <> NIL
    THEN
     IF win_ptr <> window_list
      THEN
       BEGIN
        save_window ;
        del_desc(win_ptr) ;
        ins_desc(win_ptr) ;
        display_window(win_ptr) ;
        WITH window_list^ DO
         BEGIN
          window(abs_org.x,abs_org.y,abs_org.x + window_size.x - 1,
                 abs_org.y + window_size.y - 1) ;
          gotoxy(cursor_pos.x,cursor_pos.y) ;
          textcolor(fore_color) ;
          textbackground(back_color) ;
         END ;
       END ;
  END ; (* use_window *)


 PROCEDURE scrn_refresh ;
  (* Re-draw the entire screen. The screen is assembled in a memory *)
  (* buffer before being moved to physical screen. The screen is assembled *)
  (* from the last window forward. We assemble the screen in memory *)
  (* to prevent the annoying screen blank which occurs when you assemble *)
  (* dirctly in the screen area *)
  (* screen - 4000 byte memory region to assemeble the screen *)
  VAR
   physical_scrn,save_scrn,screen : char_ptr ;
   save_size,save_org : window_pos ;
   i : row_pos ;

  PROCEDURE scrn_fill(win_ptr : window_ptr) ;
   (* This routine is like move_to_scrn, except it moves the data to *)
   (* the buffer rather than the actual screen *)
   BEGIN
    IF win_ptr <> NIL
     THEN
      BEGIN
       WITH win_ptr^ DO
        BEGIN
         get_window_co_ords(win_ptr,save_org,save_size) ;
         physical_scrn := ptr(seg(screen^),ofs(screen^) +
                             ((save_org.y - 1) * 80 + (save_org.x - 1)) * 2) ;
         save_scrn := scrn_area ;
         FOR i := 1 TO save_size.y DO
          BEGIN
           move(save_scrn^,physical_scrn^,save_size.x * 2) ;
           physical_scrn := ptr(seg(physical_scrn^),ofs(physical_scrn^) + 160) ;
           save_scrn := ptr(seg(save_scrn^),ofs(save_scrn^) + save_size.x * 2 ) ;
          END ;
        END ;
       scrn_fill(win_ptr^.prev_window) ;
      END ;
   END ; (* scrn_fill *)

  BEGIN
   getmem(screen,4000) ;
   fillchar(screen^,4000,chr(0)) ;
   scrn_fill(last_window) ;
   save_org.x := 1 ;
   save_org.y := 1 ;
   save_size.x := 80 ;
   save_size.y := 25 ;
   move_to_scrn(save_org,save_size,screen) ;
   freemem(screen,4000) ;
   IF window_list <> NIL
    THEN
     WITH window_list^ DO
      BEGIN
       window(abs_org.x,abs_org.y,abs_org.x + window_size.x - 1,
              abs_org.y + window_size.y - 1) ;
       gotoxy(cursor_pos.x,cursor_pos.y) ;
       textcolor(fore_color) ;
       textbackground(back_color) ;
      END
    ELSE window(1,1,80,25) ;
  END ; (* scrn_refresh *)


 PROCEDURE close_window(win_ptr : window_ptr) ;
  (* remove the window from the window_list, and then call scrn_refesh *)
  (* update the screen. If win_ptr is the current window, the next window *)
  (* becomes the active window *)
  VAR
   save_org,save_size : window_pos ;

  FUNCTION found_window : boolean ;
   VAR
    p : window_ptr ;
    found : boolean ;
   BEGIN
    found := false ;
    p := window_list ;
    WHILE (p <> NIL) AND (NOT found) DO
     BEGIN
      found := (win_ptr = p) ;
      p := p^.next_window ;
     END ;
    found_window := found ;
   END ; (* found_window *)

  BEGIN
   IF found_window
    THEN
     BEGIN
      IF win_ptr <> window_list
       THEN save_window ;
      get_window_co_ords(win_ptr,save_org,save_size) ;
      del_desc(win_ptr) ;
      IF win_ptr^.scrn_area <> NIL
       THEN freemem(win_ptr^.scrn_area,2 * save_size.x * save_size.y) ;
      freemem(win_ptr,sizeof(window_desc)) ;
      scrn_refresh ;
     END ;
  END ; (* close_window *)

(* ///////////////////// Window routines for this program ////////// *)

 PROCEDURE wait ;
  (* Display a message at bottom of screen and and wait for user to *)
  (* press a key *)
  VAR
   ch : char ;
   old_window : window_ptr ;
  BEGIN
   old_window := window_list ;
   use_window(message_window) ;
   clrscr ;
   gotoxy(1,2) ;
   window_write('Press any key to continue ') ;
   read(kbd,ch) ;
   clrscr ;
   use_window(old_window) ;
  END ; (* wait *)


 PROCEDURE init_windows ;
  (* Initialize windows for this program *)
  BEGIN
   clrscr ;
   get_monitor_type ;
   IF monitor_kind = mono_monitor
    THEN button_fore := blue
    ELSE button_fore := yellow ;
   button_back := black ;
   window_list := NIL ;
   message_window := open_window(2,23,78,2,false,'',white,black,white) ;
   main_window := open_window(2,2,78,20,true,'HyperText',white,blue,white) ;
   gotoxy(10,5) ;
   window_writeln('HYPE - Copyright [c] 1987 Knowledge Garden Inc.') ;
   window_writeln('                          473A Malden Bridge Rd.') ;
   window_writeln('                          Nassau, NY 12123') ;
   wait ;
   clrscr ;
  END ; (* init_windows *)


 PROCEDURE finish_up ;
  (* Clean up screen before leaving *)
  BEGIN
   window(1,1,80,25) ;
   textcolor(white) ;
   textbackground(black) ;
   clrscr ;
  END ; (* finish_up *)


 PROCEDURE error(msg : string80) ;
  (* Display a message and wait for the user to read it *)
  VAR
   error_window : window_ptr ;
  BEGIN
   error_window := open_window(10,10,60,3,true,'Error',white,red,white) ;
   window_writeln('') ;
   window_write(msg) ;
   wait ;
   close_window(error_window) ;
  END ; (* error *)

(* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ *)

 FUNCTION got_file : boolean ;
  (* Called from main program block to get the file name typed after *)
  (* the program at the DOS prompt *)
  (* If the file cannot be found, display an error message and quit *)
  VAR
   f_name : string80 ;
  BEGIN
   f_name := paramstr(1) ;
   IF f_name = ''
    THEN
     BEGIN
      error('Missing file name -- Try ''hype filename''') ;
      got_file := false ;
     END
   ELSE IF open(main_file,f_name)
    THEN got_file := true
   ELSE
    BEGIN
     error(concat('Unable to open ',f_name)) ;
     got_file := false ;
    END ;
  END ; (* got_file *)


 PROCEDURE process_file(title : string80 ; VAR f : text_file ;
                        text_window : window_ptr) ;
  (* The actual hypertext routine *)
  (* Reads file f starting at current line until eof or ..end(title) *)
  (* builds a linked list of line descriptors and displays them one page *)
  (* at a time in text_window *)
  (* first_line - start of list of lines *)
  (* last_line - last line *)
  (* mark_win_org,mark_win_size,mark_fore,mark_back - window parameters *)
  (*              for threaded text display *)
  VAR
   first_line,last_line : line_ptr ;
   mark_win_org,mark_win_size : window_pos ;
   mark_fore,mark_back : color ;

  PROCEDURE release_list(list : line_ptr) ;
   (* free memory used by line descriptors and text *)
   VAR
    p : line_ptr ;
   BEGIN
    WHILE list <> NIL DO
     BEGIN
      p := list ;
      list := list^.next_line ;
      freemem(p^.txt,length(p^.txt^) + 1) ;
      freemem(p,sizeof(line_desc)) ;
     END ;
   END ; (* release_list *)

  PROCEDURE read_file(VAR f : text_file ; f_title : string80 ;
                      VAR first,last : line_ptr) ;
   (* read file f until eof or ..end(f_title) *)
   (* build linked list of text lines *)
   (* lines beginning with .. are processed separately, only lines *)
   (* pertaining to concept f_title are processed *)
   (* first,last point to the start and end of the line list *)
   (* We only allocate enough storage for the actual characters in the line, *)
   (* not all 255 characters *)
   VAR
    line : string255 ;
    p : line_ptr ;
    done : boolean ;

   PROCEDURE insert_line(lne : line_ptr) ;
    (* insert a line at the end of the line list *)
    BEGIN
     lne^.next_line := NIL ;
     lne^.prev_line := last ;
     IF last = NIL
      THEN first := lne
      ELSE last^.next_line := lne ;
     last := lne ;
    END ; (* insert_line *)

   PROCEDURE process_dots ;
    (* process lines beginning with dots *)

    PROCEDURE process_end ;
     (* process ..end *)
     (* if ..end(f_title) then we are done with this concept *)
     BEGIN
      delete(line,1,4) ;
      strip_leading_blanks(line) ;
      IF copy(line,1,length(f_title)) = f_title
       THEN done := true ;
     END ; (* process_end *)

    PROCEDURE process_window ;
     (* process ..window(f_title) - sets window parameteres for this concept *)
     (* syntax is ..window(f_title) fore_color,back_color,org_x,org_y, *)
     (*                            size_x,size_y   *)

     FUNCTION read_num(def : integer) : integer ;
      (* read next number from line *)
      VAR
       comma_pos : byte ;
       num : string80 ;

      FUNCTION get_num(num_str : string80) : integer ;
       VAR
        finished : boolean ;
        n : string80 ;
       BEGIN
        n := '' ;
        finished := false ;
        WHILE NOT finished DO
         IF num_str = ''
          THEN finished := true
         ELSE IF num_str[1] IN ['0' .. '9']
          THEN
           BEGIN
            n := concat(n,num_str[1]) ;
            delete(num_str,1,1) ;
           END
         ELSE finished := true ;
        get_num := tointeger(n) ;
       END ; (* get_num *)

      BEGIN
       comma_pos := pos(',',line) ;
       IF comma_pos > 0
        THEN
         BEGIN
          num := copy(line,1,comma_pos - 1) ;
          delete(line,1,comma_pos) ;
         END
        ELSE
         BEGIN
          num := line ;
          line := '' ;
         END ;
       strip_leading_blanks(num) ;
       IF num = ''
        THEN read_num := def
        ELSE read_num := get_num(num) ;
      END ; (* read_num *)

     BEGIN
      delete(line,1,7) ;
      strip_leading_blanks(line) ;
      IF copy(line,1,length(f_title)) = f_title
       THEN
        BEGIN
         delete(line,1,length(f_title)) ;
         strip_leading_blanks(line) ;
         delete(line,1,1) ;
         mark_fore := abs(read_num(def_fore_color)) MOD 16 ;
         mark_back := abs(read_num(def_back_color)) MOD 16 ;
         mark_win_org.x := max(min(read_num(mark_win_org.x),80),1) ;
         mark_win_org.y := max(min(read_num(mark_win_org.y),25),1) ;
         mark_win_size.x := max(min(read_num(mark_win_size.x),80),1) ;
         mark_win_size.y := max(min(read_num(mark_win_size.y),25),1) ;
        END ;
     END ; (* process_window *)

    PROCEDURE process_new_file ;
     (* process ..file(f_title) file_name *)
     (* read a list of lines from file_name and attach them to the end *)
     (* of the current list *)
     VAR
      new_file : text_file ;
      new_file_name : string80 ;

     PROCEDURE read_new_file ;
      VAR
       new_start,new_last : line_ptr ;
      BEGIN
       read_file(new_file,f_title,new_start,new_last) ;
       IF new_start <> NIL
        THEN
         BEGIN
          new_start^.prev_line := last ;
          IF last = NIL
           THEN first := new_start
           ELSE last^.next_line := new_start ;
          last := new_last ;
         END ;
       close(new_file) ;
      END ; (* read_new_file *)

     BEGIN
      delete(line,1,5) ;
      strip_leading_blanks(line) ;
      IF copy(line,1,length(f_title)) = f_title
       THEN
        BEGIN
         delete(line,1,length(f_title)) ;
         strip_leading_blanks(line) ;
         delete(line,1,1) ;
         strip_leading_blanks(line) ;
         new_file_name := line ;
         IF open(new_file,new_file_name)
          THEN read_new_file
          ELSE error(concat(new_file_name,' can not be read.')) ;
        END ;
     END ; (* process_new_file *)

    BEGIN
     line := toupper(copy(line,3,255)) ;
     strip_trailing_blanks(line) ;
     IF copy(line,1,4) = 'END('
      THEN process_end
     ELSE IF copy(line,1,7) = 'WINDOW('
      THEN process_window
     ELSE IF copy(line,1,5) = 'FILE('
      THEN process_new_file ;
    END ; (* process_dots *)

   BEGIN
    f_title := toupper(f_title) ;
    first := NIL ;
    last := NIL ;
    done := false ;
    WHILE (NOT eof(f)) AND (NOT done) DO
     BEGIN
      readln(f,line) ;
      IF copy(line,1,2) = '..'
       THEN process_dots
       ELSE
        BEGIN
         getmem(p,sizeof(line_desc)) ;
         getmem(p^.txt,length(line) + 1) ;
         p^.txt^ := line ;
         insert_line(p) ;
        END ;
     END ;
   END ; (* read_file *)

  PROCEDURE display_list(first,last : line_ptr ; disp_window : window_ptr) ;
   (* display the list pointed to by first in disp_window *)
   (* read keyboard until F10 or Esc is pressed *)
   (* left and right arrows move among marked text, Enter selects text *)
   (* for display *)
   (* Text is displayed one page at a time - PgUp and PgDn page *)
   (* mark_list is a linked list of highlighted text on the current page *)
   (*           of the disp_window *)
   (* mark is the current mark, i.e. the one with the button color *)
   (* top_of_page points to first line on the page *)
   VAR
    done : boolean ;
    top_of_page : line_ptr ;
    mark,mark_list,last_mark : mark_ptr ;

   PROCEDURE display_message ;
    (* display available keys at bottom of screen *)
    BEGIN
     use_window(message_window) ;
     clrscr ;
     window_write('<-  ->    Select') ;
     gotoxy(1,2) ;
     window_write('<Enter>   View') ;
     gotoxy(30,1) ;
     window_write('<Esc>   Exit Window') ;
     gotoxy(60,1) ;
     window_write('PgUp PgDn   Page') ;
     gotoxy(60,2) ;
     window_write('F10         Quit') ;
     use_window(disp_window) ;
    END ; (* display_message *)

   PROCEDURE move_to_mark(m_ptr : mark_ptr) ;
    (* move to the highlighted region of screen pointed to by m_ptr *)
    (* redisplay text in button colors so that user can see where we are *)
    VAR
     p : mark_ptr ;

    PROCEDURE remove_old_mark ;
     (* return previous marked text to reverse video *)
     BEGIN
      gotoxy(mark^.mark_pos.x,mark^.mark_pos.y) ;
      window_reverse ;
      window_write(mark^.mark_text^) ;
      window_normal ;
     END ; (* remove_old_mark *)

    BEGIN
     IF m_ptr <> NIL
      THEN
       BEGIN
        IF mark <> NIL
         THEN remove_old_mark ;
        p := mark_list ;
        WHILE (p <> NIL) AND (p <> m_ptr) DO
         p := p^.next_mark ;
        IF p <> NIL
         THEN
          BEGIN
           mark := p ;
           gotoxy(mark^.mark_pos.x,mark^.mark_pos.y) ;
           textcolor(button_fore) ;
           textbackground(button_back) ;
           window_write(mark^.mark_text^) ;
           window_normal ;
           gotoxy(mark^.mark_pos.x,mark^.mark_pos.y) ;
          END ;
       END ;
    END ; (* move_to_mark *)

   PROCEDURE display_page ;
    (* display a page of text in disp_window *)
    (* marked text is displayed inreverse video *)
    (* move mark to first item on mark list *)
    VAR
     line_cnt : counter ;
     p : line_ptr ;

    PROCEDURE release_marks ;
     (* release the old mark list - the mark list is rebuilt each *)
     (* time a page is displayed *)
     VAR
      m_ptr : mark_ptr ;
     BEGIN
      WHILE mark_list <> NIL DO
       BEGIN
        m_ptr := mark_list ;
        mark_list := mark_list^.next_mark ;
        freemem(m_ptr^.mark_text,length(m_ptr^.mark_text^) + 1) ;
        freemem(m_ptr,sizeof(mark_desc)) ;
       END ;
      mark := NIL ;
      last_mark := NIL ;
     END ; (* release_marks *)

    PROCEDURE write_the_line(s : string255) ;
     (* write the line on the screen *)
     (* if text is marked add it to list and display inreverse video *)
     VAR
      mark_loc : byte ;

     PROCEDURE add_mark ;
      (* add this text to list and save its co-ordinates *)
      VAR
       m_ptr : mark_ptr ;
       ps : integer ;
      BEGIN
       getmem(m_ptr,sizeof(mark_desc)) ;
       m_ptr^.mark_pos.x := wherex ;
       m_ptr^.mark_pos.y := wherey ;
       delete(s,1,1) ;
       ps := pred(pos(mark_char,s)) ;
       IF ps < 0
        THEN ps := length(s) ;
       getmem(m_ptr^.mark_text,ps + 1) ;
       m_ptr^.mark_text^ := copy(s,1,ps) ;
       window_reverse ;
       window_write(m_ptr^.mark_text^) ;
       window_normal ;
       delete(s,1,succ(ps)) ;
       m_ptr^.next_mark := NIL ;
       m_ptr^.prev_mark := last_mark ;
       IF last_mark = NIL
        THEN mark_list := m_ptr
        ELSE last_mark^.next_mark := m_ptr ;
       last_mark := m_ptr ;
      END ; (* add_mark *)

     BEGIN
      IF s <> ''
       THEN
        BEGIN
         mark_loc := pos(mark_char,s) ;
         IF mark_loc > 0
          THEN
           BEGIN
            window_write(copy(s,1,pred(mark_loc))) ;
            delete(s,1,pred(mark_loc)) ;
            add_mark ;
            write_the_line(s) ;
           END
         ELSE window_write(s) ;
        END ;
     END ; (* write_the_line *)

    BEGIN
     release_marks ;
     clrscr ;
     p := top_of_page ;
     line_cnt := 1 ;
     WHILE (p <> NIL) AND (line_cnt <= disp_window^.window_size.y) DO
      BEGIN
       gotoxy(1,line_cnt) ;
       IF copy(p^.txt^,1,2) <> '..'
        THEN
         BEGIN
          write_the_line(p^.txt^) ;
          line_cnt := succ(line_cnt) ;
         END ;
       p := p^.next_line ;
      END ;
     move_to_mark(mark_list)
    END ; (* display_page *)

   PROCEDURE handle_keys ;
    (* read the keyboard - ignore everything but keys displayed on bottom *)
    (* of screen *)
    VAR
     ch : char ;

    PROCEDURE exit_prog ;
     (* F10 - pressed erase screen and quit *)
     BEGIN
      finish_up ;
      halt(0) ;
     END ; (* exit_prog *)

    PROCEDURE page_forward ;
     (* display previous page *)
     (* count backwards until we get to it *)
     VAR
      p : line_ptr ;
      line_cnt : counter ;
     BEGIN
      p := top_of_page ;
      line_cnt := 1 ;
      WHILE (p <> NIL) AND (line_cnt < disp_window^.window_size.y) DO
       BEGIN
        p := p^.next_line ;
        line_cnt := succ(line_cnt) ;
       END ;
      IF p <> NIL
       THEN
        IF p^.next_line <> NIL
         THEN
          BEGIN
           top_of_page := p^.next_line ;
           display_page ;
          END ;
     END ; (* page_forward *)

    PROCEDURE page_back ;
     (* display next page *)
     (* count forwards until we get to it *)
     VAR
      p : line_ptr ;
      line_cnt : counter ;
     BEGIN
      p := top_of_page ;
      line_cnt := disp_window^.window_size.y ;
      WHILE (p <> NIL) AND (line_cnt >= 1)
       BEGIN
        p := p^.prev_line ;
        line_cnt := pred(line_cnt) ;
       END ;
      IF p <> NIL
       THEN
        BEGIN
         top_of_page := p ;
         display_page ;
        END ;
     END ; (* page_back *)

    PROCEDURE move_to_next_mark ;
     (* move to next mark on screen, if at end go back to first *)
     BEGIN
      IF mark_list <> NIL
       THEN
        BEGIN
         IF mark^.next_mark <> NIL
          THEN move_to_mark(mark^.next_mark)
          ELSE move_to_mark(mark_list) ;
        END ;
     END ; (* move_to_next_mark *)

    PROCEDURE move_to_prev_mark ;
     (* move to prev mark on screen, if at first go to end *)
     BEGIN
      IF mark_list <> NIL
       THEN
        BEGIN
         IF mark^.prev_mark <> NIL
          THEN move_to_mark(mark^.prev_mark)
          ELSE move_to_mark(last_mark) ;
        END ;
     END ; (* move_to_prev_mark *)

    PROCEDURE process_mark ;
     (* process the text under the button *)
     (* find its lable in the file, open a window and display it *)
     VAR
      mark_start,mark_end : line_ptr ;
      mark_window : window_ptr ;

     FUNCTION found_mark : boolean ;
      VAR
       found : boolean ;
       mark_str,line : string255 ;
      BEGIN
       mark_str := toupper(mark^.mark_text^) ;
       found := false ;
       reset(f) ;
       WHILE (NOT eof(f)) AND (NOT found) DO
        BEGIN
         readln(f,line) ;
         found := (toupper(copy(line,3,255)) = mark_str) ;
        END ;
       found_mark := found ;
      END ; (* found_mark *)

     PROCEDURE set_window_parameters ;
      (* set default window paramters *)
      BEGIN
       mark_win_org.x := (disp_window^.abs_org.x + 2) MOD 8 ;
       mark_win_org.y := (disp_window^.abs_org.y + 2) MOD 8 ;
       mark_win_size.x := def_window_size_x ;
       mark_win_size.y := def_window_size_y ;
       mark_fore := def_fore_color ;
       mark_back := def_back_color ;
      END ; (* set_window_parameters *)

     BEGIN
      IF mark_list <> NIL
       THEN
        IF found_mark
         THEN
          BEGIN
           set_window_parameters ;
           read_file(f,mark^.mark_text^,mark_start,mark_end) ;
           mark_window := open_window(mark_win_org.x,mark_win_org.y,
                                      mark_win_size.x,mark_win_size.y,
                                      true,mark^.mark_text^,mark_fore,
                                      mark_back,mark_fore) ;
           display_list(mark_start,mark_end,mark_window) ;
           close_window(mark_window) ;
           use_window(disp_window) ;
           release_list(mark_start) ;
          END
         ELSE
          BEGIN
           error(concat('''',mark^.mark_text^,''' could not be found.')) ;
           display_message ;
          END ;
     END ; (* process_mark *)

    BEGIN
     read(kbd,ch) ;
     IF ch = enter
      THEN process_mark
     ELSE IF ch = esc
      THEN
       IF keypressed
        THEN
         BEGIN
          read(kbd,ch) ;
          CASE ch OF
           right_arrow : move_to_next_mark ;
           left_arrow  : move_to_prev_mark ;
           PgUp        : page_back ;
           PgDn        : page_forward ;
           F10         : exit_prog ;
          END ;
         END
        ELSE done := true ;
    END ; (* handle_keys *)

   BEGIN
    done := false ;
    display_message ;
    mark := NIL ;
    mark_list := NIL ;
    last_mark := NIL ;
    top_of_page := first ;
    display_page ;
    WHILE NOT done DO
     handle_keys ;
   END ; (* display_list *)

  BEGIN
   reset(f) ;
   read_file(f,title,first_line,last_line) ;
   display_list(first_line,last_line,text_window) ;
   release_list(first_line) ;
  END ; (* process_file *)


 BEGIN
  init_windows ;
  IF got_file
   THEN
    BEGIN
     process_file('MAIN',main_file,main_window) ;
     close(main_file) ;
    END ;
  finish_up ;
 END.