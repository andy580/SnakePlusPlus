#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(environment &userSpec, float userSpeed)
    : 
      snake(),
      thief(userSpeed),
      engine(dev()),
      random_w(0, static_cast<int>(userSpec.windowDim[2])),
      random_h(0, static_cast<int>(userSpec.windowDim[3])) {
  PlaceFood();
  std::cout << "\nGame constructor called\n";

  // Reference to wall points from environment object
  userWallPoints = userSpec.wallPoints;
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, thief, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

bool Game::wallCell(int x, int y){
  // std::cout << "Seg Fault here 1?\n";
  for (SDL_Point const pt : userWallPoints){
    // std::cout << "Seg Fault here 2?\n";
    if (pt.x == x && pt.y == y)
      return true;
  }
  return false;
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y) && !Game::wallCell(x,y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
  
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();
  thief.updatePosn(food);

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }

  int thief_x = static_cast<int>(thief.head_x);
  int thief_y = static_cast<int>(thief.head_y);
  if (abs(food.x - thief_x) <1.1 && abs(food.y - thief_y) <1.1) {
    score--;
    PlaceFood();
    // Grow snake and increase speed.
    
  }


}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }