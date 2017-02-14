#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <Window.h>

/**
* This class provides a concrete implemenation for Window.
*/
class BaseWindow : public Window
{
    public:
        BaseWindow(int w=100, int h=100);

        virtual ~BaseWindow();

        void draw();
};

#endif // BASEWINDOW_H
