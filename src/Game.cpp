#include <iostream>
#include <thread>
#include <algorithm>

#include "GameObject.h"
#include "Racket.h"
#include "Game.h"



Game::Game(size_t kGridWidth, size_t kGridHeight, Renderer &renderer) : _renderer(renderer)
{
}
void Game::update() {}

void Game::RegisterGameObject(GameObject *gObject){
  this->gameObjects.emplace_back(gObject);
}

void Game::run(Renderer &renderer, std::size_t target_frame_duration) {
  SDL_Event window_event;
  Racket *racket = new Racket();
  RegisterGameObject(racket);

  while(true) {
    //std::for_each(begin(gameObjects), end(gameObjects), [](GameObject &gObj){gObj.Update();});
    this->draw();
    if (SDL_PollEvent( &window_event )){
      if (SDL_QUIT == window_event.type){
        break;
      }
    }
  }
  delete racket;
    
}
void Game::draw() {
    SDL_SetRenderDrawColor(_renderer.sdl_renderer, 100, 149, 0, 255);
    SDL_RenderClear(_renderer.sdl_renderer);
    std::for_each(begin(gameObjects), end(gameObjects), [this](GameObject *gObj){gObj->Draw(_renderer);});
    SDL_RenderPresent(_renderer.sdl_renderer);
    SDL_Delay(100);
}

Game::~Game()
{
}