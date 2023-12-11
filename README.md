# CPPND: Capstone Snake Game Example

This is my attempt to build on a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The original code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg


## New Features

The new features of the game include poison and powerup blocks. Every 10 seconds a new poision block is added to the game. When the snake eats a poison block the score is decreased by 1. The powerup block is used to turn the poison blocks into food blocks for 10 seconds.

## Rubric Points Addresses

### Loops, Functions, I/O

- [x] This project demonstrates an understanding of C++ functions and control structures
  - [x] In game.cpp lines 132 to 136
- [x] This project uses data structures and immutable variables
  - [x] Vectors are used in game.h on lines 27 and 28
- [x] This program writes to a data file.
  - [x] filewrite.h

### Object Oriented Programming

- [x] Class contructors utilize member initialization lists
  - [x] In poison.h starting with line 10
- [x] One function in overloaded with different signatures for the same function name
  - [x] In game.cpp lines 132 and 31
- [x] One or more classes are added to the project with appropriate access specifiers
  - [x] poison.h and filewrite.h

### Memory Management

- [x] This project makes use of references
  - [x] filewrite.h line 10 and line 21
- [x] This project uses destructors appropriately
  - [x] In renderer.cpp line 36 and filewrite.h line 16
- [x] This project uses smart pointers instead of raw pointers
  - [x] Shared pointer is used in game.cpp line 54

### Concurrency

- [x] A mutex or lock is used in the project
  - [x] In game.cpp line 78
- [x] A condition variable is used in the project
  - [x] In game.cpp lines 9
