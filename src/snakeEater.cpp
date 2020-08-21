#include "snakeEater.h"
#include <math.h>

Thief::Thief() {
    std::cout << "\nSnakeEater class called\n";
}
Thief::Thief(float userSpeed) {
  speed = userSpeed;
}

void Thief::updatePosn(SDL_Point &food) {
    
// Inefficient method to calculate next best move
    dcurr = calcDist(head_x, head_y, food);
    
    dnext = abs(calcDist(head_x+speed, head_y, food));
    if (dnext < dcurr) {
        dcurr = dnext; 
        d = Direction::kRight;
    }
        
    dnext = abs(calcDist(head_x-speed, head_y, food));
    if (dnext < dcurr) {
        dcurr = dnext;
        d = Direction::kLeft;
    }

    dnext = abs(calcDist(head_x, head_y+speed, food));
    if (dnext < dcurr) {
        dcurr = dnext;
        d = Direction::kUp;
    }
        

    dnext = abs(calcDist(head_x, head_y-speed, food));
    if (dnext < dcurr) {
        dcurr = dnext;
        d = Direction::kDown;
    }
        
    switch (d) {
    case Direction::kUp:
      head_y += speed;
      break;

    case Direction::kDown:
      head_y -= speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

    // std::cout << "Head x: " << head_x << " Head y: " << head_y << " distance: " << dcurr << " Dist next: " << dnext << "\n";
}

float Thief::calcDist(float x1, float y1, SDL_Point &food) {
    float x2 = float(food.x);
    float y2 = float(food.y);
    x1 -= x2;
    y1 -= y2;
    float dist = pow((pow(x1,2)+pow(y1,2)), 0.5);
    // std::cout << dist << "\n";
    return dist;
}