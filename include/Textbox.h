#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <Widget.h>
#include <string>
#include "Exceptions.h"
/**
*Subclass of widget, creates a textbox (2d array) where each position holds a character
*/
class Textbox : public Widget
{
public:
    /**
    *Textbox Constructor
    *@param c The position of the textbox
    *@param w The width of the textbox
    *@param h The height of the textbox
    *@param s The string to be put into the textbox
    */
    Textbox(Coordinate c, unsigned int w, unsigned int h, std::string s);
    /**
    *The destructor for the textbox
    */
    virtual ~Textbox();
    /**
    *@param c The Coordinate that you want to check, 0,0 being at where the textbox was placed.
    *@exception widget_error if c is outside of the bounds of the textbox
    *@return The letter that is contained at that coordinate if there is a letter there
    */
    char getAt(Coordinate c);

private:
    /**
    *2d array of the contents of the textbox
    */
    char** contents;
};

#endif // TEXTBOX_H
