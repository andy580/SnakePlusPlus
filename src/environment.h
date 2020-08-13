#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "mapParser.h"
#include "SDL.h"

class environment : public map {
    
    public:
        void populateWall(); 
        void pointsToBlocks();

    private:
         std::vector<SDL_Point> wall;
        //  Origin pt for wall + deltas
         int ox, oy, dx, dy; 

};


#endif