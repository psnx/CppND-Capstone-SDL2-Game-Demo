#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Renderer.h"

class Ball : public GameObject {
public:
  Ball(int id);
  ~Ball() override;
  void Update() override;
  void Draw(Renderer &renderer) override;
  Transform transform;
private:
  void DrawCircle(int center_x, int center_y, int r);
  Renderer * _renderer;
};

#endif