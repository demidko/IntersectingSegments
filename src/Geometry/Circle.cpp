#include "Circle.h"

SmartStream::Stream & Geometry::operator>>(SmartStream::Stream & s, Circle & p)
{
    return s << '[' << SmartStream::tabl
        << "O: " >> p.Center
        << "R: " >> p.Radius
        << SmartStream::untab << ']' << SmartStream::endl;
}

bool Geometry::operator==(const Circle & a, const Circle & b)
{
    return (a.Center == b.Center) && (a.Radius == b.Radius);
}

bool Geometry::operator!=(const Circle & a, const Circle & b)
{
    return !operator==(a, b);
}
