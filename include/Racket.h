#ifndef RACKET_H
#define RACKET_H

#include "GameObject.h"
#include "Renderer.h"

class Racket : public GameObject {
public:
  Racket();
  ~Racket() override;
  void Update() override;
  void Draw(Renderer &renderer) override;
  Transform transform;
};

#endif