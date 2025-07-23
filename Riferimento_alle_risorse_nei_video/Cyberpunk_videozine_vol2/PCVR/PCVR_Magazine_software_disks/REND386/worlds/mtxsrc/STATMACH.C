/* threaded state machine animation system */

/* Written by Dave Stampe Oct. 1992 */

/* Copyright 1992 by Dave Stampe and Bernie Roehl.
	 May be freely used to write software for release into the public domain;
	 all commercial endeavours MUST contact Bernie Roehl and Dave Stampe
	 for permission to incorporate any part of this software into their
	 products!

	 ATTRIBUTION:  If you use any part of this source code or the libraries
	 in your projects, you must give attribution to REND386, Dave Stampe,
	 and Bernie Roehl in your documentation, source code, and at startup
	 of your program.  Let's keep the freeware ball rolling!
 */

#pragma inline

#include <stdio.h>
#include <stdlib.h>  	/* malloc() */
#include <conio.h>      /* kbhit() */
#include <string.h>

#include "rend386.h"  /* for current_time() */
#include "intmath.h"
#include "userint.h"

extern void connect_body(VIEW *v, SEGMENT *s);
extern void disconnect_body(VIEW *v);

/* from world.c */

typedef struct _name NAMEREF;

struct _name {
	char *name;
	void *value;
	NAMEREF *next;
};

extern NAMEREF *add_name(NAMEREF **list, char *name, void *value);
extern void del_namelist(NAMEREF *list);
extern void *find_name(NAMEREF *list, char *name);
extern SEGMENT *find_seg(char *name);

extern int flymode;

#define FREE     0      /* state (instruction) type */
#define STEP     1
#define MOVETO   2
#define POSTEST  3
#define ROTTEST  4
#define SET      5
#define SENSOR   6
#define SELECTED 7
#define TIMER    8
#define GRAVITY  9
#define POSLIMIT 10
#define ROTLIMIT 11
#define USEREP   12
#define ABSTEP   13
#define ATTACH   14
#define POPTEXT  15

#define DONTCARE 0x80000000L    /* value for sets and tests */

#define SAME     0              /* status of timer and gravity */
#define CHANGED  1
#define EXPIRED  2

typedef struct _state {
			int type;               /* type of operation       */
			int status;             /* marks timer, gravity    */
			struct _state *next;    /* next operation in state */
			int tst1v, tst1i;       /* evaluation tests        */
			int tst2v, tst2i;
			struct _state *sstate;  /* "set" assignments, next state */
			int set1v, set1i;
			int set2v, set2i;
			int set3v, set3i;
			struct _state *rstate;  /* "reset" same    */
			int rst1v, rst1i;
			int rst2v, rst2i;
			int rst3v, rst3i;
			SEGMENT *seg;           /* segment to use  */
			long x1, y1, z1;        /* numerical arg's */
			long x2, y2, z2;        /* 1 = po's'n 2 = rotate */
			long x3, y3, z3;        /* 3 = gravity accel */
			unsigned xo1, yo1, zo1; /* underflows */
			unsigned xo2, yo2, zo2;
			struct _state *ulist;   /* list of seg's moved */
			} STATE;

typedef struct _ani {
		 struct _ani *next;       /* next animation task      */
		 long last_time;          /* last time run            */
		 long period;             /* delay between runs       */
		 STATE *lstate;           /* set if state has changed */
		 STATE *state;            /* current state in machine */
		} ANIMATION;

static ANIMATION *anilist = NULL;
static ANIMATION *cur_ani = NULL;
static STATE *cur_state   = NULL;
static STATE *update_list = NULL;
static STATE *update_end  = NULL;

NAMEREF *statelist  = NULL;
NAMEREF *varlist    = NULL;

#define VARIABLES 200
static int vars[VARIABLES];
static int varcount = 0;

extern NAMEREF *figurelist;
extern NAMEREF *fixedolist;
extern SEGMENT *body_seg, *head_seg, *wrist_seg;

static long ctime;

void create_default_segs()
{
 body_seg  = new_seg(NULL);
 head_seg  = new_seg(NULL);
 wrist_seg = new_seg(NULL);

 add_name(&figurelist, "user_body", body_seg);
 add_name(&figurelist, "user_head", head_seg);
 add_name(&figurelist, "user_hand", wrist_seg);
}

static void dump_states(void)	/* remove states in preparation for new animation */
{
 del_namelist(statelist);
 statelist = NULL;
}


static int varindex(char *name)     /* return index of variable, or allocate new */
{
 void *v;

 if ((v = find_name(varlist, name))!=NULL)
	{
	 return (int)v;
	}
 else
	{
	 if (varcount == VARIABLES-1) return 0;
	 else
		{
		 varcount++;
		 v = (void *) varcount;
		 if (add_name(&varlist, name, v)) return varcount;
		 else return 0;
		}
	}
}


static STATE * stateptr(char *name)   /* return adr. of state, or allocate new */
{
 STATE *v;

 if ((v = find_name(statelist, name))!=NULL)
	{
	 return v;
	}
 else
	{
	 v = (STATE *) malloc(sizeof(STATE));
	 if (v == NULL) return NULL;
	 else
		{                   /* mark as usable as first command in state */
		 v->type = FREE;
		 if (add_name(&statelist, name, v)) return v;
		 else return NULL;
		}
	}
}


static char ps[] = " ,\t\n";
static char st[] = "%s";

void parse_ani()
{
 float period = 10;
 ANIMATION *ani, *a;

 dump_states();
 period = atof(strtok(NULL,ps));
 ani = (ANIMATION *)malloc(sizeof(ANIMATION));
 if (ani == NULL)
	{
	 cur_ani = NULL;
	 return;
	}
 ani->period = 180.0/period;
 ani->last_time = -10000000L;            /* set to run immediately */
 ani->lstate = NULL;
 ani->state = NULL;

 ani->next = NULL;                 /* put it at end of list  */
 if (anilist == NULL) anilist = ani;
 else
	{
	 for(a = anilist;a->next;a=a->next);
	 a->next = ani;
	}
 cur_ani = ani;
}


void parse_state()
{
 char name[40];
 sscanf(strtok(NULL,ps),st, name);
 cur_state = stateptr(name);             /* get new/old state adr.     */
 if (cur_ani == NULL) return;               /* sequence error!            */
 if (cur_ani->state == NULL)
		cur_ani->state = cur_state;          /* set initial state if first */
}


static STATE *new_state(void)
{
 STATE *s;

 if (cur_state == NULL) return NULL;
 if (cur_state->type == FREE) return cur_state;
 else
	{
	 s = (STATE *)malloc(sizeof(STATE));
	 if (s == NULL)
		{
		 cur_state = NULL;
		 return NULL;
		}
	 s->type = FREE;
	}
 return s;
}


static void parse_var(char *c, int *v, int *i)
{
 char *cc;

 *i = *v = 0;
 if ((cc = strchr(c, '=')) == NULL) return;
 *cc++ = 0;
 *i = varindex(c);
 *v = atoi(cc);
}


static STATE *parse_as(char *c, int *v, int *i)
{
 char *cc;

 *i = *v = 0;
 if (!strcmpi(c, "EXIT"))     /* keyword "exit" */
  {
   *v = -1;
   *i = -1;
   return NULL;
  }
 if ((cc = strchr(c, '=')) == NULL) return NULL;
 *cc++ = 0;
 if (strcmpi(c, "STATE"))
  {
   *v = atoi(cc);
   *i = varindex(c);
   return NULL;
  }
 else
  {
   *v = *i = 0;
   return stateptr(cc);
  }
}


static char *parse_assgn(char *ci, STATE *s, int set)
{
 int v1, v2, v3, i1, i2, i3;
 STATE *ss, *sp = NULL;
 char *c, *r;

 if (set)
	{
	 s->set1i = s->set2i = s->set3i = 0;
	 s->sstate = NULL;
	}
 else
	{
	 s->rst1i = s->rst2i = s->rst3i = 0;
	 s->rstate = NULL;
	}

 if ((c = strchr(ci,'[')) == NULL) return ci;   /* verify arguments   */
 if ((r = strchr(c, ']')) == NULL) return ci;   /* trim off enclosure */
 c++;  *r++ = 0;

 if ((ss = parse_as(strtok(c, " ,\t"),    &v1, &i1)) != NULL) sp = ss; ;
 if ((ss = parse_as(strtok(NULL, " ,\t"), &v2, &i2)) != NULL) sp = ss; ;
 if ((ss = parse_as(strtok(NULL, " ,\t"), &v3, &i3)) != NULL) sp = ss; ;
 if (set)
	{
	 s->set1v = v1;
	 s->set2v = v2;
	 s->set3v = v3;
	 s->set1i = i1;
	 s->set2i = i2;
	 s->set3i = i3;
	 s->sstate = sp;
	}
 else
	{
	 s->rst1v = v1;
	 s->rst2v = v2;
	 s->rst3v = v3;
	 s->rst1i = i1;
	 s->rst2i = i2;
	 s->rst3i = i3;
	 s->rstate = sp;
	}
 return r;
}


static long getarg(char *ci, float scale, long x)
{
 char *c;
 double f;

 c = strtok(ci, " \t\n,");
 if (c == NULL || !sscanf(c, "%lf", &f) ) return x;
 return (long) (scale * f);
}



static void parse_rest(char *ci, STATE *s)
{
 char cmd[40]="", var[40]="", segn[40]="";
 char *c, *cc, *cr;
 SEGMENT *sp;
 long jx, jy, jz;

 sscanf(ci, "%[^([\n]", cmd);   /* get segment and command */
 if (strchr(cmd,'='))
	{
	 c = strchr(cmd, '=');        /* split */
	 *c++ = 0;
	 sscanf(cmd, "%s", segn);      /* strip off whitespace */
	 sscanf(c,"%s", var);
	 sp = find_seg(segn);          /* find segment if any  */
	 if (!stricmp(var,"SELECTED"))
		{
		 if (sp != NULL) sp = seg_get_object(sp);
		 else sp = find_name(fixedolist, segn);
#ifdef USED_TO_BE
		 else sp = find_name(&fixedolist, segn);
#endif
		 if (sp == NULL) return;
		}
	 else
		{
		 if (sp == NULL) return;
		 full_update_segment(find_root_segment(sp));    /* make sure root is current!    */
		 seg_getjointang(sp, &jx, &jy, &jz); /* and cached angle */
		}
	 s->seg = sp;

	 if (stricmp(var,"SET"))
		{
		 if ((c = strchr(ci,'(')) == NULL) return;   /* verify arguments */
		 if ((cr = strchr(ci,')')) == NULL) return;
		 c++; *cr++ = 0;
		}
	 else cr = strchr(ci,'[');

	 if (!stricmp(var, "MOVETO"))
		{
		 s->x1 = getarg(c,    1, DONTCARE);
		 s->y1 = getarg(NULL, 1, DONTCARE);
		 s->z1 = getarg(NULL, 1, DONTCARE);
		 s->x2 = getarg(NULL, 65536, DONTCARE);
		 s->y2 = getarg(NULL, 65536, DONTCARE);
		 s->z2 = getarg(NULL, 65536, DONTCARE);
		 parse_assgn(cr, s, 1);
		 s->type = MOVETO;
		}
	 else if (!stricmp(var, "USEREP"))
		{
		 OBJECT *o;
		 if ((o = seg_get_object(sp)) == NULL) return;
		 s->seg = o;
		 s->x1 = getarg(c, 1, 0) - 1;
		 parse_assgn(cr, s, 1);
		 s->type = USEREP;
		}
	 else if (!stricmp(var, "ATTACH"))
		{
		 if (sp == NULL) return;
		 s->x1 = getarg(c, 1, 1);
		 parse_assgn(cr, s, 1);
		 s->type = ATTACH;
		}
	 else if (!stricmp(var, "STEP"))
		{
		 s->x1 = getarg(c,    256, 0);
		 s->y1 = getarg(NULL, 256, 0);
		 s->z1 = getarg(NULL, 256, 0);
		 s->x2 = getarg(NULL, 65536, 0);
		 s->y2 = getarg(NULL, 65536, 0);
		 s->z2 = getarg(NULL, 65536, 0);
		 s->xo1 = s->yo1 = s->zo1 = 0;
		 parse_assgn(cr, s, 1);
		 s->type = STEP;
		}
	 else if (!stricmp(var, "ABSTEP"))
		{
		 s->x1 = getarg(c,    256, 0);
		 s->y1 = getarg(NULL, 256, 0);
		 s->z1 = getarg(NULL, 256, 0);
		 s->x2 = getarg(NULL, 65536, 0);
		 s->y2 = getarg(NULL, 65536, 0);
		 s->z2 = getarg(NULL, 65536, 0);
		 s->xo1 = s->yo1 = s->zo1 = 0;
		 parse_assgn(cr, s, 1);
		 s->type = ABSTEP;
		}
	 else if (!stricmp(var, "GRAVITY"))
		{
		 s->x2 = getarg(c,    256, 0);         /* initial */
		 s->y2 = getarg(NULL, 256, 0);
		 s->z2 = getarg(NULL, 256, 0);
		 s->x3 = getarg(NULL, 65536, 0);    /* accel */
		 s->y3 = getarg(NULL, 65536, 0);
		 s->z3 = getarg(NULL, 65536, 0);
		 s->xo1 = s->yo1 = s->zo1 = 0;
		 s->xo2 = s->yo2 = s->zo2 = 0;
		 parse_assgn(cr, s, 1);
		 s->type = GRAVITY;
		}
	 else if (!stricmp(var, "POSTEST"))
		{
		 s->x1 = getarg(c,    1, -1000000000L);
		 s->y1 = getarg(NULL, 1, -1000000000L);
		 s->z1 = getarg(NULL, 1, -1000000000L);
		 s->x2 = getarg(NULL, 1,  1000000000L);
		 s->y2 = getarg(NULL, 1,  1000000000L);
		 s->z2 = getarg(NULL, 1,  1000000000L);
		 cr = parse_assgn(cr, s, 1);
		 parse_assgn(cr, s, 0);
		 s->type = POSTEST;
		}
	 else if (!stricmp(var, "ROTTEST"))
		{
		 s->x1 = getarg(c,    65536, DONTCARE);
		 s->y1 = getarg(NULL, 65536, DONTCARE);
		 s->z1 = getarg(NULL, 65536, DONTCARE);
		 s->x2 = getarg(NULL, 65536, DONTCARE);
		 s->y2 = getarg(NULL, 65536, DONTCARE);
		 s->z2 = getarg(NULL, 65536, DONTCARE);
		 cr = parse_assgn(cr, s, 1);
		 parse_assgn(cr, s, 0);
		 s->type = ROTTEST;
		}
	 else if (!stricmp(var, "POSLIMIT"))
		{
		 s->x1 = getarg(c,    1, DONTCARE);
		 s->y1 = getarg(NULL, 1, DONTCARE);
		 s->z1 = getarg(NULL, 1, DONTCARE);
		 s->x2 = getarg(NULL, 1, DONTCARE);
		 s->y2 = getarg(NULL, 1, DONTCARE);
		 s->z2 = getarg(NULL, 1, DONTCARE);
		 cr = parse_assgn(cr, s, 1);
		 parse_assgn(cr, s, 0);
		 s->type = POSLIMIT;
		}
	 else if (!stricmp(var, "ROTLIMIT"))
		{
		 s->x1 = getarg(c,    65536, DONTCARE);
		 s->y1 = getarg(NULL, 65536, DONTCARE);
		 s->z1 = getarg(NULL, 65536, DONTCARE);
		 s->x2 = getarg(NULL, 65536, DONTCARE);
		 s->y2 = getarg(NULL, 65536, DONTCARE);
		 s->z2 = getarg(NULL, 65536, DONTCARE);
		 cr = parse_assgn(cr, s, 1);
		 parse_assgn(cr, s, 0);
		 s->type = ROTLIMIT;
		}
		 else if (!stricmp(var, "SELECTED"))
			{
			 s->x1 = getarg(c,    1, 0);
			 cr = parse_assgn(cr, s, 1);
			 parse_assgn(cr, s, 0);
			 s->type = SELECTED;
			}
	 else return;
	}
 else
	{
	 sscanf(cmd,"%s", var);
	 if (!stricmp(var, "SET"))
		{
		 parse_assgn(ci, s, 1);
		 s->type = SET;
		}
	 else
		{
		 if ((c=strchr(ci,'('))==NULL) return;   /* verify arguments */
		 if ((cr=strchr(c,')'))==NULL) return;
		 c++;
		 *cr++ = 0;
		 if (!stricmp(var, "SENSOR"))
			{
			 s->x1 = getarg(c,    1, -1000000000L);
			 s->y1 = getarg(NULL, 1, -1000000000L);
			 s->z1 = getarg(NULL, 1, -1000000000L);
			 s->x2 = getarg(NULL, 1,  1000000000L);
			 s->y2 = getarg(NULL, 1,  1000000000L);
			 s->z2 = getarg(NULL, 1,  1000000000L);
			 cr = parse_assgn(cr, s, 1);
			 parse_assgn(cr, s, 0);
			 s->type = SENSOR;
			}
	 else if (!stricmp(var, "POPTEXT"))
		{
		 s->x1 = getarg(c, 180, 90);
		 cr = parse_assgn(cr, s, 1);
		 c = strtok(cr, "#\n");
		 if (!c) return;
		 s->seg = strdup(c);
		 s->type = POPTEXT;
		}
		 else if (!stricmp(var, "TIMER"))
			{
			 s->x1 = getarg(c, 180, 0L);
			 s->y1 = DONTCARE;
			 cr = parse_assgn(cr, s, 1);
			 parse_assgn(cr, s, 0);
			 s->type = TIMER;
			}
		 else return;
		}
	}
 s->next = NULL;                 /* put it at end of list  */
 s->status = 1;                  /* force a restart        */
 if (cur_state==s) return;
 cur_state->next = s;
 cur_state = s;
}


void parse_if()
{
 STATE *s;
 char *c, *r;

 if ((s = new_state()) == NULL) return;
 c = strtok(NULL,"\n");
 if ((c = strchr(c,'(')) == NULL) return;   /* verify conditional terminators */
 if ((r = strchr(c,')')) == NULL) return;
 *r++ = 0;                            /* trim length */
 parse_var(strtok(c+1," \t\n,"),   &(s->tst1v), &(s->tst1i) );
 parse_var(strtok(NULL, " \t\n,"), &(s->tst2v), &(s->tst2i) );
 parse_rest(r, s);
}


void parse_do()
{
 STATE *s;

 if ((s = new_state()) == NULL) return;
 s->tst1i = 0;
 parse_rest(strtok(NULL,"\n"), s);
}


/********************* EXECUTE *******************/

static long elapsed = 0;
extern int redraw;
extern VIEW *current_view;

static void exec_state(STATE *s)
{
 STATE *old_state = s;
 int changed = (s==cur_ani->lstate) ? 0 : 1 ;
 long x, y, z, rx, ry, rz;
 long nx, ny, nz, nrx, nry, nrz;
 int seg_changed = 0;
 long tps = 180L;
 int endstate = 0;

 cur_state = s;
 while((cur_ani->state==old_state) && s)
	{
   if (s->type == FREE) goto next_state;
   if (changed) s->status |= CHANGED;
   if (s->type == TIMER && changed) s->y1 = DONTCARE;   /* reset on entry */
   if(s->type == GRAVITY && changed)
    {
     s->x1 = s->x2;
     s->y1 = s->y2;
     s->z1 = s->z2;
     s->xo1 = s->yo1 = s->zo1 = 0;
     s->xo2 = s->yo2 = s->zo2 = 0;
    }
   if (s->tst1i)
    {
     if (vars[s->tst1i] != s->tst1v) goto next_state;
     if (s->tst2i)
      {
       if (vars[s->tst2i] != s->tst2v) goto next_state;
      }
    }
   switch(s->type)
		{
     case SET: goto set;

		 case SELECTED:
			 if (get_obj_flags(s->seg) & OBJ_HIGHLIGHTED)
				{
				 if (s->x1) unhighlight_obj(s->seg);
				 goto reset;
				}
       else goto set;

     case USEREP:
      {
       if (s->x1 < 0) unlock_rep(s->seg);
       else lock_rep(s->seg, s->x1);
       redraw++;
       goto set;
      }

     case ATTACH:
      {
       if (s->x1 == 0)
	{
	 disconnect_body(current_view);
	 if (!flymode)
	  {
	   current_view->roll = 0;
	  }
	}
       else connect_body(current_view, s->seg);
       goto set;
      }

     case POPTEXT:
      {
       long t;
       if (s->seg) popmsg(s->seg);
       t = current_time()+s->x1;
       while(current_time() < t) if (kbhit()) break;
       while(kbhit()) getkey();
       redraw++;
       goto set;
      }

     case SENSOR:
      {
       extern VIEW real_view;
       long x,y,z;
       real_viewpoint(&real_view, &x, &y, &z);
       if (s->x1 > x) goto set;
       if (s->x2 < x) goto set;
       if (s->y1 > y) goto set;
       if (s->y2 < y) goto set;
       if (s->z1 > z) goto set;
       if (s->z2 < z) goto set;
       goto reset;
      }
     case POSTEST:
      {
       seg_getposxyz(s->seg, &x, &y, &z);
       if (s->x1 > x) goto set;
       if (s->x2 < x) goto set;
       if (s->y1 > y) goto set;
       if (s->y2 < y) goto set;
			 if (s->z1 > z) goto set;
       if (s->z2 < z) goto set;
       goto reset;
      }
		 case ROTTEST:
      {
       seg_getrxyz(s->seg, &x, &y, &z);
       if (s->x1 != DONTCARE && s->x1>x) goto set;
       if (s->x2 != DONTCARE && s->x2<x) goto set;
       if (s->y1 != DONTCARE && s->y1>y) goto set;
       if (s->y2 != DONTCARE && s->y2<y) goto set;
			 if (s->z1 != DONTCARE && s->z1 > z) goto set;
       if(s->z2 != DONTCARE && s->z2 < z) goto set;
       goto reset;
      }
     case POSLIMIT:
      {
       seg_getjointxyz(s->seg, &x, &y, &z);
       if (s->x1 != DONTCARE && s->x1 > x) { x = s->x1; goto rstp; }
       if (s->x2 != DONTCARE && s->x2 < x) { x = s->x2; goto rstp; }
       if (s->y1 != DONTCARE && s->y1 > y) { y = s->y1; goto rstp; }
       if (s->y2 != DONTCARE && s->y2 < y) { y = s->y2; goto rstp; }
       if (s->z1 != DONTCARE && s->z1 > z) { z = s->z1; goto rstp; }
       if (s->z2 != DONTCARE && s->z2 < z) { z = s->z2; goto rstp; }
       goto reset;
   rstp:
       seg_changed++;
       abs_move_segment(s->seg, x, y, z);
       goto move_seg;
      }
     case ROTLIMIT:
      {
			 seg_getrxyz(s->seg, &x, &y, &z);
       if (s->x1 != DONTCARE && s->x1 > x) { x = s->x1; goto rstr; }
       if (s->x2 != DONTCARE && s->x2 < x) { x = s->x2; goto rstr; }
       if (s->y1 != DONTCARE && s->y1 > y) { y = s->y1; goto rstr; }
       if (s->y2 != DONTCARE && s->y2 < y) { y = s->y2; goto rstr; }
			 if (s->z1 != DONTCARE && s->z1 > z) { z = s->z1; goto rstr; }
       if (s->z2 != DONTCARE && s->z2 < z) { z = s->z2; goto rstr; }
       goto reset;
   rstr:
       seg_changed++;
       abs_rot_segment(s->seg, x, y, z, RYXZ);
			 goto move_seg;
      }
		 case MOVETO:
			{
       seg_getjointxyz(s->seg, &x, &y, &z);
       seg_getrxyz(s->seg, &rx, &ry, &rz);
       nx = x; ny = y; nz = z;
       nrx = rx; nry = ry; nrz = rz;
       if (s->x1 != DONTCARE){ nx = s->x1; s->xo1 = 0; }   /* set pos'n, zero underflow */
       if (s->y1 != DONTCARE){ ny = s->y1; s->yo1 = 0; }
       if (s->z1 != DONTCARE){ nz = s->z1; s->zo1 = 0; }
       if (s->x2 != DONTCARE) nrx = s->x2;
       if (s->y2 != DONTCARE) nry = s->y2;
       if (s->z2 != DONTCARE) nrz = s->z2;
       if (x != nx || y != ny || z != nz)
	{
	 seg_changed++;
	 abs_move_segment(s->seg, nx, ny, nz);
	}
       if (rx != nrx || ry != nry || rz != nrz)
	{
	 seg_changed++;
	 abs_rot_segment(s->seg, nrx, nry, nrz, RYXZ);
	}
       if (seg_changed) goto move_seg; else goto set;
      }
		 case ABSTEP:
			 tps = elapsed;
		 case STEP:
			{
			 seg_getrxyz(s->seg, &rx, &ry, &rz);
			 nrx = rx; nry = ry; nrz = rz;
			 asm {
			.386
			les		bx,DWORD PTR s
			mov		eax,es:[bx].(STATE)x2
			imul	DWORD PTR elapsed
			idiv 	DWORD PTR tps
			add		eax,nrx
			cmp		eax,-360*65536
			jg		nccx
			add		eax,360*65536
		 }
nccx:  asm {
			cmp		eax,360*65536
			jl		nchx
			sub		eax,360*65536
		 }
nchx:  asm {
			mov		nrx,eax

			mov		eax,es:[bx].(STATE)y2
			imul	DWORD PTR elapsed
			idiv 	DWORD PTR tps
			add		eax,nry
			cmp		eax,-360*65536
			jg		nccy
			add		eax,360*65536
		 }
nccy:  asm {
			cmp		eax,360*65536
			jl		nchy
			sub		eax,360*65536
		 }
nchy:  asm {
			mov		nry,eax

			mov		eax,es:[bx].(STATE)z2
			imul	DWORD PTR elapsed
			idiv 	DWORD PTR tps
			add		eax,nrz
			cmp		eax,-360*65536
			jg		nccz
			sub		eax,-360*65536
		 }
nccz:  asm {
			cmp		eax,360*65536
			jl		nchz
			sub		eax,360*65536
		 }
nchz:  asm {
			mov		nrz,eax
		 }

			 if (rx != nrx || ry != nry || rz != nrz)
	{
	 seg_changed++;
	 abs_rot_segment(s->seg, nrx, nry, nrz, RYXZ);
	}

do_posstep:
	seg_getjointxyz(s->seg, &x, &y, &z);
	nx = x; ny = y; nz = z;
	if (s->x1 != 0)
	 {
		asm {
		les	bx,DWORD PTR s
		mov	eax,es:[bx].(STATE)x1
		imul	DWORD PTR elapsed
		idiv 	DWORD PTR tps
		mov	dl,es:[bx].(STATE)xo1
		mov	dh,al
		sar	eax,8
		add     dl,dh
		adc	nx,eax
		mov	es:[bx].(STATE)xo1,dl
	      }
	 }
	if (s->y1 != 0)
	 {
	  asm {
		les	bx,DWORD PTR s
		mov	eax,es:[bx].(STATE)y1
		imul	DWORD PTR elapsed
		idiv 	DWORD PTR tps
		mov	dl,es:[bx].(STATE)yo1
		mov	dh,al
		sar	eax,8
		add     dl,dh
		adc	ny,eax
		mov	es:[bx].(STATE)yo1,dl
	      }
	 }
	if (s->z1 != 0)
	 {
	  asm {
		les	bx,DWORD PTR s
		mov	eax,es:[bx].(STATE)z1
		imul	DWORD PTR elapsed
		idiv 	DWORD PTR tps
		mov	dl,es:[bx].(STATE)zo1
		mov	dh,al
		sar	eax,8
		add     dl,dh
		adc	nz,eax
		mov	es:[bx].(STATE)zo1,dl
	      }
	 }
	if (x != nx || y != ny || z != nz)
	 {
	  seg_changed++;
	  abs_move_segment(s->seg, nx, ny, nz);
	 }
	if (seg_changed) goto move_seg; else goto set;
       }

      case GRAVITY:
       {
	if (s->x3 != 0)
	 {
	  asm {
		les	bx,DWORD PTR s
		mov	eax,es:[bx].(STATE)x3
		imul	DWORD PTR elapsed
		idiv 	DWORD PTR tps
		mov	dl,al
		sar	eax,8
		add     dl,es:[bx].(STATE)xo2
		adc	es:[bx].(STATE)x1,eax
		mov	es:[bx].(STATE)xo2,dl
				}
	 }
	if (s->y3 != 0)
	 {
	  asm {
		mov	eax,es:[bx].(STATE)y3
		imul	DWORD PTR elapsed
		idiv 	DWORD PTR tps
		mov	dl,al
		sar	eax,8
		add     dl,es:[bx].(STATE)yo2
		adc	es:[bx].(STATE)y1,eax
		mov	es:[bx].(STATE)yo2,dl
	      }
	 }
	if (s->z3 != 0)
	 {
	  asm {
		mov	eax,es:[bx].(STATE)z3
		imul	DWORD PTR elapsed
		idiv 	DWORD PTR tps
		mov	dl,al
		sar	eax,8
		add     dl,es:[bx].(STATE)zo2
		adc	es:[bx].(STATE)z1,eax
		mov	es:[bx].(STATE)zo2,dl
	      }
	 }
	goto do_posstep;		/* now treat as normal motion */
       }

      case TIMER:
			 {
	if (s->y1 == DONTCARE) s->y1 = ctime+s->x1;
	if (s->y1 < ctime)
			goto reset;
	else goto set;
			 }

 reset:
	if (s->rst1i > 0) vars[s->rst1i] = s->rst1v;   /* do all setup stuff  */
        else if (s->rst1i < 0) endstate++;
	if (s->rst2i > 0) vars[s->rst2i] = s->rst2v;
	else if (s->rst2i < 0) endstate++;
	if (s->rst3i > 0) vars[s->rst3i] = s->rst3v;
	else if (s->rst3i < 0) endstate++;
	if (s->rstate)
	 {
	  cur_ani->state = s->rstate;
	  goto newstate;
	 }
	break;
 move_seg:
       {
	SEGMENT *r = get_root_segment(s->seg);
	seg_set_flags(r, seg_get_flags(r)|16);  /* mark seg root to be moved */
	s->ulist = NULL;                        /* put on move list */
	if (update_list == NULL)  update_list = update_end = s;
	else
	 {
		update_end->ulist = s;
		update_end = s;
	 }
       }
 set:
	if (s->set1i > 0) vars[s->set1i] = s->set1v;
	else if (s->set1i < 0) endstate++;
	if (s->set2i > 0) vars[s->set2i] = s->set2v;
	else if (s->set2i < 0) endstate++;
	if (s->set3i > 0) vars[s->set3i] = s->set3v;
	else if (s->set3i < 0) endstate++;
	if (s->sstate)
	 {
	  cur_ani->state = s->sstate;
		goto newstate;
	 }
	break;
	default: break;
       }
next_state:
      if (endstate) s = NULL;
      else s = s->next;
     }
newstate:
 cur_ani->lstate = old_state;
}



void do_animations()
{
 SEGMENT *s;
 unsigned flags;
 ANIMATION *ani = anilist;
 ctime = current_time();
 update_list = NULL;

 while(ani)
	{
	 if (ani->last_time < ctime)       /* time to animate? */
		{
		 elapsed = ctime+ani->period-ani->last_time;
		 if (elapsed > 300) elapsed = 300;
		 ani->last_time = ctime+ani->period;
		 cur_ani = ani;
		 exec_state(ani->state);
		}
	 ani = ani->next;
	}

 while(update_list)                        /* process all root segments */
	{
	 s = get_root_segment(update_list->seg); /* first check if done yet */
	 flags = seg_get_flags(s);
	 if (flags & 16)
		{
		 seg_set_flags(s, flags&(~16));        /* clear flag, update */
		 update_segment(s);
		 redraw |= 0x4000;
		}
	 update_list = update_list->ulist;
	}
}






