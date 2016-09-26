#ifndef GRAPHICSDRIVER_H
#define GRAPHICSDRIVER_H

#include "WindowDriver.h"

//typedef void (*func_p)();

class GraphicsDriver
{
    public:
        GraphicsDriver();
        ~GraphicsDriver();

        WindowDriver *createWindow(int x, int y, int w, int h);
        void closeWindow(WindowDriver *window);

        void renderToWindow(WindowDriver *window, func_p func);
    protected:
    private:
};

#endif // GRAPHICSDRIVER_H
