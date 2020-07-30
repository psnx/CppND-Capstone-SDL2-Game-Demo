#ifndef RACKET_H
#define RACKET_H

#include "GameObject.h"
#include "Renderer.h"
#include "BoundingBox.h"

class Racket : public GameObject, public BoundingBox {
public:
  Racket(int id);
  ~Racket() override;
  void Update() override;
  void Draw(Renderer &renderer) override;
private:
  std::shared_ptr<SDL_Rect> _rect;
};

#endif