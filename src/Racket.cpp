#include <SDL.h>
#include <iostream>

#include "Racket.h"

Racket::Racket() {
  std::cout << "RACKET";
  transform.x = 0;
  transform.y = 0;
}
Racket::~Racket() {}

void Racket::Update(){
  int i = 2;
}

void Racket::Draw(Renderer &renderer) {
  SDL_Rect rectangle;
  rectangle.x = static_cast<int>(100);
  rectangle.y = static_cast<int>(100);
  rectangle.h = 10;
  rectangle.w = 10;
  SDL_SetRenderDrawColor(renderer.sdl_renderer, 100, 149, 0, 255);
  SDL_RenderClear(renderer.sdl_renderer);
  SDL_SetRenderDrawColor(renderer.sdl_renderer, 10, 12, 100, 0xFF);
  SDL_RenderFillRect(renderer.sdl_renderer, &rectangle);
  SDL_RenderPresent(renderer.sdl_renderer);
}
