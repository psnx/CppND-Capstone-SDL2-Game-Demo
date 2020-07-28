#include "Tiles.h"
#include "Renderer.h"
#include <SDL.h>

Tiles::Tiles(int id){
  int columns{10};
  int rows{10};
  int height = 10;
  int width = 10;
  for (int i = 0; i<columns * rows; i++){
    SDL_Rect t = {i/rows*60+40, i%rows *30+20, 40, 20};
    tilesList.emplace_back(std::move(t));
  }
}

void Tiles::Update(){

}

void Tiles::Draw(Renderer &renderer){
  for (const SDL_Rect &rect : tilesList ){
    SDL_SetRenderDrawColor(renderer.sdl_renderer, 10, 12, 0, 0xFF);
    SDL_RenderFillRect(renderer.sdl_renderer, &rect);
  } 
}

Tiles::~Tiles(){

}