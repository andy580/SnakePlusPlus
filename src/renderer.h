#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"

#include "environment.h"
#include "snakeEater.h"

class Renderer {
 public:
  Renderer(environment &userSpec);

  ~Renderer();

  void pointsToBlocks();
  void Render(Snake const snake, snakeEater const eater, SDL_Point const &food);
  void UpdateWindowTitle(int score, int fps);

  

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  std::vector<SDL_Point> *userWallPoints;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif