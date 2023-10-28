#include "Sphere.hpp"
#include <cmath>
#include "../Vector3.hpp"

Hit Sphere::hit(Ray r)
{
    Vector3 oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double b = 2.0 * dot(oc, r.direction());
    double c = dot(oc, oc) - radius*radius;
    double discriminant = b*b - 4*a*c;
    //return (discriminant >= 0);
    Hit hit;
    if (discriminant < 0) {
        hit.t = -1.0;
    } else {
        hit.t = (-b - sqrt(discriminant) ) / (2.0*a);
    }
    return hit;

}
