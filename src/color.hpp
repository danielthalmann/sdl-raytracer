#ifndef COLOR_H
#define COLOR_H

#include <SDL2/SDL.h>
#include "vector3.hpp"

using color = vec3;

void write_color(std::ostream &out, color pixel_color);
void write_surface_color(SDL_Surface *surface, color pixel_color, int x, int y);

#endif


