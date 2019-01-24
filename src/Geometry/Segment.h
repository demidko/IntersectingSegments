#pragma once
#include "Point.h"

namespace Geometry
{
    struct Segment
    {
        Point A, B;
    };

    template<typename Stream> Stream &operator<<(Stream &s, const Segment &seg)
    {
        return s << "(A: " << seg.A << ", B: " << seg.B << ")";
    }

    SmartStream::Stream &operator>>(SmartStream::Stream &s, Segment &seg);

    long double Length(const Segment&);

    bool operator==(const Segment&, const Segment&);

    bool operator!=(const Segment&, const Segment&);
}