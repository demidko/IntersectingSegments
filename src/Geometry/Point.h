#pragma once
#include "../SmartStream/SmartStream.h"

namespace Geometry 
{
    using Coordinate = long double;

    struct Point
    {
        Coordinate x, y;
    };

    template<typename Stream> Stream &operator<<(Stream &s, const Point &p)
    {
        return s << "(x: " << p.x << ", y: " << p.y << ")";
    }

    SmartStream::Stream &operator>>(SmartStream::Stream &s, Point &p);

    bool operator==(const Point &a, const Point &b);

    bool operator!=(const Point &a, const Point &b);

    long double Length(const Point &a, const Point &b);
}
