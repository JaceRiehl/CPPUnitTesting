#include"Widget.h"
#include"Coordinate.h"
#include "Exceptions.h"

    Widget::Widget(Coordinate c, unsigned int w, unsigned int h) : location(c), width(w), height(h){}
    Widget::~Widget()
    {

    }

    bool Widget::locatedAt(Coordinate c)
    {
        if(c == location)
            return true;
        else
            return false;
    }

    unsigned int Widget::getWidth()
    {
        return width;
    }

    unsigned int Widget::getHeight()
    {
        return height;
    }

    Coordinate Widget::getLocation()
    {
        return location;
    }

    void Widget::checkOutOfBounds(Coordinate c)
    {
        string s = "Image was cutoff";
        throw widget_error(s.c_str());
    }
