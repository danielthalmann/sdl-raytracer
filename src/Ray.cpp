#include "Ray.hpp"


inline Point3 Ray::at(double t) const
{
    return orig + t * dir;
}