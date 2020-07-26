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
  BoundingBox CheckAllForCollision(std::vector<BoundingBox*> others);
  BoundingBox* DetectCollision(std::vector<BoundingBox*> others_list);
private:
  bool Overlaps(BoundingBox *other);
  Point topLeftCorner;
  int height{0};
  int width{0};
};

#endif