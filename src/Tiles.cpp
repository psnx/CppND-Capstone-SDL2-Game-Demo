#include "Tiles.h"
#include "Renderer.h"
#include <SDL.h>

Tiles::Tiles(int id){
  tilesMatrix.resize( 10, std::vector<int>( 3 , 1 ) );
}

void Tiles::Update(){

}

void Tiles::Draw(Renderer &renderer){
  int height = 10;
  int width = 10;
  for (int i = 0; i<10; i++){
    for (int j = 0; j<5; j++){
      SDL_Rect rect; 
      rect.x = i*60+40;
      rect.y = j*30+20;
      rect.w = 40;
      rect.h = 20;
      SDL_SetRenderDrawColor(renderer.sdl_renderer, 10, 12, 0, 0xFF);
      SDL_RenderFillRect(renderer.sdl_renderer, &rect);
    }
  }
    
 

}

Tiles::~Tiles(){

}