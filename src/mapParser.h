#ifndef MAPPARSER_H
#define MAPPARSER_H


#include <vector>
#include <string>
#include <iostream>

template <typename inputCheck>
inputCheck frameDim (inputCheck userInput) {
    if (userInput < 100 || userInput > 2000)
    {
        std::cout << "Incorrect dimension input, default dimension 640 used\n"; 
        return 640;
    } else 
        return userInput;   
};


class map {

public:
    void readMap();
    void renderMap(); 
    
    
private:
    int userWidth =0;
    int userHeight =0; 
    std::vector<int> walls; 
    std::string filename = "/home/andy/workspace/SnakePlusPlus/src/setup.txt";
};

#endif