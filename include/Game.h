#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Renderer.h"
#include "GameObject.h"
#include "Racket.h"

class Game {  
public:
  Game(size_t kGridWidth, size_t kGridHeight, Renderer &renderer);
  void run(Renderer &renderer, std::size_t target_frame_duration);
  Racket racket;
  void RegisterGameObject(GameObject *racket);
  ~Game();

private:
  void draw();
  void update();
  std::vector<GameObject *> gameObjects;
  Renderer &_renderer;
};

#endif