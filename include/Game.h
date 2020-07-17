#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Renderer.h"
#include "GameObject.h"
#include "Racket.h"

class Game {  
public:
  Game(size_t kGridWidth, size_t kGridHeight, Renderer &renderer);
  void Run(Renderer &renderer, std::size_t target_frame_duration);
  void RegisterGameObject(std::unique_ptr<GameObject> &&gObject);
  ~Game();

private:
  void Draw();
  void Update();
  std::vector<std::unique_ptr<GameObject>> gameObjects;
  Renderer &_renderer;
};

#endif