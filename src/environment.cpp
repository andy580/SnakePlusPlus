#include "environment.h"

void environment::populateWall(map &specs) {
    int row = specs.walls.size();
    int col = specs.walls[0].size();

    for (int i =0; i<row; i++){
        ox = specs.walls[i][0];
        oy = specs.walls[i][1];
        
        for (int j=0; j<=specs.walls[i][2]+0; j++){
            dx = ox + j;

            for (int k=0; k<=specs.walls[i][3]+0; k++){
                dy = oy+k;
                point.x = dx;
                point.y = dy;
                wallPoints.push_back(point);             
            }
        }
              
    }
}
