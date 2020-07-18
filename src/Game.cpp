#include <iostream>
#include <thread>
#include <algorithm>
#include "GameObject.h"
#include "Racket.h"
#include "Game.h"

Game::Game(size_t kGridWidth, size_t kGridHeight, Renderer &renderer) : _renderer(renderer){ }

void Game::ReadInput(){
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          auto it = std::find_if(this->gameObjects.begin(), this->gameObjects.end(), 
            [&](std::unique_ptr<GameObject>& gObj){
              return (gObj.get()->id == 1); 
            });
          if (it != gameObjects.end()){
            ((Racket *) it->get())->transform.x += 100;
          }
          break;
      }
    }
  }
}

void Game::Update() {}

void Game::RegisterGameObject(std::unique_ptr<GameObject> &&gObject){
  this->gameObjects.emplace_back(std::move(gObject));
}

void Game::Run(std::size_t target_frame_duration) {
  SDL_Event window_event;
  std::unique_ptr<Racket> racket_ptr = std::make_unique<Racket>(Racket(1));
  RegisterGameObject(std::move(racket_ptr));

  while(running) {
    ReadInput();
    //std::for_each(begin(gameObjects), end(gameObjects), [](GameObject &gObj){gObj.Update();});
    this->Draw();
    if (SDL_PollEvent( &window_event )){
       if (SDL_QUIT == window_event.type || !running){
         break;
       }
     }
  SDL_Delay(10);
  } 
}

void Game::Draw() {
    SDL_SetRenderDrawColor(_renderer.sdl_renderer, 100, 149, 0, 255);
    SDL_RenderClear(_renderer.sdl_renderer);
    std::for_each(begin(gameObjects), end(gameObjects), [this](std::unique_ptr<GameObject>& gObj){gObj->Draw(_renderer);});
    SDL_RenderPresent(_renderer.sdl_renderer);
}

Game::~Game()
{
}