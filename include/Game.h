#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Renderer.h"
#include "GameObject.h"
#include "Racket.h"
#include "Controller.h"
#include "Ball.h"
#include "Tile.h"
/* 
This is the main engine. 
Update() and Draw() are called periodically according to the set 
framerate
*/

class Game {  
public:
  /* 
  Initialize and register GameObjects here
  */
  Game(Renderer &renderer);
  ~Game();
  /*
  The game loop is implemented here. returns when the main loop exits
  */
  void Run(std::size_t target_frame_duration);
  /*
  Add GameObjects to the game
  */
  void RegisterGameObject(std::shared_ptr<GameObject> gObject);
  /*
  Reads user inputs
  */
  void ReadInput();

private:
  void Update();
  void Draw();                                           // Calls GameObject.Draw + rendering
  std::vector<std::shared_ptr<GameObject>> gameObjects;  // Holds the game objects
  Renderer &_renderer;                                   // Wrapper around SDL's renderer
  bool running{true};
  std::shared_ptr<Racket> racket;                         // The racket which implements GameObject and BoundingBox
  Controller controller;                                  // Handles user input
  std::shared_ptr<Ball> ball;                             // The ball which implements GameObject and BoundingBox
  std::vector<std::shared_ptr<Tile>> tiles;               // The tile list which implements GameObject and BoundingBox
};

#endif