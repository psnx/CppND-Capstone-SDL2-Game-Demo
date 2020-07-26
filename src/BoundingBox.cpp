#include "BoundingBox.h"

BoundingBox* BoundingBox::DetectCollision(std::vector<BoundingBox*> others_list){
  for (auto bb : others_list){
    if (Overlaps(bb)) return bb; 
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
bool BoundingBox::Overlaps(BoundingBox *other){
  // Overlap on X
  int thisTopRightX = this->topLeftCorner.X + this->width;
  int otherTopRightX = other->topLeftCorner.X + other->width;
  int extremeRightX= std::max(thisTopRightX, otherTopRightX);
  int extremeLeftX = std::min(this->topLeftCorner.X, other->topLeftCorner.X);
  bool overlapsOnX =  other->width + this->width > extremeRightX-extremeLeftX;

  // Overlap on Y
  int thisDownY = this->topLeftCorner.Y + this->height;
  int otherDownY = other->topLeftCorner.Y + other->height;
  int extremeUpY= std::min(thisDownY, otherDownY);
  int extremeDownY = std::max(this->topLeftCorner.Y, other->topLeftCorner.Y);

  bool overlapsOnY = other->height + this->height > extremeDownY-extremeUpY;
  return overlapsOnY && overlapsOnX;

}