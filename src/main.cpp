#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

#include "mapParser.h"

int main() {
  map userInput;
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  const int kScreenWidth{userInput.userWidth};
  const int kScreenHeight{userInput.userHeight};
  const int kGridWidth{userInput.gridWidth};
  const int kGridHeight{userInput.gridHeight};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);


  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}