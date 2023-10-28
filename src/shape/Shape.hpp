#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "../Vector3.hpp"
#include "../Ray.hpp"

class Shape
{  
public:
    Shape(Point3 c) : center(c)  {}
    virtual ~Shape() {}

    virtual bool hit(Ray ray) = 0;

protected:
    Point3 center;

};

#endif