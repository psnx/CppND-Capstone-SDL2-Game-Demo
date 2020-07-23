#include "Tiles.h"
#include "Renderer.h"

Tiles::Tiles(int id){
  tilesMatrix = new std::vector<std::vector<int>>();
  
}

void Tiles::Update(){

}

void Tiles::Draw(Renderer &renderer){

}

Tiles::~Tiles(){
  delete tilesMatrix;
}