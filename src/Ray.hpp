#ifndef RAY_HPP
#define RAY_HPP

#include "Vector3.hpp"

class ray {
  public:
    ray() {}

    ray(const Point3& origin, const Vector3& direction) : orig(origin), dir(direction) {}

    Point3 origin() const  { return orig; }
    Vector3 direction() const { return dir; }

    Point3 at(double t) const {
        return orig + t * dir;
    }

  private:
    Point3 orig;
    Vector3 dir;
};

#endif

