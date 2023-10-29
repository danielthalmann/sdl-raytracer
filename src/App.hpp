#ifndef APP_HPP
#define APP_HPP

#include <SDL2/SDL.h>
#include "Camera.hpp"
#include "World.hpp"
#pragma once

class App
{
private:
    static App instance;


private:
    SDL_Window *window;
    SDL_Surface *primarySurface;
    SDL_Surface *surface;
    SDL_Renderer *renderer;
    
    World world;
    Camera camera;

public:
    ~App();
    App();

    /**
     * @brief get the singleton app instance
     * 
     * @return App* 
     */
    static App *getInstance();
    
public:
    void loop();
    void render();
    void clean();
    int init();
    void start();

private:

    int image_width;
    int image_height;
    bool running = false;
    

};

#endif