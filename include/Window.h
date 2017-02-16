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
     * Abstract class for GUI windows
     *@param w The width of the window(default(100))
     *@param h The heigh of the window(default(100))
     *@throw illegal_size_error Thrown if the width exceeds the maximum(1024) width or height.
     */
    Window(int w=100, int h=100);
     /**
     *Class Destructor
     */
    virtual ~Window();
    /**
     *Adds a Widget to the window
     * @param w the widget that is attempted to be added
     * @exception widget_operation_failed_error Thrown if \a w overlaps onto another widget
     */
    void addWidget(Widget* w);
     /**
     *@return Width of the window
     */
    unsigned int getWidth();
     /**
     *@return Height of the window
     */
    unsigned int getHeight();
     /**
     *@return A vector of the Widgets on the screen
     */
    std::vector<Widget*> getWidgets();
     /**
     *Removes the Widget in the window
     *@param w The Widget to be removed
     */
    void removeWidget(Widget* w);
     /**
     * Resizes the Window
     *@param w The new Width for the window to be resized
     *@param h The new Height for the window to be resized
     *@throw illegal_size_error Thrown if the windows new width or height exceed the maximums or if resizing the window will cutoff a widget.
     */
    void resize(unsigned int w, unsigned int h);
     /**
     *
     */
    virtual void draw() = 0;

private:
     /**
     * Setter function for Width
     *@param h The width to be set.
     */
    void setHeight(int h);
     /**
     * Setter function for height
     *@param h The height to be set.
     */
    void setWidth(int w);
    unsigned int width;
    unsigned int height;
    std::vector<Widget*> contents;
};


#endif // WINDOW_H_INCLUDED
