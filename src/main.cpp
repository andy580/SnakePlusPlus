#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

#include "mapParser.h"
#include "environment.h"

int main() {
  environment userDef;

  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  const int kScreenWidth{userDef.windowDim[0]};
  const int kScreenHeight{userDef.windowDim[1]};
  const int kGridWidth{userDef.windowDim[2]};
  const int kGridHeight{userDef.windowDim[3]};

  Renderer renderer(userDef);
  Controller controller;
  Game game(userDef);
  game.Run(controller, renderer, kMsPerFrame);


  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}