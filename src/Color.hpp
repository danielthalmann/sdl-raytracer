#ifndef COLOR_HPP
#define COLOR_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include "Vector3.hpp"

class Color : public Vector3
{
public:
    Color() : Vector3{0,0,0} {}
    Color(double r, double g, double b) : Vector3{r, g, b} {}
    ~Color() {}

    double r() const { return e[0]; }
    double g() const { return e[1]; }
    double b() const { return e[2]; }

    void write_color(std::ostream &out);
    void write_surface_color(SDL_Surface *surface, int x, int y);

};


#endif


