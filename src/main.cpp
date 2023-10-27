#include <iostream>
#include <SDL2/SDL.h>
#include "Vector3.hpp"
#include "Color.hpp"
#include "App.hpp"

// https://raytracing.github.io/books/RayTracingInOneWeekend.html

// Image


void set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
  Uint32 * const target_pixel = (Uint32 *) ((Uint8 *) surface->pixels
                                             + y * surface->pitch
                                             + x * surface->format->BytesPerPixel);
  *target_pixel = pixel;
}

int main() 
{

    App::getInstance()->start();

}




