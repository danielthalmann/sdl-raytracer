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
    Color(double r, double g, double b) : Vector3(r, g, b) {}
    ~Color() {}

    double r() const { return e[0]; }
    double g() const { return e[1]; }
    double b() const { return e[2]; }

    void write_color(std::ostream &out);
    void write_surface_color(SDL_Surface *surface, int x, int y);

    inline Color operator*(double t) {
        return Color(t*this->e[0], t*this->e[1], t*this->e[2]);
    }

    inline Color operator+(const Color &v) {
        return Color(this->e[0] + v.e[0], this->e[1] + v.e[1], this->e[2] + v.e[2]);
    }

    static Color ray_color(const Ray& r);

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

inline Color operator*(double t, const Color &v) {
    return Color(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline Color operator/(Color v, double t) {
    return (1/t) * v;
}

#endif


