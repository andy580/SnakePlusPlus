#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "mapParser.h"
#include "SDL.h"
#include <iostream>

class environment {
    
    public:
        environment() {
            std::cout << "\nEnvironment constructor called\n";
            map userInput;
            populateWall(userInput);
            windowDim = {userInput.userWidth, userInput.userHeight, userInput.gridWidth, userInput.gridHeight};
        }
        void populateWall(map &specs); 

        std::vector<SDL_Point> wallPoints;
        std::vector<int> windowDim; 

    private:
         
         SDL_Point point; 
        //  Origin pt for wall + deltas
         int ox=0, oy=0, dx =0, dy =0; 

};


#endif