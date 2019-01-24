#pragma once
#include "Circle.h"

namespace Geometry
{
    std::vector<Circle> RandomCircles(
        const size_t &len, 
        const Coordinate &min, const Coordinate &max, 
        const Coordinate &minlen, const Coordinate &maxlen);
}
