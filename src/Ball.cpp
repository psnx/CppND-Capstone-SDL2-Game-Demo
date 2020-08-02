#include <SDL.h>
#include <iostream>
#include "Ball.h"

Ball::Ball(int id, bool *running) : _running(running){
  location = Vector2d(100, 200);
  speed = Vector2d(3,3);
  SDL_Rect r {location.X, location.Y, 10, 10};
  _rect = std::make_shared<SDL_Rect>(std::move(r));
  bbox = _rect; 
}

void Ball::AddToCollisionWatchList(std::shared_ptr<BoundingBox> boundingBox){
  _collisionWatchList.emplace_back(boundingBox);
}

void Ball::MoveToCollisionWatchList(std::shared_ptr<BoundingBox> &&boundingBox){
  _collisionWatchList.emplace_back(std::move(boundingBox));
}

void Ball::CalculateBounceBackSpeedVector(Vector2d<int> &collisionNormal, Vector2d<int> &speed){
  speed -= collisionNormal.Scale(2*(collisionNormal * speed));
}

void Ball::Update(){
  auto other = DetectCollision(_collisionWatchList);
  if (other !=  nullptr){
    CalculateBounceBackSpeedVector(collisionNormal, speed); 
  }
  
  location += speed;
  if (this->location.X <= 2 or location.X >= 598) speed.X *= -1;
  if (this->location.Y <= 2) speed.Y *= -1;
  if (this->location.Y >= 800) *_running = false;
  _rect->x = location.X;
  _rect->y = location.Y;
}

void Ball::Draw(Renderer &renderer){
  _renderer = &renderer;
  SDL_SetRenderDrawColor(_renderer->sdl_renderer, 10, 12, 100, 0xFF);
  SDL_RenderFillRect(renderer.sdl_renderer, _rect.get());
}

Ball::~Ball(){}
