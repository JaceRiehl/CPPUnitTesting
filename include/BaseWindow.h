#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <Window.h>

/**
* This class provides a concrete implemenation for Window.
*/
class BaseWindow : public Window
{
    public:
        /**
        * The constructor of the BaseWindow
        *@param w The width of the BaseWindow(default 10)
        *@param h the Height of the BaseWindow(default 10)
        */
        BaseWindow(int w=10, int h=10);
        /**
        * Destructor for BaseWindow
        */
        virtual ~BaseWindow();
        /**
        * This function does nothing
        */
        void draw();
};

#endif // BASEWINDOW_H
