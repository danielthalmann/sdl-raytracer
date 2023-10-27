#include <iostream>
#include <SDL2/SDL.h>
#include "vector3.hpp"
#include "color.hpp"
#include "App.hpp"

// https://raytracing.github.io/books/RayTracingInOneWeekend.html

// Image

float aspect_ratio;
int image_width;
int image_height;
float viewport_height;
float viewport_width;


int start = 0;

void set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
  Uint32 * const target_pixel = (Uint32 *) ((Uint8 *) surface->pixels
                                             + y * surface->pitch
                                             + x * surface->format->BytesPerPixel);
  *target_pixel = pixel;
}

void next(SDL_Renderer* renderer)
{
    SDL_Surface* surface = SDL_CreateRGBSurface(0,image_width,image_height,32,0,0,0,0);

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            color pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), double(j)/(image_height-1));
            write_surface_color(surface, pixel_color, i, j);
        }
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
std::cout << "next" << std::endl;

    SDL_FreeSurface(surface);

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);

    std::cout << rect.w << "x" << rect.h << std::endl;

    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_DestroyTexture(texture);

}


int main() 
{

    App::getInstance()->start();

}




