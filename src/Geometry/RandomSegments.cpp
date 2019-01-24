#include "RandomSegments.h"
#include <random>
#include <execution>

namespace Geometry
{
    std::vector<Segment> Geometry::RandomSegments(const size_t & len, const Coordinate & min, const Coordinate & max)
    {
        std::vector<Segment> res(len);
        std::generate(std::execution::par_unseq, begin(res), end(res),
            [e = std::default_random_engine(std::random_device{}()),
            xy = std::uniform_real_distribution<long double>(min, max)]() mutable
        {
            return Segment{ { xy(e), xy(e) } , { xy(e), xy(e) } };
        });
        return res;
    }
}


