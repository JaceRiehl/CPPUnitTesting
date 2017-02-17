#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

using namespace std;

/**
* Holds a 2d coordinates' x and y values
*/
class Coordinate
{
public:
     /**
     *Specifies a 2d coordinate
     *@param x value(default 0)
     *@param y value(default 0)
     */
    Coordinate(unsigned int x=0, unsigned int y=0);
     /**
     *Destructor for Coordinate
     */
    virtual ~Coordinate();
     /**
     *@return true if two Coordinates x and y values are the same, false if they aren't the same
     */
    bool operator==(const Coordinate& c) const;
     /**
     *@return true if two Coordinates x and y values aren't the same, false if they are the same
     */
    bool operator!=(const Coordinate& c) const;
     /**
     *@return The x and y values of the Coordinate inputted
     */
    friend std::ostream& operator<<(std::ostream& os, const Coordinate& c);
     /**
     *The x coordinate
     */
    const unsigned int x;
     /**
     *The y coordinate
     */
    const unsigned int y;
};

#endif // COORDINATE_H
