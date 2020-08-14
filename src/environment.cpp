#include "environment.h"

void environment::populateWall() {
    int row = map::walls.size();
    int col = map::walls[0].size();

    for (int i =0; i<row; i++){
        ox = walls[i][0];
        oy = walls[i][1];
        
        for (int j=0; j<=walls[i][2]+0; j++){
            dx = ox + j;

            for (int k=0; k<=walls[i][3]+0; k++){
                dy = oy+k;
                point.x = dx;
                point.y = dy;
                wallPoints.push_back(point);             
            }
        }
              
    }
}
