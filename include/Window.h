#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include "Widget.h"
#include "Coordinate.h"
#include <vector>
/**
  * Abstract class for the implementation of a window
  */
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
     * Pure virtual draw
     */
    virtual void draw() = 0;

private:
     /**
     * Setter function for Width
     *@param h The width to be set.
     *@throw illegal_size_error Exception thrown if the height is above MAX_HEIGHT
     */
    void setHeight(int h);
     /**
     * Setter function for height
     *@param h The height to be set.
     *@throw illegal_size_error Exception thrown if the width is above MAX_WIDTH
     */
    void setWidth(int w);
     /**
     *The width of the window
     */
    unsigned int width;
     /**
     * The height of the window
     */
    unsigned int height;
     /**
     *The vector of Widets in the window
     */
    std::vector<Widget*> contents;
};


#endif // WINDOW_H_INCLUDED
