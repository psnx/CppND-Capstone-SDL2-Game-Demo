#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Renderer.h"
#include "BoundingBox.h"

class Ball : public GameObject, public BoundingBox{
public:
  Ball(int id);
  ~Ball() override;
  void Update() override;
  void Draw(Renderer &renderer) override;
  Transform transform;
  void AddToCollisionWatchList(BoundingBox* boundingBox);
private:
  void DrawCircle(int center_x, int center_y, int r);
  Renderer * _renderer;
  SDL_Rect _rect;
  std::vector<BoundingBox *> _collisionWatchList;
};

#endif