#include "Window.h"
#include "AsciiWindow.h"
#include "Exceptions.h"
#include <string>
#include <vector>


    Window(int w=100, int h=100)
    {
        if(w > 1024 || h > 1024)
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
        for(int i = 0; i < std::vector contents.size; i++)
        {
            if(contents[i] == *w)
                contents.erase(i);
        }
    }

    void Window::resize(unsigned int w, unsigned int h)
    {
        if((w || h) > 1024)
            throw illegal_size_error("Window exceeds maximum size");

        for(int i = 0; i < contents.size() + 1; i++)
        {
            if(w < (contents[i]->width + contents[i]->location.x) || h < (contents[i]->height + contents[i]->location.y))
                throw illegal_size_error("Window cuts off a widget");
        }

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
