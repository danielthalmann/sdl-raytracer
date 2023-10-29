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
    aspect_ratio = 16.0 / 10.0;
    image_width = 1200;
    image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    std::cout << aspect_ratio << ":" << image_width << "x" << image_height << std::endl; 

    viewport_height = 2.0;
    viewport_width = viewport_height * (static_cast<float>(image_width)/image_height);

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


    camera.focal_length = 1.0;
    camera.viewport_height = 2.0;
    camera.viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);
    camera.camera_center = Point3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    camera.viewport_u = Vector3(camera.viewport_width, 0, 0);
    camera.viewport_v = Vector3(0, -camera.viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    camera.pixel_delta_u = camera.viewport_u / static_cast<float>(image_width);
    camera.pixel_delta_v = camera.viewport_v / static_cast<float>(image_height);

    // Calculate the location of the upper left pixel.
    Vector3 viewport_upper_left = camera.camera_center
                             - Vector3(0, 0, camera.focal_length) - camera.viewport_u / 2 - camera.viewport_v / 2;
    Vector3 pixel00_loc = viewport_upper_left + 0.5 * (camera.pixel_delta_u + camera.pixel_delta_v);

    Sphere sphere(Point3(0,0,-1), 0.5);

    double ray_tmin = 0.1;
    double ray_tmax = 1.5;

    for (int j = 0; j < image_height; ++j) {

        for (int i = 0; i < image_width; ++i) {
            Vector3 pixel_center = pixel00_loc + (i * camera.pixel_delta_u) + (j * camera.pixel_delta_v);
            Vector3 ray_direction = pixel_center - camera.camera_center;
            Ray r(camera.camera_center, ray_direction);

            Color pixel_color;
            Hit hit;
            if (sphere.hit(r, ray_tmin, ray_tmax, hit)) {
                Vector3 N = r.at(hit.t) - Vector3(0,0,-1);
                N = N.unit_vector();
                pixel_color = Color(N.x()+1, N.y()+1, N.z()+1) * 0.5;
            }
            else
                pixel_color = Color::ray_color(r);

            pixel_color.write_surface_color(surface, i, j);

        }
    }

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
