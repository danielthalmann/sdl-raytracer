#include <iostream>
#include <SDL2/SDL.h>
#include "Vector3.hpp"
#include "Color.hpp"
#include "App.hpp"
#include "Vector.hpp"

// https://raytracing.github.io/books/RayTracingInOneWeekend.html

int main() 
{

    Vector<3, double> v;

    std::cout << v.x() << std::endl;
    std::cout << v.w() << std::endl;


    App::getInstance()->start();

}




