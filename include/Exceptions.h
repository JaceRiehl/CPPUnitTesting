#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

class illegal_size_error: public std::runtime_error
{
public:
    illegal_size_error(const char* errMessage) :
        std::runtime_error(errMessage)
    {
    }
};

class widget_operation_failed_error: public std::runtime_error
{
public:
    widget_operation_failed_error(const char* errMessage) :
        std::runtime_error(errMessage)
    {
    }
};

class widget_error: public std::runtime_error
{
public:
    widget_error(const char* errMessage) :
        std::runtime_error(errMessage)
    {
    }
};

#endif // EXCEPTIONS_H_INCLUDED
