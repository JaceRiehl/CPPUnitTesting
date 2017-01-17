#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include "Widget.h"
#include "Coordinate.h"
#include <vector>

class Window
{

public:

    static const int MAX_WIDTH = 1024;
    static const int MAX_HEIGHT = 1024;

    /**
     * A GUI window at location c.
     * @param w The width of the window (default: 100).
     * @param h The height of the window (default: 100).
     * @throw illegal_size_error Thrown if the width exceeds the maximum width or height.
     * @exception illegal_placement_error Thrown if \a w cannot be placed at \a c
     */
    Window(int w=100, int h=100);

    /**
    * Destructor for window
    */
    virtual ~Window(){}

    /**
     * @return the location of the window
     */
    Coordinate getLocation();

    /**
     * Add a widget to the window
     * @param w the widget to add
     * @exception illegal_placement_error Thrown if \a w cannot be placed
     */
    void addWidget(Widget* w);

    /**
    * @return The width of the window.
    */
    unsigned int getWidth();

    /**
    * @return The height of the window.
    */
    unsigned int getHeight();

    /**
    * @return The widgets in the window.
    */
    std::vector<Widget*> getWidgets();


    /**
    * @return The widgets in the window.
    */
    void removeWidget(Widget* w);


    /**
    * Resize the window.
    * @throw illegal_size_error Thrown if the new window size will exceed either the maximum width or height
    * or if resizing the window will cutoff a widget.
    */
    void resize(unsigned int w, unsigned int h);

    /**
    * Draw the window.
    */
    virtual void draw() = 0;

private:
    /**
    * Set the height of the window.
    * @param h The new height of the window.
    * @throw illegal_size_error Thrown if the width exceeds the maximum width.
    */
    void setHeight(int h);

    /**
    * Set the width of the window.
    * @param w The new width of the window.
    * @throw illegal_size_error Thrown if the width exceeds the maximum width.
    */
    void setWidth(int w);

    /**
    * Set the location of the window.
    * @param c The new location of the window.
    * @throw illegal_move_error Thrown if the newly moved window will be moved completely outside of the screen.
    */
    void setLocation(Coordinate c);

    /**
    * Width of the window
    */
    unsigned int width;

    /**
    * Height of the window
    */
    unsigned int height;

    /**
    * The location of the window
    */
    Coordinate* location = nullptr;

    /**
    * The widgets in the window
    */
    std::vector<Widget*> contents;

};


#endif // WINDOW_H_INCLUDED
