#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <Widget.h>
#include <string>
#include "Exceptions.h"

class Textbox : public Widget
{
public:
    Textbox(Coordinate c, unsigned int w, unsigned int h, std::string s);
    virtual ~Textbox();
    char getAt(Coordinate c);

private:
    char** contents;
};

#endif // TEXTBOX_H
