#include "BoundingBox.h"
#include <iostream>

BoundingBox::BoundingBox(){}
BoundingBox::~BoundingBox(){}
std::shared_ptr<BoundingBox> BoundingBox::DetectCollision(const std::vector<std::shared_ptr<BoundingBox>> others_list){
  for (auto bb : others_list){
    //function takes const so using the raw pointer should be OK...
    if (Overlaps(bb.get())) {
      bb->collisionFlag = true;
      return bb; 
    }
  }
  return nullptr;
}

bool BoundingBox::Overlaps(const BoundingBox *other){
  SDL_bool overlaps = SDL_HasIntersection(this->bbox.get(), other->bbox.get());
  if (overlaps == SDL_TRUE){
    SetNormalVector(other);
    return true;
  }
  return false;
}

void BoundingBox::SetNormalVector(const BoundingBox *other){
  if (other->bbox->y <= this->bbox->y) {
    this->collisionNormal.Y = -1;
    this->collisionNormal.X = 0;
  }
  this->collisionNormal.Y = 1;
  this->collisionNormal.X = 0;
}



