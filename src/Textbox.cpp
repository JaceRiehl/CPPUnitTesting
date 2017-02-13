#include "Textbox.h"
#include "Exceptions.h"

  Textbox::Textbox(Coordinate c, unsigned int w, unsigned int h, std::string s) : Widget(c, w, h)
  {

    if((width || height) <= 0)
    {
        if (s.length() != 0)
        {
            throw widget_error("Text doesn't fit in textbox!");
        }
    }
    else if(s.length() > width * height && width != 0 && height != 0)
    {
        throw widget_error("Text doesn't fit in textbox");
    }

    int k = 0;
    contents = new char*[height];
    while(k < (width * height))
    {
        for (int i = 0; i < height; i++)
        {
        contents[i] = new char[width];
            for (int j = 0; j < width; j++)
            {
                if(k > s.length())
                {
                    contents[i][j] = ' ';
                    k++;
                }
                else
                {
                    contents[i][j] = s[k];
                    k++;
                }
            }
        }
    }

   }

    Textbox::~Textbox()
    {

    for(int i = 0; i < height; i++)
      delete [] contents[i];
    delete [] contents;
    contents = nullptr;
    }

    char Textbox::getAt(Coordinate c)
    {
            checkOutOfBounds(c);
            return contents[c.y][c.x];

    }
