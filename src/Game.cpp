#include <iostream>
#include <thread>
#include <future>
#include <algorithm>
#include "Game.h"

Game::Game(Renderer &renderer) : _renderer(renderer){
  racket = std::make_shared<Racket>(Racket(1));
  RegisterGameObject(racket);
  controller.SetContext(&running, std::static_pointer_cast<GameObject> (racket));

  ball = std::make_shared<Ball>(Ball(2, &running));
  RegisterGameObject(ball);
  ball->AddToCollisionWatchList(racket);
  
  tiles = Tile::MakeTilesList();
  for (auto t : tiles){
    RegisterGameObject(t);
    ball->AddToCollisionWatchList(t);
  }
}

void Game::Update() {
  std::for_each(begin(gameObjects), end(gameObjects), [this](std::shared_ptr<GameObject> &gObj){gObj->Update();});  
}

void Game::RegisterGameObject(std::shared_ptr<GameObject> gObject){
  this->gameObjects.emplace_back(gObject);
} 

void Game::Run(std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;

  while(running) {
    frame_start = SDL_GetTicks();
    controller.ReadInput();
    this->Update();
    this->Draw();

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
  std::cout << "----***Game over***----\n";
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