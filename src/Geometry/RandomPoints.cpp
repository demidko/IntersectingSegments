#include "RandomPoints.h"
#include <random>
#include <execution>

namespace Geometry
{
    std::vector<Point> RandomPoints(const size_t &len, const Coordinate &min, const Coordinate &max)
    {
        std::vector<Point> res(len);
        std::generate(std::execution::par_unseq, begin(res), end(res), 
            [e = std::default_random_engine(std::random_device{}()),
            xy = std::uniform_real_distribution<long double>(min, max)]() mutable
        {
            return Point{ xy(e), xy(e) };
        });
        return res;
    }
}