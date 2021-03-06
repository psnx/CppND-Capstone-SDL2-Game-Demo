#include <iostream>
#include <SDL.h>

#include "Game.h"
#include "Renderer.h"


int main(){
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  
  Renderer renderer(kScreenWidth, kScreenHeight);
  Game game(renderer);
  game.Run(kMsPerFrame);
  return 0;
}
