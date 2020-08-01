#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <SDL.h>

class Renderer {
public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
                const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();
  
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

private:
  int screen_width;
  int screen_height;
  int grid_width;
  int grid_height;
};

#endif
