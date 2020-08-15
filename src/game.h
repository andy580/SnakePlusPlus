#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(environment &userSpec);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration, environment &userSpec);
  int GetScore() const;
  int GetSize() const;

  bool wallCell(int x, int y, environment &userSpec);


 private:
  Snake snake;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood(environment &userSpec);
  void Update(environment &userSpec);

  
};

#endif