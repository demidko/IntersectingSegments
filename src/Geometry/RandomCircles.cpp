#include "RandomCircles.h"
#include <execution>
#include <random>

namespace Geometry
{
    std::vector<Circle> RandomCircles(
        const size_t & len,
        const Coordinate & xymin, const Coordinate & xymax,
        const Coordinate & rmin, const Coordinate & rmax)
    {
        std::vector<Circle> res(len);
        std::generate(std::execution::par_unseq, begin(res), end(res),
            [e = std::default_random_engine(std::random_device{}()),
            xy = std::uniform_real_distribution<long double>(xymin, xymax),
            r = std::uniform_real_distribution<long double>(rmin, rmax)]() mutable
        {
            return Circle{ {xy(e), xy(e)}, r(e) };
        });
        return res;
    }
}
