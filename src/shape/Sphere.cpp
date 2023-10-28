#include "Sphere.hpp"
#include <cmath>
#include "../Vector3.hpp"

Hit Sphere::hit(Ray r)
{
    Vector3 oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double half_b = dot(oc, r.direction());
    double c = dot(oc, oc) - radius*radius;
    double discriminant = half_b * half_b - a*c;
    //return (discriminant >= 0);
    Hit hit;

    hit.t = -1;

    double ray_tmin = 0.1;
    double ray_tmax = 4.0;

    double sqrtd = sqrt(discriminant);
    // Find the nearest root that lies in the acceptable range.
    double root = (-half_b - sqrtd) / a;
    if (root <= ray_tmin || ray_tmax <= root) {
        root = (-half_b + sqrtd) / a;
        if (root <= ray_tmin || ray_tmax <= root)
            return hit;
    }


    if (discriminant < 0) {
        hit.t = -1.0;
    } else {
        hit.t = root;
        hit.point = r.at(hit.t);
        hit.normal = (hit.point - center) / radius;
    }
    return hit;

}
