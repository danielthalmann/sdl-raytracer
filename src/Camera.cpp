#include "Camera.hpp"

Camera::Camera() 
{

}

Camera::~Camera()
{

}

void Camera::size(int width, int height)
{
    image_width = width;
    image_height = height;

    focal_length = 1.0;
    viewport_height = 2.0;
    viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);
    camera_center = Point3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    viewport_u = Vector3(viewport_width, 0, 0);
    viewport_v = Vector3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    pixel_delta_u = viewport_u / static_cast<float>(image_width);
    pixel_delta_v = viewport_v / static_cast<float>(image_height);

    // Calculate the location of the upper left pixel.
    Vector3 viewport_upper_left = camera_center - Vector3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
}

void Camera::renderWorld(World &world, SDL_Surface *surface)
{

    for (int j = 0; j < image_height; ++j) {

        for (int i = 0; i < image_width; ++i) {
            Vector3 pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            Vector3 ray_direction = pixel_center - camera_center;
            Ray r(camera_center, ray_direction);

            Color pixel_color;
            Hit hit;
            if (world.hit(r, ray_tmin, ray_tmax, hit)) {
                Vector3 N = r.at(hit.t) - Vector3(0,0,-1);
                N = N.unit_vector();
                pixel_color = Color(N.x()+1, N.y()+1, N.z()+1) * 0.5;
            }
            else {
                pixel_color = Color::ray_color(r);
            }

            pixel_color.write_surface_color(surface, i, j);

        }
    }

}