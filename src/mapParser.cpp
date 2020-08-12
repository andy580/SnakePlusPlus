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
        }
    
    std::cout << "height: " << map::userHeight << "\nwidth: " << map::userWidth << "\n";
    }
}