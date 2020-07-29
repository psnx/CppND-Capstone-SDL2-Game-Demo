#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <vector>

struct Point {
  int X{0};
  int Y{0};
};

class BoundingBox {
public:
  BoundingBox();
  ~BoundingBox();
  BoundingBox* DetectCollision(const std::vector<BoundingBox*> &others_list);
  Point topLeftCorner;
  Point collisionNormal;
  int height{0};
  int width{0};
private:
  bool Overlaps(const BoundingBox *other);
  void SetNormalVector(int &x_overlap, int &y_overlap);
};

#endif