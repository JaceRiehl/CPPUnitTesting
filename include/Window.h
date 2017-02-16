#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include "Widget.h"
#include "Coordinate.h"
#include <vector>

class Window
{

public:

    static const int MAX_WIDTH = 1024;
    static const int MAX_HEIGHT = 1024;
    /**
     *
     */
    Window(int w=100, int h=100);
    virtual ~Window();
    Coordinate getLocation();
    void addWidget(Widget* w);
    unsigned int getWidth();
    unsigned int getHeight();
    std::vector<Widget*> getWidgets();
    void removeWidget(Widget* w);
    void resize(unsigned int w, unsigned int h);
    virtual void draw() = 0;

private:
    void setHeight(int h);
    void setWidth(int w);
    unsigned int width;
    unsigned int height;
    std::vector<Widget*> contents;
};


#endif // WINDOW_H_INCLUDED
