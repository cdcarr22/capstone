#ifndef POISON_H
#define POISON_H

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include "SDL.h"

class Poison {
 public:
  Poison() : engine(dev()),
      random_w(0, static_cast<int>(32 - 1)),
      random_h(0, static_cast<int>(32 - 1)) {
    int x, y;
    SDL_Point point;
    x = random_w(engine);
    y = random_h(engine);
    point.x = x;
    point.y = y;
    _point = point;
      
    
  };
    SDL_Point GetPoint() { return _point; }


 

 private:


  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  SDL_Point _point;


};

#endif