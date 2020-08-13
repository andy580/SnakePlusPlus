#include "mapParser.h"

#include <fstream>
#include <sstream>
#include <iostream>




void map::readMap() {
    std::string line, key, value; 
    std::ifstream filestream(map::filename);

    if (!filestream.is_open())
        std::cout << "setup file not found\n";
    else {
        while(std::getline(filestream, line)) 
        {
            std::istringstream linestream(line);
            linestream >> key >> value;

            if (key == "Height:")
                map::userHeight = frameDim<int>(std::stoi(value));
            else if (key == "Width:")
                map::userWidth = frameDim<int>(std::stoi(value));
            else if (key == "Wall:")
            {
                std::string value2, value3, value4;
                
                linestream >> value2 >> value3 >> value4;
                std::vector<int> wall = {std::stoi(value), std::stoi(value2), std::stoi(value3), std::stoi(value4)};
                map::walls.push_back(wall);
                std::cout << value << " " << value2 << " " << value3 << " " << value4 << "\n";
            }
        }
    
    map::gridHeight = int(map::userHeight/20)-1;
    map::gridWidth = int(map::userWidth/20)-1;

    std::cout << "height: " << map::userHeight << "\nwidth: " << map::userWidth << "\n";
    for (int i=0; i<2; i++)
        for (int j=0; j<4; j++)
            std::cout << "i: " << i << " j: " << j <<  " " << map::walls[i][j] << "\n";
    }
}