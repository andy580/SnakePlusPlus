#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "mapParser.h"
#include "SDL.h"
#include <iostream>

class environment : public map {
    
    public:
        environment() {
            std::cout << "\nEnvironment constructor called\n";
            populateWall();

        }
        void populateWall(); 

        std::vector<SDL_Point> wallPoints;

    private:
         
         SDL_Point point; 
        //  Origin pt for wall + deltas
         int ox=0, oy=0, dx =0, dy =0; 

};


#endif