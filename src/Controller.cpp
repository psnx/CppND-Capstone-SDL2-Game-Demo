#include <SDL.h>
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

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
    if (e.type == SDL_QUIT) {
      *_running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_RIGHT:
          _gameObject->transform.x += 30;
          break;
        case SDLK_LEFT:
          _gameObject->transform.x -= 30;   
          break;       
      }
    }
  }

}