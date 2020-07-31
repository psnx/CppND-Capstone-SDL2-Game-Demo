#include "BoundingBox.h"
#include <iostream>

BoundingBox::BoundingBox(){}
BoundingBox::~BoundingBox(){}
std::shared_ptr<BoundingBox> BoundingBox::DetectCollision(const std::vector<std::shared_ptr<BoundingBox>> others_list){
  for (auto bb : others_list){
    //function takes const so using the raw pointer should be OK...
    if (Overlaps(bb.get())) {
      //std::cout << "Collision Detected \n";
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
  // Overlap on X
  /*
  int thisTopRightX = this->bbox->x + this->bbox->w;
  int otherTopRightX = other->bbox->x + other->bbox->w;
  int extremeRightX= std::max(thisTopRightX, otherTopRightX);
  int extremeLeftX = std::min(this->bbox->x, other->bbox->x);
  bool overlapsOnX =  other->bbox->w + this->bbox->w > extremeRightX-extremeLeftX;

  // Overlap on Y
  int thisBottomY = this->bbox->y + this->bbox->h;
  int otherBottomY = other->bbox->y + other->bbox->h;
  int extremeUpY= std::min(thisBottomY, otherBottomY);
  int extremeBottomY = std::max(this->bbox->y, other->bbox->y);
  */

  SDL_bool overlaps = SDL_HasIntersection(this->bbox.get(), other->bbox.get());
  int x{10};
  int y{1};
  if (overlaps == SDL_TRUE){
    //std::cout << "Overlap \n";
    SetNormalVector(x, y);
    return true;
  }
  return false;
}

void BoundingBox::SetNormalVector(int &x_overlap, int &y_overlap){
  if (x_overlap >= y_overlap) {
    //hits the X side
    this->collisionNormal.Y = -1;
    this->collisionNormal.X = 0;
  }
  this->collisionNormal.Y = 0;
  this->collisionNormal.X = -1;
}



