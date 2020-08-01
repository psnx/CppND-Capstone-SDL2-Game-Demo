#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Renderer.h"
#include "Vector2d.h"

class GameObject {
public:
  GameObject() {};
  GameObject(int id) {};
  virtual ~GameObject() {};
  virtual void Update() = 0;
  virtual void Draw(Renderer &renderer) = 0;
  int id;
  Vector2d<int> location;
  Vector2d<int> speed;

};

#endif