#include "BoundingBox.h"
#include <iostream>

BoundingBox::BoundingBox(){}
BoundingBox::~BoundingBox(){}
std::shared_ptr<BoundingBox> BoundingBox::DetectCollision(const std::vector<std::shared_ptr<BoundingBox>> others_list){
  for (auto bb : others_list){
    //function takes const so using the raw pointer should be OK...
    if (Overlaps(bb.get())) {
      //std::cout << "Collision Detected \n";
      bb->collisionFlag = true;
      return bb; 
    }
  }
  return nullptr;
}

/* Detects collison on each axis
if there is an overlap on both axes there is a collision
It calculates the extremes (points furthest apart) on each axis and cheks
if the summed lenght of the corresponging sides is enough to cover the distance inbetween.
if yes for both X and Y dimensions it returns true, othervise false.
Follows SDL convention (topleft is origin)
*/
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
    //hit from above - this should not work yet it does. bug?
    this->collisionNormal.Y = -1;
    this->collisionNormal.X = 0;
  }
  this->collisionNormal.Y = 1;
  this->collisionNormal.X = 0;
}



