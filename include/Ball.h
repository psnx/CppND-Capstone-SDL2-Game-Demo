#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Renderer.h"
#include "BoundingBox.h"
#include "Vector2d.h"

class Ball : public GameObject, public BoundingBox{
public:
  Ball(int id);
  ~Ball() override;
  void Update() override;
  void Draw(Renderer &renderer) override;
  Vector2d<int> location;
  Vector2d<int> speed;
  void AddToCollisionWatchList(std::shared_ptr<BoundingBox> boundingBox);
  void MoveToCollisionWatchList(std::shared_ptr<BoundingBox> &&boundingBox);
private:
  Renderer *_renderer;
  std::shared_ptr<SDL_Rect> _rect;
  std::vector<std::shared_ptr<BoundingBox>> _collisionWatchList;
    /* 
    Light ray mirror reflection equation to simulate bounce back 
    R = L-2(N*L)N
    where N is the surface normal and L is the speed vector of the ball
    */
  void CalculateBounceBackSpeedVector(Vector2d<int> &collisionNormal, Vector2d<int> &speed);
};

#endif