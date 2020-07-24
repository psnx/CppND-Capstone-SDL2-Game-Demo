#include "Tiles.h"
#include "Renderer.h"
#include <SDL.h>

Tiles::Tiles(int id){
  tilesMatrix.resize( columns, std::vector<int>( rows , 1 ) );
  tilesMatrix[2][2] = 0;
}

void Tiles::Update(){

}

void Tiles::Draw(Renderer &renderer){
  int height = 10;
  int width = 10;
  for (int i = 0; i<columns; i++){
    for (int j = 0; j<rows; j++){
      SDL_Rect rect; 
      rect.x = i*60+40;
      rect.y = j*30+20;
      rect.w = 40;
      rect.h = 20;
      if (tilesMatrix[i][j]== 1){
        SDL_SetRenderDrawColor(renderer.sdl_renderer, 10, 12, 0, 0xFF);
        SDL_RenderFillRect(renderer.sdl_renderer, &rect);
      }
    }
  }
    
 

}

Tiles::~Tiles(){

}