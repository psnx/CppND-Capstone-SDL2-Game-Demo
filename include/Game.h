#ifndef GAME_H
#define GAME_H

#include "Renderer.h"

class Game {  
public:
    Game(size_t kGridWidth, size_t kGridHeight);
    void run(Renderer &renderer, std::size_t target_frame_duration);
    ~Game();

private:
    void update();
};




#endif