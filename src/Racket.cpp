#include <SDL.h>
#include <iostream>

#include "Racket.h"

Racket::Racket(int id) {
  this->id = id;
  transform.x = 10;
  transform.y = 600;
  _rect.h = 10;
  _rect.w = 80;
  _rect.x = transform.x;
  _rect.y = transform.y;
}

Racket::~Racket() {}

void Racket::Update(){
  _rect.x = transform.x;
  _rect.y = transform.y;

}

void Racket::Draw(Renderer &renderer) {
  
  SDL_SetRenderDrawColor(renderer.sdl_renderer, 10, 12, 100, 0xFF);
  SDL_RenderFillRect(renderer.sdl_renderer, &_rect);
  
}
