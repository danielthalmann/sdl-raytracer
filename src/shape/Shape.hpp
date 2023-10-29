#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "../Vector3.hpp"
#include "../Ray.hpp"
#include "../Hit.hpp"

class Shape
{  
public:
    Shape(Point3 c) : center(c)  {}
    virtual ~Shape() {}

    virtual bool hit(const Ray &r, double ray_tmin, double ray_tmax, Hit &hit) = 0;

    virtual void translate(Vector3 t);

protected:
    Point3 center;

};

#endif