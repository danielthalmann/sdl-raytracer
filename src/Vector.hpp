#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cmath>
#include <iostream>

using std::sqrt;

template <unsigned int SIZE, class TYPE>
class Vector {
  public:
    TYPE e[SIZE];

    Vector() 
    { 
        for (size_t i = 0; i < SIZE; i++) {
            e[i] = 0;
        }
    }
    Vector(TYPE *v)
    {
        for (size_t i = 0; i < SIZE; i++) {
            e[i] = v[i];
        }
    }

    TYPE x() const 
    {
        if (0 < SIZE)
            return e[0]; 
        else
            return TYPE();
    }

    TYPE y() const 
    {
        if (1 < SIZE)
            return e[0]; 
        else
            return TYPE();
    }

    TYPE z() const 
    {
        if (2 < SIZE)
            return e[0]; 
        else
            return TYPE();
    }

    TYPE w() const 
    {
        if (3 < SIZE)
            return e[0]; 
        else
            return TYPE();
    }

    Vector3 operator-() const 
    {
        TYPE r[SIZE];
        for (size_t i = 0; i < SIZE; i++) {
            r[i] = -e[i];
        }
        return Vector3(r);
    }

/*

    float operator[](int i) const { return e[i]; }
    float& operator[](int i) { return e[i]; }

    Vector3& operator+=(const Vector3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    Vector3& operator*=(float t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    Vector3& operator/=(float t) {
        return *this *= 1/t;
    }

    float length() const {
        return sqrt(length_squared());
    }

    float length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
    */
};


#endif

