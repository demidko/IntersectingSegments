#pragma once
#include "Point.h"

namespace Geometry
{
    struct Circle
    {
        Point Center;
        Coordinate Radius;
    };

    template<typename Stream> Stream &operator<<(Stream &s, const Circle &p)
    {
        return s << '(' << "O: " << p.Center << ", R: " << p.Radius << ')';
    }

    SmartStream::Stream &operator>>(SmartStream::Stream &s, Circle &p);

    bool operator==(const Circle &a, const Circle &b);

    bool operator!=(const Circle &a, const Circle &b);
}

