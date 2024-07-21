#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "window.h"

using namespace std;

Xwindow::Xwindow(int width, int height) : width{width}, height{height} {

  d = XOpenDisplay(NULL);
  if (d == NULL) {
    cerr << "Cannot open display" << endl;
    exit(1);
  }
  s = DefaultScreen(d);
  w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                          BlackPixel(d, s), WhitePixel(d, s));
  XSelectInput(d, w, ExposureMask | KeyPressMask);
  XMapRaised(d, w);

  Pixmap pix = XCreatePixmap(d,w,width,
        height,DefaultDepth(d,DefaultScreen(d)));
  gc = XCreateGC(d, pix, 0,(XGCValues *)0);

  XFlush(d);
  XFlush(d);

  XColor xcolour;
  Colormap cmap;
  char color_vals[11][10]={"white", "black", "red", "green", "magenta", "lightblue", "darkgreen", "yellow", "darkblue", "pink", "brown" };

  cmap=DefaultColormap(d,DefaultScreen(d));
  for(int i=0; i < 11; ++i) {
      XParseColor(d,cmap,color_vals[i],&xcolour);
      XAllocColor(d,cmap,&xcolour);
      colours[i]=xcolour.pixel;
  }

  XSetForeground(d,gc,colours[Black]);

  // Make window non-resizeable.
  XSizeHints hints;
  hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
  hints.height = hints.base_height = hints.min_height = hints.max_height = height;
  hints.width = hints.base_width = hints.min_width = hints.max_width = width;
  XSetNormalHints(d, w, &hints);

  XSynchronize(d,True);

  usleep(1000);
}

Xwindow::~Xwindow() {
  XFreeGC(d, gc);
  XCloseDisplay(d);
}

int Xwindow::getWidth() const { return width; }
int Xwindow::getHeight() const { return height; }

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
  XSetForeground(d, gc, colours[Black]);
  XFillRectangle(d, w, gc, x, y, width, height);
  XSetForeground(d, gc, colours[colour]);
  XFillRectangle(d, w, gc, x + 1, y + 1, width - 1, height - 1);
}

void Xwindow::drawString(int x, int y, string msg) {
  XDrawString(d, w, DefaultGC(d, s), x, y, msg.c_str(), msg.length());
}

void Xwindow::fillToilet(int x, int y) { // draws a toilet
  XSetForeground(d, gc, colours[White]);
  XFillRectangle(d, w, gc, x, y, 10, 5);
    XFillRectangle(d, w, gc, x + 2, y + 4, 6, 5);
  XSetForeground(d, gc, colours[Black]);
  XFillRectangle(d, w, gc, x + 4, y + 5, 2, 2);
}

void Xwindow::fillCafe(int x, int y) { // draws a toilet
  XSetForeground(d, gc, colours[White]);
  XFillRectangle(d, w, gc, x + 1, y, 7, 9);
  XFillRectangle(d, w, gc, x + 8, y + 2, 2, 2);
  XFillRectangle(d, w, gc, x + 8, y + 4, 2, 2);
  XFillRectangle(d, w, gc, x + 9, y + 3, 1, 1);
  XSetForeground(d, gc, colours[White]);
  XFillRectangle(d, w, gc, x + 2, y + 1, 5, 1);
}


void Xwindow::fillGoose(int x, int y) { // draws a toilet
  XSetForeground(d, gc, colours[Black]);
  XFillRectangle(d, w, gc, x + 1, y, 1,1);
  XFillRectangle(d, w, gc, x + 1, y + 2, 1,1);
  XFillRectangle(d, w, gc, x, y+1, 3,1);
  XFillRectangle(d, w, gc, x + 4, y+7, 1, 2);
    XFillRectangle(d, w, gc, x + 3, y+9, 3, 1);
  XSetForeground(d, gc, colours[White]);
  XFillRectangle(d, w, gc, x+2, y, 1,1);
  XSetForeground(d, gc, colours[Brown]);
  XFillRectangle(d, w, gc, x + 2, y + 3, 2,1);
  XFillRectangle(d, w, gc, x + 2, y + 4, 6,1);
  XFillRectangle(d, w, gc, x+2, y + 5, 7,1);
  XFillRectangle(d, w, gc, x+3, y + 5, 5, 1);
}

void Xwindow::fillBus(int x, int y) { // draws a toilet
  XSetForeground(d, gc, colours[Black]);
  XFillRectangle(d, w, gc, x+1, y+8, 2,2);
  XFillRectangle(d, w, gc, x+7, y+8, 2,2);
  XSetForeground(d, gc, colours[Darkblue]);
  XFillRectangle(d, w, gc, x, y + 2, 10,1);
  XFillRectangle(d, w, gc, x, y + 6, 10, 1);
  XFillRectangle(d, w, gc, x+2, y + 4, 1,2);
  XFillRectangle(d, w, gc, x+6, y + 4, 1,2);
  XFillRectangle(d, w, gc, x+8, y + 4, 1,2);
  XSetForeground(d, gc, colours[Lightblue]);
  XFillRectangle(d, w, gc, x, y + 4, 2,2);
  XFillRectangle(d, w, gc, x+3, y + 4, 2,2);
  XFillRectangle(d, w, gc, x+7, y + 4, 2,2);
  XFillRectangle(d, w, gc, x+9, y + 4, 1,2);
}

void Xwindow::fillDount(int x, int y) { // draws a toilet
  XSetForeground(d, gc, colours[Pink]);
  XFillRectangle(d, w, gc, x + 2, y + 1, 7, 1);
  XFillRectangle(d, w, gc, x + 1, y + 2, 3, 1);
  XFillRectangle(d, w, gc, x, y + 3, 3, 2);
  XFillRectangle(d, w, gc, x + 6, y + 3, 4, 2);
  XFillRectangle(d, w, gc, x + 1, y + 4, 8, 1);
    XFillRectangle(d, w, gc, x + 2, y + 5, 6, 1);

  XSetForeground(d, gc, colours[Brown]);
  XFillRectangle(d, w, gc, x, y + 4, 1, 1);
  XFillRectangle(d, w, gc, x + 8, y + 4, 1, 1);
  XFillRectangle(d, w, gc, x, y + 5, 2, 1);
  XFillRectangle(d, w, gc, x + 7, y + 5, 2, 1);
  XFillRectangle(d, w, gc, x + 1, y + 6, 8, 1);
  XFillRectangle(d, w, gc, x + 2, y + 7, 6, 1);
}

void Xwindow::fillProfessor(int x, int y) { // draws a toilet
  XSetForeground(d, gc, colours[White]);
  XFillRectangle(d, w, gc, x + 2, y, 6,10);
  XSetForeground(d, gc, colours[Pink]);
  XFillRectangle(d, w, gc, x + 2, y + 2, 6, 3);
  XFillRectangle(d, w, gc, x + 3, y + 3, 4, 1);
  XFillRectangle(d, w, gc, x+2, y + 1, 1, 1);
  XSetForeground(d, gc, colours[Black]);
  XFillRectangle(d, w, gc, x + 3, y + 3, 1,1);
  XFillRectangle(d, w, gc, x + 6, y + 3, 1,1);
  XSetForeground(d, gc, colours[Red]);
  XFillRectangle(d, w, gc, x + 4, y + 7, 2,1);
}

void Xwindow::fillStudent(int x, int y) { // draws a toilet
  XSetForeground(d, gc, colours[Pink]);
  XFillRectangle(d, w, gc, x + 2, y + 1, 8, 9);
  XSetForeground(d, gc, colours[Brown]);
  XFillRectangle(d, w, gc, x + 1, y, 8, 2);
    XFillRectangle(d, w, gc, x + 1, y + 2, 1, 3);
  XFillRectangle(d, w, gc, x + 9, y + 2, 1, 3);
  XSetForeground(d, gc, colours[Black]);
  XFillRectangle(d, w, gc, x + 3, y + 3, 1,1);
  XFillRectangle(d, w, gc, x + 6, y + 3, 1,1);
}

void  Xwindow::fillMoney(int x, int y) {
  XSetForeground(d, gc, colours[Darkgreen]);
  XFillRectangle(d, w, gc, x, y + 2, 10, 6);
  XSetForeground(d, gc, colours[Black]);
  XFillRectangle(d, w, gc, x + 2, y + 3, 3,1);
  XFillRectangle(d, w, gc, x + 5, y + 4, 2,2);
  XFillRectangle(d, w, gc, x + 7, y + 6, 3,1);

}
void  Xwindow::fillLaptop(int x, int y) {
  XSetForeground(d, gc, colours[Black]);
  XFillRectangle(d, w, gc,x,y + 1,10,8);
    XSetForeground(d, gc, colours[Lightblue]);
  XFillRectangle(d, w, gc, x + 1, y + 2, 8, 6);
  XSetForeground(d, gc, colours[Darkgreen]);
  XFillRectangle(d, w, gc, x + 3, y + 6, 2,2);
  XSetForeground(d, gc, colours[Darkblue]);
  XFillRectangle(d, w, gc, x + 6, y + 3, 2,2);
  XSetForeground(d, gc, colours[Red]);
  XFillRectangle(d, w, gc, x+3, y + 3, 2,2);
    XSetForeground(d, gc, colours[Yellow]);
  XFillRectangle(d, w, gc, x+6, y + 6, 2,2);
}
void  Xwindow::fillTie(int x, int y) {
  XSetForeground(d, gc, colours[Pink]);
  XFillRectangle(d, w, gc, x+4, y, 2,10);
  XFillRectangle(d, w, gc, x+3, y + 1, 1,1);
  XFillRectangle(d, w, gc, x+6, y + 1, 1,1);
  XFillRectangle(d, w, gc, x + 3, y + 5, 4, 4);
  XFillRectangle(d, w, gc, x+2, y + 6, 1,2);
  XFillRectangle(d, w, gc, x+7, y + 6, 1,2);
}
