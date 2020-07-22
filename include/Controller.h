#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <memory>

#include "GameObject.h"

class Controller{
public:
  Controller();
  ~Controller();
  void SetContext(bool *running, std::shared_ptr<GameObject> gameObject);
  void ReadInput();
private:
  bool* _running;
  std::shared_ptr<GameObject> _gameObject;
};
#endif