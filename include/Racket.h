#ifndef RACKET_H
#define RACKET_H

#include "GameObject.h"
#include "Renderer.h"
#include "BoundingBox.h"

/*
The racket that reacts to user input, racts to collision and
Updated / Drawn by the Game
*/

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