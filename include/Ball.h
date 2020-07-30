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
  Renderer *_renderer;
  std::shared_ptr<SDL_Rect> _rect;
  std::vector<BoundingBox *> _collisionWatchList;
};

#endif