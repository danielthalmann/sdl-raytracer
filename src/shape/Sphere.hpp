#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "Shape.hpp"
#include "../Ray.hpp"
#include "../Hit.hpp"

class Sphere : public Shape
{  
public:
    Sphere(Point3 c, double r) : Shape(c), radius(r) {}
    virtual ~Sphere() {}

    virtual bool hit(const Ray &r, double ray_tmin, double ray_tmax, Hit &hit);

protected:
    double radius;

};

#endif