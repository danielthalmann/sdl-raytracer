#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Vector3.hpp"

#pragma once
/*

                  U

         ────────────────────►

     │   ┌───────────────────┐
     │   │                   │
     │   │  . . . . . . . .  │
     │   │                   │
  V  │   │  . . ▲ . . . ◄─► ◄├──── Pixel_delta_U
     │   │      │            │
     │   │  . . ▼ . . . . .  │
     │   │                   │
     ▼   └──────▲────────────┘
                │
                │
                │
                │

              Pixel_delta_V
*/

class Camera
{


public:
    Camera();
    ~Camera();

public:
    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    Vector3 viewport_u;
    Vector3 viewport_v;
    
    Point3 camera_center;
    float focal_length;

    float viewport_height;
    float viewport_width;

    Vector3 pixel_delta_u;
    Vector3 pixel_delta_v;

};

#endif