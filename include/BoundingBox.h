#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <vector>
#include <SDL.h>

#include "Vector2d.h"

class BoundingBox {
public:
  BoundingBox();
  ~BoundingBox();

  std::shared_ptr<BoundingBox> DetectCollision(const std::vector<std::shared_ptr<BoundingBox>> others_list);
  Vector2d<int> collisionNormal;
  std::shared_ptr<SDL_Rect> bbox;
  bool collisionFlag{false};
private:
  bool Overlaps(const BoundingBox *other);
  void SetNormalVector(const BoundingBox *other);
};

#endif