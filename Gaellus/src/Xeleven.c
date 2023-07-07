#include "liblife.h"

int loop = 0;

unsigned long colorMapping[150] = {
    [0] = (23 << 16) | (120 << 8) | 2,
    [1] = (160 << 16) | (82 << 8) | 45,
    [2] = (139 << 16) | (69 << 8) | 19,
    [3] = (128 << 16) | (0 << 8) | 0,
    [4] = (9 << 16) | (121 << 8) | 45,
    [10] = (211 << 16) | (84 << 8) | 45,
    [11] = (218 << 16) | (247 << 8) | 45,
    [12] = (199 << 16) | (0 << 8) | 57,
    [101] = (192 << 16) | (57 << 8) | 43,
    [103] = (90 << 16) | (90 << 8) | 90,
};


static void drawPixel(Display* display, Drawable drawable, GC gc, int x, int y, unsigned long color) {
    XSetForeground(display, gc, color);
    for (int i = 0; i < PIX_SIZE; ++i) {
        for (int j = 0; j < PIX_SIZE; ++j) {
            XDrawPoint(display, drawable, gc, x * PIX_SIZE + i, y * PIX_SIZE + j);
        }
    }
}

void runXlibGraphics() {
    Display* display = XOpenDisplay(NULL);
    if (display == NULL) {
        printf("Error: Could not open display.\n");
        return;
    }

    int screen = DefaultScreen(display);
    Window window = XCreateSimpleWindow(display, RootWindow(display, screen), 0, 0,
                                        PIX_SIZE * WIDTH, PIX_SIZE * HEIGHT,
                                        0, 0, 0);
    XSelectInput(display, window, ExposureMask);
    XMapWindow(display, window);

    GC gc = XCreateGC(display, window, 0, NULL);

    XEvent event;
	while (1) 
	{
        	XNextEvent(display, &event);
		printf("debug\n");
		apply_patterns();
		usleep(500 * 1000);
		if (event.type == Expose) 
		{
			for (int y = 0; y < HEIGHT; ++y) 
			{
				for (int x = 0; x < WIDTH; ++x) 
				{
					int ID = g_world[INDEX(x, y)].ID;
					unsigned long color;
					if (ID >= 0 && (unsigned int)ID < sizeof(colorMapping) / sizeof(colorMapping[0])) 
					{
						color = colorMapping[ID];
					} 
					else 
					{
						color = WhitePixel(display, screen);
					}
					drawPixel(display, window, gc, x, y, color);
				}
				XExposeEvent exposeEvent;
				exposeEvent.type = Expose;
				exposeEvent.display = display;
				exposeEvent.window = window;
				exposeEvent.x = 0;
				exposeEvent.y = 0;
				exposeEvent.width = PIX_SIZE * WIDTH;
				exposeEvent.height = PIX_SIZE * HEIGHT;
				exposeEvent.count = 0;
				XSendEvent(display, window, False, ExposureMask, (XEvent*)&exposeEvent);
				XFlush(display);
			}
		}
	}
	XFreeGC(display, gc);
	XDestroyWindow(display, window);
	XCloseDisplay(display);
}
