/*Not used for the time being */
void Ball::DrawCircle(int center_x, int center_y, int r){
  int r2 = r*r;
  int x{0};
  SDL_SetRenderDrawColor(_renderer->sdl_renderer, 10,10,10,10);
  for (int x = 0; x < r; x++){
    int y = (int)sqrt(r2-(x*x));
    SDL_RenderDrawPoint(_renderer->sdl_renderer, center_x-x, center_x+y);
    SDL_RenderDrawPoint(_renderer->sdl_renderer, center_x+x, center_x+y);
    SDL_RenderDrawPoint(_renderer->sdl_renderer, center_x-x, center_x-y);
    SDL_RenderDrawPoint(_renderer->sdl_renderer, center_x+x, center_x-y);
  }
}