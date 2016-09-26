#include "GraphicsDriver.h"

GraphicsDriver::GraphicsDriver()
{

}

WindowDriver *GraphicsDriver::createWindow(int x, int y, int w, int h)
{
    WindowDriver *window = new WindowDriver(x, y, w, h);
    window->createWindow();

    return window;
}


void GraphicsDriver::renderToWindow(WindowDriver *window, func_p func)
{
    window->renderToWindow(func);
}

void GraphicsDriver::closeWindow(WindowDriver *d)
{
    delete d;
    d = nullptr;
}

GraphicsDriver::~GraphicsDriver()
{

}
