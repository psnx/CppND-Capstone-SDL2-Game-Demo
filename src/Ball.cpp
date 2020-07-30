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

void Ball::AddToCollisionWatchList(BoundingBox *boundingBox){
  _collisionWatchList.emplace_back(boundingBox);
}

void Ball::Update(){
  auto other = DetectCollision(_collisionWatchList);
  if (other !=  nullptr){
    /* 
    Light ray mirror reflection equation to simulate bounce back 
    R = 2(N*L)N-L
    where N is the surface normal and L is the speed vector of the ball
    */
    std::cout << "collsion" << std::endl;
    const int &nx = collisionNormal.X;
    const int &ny = collisionNormal.Y;
    const int dotproduct = 2*(nx*transform.v_x + ny*transform.v_y);
    this->transform.v_x = dotproduct*nx-transform.v_x;
    this->transform.v_y = dotproduct*ny-transform.v_y;

  }

  if (this->transform.x == 2 or transform.x == 598) transform.v_x *= -1;
  if (this->transform.y == 2) transform.v_y *= -1;
  transform.x += transform.v_x;
  transform.y += transform.v_y;
  topLeftCorner.X = transform.x;
  topLeftCorner.Y = transform.y;
}

void Ball::Draw(Renderer &renderer){
  _renderer = &renderer;
  SDL_SetRenderDrawColor(_renderer->sdl_renderer, 10, 12, 100, 0xFF);
  _rect.x = transform.x;
  _rect.y = transform.y;
  SDL_RenderFillRect(renderer.sdl_renderer, &_rect);
}

Ball::~Ball(){
  _renderer = nullptr;
}