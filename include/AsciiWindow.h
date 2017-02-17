#ifndef ASCIIWINDOW_H
#define ASCIIWINDOW_H

#include <Window.h>
#include <iostream>

/**
* Subclass of window that will respresent the window with the widgets contained within it
*/
class AsciiWindow : public Window
{
    public:
        /**
        *Constructor to build that AsciiWindow, calls the Window constructor
        *@param w The width of the window(defaulted to 100)
        *@param h The height of the window(defaulted to 100)
        */
        AsciiWindow(int w, int h):Window(w,h){}
        /**
        * Destructor for AsciiWindow
        */
        virtual ~AsciiWindow(){}
        /**
        *Draws the ascii window that will display the window with the widgets in it onto the screen
        */
        void draw();
};

#endif // ASCIIWINDOW_H
