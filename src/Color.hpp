#ifndef COLOR_HPP
#define COLOR_HPP

#include <SDL2/SDL.h>
#include "Vector3.hpp"

using Color = Vector3;

void write_color(std::ostream &out, Color pixel_color);
void write_surface_color(SDL_Surface *surface, Color pixel_color, int x, int y);

#endif


