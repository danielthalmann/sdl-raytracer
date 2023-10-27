#include "App.hpp"
#include "Vector3.hpp"
#include "Color.hpp"

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
    aspect_ratio = 16 / 9;
    image_width = 400;
    image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    viewport_height = 2.0;
    viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);

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

    // TODO RENDER

    SDL_Surface* surface = SDL_CreateRGBSurface(0,image_width,image_height,32,0,0,0,0);

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            Color pixel_color = Color(double(i)/(image_width-1), double(j)/(image_height-1), double(j / 2)/(image_height-1));
            pixel_color.write_surface_color(surface, i, j);
        }
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

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
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

/**
 * @brief Start application
 * 
 */
void App::start()
{

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return;
    }

    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        SDL_Log("Unable to Init hinting: %s", SDL_GetError());
        return;
    }

    window = SDL_CreateWindow("TEST",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, image_width, image_height,
		SDL_WINDOW_SHOWN);
    
    if (window == NULL) {
        SDL_Log("Unable to Init windows: %s", SDL_GetError());
        return;
    }

    primarySurface = SDL_GetWindowSurface(window);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

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
