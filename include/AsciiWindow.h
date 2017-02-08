#ifndef ASCIIWINDOW_H
#define ASCIIWINDOW_H

#include <Window.h>
#include <iostream>


class AsciiWindow : public Window
{
    public:
        AsciiWindow(int w, int h):Window(w,h){}
        virtual ~AsciiWindow(){}
        void draw();
};

#endif // ASCIIWINDOW_H
