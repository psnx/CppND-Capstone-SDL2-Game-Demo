#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Renderer.h"
#include "GameObject.h"
#include "Racket.h"
#include "Controller.h"
#include "Ball.h"
#include "Tile.h"

class Game {  
public:
  Game(Renderer &renderer);
  void Run(std::size_t target_frame_duration);
  void RegisterGameObject(std::shared_ptr<GameObject> gObject);
  ~Game();
  void ReadInput();

private:
  void Update();
  void Draw();
  std::vector<std::shared_ptr<GameObject>> gameObjects;
  Renderer &_renderer;
  bool running{true};
  std::shared_ptr<Racket> racket;
  Controller controller;
  std::shared_ptr<Ball> ball;
  std::vector<std::shared_ptr<Tile>> tiles;
};

#endif