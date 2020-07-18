#include <SDL.h>
#include <iostream>

#include "Racket.h"

Racket::Racket() {
  std::cout << "RACKET";
  transform.x = 10;
  transform.y = 10;
  
}
Racket::~Racket() {}

void Racket::Update(){

}

void Racket::Draw(Renderer &renderer) {
  SDL_Rect rectangle;
  rectangle.x = transform.x;
  rectangle.y = transform.y;
  rectangle.h = 10;
  rectangle.w = 10;
  

  SDL_SetRenderDrawColor(renderer.sdl_renderer, 10, 12, 100, 0xFF);
  SDL_RenderFillRect(renderer.sdl_renderer, &rectangle);
  
}
