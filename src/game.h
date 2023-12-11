#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include <memory>
#include <condition_variable>
#include <thread>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "poison.h"
#include "worker.h"



class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
    //Help from Udacity GPT
  void Print(const char* str) {
    std::cout << "Player is: " << str << "\n";
  }
  void Print(int score) {
    std::cout << "Current Score is: " << score << "\n";
  }
  void doWork();



 private:
  Snake snake;
  Worker worker;
  SDL_Point food;
  SDL_Point powerup;
  std::vector<std::shared_ptr<Poison>>  _poisons;
    bool condition = false;
    bool flag = true;
  std::mutex mtx;
  std::condition_variable cv;
  //std::vector<std::unique_ptr<SDL_Point>> powerups;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
  bool invulnerable = false;

  void PlaceFood();
  void PlacePowerup();
  void AddPoison(std::shared_ptr<Poison> poison);
  void Update();

};

#endif