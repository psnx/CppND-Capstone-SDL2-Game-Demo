#include <memory>
#include <vector>
#include <SDL.h>
#include "Tile.h"

Tile::Tile(int id, SDL_Rect r) : _rect(std::make_shared<SDL_Rect>(r)) {
  bbox = _rect;
}

Tile::~Tile(){}
void Tile::Update(){
  if (collisionFlag){
    isAlive = false;
    collisionFlag = false;
    _rect->x=0;
    _rect->y=0;
    _rect->w=0;
    _rect->h=0;    
  }
}

std::vector<std::shared_ptr<Tile>> Tile::MakeTilesList() {
  std::vector<std::shared_ptr<Tile>> _tileList;
  int columns{10};
  int rows{5};
  for (int i = 0; i<columns * rows; i++){
    SDL_Rect _r = {i/rows*60+40, i%rows *30+20, 40, 20};
    std::shared_ptr<Tile> tile = std::make_shared<Tile>(10, std::move(_r));
    _tileList.emplace_back(std::move(tile));
  }
  return _tileList;
}

void Tile::Draw(Renderer &renderer){
    SDL_SetRenderDrawColor(renderer.sdl_renderer, 10, 12, 0, 0xFF);
    if (isAlive) SDL_RenderFillRect(renderer.sdl_renderer, _rect.get());
} 

