#ifndef APP_HPP
#define APP_HPP

#include <SDL2/SDL.h>
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
    void start();

private:

    float aspect_ratio;
    int image_width;
    int image_height;
    float viewport_height;
    float viewport_width;
    bool running = false;

};

#endif