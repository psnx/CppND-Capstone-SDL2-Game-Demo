#include <SDL.h>
#include "Ball.h"
#include <iostream>
#include "Vector2d.h"

Ball::Ball(int id){
  this->id = id;
  location = Vector2d(100, 200);
  speed = Vector2d(1,1);
  _rect = std::make_shared<SDL_Rect>();
  _rect->x = location.X;
  _rect->y = location.Y;  
  _rect->h = 10;
  _rect->w = 10;
  bbox = _rect; 
}

void Ball::AddToCollisionWatchList(std::shared_ptr<BoundingBox> boundingBox){
  _collisionWatchList.emplace_back(boundingBox);
}
void Ball::MoveToCollisionWatchList(std::shared_ptr<BoundingBox> &&boundingBox){
  _collisionWatchList.emplace_back(std::move(boundingBox));
}

void Ball::CalculateBounceBackSpeedVector(Vector2d<int> &collisionNormal, Vector2d<int> &speed){
    //R = L-2(N*L)N
    //speed = speed - collisionNormal.Scale(2*(collisionNormal * speed));
    
    const int &ny = collisionNormal.Y;
    const int &nx = collisionNormal.X;
    const int dotproduct = 2*(nx*speed.X + ny*speed.Y);
    speed.X = speed.X-dotproduct*nx;
    speed.Y = speed.Y-dotproduct*ny;
    
}

void Ball::Update(){
  std::cout << "Ball location x: " << speed.X << " y:" << speed.Y << std::endl;
  auto other = DetectCollision(_collisionWatchList);
  if (other !=  nullptr){
    std::cout << "COLL \n";
    /* 
    Light ray mirror reflection equation to simulate bounce back 
    R = 2(N*L)N-L
    where N is the surface normal and L is the speed vector of the ball
    */
    CalculateBounceBackSpeedVector(collisionNormal, speed); 
    
  }
  
  location += speed;
  if (this->location.X == 2 or location.X == 598) speed.X *= -1;
  if (this->location.Y == 2) speed.Y *= -1;
  _rect->x = location.X;
  _rect->y = location.Y;
}

void Ball::Draw(Renderer &renderer){
  _renderer = &renderer;
  SDL_SetRenderDrawColor(_renderer->sdl_renderer, 10, 12, 100, 0xFF);
  SDL_RenderFillRect(renderer.sdl_renderer, _rect.get());
}

Ball::~Ball(){}
