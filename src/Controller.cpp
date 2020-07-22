#include <SDL.h>
#include <iostream>
#include "Controller.h"

Controller::Controller() : _running{nullptr}, _gameObject(nullptr) {}

void Controller::SetContext(bool *running, std::shared_ptr<GameObject> gameObject) {
  _gameObject = gameObject;
  _gameObject->transform.x = 100;
  _running = running;
}

Controller::~Controller(){
  _running = nullptr;
}

void Controller::ReadInput(){
SDL_Event e;
  while (SDL_PollEvent(&e)) {
    std::cout << "Controller ReadInput in while loop \n";
    if (e.type == SDL_QUIT) {
      *_running = false;

    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_RIGHT:
          _gameObject->transform.x += 10;
          break;
        case SDLK_LEFT:
          _gameObject->transform.x -= 10;   
          break;       
        }  
      }
    }
}