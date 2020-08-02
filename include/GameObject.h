#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Renderer.h"
#include "Vector2d.h"

/*
Base class that specifes interface for game objects
All registered gameObjects' Update() and Draw() methods are called 
by the game engine according to the set frame rate requirement.
*/

class GameObject {
public:
  GameObject() {};
  GameObject(int id) {};
  virtual ~GameObject() {};
  virtual void Update() = 0;                    // Called once in every cycle
  virtual void Draw(Renderer &renderer) = 0;    // Called once in every cycle - implement rendering here
  int id;                                       // not used, may be useful for lookup
  Vector2d<int> location;                       // Location of game object
  Vector2d<int> speed;                          // Speed of game object. Not linked to location
};

#endif