#ifndef COLOR_HPP
#define COLOR_HPP

#include <SDL2/SDL.h>
#include <iostream>
#include "Vector3.hpp"
#include "Ray.hpp"

class Color : public Vector3
{
public:
    Color() : Vector3(0,0,0) {}
    Color(float r, float g, float b) : Vector3(r, g, b) {}
    ~Color() {}

    float r() const { return e[0]; }
    float g() const { return e[1]; }
    float b() const { return e[2]; }

    void write_color(std::ostream &out);
    void write_surface_color(SDL_Surface *surface, int x, int y);

    static Color ray_color(const Ray& r) {

        Vector3 unit_direction = unit_vector(r.direction());
        float a = 1.0 - (0.5 * (unit_direction.y() + 1.0));
        Color color = 1.0f * Color(1.0, 1.0, 1.0);
        return color + (a * Color(0.5, 0.7, 1.0));
        
        //return Color(0,0,0);
    }

};

inline std::ostream& operator<<(std::ostream &out, const Color &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline Color operator+(const Color &u, const Color &v) {
    return Color(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline Color operator-(const Color &u, const Color &v) {
    return Color(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline Color operator*(const Color &u, const Color &v) {
    return Color(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline Color operator*(float t, const Color &v) {
    return Color(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline Color operator*(const Color &v, float t) {
    return t * v;
}

inline Color operator/(Color v, float t) {
    return (1/t) * v;
}

#endif


