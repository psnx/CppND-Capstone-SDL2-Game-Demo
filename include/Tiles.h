#ifndef TILES_H
#define TILES_H

#include <vector>
#include <SDL.h>
#include "GameObject.h"

class Tiles : public GameObject {
  public:
    Tiles(int id);
    ~Tiles() override;
    void Update() override;
    void Draw(Renderer &renderer) override;
  private:
    void DrawMatrix();
    std::vector<std::vector<int>> tilesMatrix;
    int rows{3};
    int columns{10};
    std::vector<SDL_Rect> tilesList;
    
};

#endif