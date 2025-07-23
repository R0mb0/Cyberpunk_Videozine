/*
 LOGITECH 6D head tracker: overhead, no recenter
 by Dave Stampe, April 1993
 (c) 1993 Bernie Roehl, Dave Stampe
*/

#include <stdlib.h>
#include <dos.h>
#include <bios.h>
#include <stdio.h>
#include <conio.h>
#include <signal.h>
#include <mem.h>

#include "rend386.h"
#include "userint.h"
#include "pointer.h"

/******************* INTERRUPT CONSTANTS  ****************/


#define PIC_CMD     0x20     /* constants for PIC EOI command */
#define NONSPEC_EOI 0x20
#define PIC_MASK    0x21

extern int logitech_port;             /* 1: default of com2, 0 for com1 */

static int serirqnum = 3;
static int serirqvect = 11;
static int serirqmask = 0x08;
static unsigned int address = 0x2F8;

#define DIVILOW (address + 0)    /* latch bit 1 */
#define DIVIHIGH (address + 1)   /* latch bit 1 */
#define INTENABLE (address + 1)  /* latch bit 0 */
#define LINECTRL (address + 3)
#define MODEMCTRL (address + 4)
#define LINESTAT (address + 5)
#define MODEMSTAT (address + 6)

#define BAUD_19200 6             /* baud rate constants */
#define BAUD_1200  96

static void interrupt (*old_int)();     /* old timer ISR vector */
static void interrupt serirq_handler();

static int schar = 0;
static int errstat = 0;

#define PACKETSIZE 16
static unsigned char buff1[20], buff2[20];
static unsigned char *rcvbuff = buff1, *currbuff = buff2;
static int indx = -1;
static int received = 0;  /* positive if packet received */


/***************** SERIAL SUPPORT *****************/


static void set_baud(int divisor)
{
 int save = inportb(LINECTRL);
 outportb(LINECTRL, 0x83);     /* enable latch */
 outportb(DIVILOW, divisor);   /* baud rate: 6 = 19200, 96=1200 */
 outportb(DIVIHIGH, 0);
 outportb(LINECTRL, 3|save);        /* 8 bits, no parity, one stop bit */
}


static void pulse_rts()
{
 outportb(MODEMCTRL,0x00);     /* clear RTS */
 delay(500);
 outportb(MODEMCTRL,0x02);     /* set RTS   */
 delay(500);
}


static void outch(unsigned char c)
{
 int i;

/* printf("%c\n", c); */

 while ((inportb(LINESTAT) & 0x40) == 0)
 if (bioskey(1)) { getch(); return; }
 outportb(address, c);
 for (i = 0; i < 100; i++);		/* settling time for fast PCs */
}


static unsigned char inch(void)
{
 while ((inportb(LINESTAT) & 0x01) == 0)
 if (bioskey(1)) { getch(); return 0; }
 return inportb(address);
}

static void flush_port()
{
 while ((inportb(LINESTAT) & 0x01))
     inportb(address);
}


/***************** 6D MOUSE SUPPORT *****************/

static void reset_unit()
{
 outch('*');  outch('D');   /* reset */
 delay(200);
 outch('*');  outch('R');   /* reset */
 delay(1000);
 flush_port();
}


static int diagnostics()
{
 char c;

return 0;
 outch('*');  outch(0x05);                  /* diagnostics */
 if ((c = inch()) != 0xBF)
  {
   printf("Diagnostics failed -- first byte = 0x%02.2X\n", c);
   return 2;
  }
 if ((c = inch()) != 0x3F)
  {
   printf("Diagnostics failed -- second byte = 0x%02.2X\n", c);
   return 3;
  }
 return 0;
}

			/* 0: enter hi-res mouse mode */
static void head_mode(int hm)  /* 1: enter head track mode   */
{
 received = -1;        /* force discard of packets */
 indx = -1;

 outch('*');	       /* demand mode */
 outch('D');
 delay(150);

 outch('*');
 if (hm)
	outch('H');
 else
	outch('h');
 delay(150);

 outch('*');
 outch('I');           /* incremental reporting */
 delay(150);
}


static int init_6D()
{
 set_baud(BAUD_19200);
 pulse_rts();

 inportb(address);
 if ((inportb(MODEMSTAT) & 0x10) == 0)
  {
   printf("No CTS\n");
   exit(1);
  }

 reset_unit();
 if (diagnostics()) exit(1);

 outch('*');
 outch('I');   /* incremental reporting */
 delay(300);
 return 1;
}



/***************** 6D MOUSE READING *****************/


static void poll_packet(char *buf)
{
 unsigned char c;
 char *b = buf;
 int i;

 for (i = 0; i < PACKETSIZE; i++)
  {
wstart:
   while ((inportb(LINESTAT) & 0x01) == 0)  if (bioskey(1)) { getch(); return; }
			/* data received */
   c = inportb(address);
   if (i == 0 && (c & 0x80) == 0) goto wstart;
   *b++ = c;
  }
}


static void dump_packet(char *buf)
{
 unsigned char buttons;
 long x, y, z;
 int rx, ry, rz;

 if (buf[0] & 0x40) printf("(FRI)");
 if (buf[0] & 0x20) printf("(OUT)");

 buttons = buf[0] & 0x0F;
 printf("%02.2X", buttons);

	/* sign extend if needed */
 x = (buf[1] & 0x40) ? 0xFFE00000 : 0;
 x |= (long)(buf[1] & 0x7f) << 14;
 x |= (long)(buf[2] & 0x7f) << 7;
 x |= (buf[3] & 0x7f);

 y = (buf[4] & 0x40) ? 0xFFE00000 : 0;
 y |= (long)(buf[4] & 0x7f) << 14;
 y |= (long)(buf[5] & 0x7f) << 7;
 y |= (buf[6] & 0x7f);

 z = (buf[7] & 0x40) ? 0xFFE00000 : 0;
 z |= (long)(buf[7] & 0x7f) << 14;
 z |= (long)(buf[8] & 0x7f) << 7;
 z |= (buf[9] & 0x7f);

 printf("%f,%f,%f", ((float) x) / 1000.0, ((float) y) / 1000.0, ((float) z) / 1000.0);

 rx  = (buf[10] & 0x7f) << 7;
 rx += (buf[11] & 0x7f);

 ry  = (buf[12] & 0x7f) << 7;
 ry += (buf[13] & 0x7f);

 rz  = (buf[14] & 0x7f) << 7;
 rz += (buf[15] & 0x7f);

 printf("\t%f,%f,%f\n", ((float) rx) / 40.0, ((float) ry) / 40.0, ((float) rz) / 40.0);
}


/***************** INTERRUPT ROUTINES *****************/



static void reset_serirq()
{                                /* RESET PC TO NORMAL */
 disable();

 outportb(PIC_MASK,(inportb(PIC_MASK)|serirqmask)); /* mask serial IRQ */

 outportb(INTENABLE,0);
 outportb(MODEMCTRL,0);               /* disable data available int */
 inportb(address);

 setvect(serirqvect, old_int);        /* reset ISR vector */
 outportb(PIC_CMD, NONSPEC_EOI);      /* reset any pending interrupts */

 enable();
}


static void init_serirq()                /* SET UP IRQ3 (COM2) */
{

 old_int = getvect(serirqvect);   	/* save old ISR vector */
 set_baud(BAUD_19200);

 disable();
 outportb(MODEMCTRL,0x0b);               /* enable data available int */
 outportb(INTENABLE,0x05);

 setvect(serirqvect, serirq_handler);   	/* new ISR handler */
 outportb(PIC_MASK,(inportb(PIC_MASK)&(!serirqmask)));   /* unmask serial IRQ */
 outportb(PIC_CMD, NONSPEC_EOI);	/* clear pending interrupts */

 enable();
}



/****************** READ POINTS FROM TRACKER ****************/

static void interrupt serirq_handler()      /* COM2 input ISR */
{
 unsigned char c;

 disable();
++received;  /* DEBUG ONLY */
 if (inportb(LINESTAT) & 0x01) /* data received */
  {
   c = inportb(address);
   if (c & 0x80) indx = 0;
   if (indx >= 0) rcvbuff[indx++] = c;
   if (indx >= 16)
    {
     unsigned char *t;         /* buffer ready! */

     t = currbuff;
     currbuff = rcvbuff;
     rcvbuff = t;
     indx = -1;
     received++;
    }
  }
 else
  {
   if ((inportb(LINESTAT) & 0x0E)!=0)    /* correct overrun errors */
    {
     inportb(address);
     inportb(address);
     inportb(address);
    }
  }
 outportb(INTENABLE, 5);
 outportb(PIC_CMD, NONSPEC_EOI);	/* reset int at PIC */
 enable();
}


static int copy_int_packet(char *dest)
{
 disable();
 if (received < 1)
  {
   enable();
   return 0;
  }
 received = 0;
 memcpy(dest, rcvbuff, PACKETSIZE);
 enable();
 return 1;
}


static long rx_6d=0, ry_6d=0, rz_6d=0;
static long x_6d=0, y_6d=0, z_6d=0;
static int buttons_6d=0;
static int status_6d= -1;

/* returns status_6d:    */
/* -1 : no data read yet */
/* 40h: out of range     */
/* 20h: fringe of range  */
/* 1  : no new data      */
/* 0  : new data         */

static int get_6D_data()
{
 int but, i;
 char buf[PACKETSIZE];

 i = copy_int_packet(buf);
 if (i == 0)
  {
   status_6d |= 1;
   return status_6d;
  }

 status_6d  = buf[0] & 0x60;
 buttons_6d = buf[0] & 0x0F;

	/* sign extend if needed */
 x_6d = (buf[1] & 0x40) ? 0xFFE00000 : 0;
 x_6d |= (long)(buf[1] & 0x7f) << 14;
 x_6d |= (long)(buf[2] & 0x7f) << 7;
 x_6d |= (buf[3] & 0x7f);

 y_6d = (buf[4] & 0x40) ? 0xFFE00000 : 0;
 y_6d |= (long)(buf[4] & 0x7f) << 14;
 y_6d |= (long)(buf[5] & 0x7f) << 7;
 y_6d |= (buf[6] & 0x7f);

 z_6d = (buf[7] & 0x40) ? 0xFFE00000 : 0;
 z_6d |= (long)(buf[7] & 0x7f) << 14;
 z_6d |= (long)(buf[8] & 0x7f) << 7;
 z_6d |= (buf[9] & 0x7f);

 rx_6d  = (buf[10] & 0x7f) << 7;
 rx_6d += (buf[11] & 0x7f);

 ry_6d  = (buf[12] & 0x7f) << 7;
 ry_6d += (buf[13] & 0x7f);

 rz_6d  = (buf[14] & 0x7f) << 7;
 rz_6d += (buf[15] & 0x7f);

 return status_6d;
}



/*****************/

static int tbuf[20];      /* working copy buffer */

static logitech_init()
{
 if (logitech_port)
  {
   serirqnum = 3;           /* COM2 select */
   serirqvect = 11;
   serirqmask = 0x08;
   address = 0x2f8;
  }
 else
  {
   serirqnum = 4;           /* COM1 select */
   serirqvect = 12;
   serirqmask = 0x10;
   address = 0x3f8;
  }

 init_6D();
 head_mode(1);

 init_serirq();   /* assume pointer shutdown will handle */
/* ldtest(0); */
}


static p_dump(int i)
{
 char c[100];

 sprintf(c,"%d: %d %.0f,%.0f,%.0f %.0f,%.0f,%.0f", i, status_6d,
 ((float) x_6d) / 40.0, ((float) y_6d) / 40.0, ((float) z_6d) / 40.0,
 ((float) rx_6d) / 40.0, ((float) ry_6d) / 40.0, ((float) rz_6d) / 40.0);

 popmsg(c);
}


static ldtest(int i)              /* debug: interrupt report */
{
 int t;
 while (!kbhit())
  {
   if (!get_6D_data(tbuf)) p_dump(i);
  }
 getch();
}

static ddtest(int i)
{
 poll_packet(tbuf);
 p_dump(i);
}

static idtest(int i)
{
 get_6D_data(tbuf);
 p_dump(i);
}



/***************** LOGITECH POINTER DRIVER *************/

static pconfig logi_pconfig = {
	1640L, 1640L, 1640L,	        /* position res: mm/tick in <16.16>  */
	1048575L, 1048575L, 1048575L,   /* xyz ranges:                */
	-1048575L, -1048575L, -1048575L,
	1640L, 1640L, 1640L,		/* rotation res: <ticks per */
	7200L, 7200L, 7200L,
	-7200L, -7200L, -7200L,         /* rotation range      */
	320, 200, /* mouse emulation limits (writable) */
	P_HASX | P_HASY | P_HASZ | P_HASRX | P_HASRY | P_HASRZ | P_HASB1 | P_HASB2 | P_HASB3,    /* databits  */
	P_POINTER, 0, 0,                 /* modes, nullkey, flexnum           */
	40, 50, 25,                     /* delay, idelay, reads/sec          */
	P_IS6D | P_IS6H | P_IS3D,       /* uses  */
	"Logitech Red Baron Head Tracker"
};


pconfig *logitech_driver(int op, POINTER *p, int mode)
{
	int type = FP_OFF(p); 		/* way to get integer arg. */
	int ft, fi, fm, fp;

	switch(op)
	{
	case DRIVER_CMD:
	case DRIVER_RESET:
		break;

	case DRIVER_INIT:
		logitech_init();
		break;

	case DRIVER_READ:		/* head pointer (6DP) read */
		if (mode == P_POINTER)
		 {
		  if (get_6D_data(tbuf))
		   {
	       /*	    popmsg("none"); */
		    return NULL;
		   }
	      /*	  p_dump(9); */
		  p->x = -x_6d;
		  p->z = y_6d;
		  p->y = -z_6d;
		  p->rx = rx_6d<<16;
		  p->rz = -ry_6d<<16;
		  p->ry = rz_6d<<16;
		  p->buttons = buttons_6d;
		  p->keys = 0;
		  p->gesture = -1 ;
		 }
		break;

	case DRIVER_CHECK:
		break;
	case DRIVER_QUIT:
		reset_serirq();
		break;
	}
	return &logi_pconfig;
}

