#include <iostream>
#include <SDL2/SDL.h>
#include "vector3.hpp"
#include "color.hpp"

// https://raytracing.github.io/books/RayTracingInOneWeekend.html

// Image

float aspect_ratio;
int image_width;
int image_height;
float viewport_height;
float viewport_width;


int start = 0;

void set_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
  Uint32 * const target_pixel = (Uint32 *) ((Uint8 *) surface->pixels
                                             + y * surface->pitch
                                             + x * surface->format->BytesPerPixel);
  *target_pixel = pixel;
}

void next(SDL_Renderer* renderer)
{
    SDL_Surface* surface = SDL_CreateRGBSurface(0,image_width,image_height,32,0,0,0,0);

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            color pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), double(j)/(image_height-1));
            write_surface_color(surface, pixel_color, i, j);
        }
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
std::cout << "next" << std::endl;

    SDL_FreeSurface(surface);

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);

    std::cout << rect.w << "x" << rect.h << std::endl;

    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_DestroyTexture(texture);    

}


int main() 
{

    aspect_ratio = 16.0 / 9.0;

    image_width = 400;
    image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    std::cout << image_width << "x" << image_height << std::endl;
    // Viewport widths less than one are ok since they are real valued.
    viewport_height = 2.0;
    viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);

    std::cout << viewport_height << "x" << viewport_width << std::endl;


	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
       	return (0);
    }

    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        SDL_Log("Unable to Init hinting: %s", SDL_GetError());
        return (0);
    }

    SDL_Window* window = SDL_CreateWindow("TEST",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, image_width, image_height,
		SDL_WINDOW_SHOWN);
    if( window == NULL) {
        SDL_Log("Unable to Init windows: %s", SDL_GetError());
        return (0);
    }

    SDL_Surface* primarySurface = SDL_GetWindowSurface(window);

    SDL_Surface* surface = SDL_CreateRGBSurface(0,image_width,image_height,32,0,0,0,0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    // Render

/*
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            write_color(std::cout, pixel_color);
            write_surface_color(surface, pixel_color, j, i);
        }
    }
*/
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

    // SDL_UpdateWindowSurface(window);


    bool Running = true;

    SDL_Event Event;

	while(Running) {

		while(SDL_PollEvent(&Event) != 0) {
			
            if(Event.type == SDL_QUIT) Running = false;

		
        }

		//Loop();
		//Render();

        SDL_RenderClear(renderer);

        next(renderer);

        SDL_RenderPresent(renderer);

		SDL_Delay(1); // Breath
	}


    std::clog << "\rDone.                 \n";

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

}




