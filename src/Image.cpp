  #include"Image.h"
  #include"Exceptions.h"

    Image::Image(Coordinate c, unsigned int w, unsigned int h): Widget(c, w, h){}

     Image::~Image()
    {

    }

    char Image::getAt(Coordinate c)
    {
        if(c == this->location)
            return 'I';
       else
            checkOutOfBounds(c);

    }
