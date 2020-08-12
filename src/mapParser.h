#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <fstream>
#include <sstream>
#include <vector>

class map {

public:
    void readMap();
    void renderMap(); 
    
private:
    int userWidth;
    int userHeight; 
    std::vector<int> walls; 
};

#endif