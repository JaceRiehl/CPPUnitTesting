#include "Window.h"
#include "AsciiWindow.h"
#include "Exceptions.h"
#include <string>
#include <vector>


    Window(int w=100, int h=100) : height(h), width(w){}

    virtual ~Window()
    {

    }

    Coordinate getLocation()
    {

    }

    void addWidget(Widget* w)
    {
        contents.push_back(w);
    }

    unsigned int getWidth()
    {
        return width;
    }

    unsigned int getHeight()
    {
        return height;
    }

    std::vector<Widget*> getWidgets()
    {
        return contents;
    }

    void removeWidget(Widget* w)
    {
        for(int i = 0; i < std::vector contents.size; i++)
        {
            if(contents[i] == *w)
                contents.erase(i);
        }
    }

    void resize(unsigned int w, unsigned int h)
    {

    }

    void setHeight(int h)
    {
         height = h;
    }
    void setWidth(int w)
    {
       width = w;
    }
