#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <Window.h>

/**
* This class provides a concrete implemenation for Window.
*/
class BaseWindow : public Window
{
    public:
        BaseWindow(int w=10, int h=10);

        virtual ~BaseWindow();

        /**
        * Method does nothing.
        */
        void draw(){};
};

#endif // BASEWINDOW_H
