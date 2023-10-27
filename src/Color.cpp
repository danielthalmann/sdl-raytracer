#include "Color.hpp"
#include <iostream>


void write_color(std::ostream &out, Color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

void write_surface_color(SDL_Surface *surface, Color pixel_color, int x, int y) 
{

    Uint32 * const target_pixel = (Uint32 *) ((Uint8 *) surface->pixels
                                             + y * surface->pitch
                                             + x * surface->format->BytesPerPixel);

    Uint32 c = 0;
	c += static_cast<unsigned int>(1 * 255.0) & 0xFF;
	c = c << 8;
	c += static_cast<unsigned int>(255.999 * pixel_color.x()) & 0xFF;
	c = c << 8;
	c += static_cast<unsigned int>(255.999 * pixel_color.y()) & 0xFF;
	c = c << 8;
	c += static_cast<unsigned int>(255.999 * pixel_color.z()) & 0xFF;

    *target_pixel = c;
}

