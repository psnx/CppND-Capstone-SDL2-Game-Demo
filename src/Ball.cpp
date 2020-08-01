#include <SDL.h>
#include "Ball.h"
#include <iostream>

Ball::Ball(int id){
  this->id = id;
  transform.x = 100;
  transform.y = 200;
  transform.v_x = 1;
  transform.v_y = 1;
  _rect = std::make_shared<SDL_Rect>();
  _rect->h = 10;
  _rect->w = 10;
  _rect->x = transform.x;
  _rect->y = transform.y;  
  bbox = _rect; 
}

void Ball::AddToCollisionWatchList(std::shared_ptr<BoundingBox> boundingBox){
  _collisionWatchList.emplace_back(boundingBox);
}
void Ball::MoveToCollisionWatchList(std::shared_ptr<BoundingBox> &&boundingBox){
  _collisionWatchList.emplace_back(std::move(boundingBox));
}

void Ball::Update(){
  auto other = DetectCollision(_collisionWatchList);
  if (other !=  nullptr){
    /* 
    Light ray mirror reflection equation to simulate bounce back 
    R = 2(N*L)N-L
    where N is the surface normal and L is the speed vector of the ball
    */
    
    const int &ny = collisionNormal.Y;
    const int &nx = collisionNormal.X;
    const int dotproduct = 2*(nx*transform.v_x + ny*transform.v_y);
    this->transform.v_x = transform.v_x-dotproduct*nx;
    this->transform.v_y = transform.v_y-dotproduct*ny;
  }
  
  transform.x += transform.v_x;
  transform.y += transform.v_y;
  if (this->transform.x == 2 or transform.x == 598) transform.v_x *= -1;
  if (this->transform.y == 2) transform.v_y *= -1;
  _rect->x = transform.x;
  _rect->y = transform.y;
}

void Ball::Draw(Renderer &renderer){
  _renderer = &renderer;
  SDL_SetRenderDrawColor(_renderer->sdl_renderer, 10, 12, 100, 0xFF);
  SDL_RenderFillRect(renderer.sdl_renderer, _rect.get());
}

Ball::~Ball(){}
