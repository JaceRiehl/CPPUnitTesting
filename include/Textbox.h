#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <Widget.h>
#include <string>
#include "Exceptions.h"

class Textbox : public Widget
{
public:
    /**
    * Constructor of a textbox.
    * @throw widget_error Thrown if the text cannot fit in the textbox.
    */
    Textbox(Coordinate c, unsigned int w, unsigned int h, std::string s);
    virtual ~Textbox();

    /**
    * @return The letter of the string at \a c, or a space.
    * @throw widget_err if \a c is outside the bounds of the textbox.
    */
    char getAt(Coordinate c);

private:
    char** contents;
};

#endif // TEXTBOX_H
