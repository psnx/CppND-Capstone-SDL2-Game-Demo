#include <iostream>
#include <thread>
#include <future>
#include <algorithm>
#include "GameObject.h"
#include "Racket.h"
#include "Game.h"
#include "Controller.h"
#include "Ball.h"

Game::Game(size_t kGridWidth, size_t kGridHeight, Renderer &renderer) : _renderer(renderer){
  racket = std::make_shared<Racket>(Racket(1));
  RegisterGameObject(racket);
  controller.SetContext(&running, std::static_pointer_cast<GameObject> (racket));

  ball = std::make_shared<Ball>(Ball(2));
  RegisterGameObject(ball);
}

void Game::Update() {
  std::for_each(begin(gameObjects), end(gameObjects), [this](std::shared_ptr<GameObject> &gObj){gObj->Update();});  
}

void Game::RegisterGameObject(std::shared_ptr<GameObject> gObject){
  this->gameObjects.emplace_back(gObject);
} 

void Game::Run(std::size_t target_frame_duration) {
  int i = 0;
  while(running) {
    controller.ReadInput();
    this->Update();
    this->Draw();
    SDL_Delay(1);
  }
}

void Game::Draw() {
    SDL_SetRenderDrawColor(_renderer.sdl_renderer, 100, 149, 0, 255);
    SDL_RenderClear(_renderer.sdl_renderer);
    std::for_each(begin(gameObjects), end(gameObjects), [this](std::shared_ptr<GameObject>& gObj){gObj->Draw(_renderer);});
    SDL_RenderPresent(_renderer.sdl_renderer);
}

Game::~Game()
{
}