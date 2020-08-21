# Game Instructions

Before running the game, one can modify the "setup.txt" file to add obstacles (walls) into the game. 
If the snake runs into these walls the game is over. 
Food will not be placed on these walls. 

Once the game begins, the console will ask for adverserial cpu speed.
The adverserial CPU will steal food and reduce score by -1. 
Recommend speed of 0.2. 

Ensure path to "setup.txt" file is correct in file "mapParser.h" Line 38.

# Criteria Met:
- README (ALL)
- Compiles

- Loops / IO: 
  -> External file read in class "mapParser.h" Line 24
  -> User input takein from "main.cpp" Line 22
  -> Variety of control structures and clear organization in classes "mapParser.h", "snakeEater.h", "environment.h"
  
- OOP: 
  -> Project uses OOP techniques in files "mapParser.h", "snakeEater.h", "environment.h"
  -> All class variables in "mapParser.h", "snakeEater.h", "environment.h" are declared as public / private
  -> Overloaded class constructor / function in "snakeEater.cpp" Line 7 
  -> Template used in "mapParser.h" Line 9

- Memory Management:
  -> Function pass by references: 
    --> "Environment.h" Line 17
    --> "Renderer.h" Line 13
    --> "Renderer.h" Line 18
    --> "Game.h" Line 13
    (many more, more than 2 already listed, met requirements)


# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.