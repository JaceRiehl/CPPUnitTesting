#include "Window.h"
#include "AsciiWindow.h"
#include "Exceptions.h"
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

    }


    void Window::addWidget(Widget* w)
    {
    //add operation failed error
    //if(w < (contents[i]->width + contents[i]->location.x) || h < (contents[i]->height + contents[i]->location.y))
     //if((w < (contents[i]->getWidth() + x)) || (h < (contents[i]->getHeight() + y)))
     for(int i = 0; i < contents.size(); i++)
        {

            if(w->getWidth)
            {
            contents.push_back(w);
            }

        }
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
