#include <SDL.h>
#include "Ball.h"
#include <iostream>

Ball::Ball(int id){
  this->id = id;
  transform.x = 100;
  transform.y = 100;
  _rect.h = 10;
  _rect.w = 10;
  _rect.x = transform.x;
  _rect.y = transform.y;
  height = 10;
  width = 10;  
  transform.v_x = 1;
  transform.v_y = 1;
  
}

void Ball::AddToCollisionWatchList(BoundingBox * boundingBox){
  _collisionWatchList.emplace_back(boundingBox);
}


void Ball::Update(){

  auto other = DetectCollision(_collisionWatchList);
  if (other !=  nullptr){
    this->transform.v_y = -1;
  }

  if (this->transform.x == 2 or transform.x == 598) transform.v_x *= -1;
  if (this->transform.y == 2) transform.v_y *= -1;
  transform.x += transform.v_x;
  transform.y += transform.v_y;
  topLeftCorner.X = transform.x;
  topLeftCorner.Y = transform.y;
}
/*Not used for the time being */
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
  _rect.x = transform.x;
  _rect.y = transform.y;
  SDL_RenderFillRect(renderer.sdl_renderer, &_rect);
  //DrawCircle(transform.x, transform.y, 10);
}

Ball::~Ball(){
  _renderer = nullptr;
}