#include "Point.h"

namespace Geometry
{
    SmartStream::Stream &operator>>(SmartStream::Stream &s, Point &p)
    {
        return s << '[' << SmartStream::tabl 
            << "x: " >> p.x
            << "y: " >> p.y
            << SmartStream::untab << ']' << SmartStream::endl;
    }

    bool operator==(const Point &a, const Point &b)
    {
        return a.x == b.x && a.y == b.y;
    }

    bool operator!=(const Point & a, const Point & b)
    {
        return !operator==(a, b);
    }

    long double Length(const Point & a, const Point & b)
    {
        return sqrtl(powl(long double(b.x - a.x), 2) + powl(long double(b.y - a.y), 2));
    }
}