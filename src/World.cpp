#include "World.hpp"

World::World()
{

}

World::~World()
{

}

void World::addShape(Shape *shape)
{
    shapes.push_back(shape);
}

bool World::hit(const Ray& r, double ray_tmin, double ray_tmax, Hit& hit) const
{
    Hit temp_hit;
    bool hit_anything = false;
    auto closest_so_far = ray_tmax;

    for (Shape* shape : shapes) {
        if (shape->hit(r, ray_tmin, closest_so_far, temp_hit)) {
            hit_anything = true;
            closest_so_far = temp_hit.t;
            hit = temp_hit;
        }
    }

    return hit_anything; 

}
