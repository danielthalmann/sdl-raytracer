#include <iostream>
#include "Color.hpp"


void Color::write_color(std::ostream &out) 
{
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * r()) << ' '
        << static_cast<int>(255.999 * g()) << ' '
        << static_cast<int>(255.999 * b()) << '\n';
}

void Color::write_surface_color(SDL_Surface *surface, int x, int y) 
{

    Uint32 * const target_pixel = (Uint32 *) ((Uint8 *) surface->pixels
                                             + y * surface->pitch
                                             + x * surface->format->BytesPerPixel);

    Uint32 c = 0;
	c += static_cast<unsigned int>(1 * 255.0) & 0xFF;
	c = c << 8;
	c += static_cast<unsigned int>(255.999 * r()) & 0xFF;
	c = c << 8;
	c += static_cast<unsigned int>(255.999 * g()) & 0xFF;
	c = c << 8;
	c += static_cast<unsigned int>(255.999 * b()) & 0xFF;

    *target_pixel = c;
}

Color Color::ray_color(const Ray& r) {

    float a = (0.5 * (r.direction().y() + 1.0));  
    Color color = Color(1.0, 1.0, 1.0) * (1.0 - a);
    return color + (Color(0.5, 0.8, 1.0) * a);
    
}