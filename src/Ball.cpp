#include <SDL.h>
#include "Ball.h"

Ball::Ball(int id){
  this->id = id;
  transform.x = 100;
  transform.y = 100;
}

void Ball::Update(){
    transform.x += 1;
    transform.y += 1;

}

void Ball::DrawCircle(int center_x, int center_y, int r){
  int r2 = r*r;
  int x{0};
  SDL_SetRenderDrawColor(_renderer->sdl_renderer, 10,10,10,10);
  for (int x = 0; x < r; x++){
    int y = (int)sqrt(r2-(x*x));
    SDL_RenderDrawPoint(_renderer->sdl_renderer, center_x-x, center_x+y);
    SDL_RenderDrawPoint(_renderer->sdl_renderer, center_x+x, center_x+y);
    SDL_RenderDrawPoint(_renderer->sdl_renderer, center_x-x, center_x-y);
    SDL_RenderDrawPoint(_renderer->sdl_renderer, center_x+x, center_x-y);
  }
}

void Ball::Draw(Renderer &renderer){
  _renderer = &renderer;
  SDL_SetRenderDrawColor(_renderer->sdl_renderer, 10, 12, 100, 0xFF);
  DrawCircle(transform.x, transform.y, 10);
}

Ball::~Ball(){
  _renderer = nullptr;
}