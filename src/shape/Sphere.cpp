#include "Sphere.hpp"
#include <cmath>
#include "../Vector3.hpp"

bool Sphere::hit(const Ray &r, double ray_tmin, double ray_tmax, Hit &hit)
{
    Vector3 oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double half_b = dot(oc, r.direction());
    double c = dot(oc, oc) - radius*radius;
    double discriminant = half_b * half_b - a*c;

    if (discriminant < 0)
        return false;

    double sqrtd = sqrt(discriminant);
    // Find the nearest root that lies in the acceptable range.
    double root = (-half_b - sqrtd) / a;
    if (root <= ray_tmin || ray_tmax <= root) {
        root = (-half_b + sqrtd) / a;
        if (root <= ray_tmin || ray_tmax <= root)
            return false;
    }

    hit.t = root;
    hit.point = r.at(hit.t);
    hit.normal = (hit.point - center) / radius;

    return true;

}
