#ifndef IMAGE_H
#define IMAGE_H

#include <Widget.h>


class Image : public Widget
{

public:
    /**
    * Constructor of a image.
    * @param c The coordinate location of the image in the window.
    * @param w The width of the image.
    * @param h The height of the image.
    */
    Image(Coordinate c, unsigned int w, unsigned int h);

    virtual ~Image();

    /**
    * @param c The coordinate to get the letter of the text relative to the top left corner of the widget.
    * @return Returns 'I' as the representation of an image.
    * @throw widget_err if \a c is outside the bounds of the image, where \a c is relative to the image not the containing window.
    */
    char getAt(Coordinate c);
};

#endif // IMAGE_H
