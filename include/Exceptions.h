#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

/**
* Exception for a window size greater than the maximum allowed or cutting off a widget when resizing the window.
*/
class illegal_size_error: public std::runtime_error
{
public:
    /**
    *@param errMessage An error message.
    */
    illegal_size_error(const char* errMessage) :
        std::runtime_error(errMessage)
    {
    }
};

/**
* Exception for when a widget is cut off.
*/
class widget_operation_failed_error: public std::runtime_error
{
public:
    /**
    *@param errMessage An error message.
    */
    widget_operation_failed_error(const char* errMessage) :
        std::runtime_error(errMessage)
    {
    }
};

/**
* Exception for when there is a problem with a widget.
*/
class widget_error: public std::runtime_error
{
public:
    /**
    *@param errMessage An error message.
    */
    widget_error(const char* errMessage) :
        std::runtime_error(errMessage)
    {
    }
};

#endif // EXCEPTIONS_H_INCLUDED
