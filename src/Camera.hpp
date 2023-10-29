#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Vector3.hpp"
#include "World.hpp"
#include "Color.hpp"

#pragma once
/*
             U
      ──────────────────►
    │ ┌─────────────────┐
    │ │  . . . . . . .  │
 V  │ │  . . ▲ . . ◄─► ◄├── Pixel_delta_U
    │ │  . . ▼ . . . .  │
    ▼ └──────▲──────────┘
             │
        Pixel_delta_V
*/

class Camera
{

public:
    Camera();
    ~Camera();


    /**
     * @brief specify the size of view
     * 
     * @param width 
     * @param height 
     */
    void size(int width, int height);

    /**
     * @brief render all object in world
     * 
     * @param world 
     */
    void renderWorld(World &world, SDL_Surface *surface);

private:

    double aspect_ratio;
    double image_width;
    double image_height;

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    Vector3 viewport_u;
    Vector3 viewport_v;
    
    Point3 camera_center;
    float focal_length;

    float viewport_height;
    float viewport_width;

    Vector3 pixel00_loc;
    Vector3 pixel_delta_u;
    Vector3 pixel_delta_v;

    double ray_tmin = 0.1;
    double ray_tmax = 1.5;

};

#endif