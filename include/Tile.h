#ifndef TILE_H
#define TILE_H

#include "BoundingBox.h"
#include "GameObject.h"

class Tile : public BoundingBox, public GameObject {
  public:
    Tile(int id, SDL_Rect r);
    ~Tile();
    void Update() override;
    static std::vector<std::shared_ptr<Tile>> MakeTilesList();
    void Draw(Renderer &renderer) override;
    bool isAlive{true};

  private:
    std::shared_ptr<SDL_Rect> _rect;
};

#endif