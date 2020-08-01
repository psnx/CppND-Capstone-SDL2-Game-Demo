#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <vector>
#include <SDL.h>

template<class T>
struct Vector2d {
  T X{0};
  T Y{0};
  static T DotProduct (const Vector2d one, const Vector2d two){
    return (one.X * two.X + one.Y * two.Y);
  }
};

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