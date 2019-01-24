#include "Segment.h"

SmartStream::Stream & Geometry::operator>>(SmartStream::Stream & s, Segment & seg)
{
    return s << '[' << SmartStream::tabl
        << "A: " >> seg.A
        << "B: " >> seg.B
        << SmartStream::untab << ']' << SmartStream::endl;
}

long double Geometry::Length(const Segment & seg)
{
    return Length(seg.A, seg.B);
}

bool Geometry::operator==(const Segment & first, const Segment & second)
{
    return (first.A == second.A) && (first.B == second.B);
}

bool Geometry::operator!=(const Segment & a, const Segment & b)
{
    return !operator==(a, b);
}
