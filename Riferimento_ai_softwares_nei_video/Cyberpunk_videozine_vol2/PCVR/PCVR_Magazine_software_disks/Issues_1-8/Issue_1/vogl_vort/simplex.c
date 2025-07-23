/*
 * Simple X program.....
 */
#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

main(argc, argv)
	int	argc;
	char	*argv[];
{
	XFontStruct     *font_id;
	GC		theGC;
        XGCValues       xgcvals;
	KeySym	key;
	XEvent	event;
	Window	window;
	Display	*display;

	XSizeHints sizehints;
	XWMHints   wmhints;
	XGCValues  values;

	char	 temp;
	int	 num, thescreen, cwidth, cheight;
	unsigned long mask, foreground, background;


	if ((display = XOpenDisplay((char *)NULL)) == NULL) {
		fprintf(stderr,"Can't open display %s\n", XDisplayName((char *)NULL));
		exit(1);
	}

	thescreen  = DefaultScreen(display);
	foreground = WhitePixel(display, thescreen);
	background = BlackPixel(display, thescreen);

	sizehints.x      = 200;
	sizehints.y      = 200;
	sizehints.width  = 512;
	sizehints.height = 400;
	sizehints.flags  = PPosition | PSize;


	window = XCreateSimpleWindow(display, 
			DefaultRootWindow(display),
			sizehints.x, sizehints.y,
			sizehints.width, sizehints.height,
			2, 
			foreground, background
		);


	mask      	  = GCForeground | GCBackground;;
	values.foreground = foreground;
	values.background = background;

	theGC = XCreateGC(display, window, mask, &values);

	wmhints.input = True;
	wmhints.flags = InputHint;
	XSetWMHints(display, window, &wmhints);

	mask = KeyPressMask  | ExposureMask ;
	XSelectInput(display, window, mask);

	XSetStandardProperties(display,
			window, 
			"Hello Demo", 
			"Hello Icon",
			None, 
			" ", 0,
			&sizehints
	);

	if ((font_id = XLoadQueryFont(display, "fixed")) == (XFontStruct *)NULL) {
		fprintf(stderr, "Can't open fixed font\n");
		exit(1);
	}

	cheight = font_id->max_bounds.ascent + font_id->max_bounds.descent;
	cwidth = font_id->max_bounds.width;

        xgcvals.font = XLoadFont(display, "fixed");

        XChangeGC(display, theGC, GCFont, &xgcvals);

	XMapRaised(display, window);

        XFlush(display);

	while (True) {
		XWindowEvent(display,window, mask,  &event);

		switch (event.type) {
		case Expose:
			if (event.xexpose.count == 0)
				XClearWindow(display, window);

				XDrawString(display, 
					window, 
					theGC, 
					sizehints.width / 2 - 12 * cwidth / 2,
					sizehints.height / 2 - cheight / 2,
					"Hello, world", 
					12
				);
			break;

		case MappingNotify:
			XRefreshKeyboardMapping(&event);
			break;

		case KeyPress:
			printf("KeyPress\n");
			num = XLookupString(&event, &temp, 1, &key, 0);
			if (num == 1 && (temp == 'q' || temp == 'Q')) {
				XFreeGC(display, theGC);
				XDestroyWindow(display, window);
				XCloseDisplay(display);
				exit(0);
			}
			break;
		}
		XFlush(display);
	}
}
