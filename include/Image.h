#ifndef IMAGE_H
#define IMAGE_H

#include <Widget.h>


class Image : public Widget
{

public:
    /**
    * Constructor of a image.
    */
    Image(Coordinate c, unsigned int w, unsigned int h):Widget{c,w,h} {}
    virtual ~Image();

    /**
    * @return Returns 'I' as the representation of an image.
    * @throw widget_err if \a c is outside the bounds of the image.
    */
    char getAt(Coordinate c);
};

#endif // IMAGE_H
