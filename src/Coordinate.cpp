#include "Coordinate.h"
#include <iostream>

    Coordinate::Coordinate(unsigned int x, unsigned int y):x(x), y(y){}
    Coordinate::~Coordinate()
    {
    }
    bool Coordinate::operator==(const Coordinate& c) const
    {
        if(c.x == x && c.y == y)
            return true;
        return false;
    }
    bool Coordinate:: operator!=(const Coordinate& c) const
    {
        if(c.x == x && c.y == y)
            return false;
        return true;
    }
    ostream& operator<<(ostream& os, const Coordinate& c)
    {
        os << "[" << c.x << "," << c.y << "]";
    }
