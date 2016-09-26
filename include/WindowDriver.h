#ifndef WINDOWDRIVER_H
#define WINDOWDRIVER_H

#include <GL/glut.h>

#include "Globals.h"

class WindowDriver
{
    public:
        WindowDriver(int x, int y, int w, int h);
        ~WindowDriver();

        void createWindow();
        void renderToWindow(func_p func);

        int getWindowID();
    protected:
    private:
        int x, y;
        int w, h;

        int id;
};

#endif // WINDOWDRIVER_H
