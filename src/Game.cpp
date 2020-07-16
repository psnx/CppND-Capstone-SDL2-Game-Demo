#include <iostream>
#include <thread>
#include "Game.h"

Game::Game(size_t kGridWidth, size_t kGridHeight)
{
}
void Game::update(){

}
void Game::run(Renderer &renderer, std::size_t target_frame_duration){
    renderer.draw();
    
}

Game::~Game()
{
}