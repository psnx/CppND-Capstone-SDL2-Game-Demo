#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Renderer.h"
#include "GameObject.h"
#include "Racket.h"

class Game {  
public:
  Game(size_t kGridWidth, size_t kGridHeight, Renderer &renderer);
  void Run(std::size_t target_frame_duration);
  void RegisterGameObject(std::unique_ptr<GameObject> &&gObject);
  ~Game();

private:
  void ReadInput();
  void Update();
  void Draw();
  std::vector<std::unique_ptr<GameObject>> gameObjects;
  Renderer &_renderer;
  bool running{true};
};

#endif