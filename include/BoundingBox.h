#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <vector>
#include <SDL.h>

struct Vector2d {
  int X{0};
  int Y{0};
};

class BoundingBox {
public:
  BoundingBox();
  ~BoundingBox();
  BoundingBox* DetectCollision(const std::vector<BoundingBox*> &others_list);
  Vector2d collisionNormal;
  SDL_Rect bbox;
private:
  bool Overlaps(const BoundingBox *other);
  void SetNormalVector(int &x_overlap, int &y_overlap);
};

#endif