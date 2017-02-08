#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include "Coordinate.h"

class Widget
{
public:
    Widget(Coordinate c, unsigned int w, unsigned int h);
    virtual ~Widget();
    bool locatedAt(Coordinate c);
    unsigned int getWidth();
    unsigned int getHeight();
    virtual char getAt(Coordinate c) = 0;
    Coordinate getLocation();

protected:

    void checkOutOfBounds(Coordinate c);

    Coordinate location;
    unsigned int width;
    unsigned int height;
};

#endif // WIDGET_H_INCLUDED
