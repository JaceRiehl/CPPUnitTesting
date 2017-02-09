#ifndef IMAGE_H
#define IMAGE_H

#include <Widget.h>
#include "Exceptions.h"


class Image : public Widget
{

public:
    Image(Coordinate c, unsigned int w, unsigned int h);
    virtual ~Image();
    char getAt(Coordinate c);
};

#endif // IMAGE_H
