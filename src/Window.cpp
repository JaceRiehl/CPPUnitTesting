#include "Window.h"
#include "AsciiWindow.h"
#include "Exceptions.h"
#include "Widget.h"
#include "Coordinate.h"

#include <string>
#include <vector>


    Window::Window(int w, int h)
    {
        if(w > MAX_WIDTH || h > MAX_HEIGHT)
            throw illegal_size_error("Window exceeds maximum size");
        else
        {
            width = w;
            height = h;
        }
    }

    Window::~Window()
    {
        delete[] contents;
    }


    void Window::addWidget(Widget* w)
    {
    //add operation failed error

     for(int i = 0; i < contents.size(); i++)
        {
            if(w->getLocation().x == contents[i]->getLocation().x && w->getLocation().y == contents[i]->getLocation().y)
             throw widget_operation_failed_error("Widget Overlaps");
        }
         contents.push_back(w);
    }

    unsigned int Window::getWidth()
    {
        return width;
    }

    unsigned int Window::getHeight()
    {
        return height;
    }

    std::vector<Widget*> Window::getWidgets()
    {
        return contents;
    }

    void Window::removeWidget(Widget* w)
    {
        for(int i = 0; i < contents.size(); i++)
        {
            if(contents[i] == w)
                contents.erase(contents.begin()+i);
        }
    }

    void Window::resize(unsigned int w, unsigned int h)
    {
        for(int i = 0; i < contents.size(); i++)
        {
            unsigned int x = contents[i]->getLocation().x;
            unsigned int y = contents[i]->getLocation().y;
            if((w < (contents[i]->getWidth() + x)) || (h < (contents[i]->getHeight() + y)))
                throw illegal_size_error("Window cuts off a widget");
        }


            if(w > MAX_WIDTH || h > MAX_HEIGHT)
                throw illegal_size_error("Window exceeds maximum size");

            else
            {
                width = w;
                height = h;
            }
    }

    void Window::setHeight(int h)
    {
         height = h;
    }
    void Window::setWidth(int w)
    {
       width = w;
    }
