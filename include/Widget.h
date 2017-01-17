#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include "Coordinate.h"

class Widget
{
public:
    /**
    * A widget that can be placed inside a window.
    * @param c The location of the widget.
    * @param w The width of the widget.
    * @param h The height of the widget.
    */
    Widget(Coordinate c, unsigned int w, unsigned int h):location{c}, width{w}, height{h} {}

    virtual ~Widget(){}

    /**
    * Determine if the widget is at location (x,y).
    * @param c Coordinate to examine.
    */
    bool locatedAt(Coordinate c);

    /**
    * Get the representation of the widget at \a c.
    * @throw widget_err if \a c is outside of widget boundry.
    */
    virtual char getAt(Coordinate c) = 0;

    /**
    * @return Location of the widget
    */
    Coordinate getLocation();

protected:

    void checkOutOfBounds(Coordinate c);

    Coordinate location;
    unsigned int width;
    unsigned int height;
};

#endif // WIDGET_H_INCLUDED
