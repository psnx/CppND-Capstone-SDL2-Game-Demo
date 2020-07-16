#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Renderer.h"

struct Transform{
    int x{0};
    int y{0};
};

class GameObject {
public:
  GameObject() {};
  virtual ~GameObject() {};
  virtual void Update() = 0;
  virtual void Draw(Renderer &renderer) = 0;
};

#endif