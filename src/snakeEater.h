#ifndef SNAKEEATER_H
#define SNAKEEATER_H

#include "snake.h"
#include <iostream>
#include "SDL.h"
#include <cmath>


class Thief : public Snake {

public:
    Thief();
    Thief(float userSpeed);
    int posn = 1;
    int posn2 = 1;

    void updatePosn(SDL_Point &food); 
    float calcDist(float x1, float y1, SDL_Point &food); 
    float head_x;
    float head_y;
    



private:
    float speed{0.5f};
    float dcurr;
    float dnext; 
    Direction d;
    
};



#endif
