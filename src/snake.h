#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

#include "environment.h"

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(environment &userSpec)
      : grid_width(userSpec.windowDim[2]),
        grid_height(userSpec.windowDim[3]),
        head_x(userSpec.windowDim[2] / 2),
        head_y(userSpec.windowDim[3] / 2) {
            std::cout << "\nSnake constructor called\n";
        }

  void Update(environment &userSpec);

  void GrowBody();
  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell, environment &userSpec);

  bool growing{false};
  int grid_width;
  int grid_height;
};

#endif