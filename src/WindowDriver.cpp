#include "WindowDriver.h"

WindowDriver::WindowDriver(int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

void WindowDriver::renderToWindow(func_p func)
{
    glutDisplayFunc(func);
}

void WindowDriver::createWindow()
{
    glutInitWindowSize(w, h);
    glutInitWindowPosition(x, y);

    id = glutCreateWindow("OpenGL");
}

int WindowDriver::getWindowID()
{
    return id;
}

WindowDriver::~WindowDriver()
{
    glutDestroyWindow(id);
}
