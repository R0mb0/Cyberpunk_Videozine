#include <stdio.h>
#include <dos.h>     /* delay() */
#include <conio.h>

static char *title[] = {
	"",
	"                                   REND386",
	"",
	"                                 Version 5.0",
	"",
	"           copyrighted (c) freeware, protected by the copyright laws",
	"                      of Canada and the United States",
	"",
	"                        Written and (c) 1992,1993 by",
	"                        Dave Stampe and Bernie Roehl",
	"",
	"             This program is free for non-commercial, non-profit,",
	"              non-promotional use.  Any other use requires prior",
	"                    written permission from the authors",
	"",
	"                  Note: a 386 or 486 PC and VGA card are",
	"                      required to run this software.",
	"",
	"                           Version date: 5/9/93",
	"",
	"Loading files...",
	"",
	NULL
	};

void title_screen()
{
	int i;
	textattr((BLUE<<4)+WHITE);
	directvideo = 0;
	clrscr();

	for (i = 0; title[i]; ++i) {
		cputs(title[i]);
		cputs("\r\n");
		}
	directvideo = 1;
}

void wait_for_title()
{
	int i;
	cputs("\n\r Ready- Press a key to start.\n\r");
	for (i = 0; i < 100; i++)
	{
		delay(100);
		if (kbhit()) break;
	}
	if (kbhit()) getch();
}
