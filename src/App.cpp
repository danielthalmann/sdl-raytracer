#include "App.hpp"
#include "Vector3.hpp"
#include "Color.hpp"
#include "Ray.hpp"
#include <iostream>
#include "shape/Sphere.hpp"
#include "Hit.hpp"

App App::instance; 

/**
 * @brief get the singleton app instance
 * 
 * @return App* 
 */
App *App::getInstance()
{
    return &instance;
}

App::App()
{
    double aspect_ratio = 16.0 / 10.0;
    image_width = 1200;
    image_height = static_cast<int>(image_width / aspect_ratio);

    camera.size(image_width, image_height);

    world.addShape(new Sphere(Point3(0,0,-1), 0.5));

}

App::~App()
{

}

void App::loop()
{

}

/**
 * @brief render scene
 * 
 */
void App::render()
{
    SDL_RenderClear(renderer);

    camera.renderWorld(world, surface);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);

    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_DestroyTexture(texture);    

    SDL_RenderPresent(renderer);
}


/**
 * @brief Clean memory used
 * 
 */
void App::clean()
{
    SDL_FreeSurface(surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

int App::init() 
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 0;
    }

    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        SDL_Log("Unable to Init hinting: %s", SDL_GetError());
        return 0;
    }

    window = SDL_CreateWindow("TEST",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, image_width, image_height,
		SDL_WINDOW_SHOWN);
    
    if (window == NULL) {
        SDL_Log("Unable to Init windows: %s", SDL_GetError());
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        SDL_Log("Unable to Init windows: %s", SDL_GetError());
        return 0;
    }

    primarySurface = SDL_GetWindowSurface(window);
    surface = SDL_CreateRGBSurface(0, image_width, image_height, 32, 0, 0, 0, 0);

    return 1;

}


/**
 * @brief Start application
 * 
 */
void App::start()
{

    if( ! init() )
        return;

    SDL_Event event;

    running = true;

	while(running) {

		while(SDL_PollEvent(&event) != 0) {
			
            if(event.type == SDL_QUIT) running = false;

        }

		loop();

		render();

		SDL_Delay(1); // Breath
	}  

    clean();  
    
}
