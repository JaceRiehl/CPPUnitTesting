#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include "Coordinate.h"
/**
* Widget acts as an abstract class for different types of interfaces on the screen
*/
class Widget
{
public:
    /**
    *The constructor for the Widgets
    *@param c The Coordinate to be placed on the window
    *@param w the width of the widget
    *@param h the height of the widget
    */
    Widget(Coordinate c, unsigned int w, unsigned int h);
    /**
    *The destructor for Widget
    */
    virtual ~Widget();
    /**
    *Checks if the Coordinate is where the widget is located
    *@param c the Coordinate that is being checked against the location of the widget
    *@return true if \a c is where the widget is located, false if it isn't
    */
    bool locatedAt(Coordinate c);
    /**
    *Getter function for width
    *@return Width of the widget
    */
    unsigned int getWidth();
    /**
    *Getter function for height
    *@return Height of the widget
    */
    unsigned int getHeight();
    /**
    *Pure virtual function for getAt
    */
    virtual char getAt(Coordinate c) = 0;
    /**
    *Getter function for the location of the widget
    *@return Location of the widget
    */
    Coordinate getLocation();

protected:
    /**
    *Helper function to ensure that \a c's y or x is not outside the height of width respectively
    *@param c The Coordinate to be checked
    *@throw widget_error if \a c is outside of the height or width
    */
    void checkOutOfBounds(Coordinate c);
    /**
    *The location of the widget
    */
    Coordinate location;
    /**
    *The width of the widget
    */
    unsigned int width;
    /**
    *The height of the widget
    */
    unsigned int height;
};

#endif // WIDGET_H_INCLUDED
