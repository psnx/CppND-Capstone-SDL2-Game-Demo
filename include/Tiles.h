#ifndef TILES_H
#define TILES_H

#include <vector>
#include "GameObject.h"

class Tiles : public GameObject {
  public:
    Tiles(int id);
    ~Tiles() override;
    void Update() override;
    void Draw(Renderer &renderer) override;
    Tiles operator()() = delete;
    Tiles operator=(Tiles &tiles) = delete;
  private:
    void DrawMatrix();
    std::vector<std::vector<int>> *tilesMatrix;
};

#endif