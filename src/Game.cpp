#include <iostream>
#include <thread>
#include <algorithm>

#include "GameObject.h"
#include "Racket.h"
#include "Game.h"



Game::Game(size_t kGridWidth, size_t kGridHeight)
{
}
void Game::update(){

}

void Game::RegisterGameObject(GameObject *gObject){
  this->gameObjects.emplace_back(gObject);
}

void Game::run(Renderer &renderer, std::size_t target_frame_duration){
  SDL_Event window_event;
  Racket *racket = new Racket();
  RegisterGameObject(racket);

  while(true) {
      //std::for_each(begin(gameObjects), end(gameObjects), [](GameObject &gObj){gObj.Update();});
      std::for_each(begin(gameObjects), end(gameObjects), [&renderer](GameObject *gObj){gObj->Draw(renderer);});
    
    if (SDL_PollEvent( &window_event )){
      if (SDL_QUIT == window_event.type){
        break;
      }
    }
    SDL_Delay(100);

  }
  renderer.draw();
  delete racket;
    
}

Game::~Game()
{
}