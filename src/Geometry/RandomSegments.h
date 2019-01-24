#pragma once
#include "Segment.h"

namespace Geometry
{
    std::vector<Segment> RandomSegments(const size_t &len, const Coordinate &xymin, const Coordinate &xymax);
}
