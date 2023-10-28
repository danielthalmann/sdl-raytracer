#ifndef HIT_HPP
#define HIT_HPP
#include "Vector3.hpp"

typedef struct sHit
{
    Point3 point;
    Vector3 normal;
    double t;

} Hit;


#endif