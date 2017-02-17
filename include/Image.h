#ifndef IMAGE_H
#define IMAGE_H

#include <Widget.h>
#include "Exceptions.h"

/**
* Subclass of Widget that is used to represent an image
*/
class Image : public Widget
{

public:
    /**
    *Image contructor
    *@param c The Coordinate that the image is placed at
    *@param w The width of the image
    *@param h The height of the image
    */
    Image(Coordinate c, unsigned int w, unsigned int h);
    /**
    *Destructor for the image
    */
    virtual ~Image();
    /**
    *@param c The Coordinate that you want to check, 0,0 being at where the image was placed.
    *@exception widget_error if c is outside of the bounds of the image
    *@return 'I' when there is an image contained at this coordinate
    */
    char getAt(Coordinate c);
};

#endif // IMAGE_H
