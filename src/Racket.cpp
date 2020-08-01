#include <SDL.h>
#include <iostream>

#include "Racket.h"

Racket::Racket(int id) {
  this->id = id;
  location = Vector2d(400, 600);
  SDL_Rect r {location.X, location.Y, 80, 10};
  _rect = std::make_shared<SDL_Rect>(std::move(r));
  bbox = _rect;
}

Racket::~Racket() {}

void Racket::Update(){
  _rect->x = location.X; //this is updated by the controller
  _rect->y = location.Y;
}

void Racket::Draw(Renderer &renderer) {
  SDL_SetRenderDrawColor(renderer.sdl_renderer, 10, 12, 100, 0xFF);
  SDL_RenderFillRect(renderer.sdl_renderer, _rect.get());
}
