#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

using namespace std;

class Coordinate
{
public:
    Coordinate(unsigned int x=0, unsigned int y=0);
    virtual ~Coordinate();
    bool operator==(const Coordinate& c) const;
    bool operator!=(const Coordinate& c) const;
    friend std::ostream& operator<<(std::ostream& os, const Coordinate& c);
    const unsigned int x;
    const unsigned int y;
};

#endif // COORDINATE_H
