#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <Widget.h>
#include <string>
#include "Exceptions.h"

class Textbox : public Widget
{
public:
    /**
    * Constructor of a textbox. If the text of the textbox is longer than the width,
    * the text is wrapped to the next row of the textbox.
    * @param c The coordinate location of the textbox in the window.
    * @param w The width of the textbox.
    * @param h The height of the textbox.
    * @param s The string contained in the textbox.
    * @throw widget_error Thrown if the text cannot fit in the textbox.
    */
    Textbox(Coordinate c, unsigned int w, unsigned int h, std::string s);

    virtual ~Textbox();

    /**
    * @param c The coordinate to get the letter of the text relative to the top left corner of the widget.
    * @return The letter of the string at \a c, or a space.
    * @throw widget_err if \a c is outside the bounds of the textbox.
    */
    char getAt(Coordinate c);

private:
    char** contents;
};

#endif // TEXTBOX_H
