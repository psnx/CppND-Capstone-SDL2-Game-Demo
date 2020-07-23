/*
void Game::ReadInput(){
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          auto it = std::find_if(this->gameObjects.begin(), this->gameObjects.end(), 
            [&](std::unique_ptr<GameObject>& gObj){
              return (gObj.get()->id == 1); 
            });
          if (it != gameObjects.end()){
            ((Racket *) it->get())->transform.x += 100;
          }
          break;
      }
    }
  }
}
*/
