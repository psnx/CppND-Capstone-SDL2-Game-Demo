#include "BoundingBox.h"
#include <iostream>

BoundingBox::BoundingBox(){}
BoundingBox::~BoundingBox(){}

BoundingBox* BoundingBox::DetectCollision(const std::vector<BoundingBox*> &others_list){
  for (auto bb : others_list){
    if (Overlaps(bb)) {
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
  int thisTopRightX = this->topLeftCorner.X + this->width;
  int otherTopRightX = other->topLeftCorner.X + other->width;
  int extremeRightX= std::max(thisTopRightX, otherTopRightX);
  int extremeLeftX = std::min(this->topLeftCorner.X, other->topLeftCorner.X);
  bool overlapsOnX =  other->width + this->width > extremeRightX-extremeLeftX;

  // Overlap on Y
  int thisBottomY = this->topLeftCorner.Y + this->height;
  int otherBottomY = other->topLeftCorner.Y + other->height;
  int extremeUpY= std::min(thisBottomY, otherBottomY);
  int extremeBottomY = std::max(this->topLeftCorner.Y, other->topLeftCorner.Y);

  bool overlapsOnY = other->height + this->height > extremeBottomY-extremeUpY;

  if (overlapsOnY && overlapsOnX){
    int x_overlap = other->height + this->height - (extremeBottomY-extremeUpY);
    int y_overlap = other->width + this->width - (extremeRightX-extremeLeftX);
    SetNormalVector(x_overlap, y_overlap);
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



