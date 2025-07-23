From news.media.mit.edu!snorkelwacker.mit.edu!stanford.edu!ames!haven.umd.edu!darwin.sura.net!zaphod.mps.ohio-state.edu!sol.ctr.columbia.edu!The-Star.honeywell.com!umn.edu!mmm.serc.3m.com!mmc.mmmg.com!timbuk.cray.com!hemlock.cray.com!kilian Thu Oct 15 10:59:58 EDT 1992
Article: 2578 of comp.robotics
Newsgroups: comp.robotics
Path: news.media.mit.edu!snorkelwacker.mit.edu!stanford.edu!ames!haven.umd.edu!darwin.sura.net!zaphod.mps.ohio-state.edu!sol.ctr.columbia.edu!The-Star.honeywell.com!umn.edu!mmm.serc.3m.com!mmc.mmmg.com!timbuk.cray.com!hemlock.cray.com!kilian
From: kilian@cray.com (Alan Kilian)
Subject: Test program for miniboard & hexmon
Message-ID: <1992Oct14.162907.15470@hemlock.cray.com>
Lines: 178
Nntp-Posting-Host: gopher
Organization: Cray Research, Inc.
Date: 14 Oct 92 16:29:07 CDT

Here is a program that communicates with HEXMON and prints out several 
interesting values.

It's written for Microsoft quick C and the cct serial communications
library but you'll figure out your own serial I/O if it's different.

Have fun.
                     -Alan Kilian

----------------------------- cut here -----------------------------------------
#include <comm.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

/* MANIFEST CONSTANTS AND MACROS */
#define MENU            ALT_M          /* key for menu */
#define ECHO		1
#define	NOECHO		0
#define FORWARD 	1
#define REVERSE		2

/* FUNCTION PROTOTYPES */
short   menu(void);
void    doit(COMM_PORT *p);
void	bios_cur_pos(short row, short col);
void	read_hexmon(int echo);

/* GLOBAL VARIABLES */
COMM_PORT   port1;
BYTE        rxbuf[2048];             /* RECEIVE BUFFER */
char	    buffer[80];

int main(void)
{
    int i;
    init_port(&port1, COM1, 9600L, DATABITS8, PARITY_NONE, STOPBITS1);
    install_ipr(&port1, RECEIVE, NULL, rxbuf, sizeof(rxbuf));
    install_isr(&port1, 4, NULL);       /* USE IRQ4 */

    for(i=0;i<24;i++) {
        bios_cur_pos(0,i);
        printf("                                                                              \n");
    }
    bios_cur_pos(20,0);
    printf("MC68HC811E2 tester using HEXMON 4.0\n");
    bios_cur_pos(20,8);
    printf("     Press Alt-M for menu to quit  \n");

    doit(&port1);

    deinit_port(&port1);

    return (0);
}

void read_hexmon(int echo) {
    int c;

    while ((c = c_inchar(&port1)) == EOF);	/* Get the command char */
    do {
        while ((c = c_inchar(&port1)) == EOF);	/* Get any char */
	if(c != '>') if (echo == ECHO) putchar(c);
    } while (c != '>');
    fflush(stdout);
}

void doit(COMM_PORT *p)
{
    short c;              /* must be signed to detect a -1 return */
    int i;
    int direction = FORWARD;

    /*
     * Turn the motors on
     */
    c_printf(p,"w00ff005d");
    read_hexmon(NOECHO);

    /*
     * Turn the motors PWM to 50%
     */
    c_printf(p,"z5555005e");
    read_hexmon(NOECHO);
    c_printf(p,"z55550060");
    read_hexmon(NOECHO);
    c_printf(p,"z55550062");
    read_hexmon(NOECHO);
    c_printf(p,"z55550064");
    read_hexmon(NOECHO);

    for (;;) {
	/*
	 * Print out the analog input values
 	 */
	for(i=0;i<8;i++) {
	    bios_cur_pos(0,i+2);
	    printf("Analog input #%d = ",i);
	    sprintf(buffer,"r000000%02x",0x54+i);
	    c_printf(p,buffer);
	    read_hexmon(ECHO);
	}

	/*
	 * Print out the timestamp
 	 */
        bios_cur_pos(22,2);
	printf("Timestamp ");
	c_printf(p,"q00000000");
	read_hexmon(ECHO);
	c_printf(p,"q00000002");
	read_hexmon(ECHO);

	/*
	 * Print out the digital inputs
 	 */
        bios_cur_pos(22,3);
	printf("Digital inputs ");
	c_printf(p,"r00001003");
	read_hexmon(ECHO);

	/*
	 * reverse all the motors
 	 */
	if(direction == FORWARD) {
	    direction = REVERSE;
	    c_printf(p,"w00f0005d");
	    read_hexmon(NOECHO);
	} else {
	    direction = FORWARD;
	    c_printf(p,"w00ff005d");
	    read_hexmon(NOECHO);
	}

        /* CHECK KEYBOARD FOR A KEY PRESS */
        if ( (c = inkey()) != EOF) {
            if (c == MENU) {
                if (menu()) break;
            }
            else c_putc(p, c);
        }
    }
}

#define EXIT 'Q'                /* key to exit from main */

short menu(void)
{
    int c, retval = 0;
    static char *menus[] = {
        "\tQ.  EXIT from TERM.",
        NULL                        /* null string terminates list */
    };
    char **p_menu;

    c = !EXIT;
    while (c != EXIT && c != LF) {
        puts("\n\n");
        for (p_menu = menus; *p_menu != NULL; p_menu++) printf("%s\n", *p_menu);
        printf("\n\t\t Enter selection (CR to quit menu) :  ");
        c = getchar();
        c = toupper(c);
        switch (c) {
            case EXIT:
                retval = 1;
                break;
            default:
                break;
        }
    }
    puts("\nExiting menu");

    return (retval);                /* will be zero except if EXIT */
}
-- 
 -Alan Kilian           kilian@cray.com 612.683.5499 (Work) 612.721.3990 (Home)
  Cray Research, Inc.   655 F Lone Oak Drive, Eagan  MN, 55121 
                        "It's based on actual math". -Dilbert


