#include <iostream>
#include <thread>
#include <algorithm>
#include "GameObject.h"
#include "Racket.h"
#include "Game.h"

Game::Game(size_t kGridWidth, size_t kGridHeight, Renderer &renderer) : _renderer(renderer){ 
  
}

void Game::ReadInput(){
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_RIGHT:
          racket->transform.x += 10;
          break;
        case SDLK_LEFT:
          racket->transform.x -= 10;   
          break;       
        }  
      }
    }
  }


void Game::Update() {
  std::for_each(begin(gameObjects), end(gameObjects), [this](std::shared_ptr<GameObject> &gObj){gObj->Update();});  
}

void Game::RegisterGameObject(std::shared_ptr<GameObject> gObject){
  this->gameObjects.emplace_back(gObject);
} 

void Game::Run(std::size_t target_frame_duration) {

  racket = std::make_shared<Racket>(Racket(1));
  RegisterGameObject(racket);

  while(running) {
    this->ReadInput();
    this->Update();
    this->Draw();
    SDL_Event window_event;
    if (SDL_PollEvent( &window_event )){
       if (SDL_QUIT == window_event.type){
         running = false;
       }
     }
    SDL_Delay(10);
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