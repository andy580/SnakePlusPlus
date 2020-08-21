#ifndef SNAKEEATER_H
#define SNAKEEATER_H

#include "snake.h"
#include <iostream>
#include "SDL.h"
#include <cmath>


class snakeEater : public Snake {

public:
    snakeEater();
    int posn = 1;
    int posn2 = 1;

    void updatePosn(SDL_Point &food); 
    float calcDist(float x1, float y1, SDL_Point &food); 
    float head_x;
    float head_y;
    Direction d;



private:
    float speed{0.2f};
    float dcurr;
    float dnext; 
    
};



#endif
