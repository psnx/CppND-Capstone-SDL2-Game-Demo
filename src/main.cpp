#include <iostream>
#include <SDL.h>

#include "Game.h"
#include "Renderer.h"


int main(){
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};
  
  Game game(kGridWidth, kGridHeight);
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  game.run(renderer, kMsPerFrame);
  return 0;
}
