#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include "shape/Shape.hpp"
#include "Hit.hpp"

#pragma once

class World
{
public:
    World();
    ~World();

    void addShape(Shape *shape);
    bool hit(const Ray &r, double ray_tmin, double ray_tmax, Hit& rec) const;

private:
    std::vector<Shape*> shapes;

};

#endif