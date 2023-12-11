#include "game.h"
#include "filewrite.h"
#include <iostream>
#include <memory>
#include "SDL.h"
#include <algorithm>
#include "poison.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
  PlacePowerup();
}


void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 poison_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  int frame_count_poison = 0;
  bool running = true;

  Print("Player1");

  

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, powerup, _poisons);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

  if (frame_end - poison_timestamp >= 8000) {
      std::shared_ptr<Poison> pp = std::make_unique<Poison>();
      AddPoison(pp);
      frame_count_poison = 0;
      poison_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::doWork() {
  std::cout << "Thread is running" << "\n";
  invulnerable = true;
  std::this_thread::sleep_for(std::chrono::seconds(10));
  
  {
  std::unique_lock<std::mutex> lock(mtx);
  cv.wait_for(lock, std::chrono::seconds(10), [this]{ return condition; });
  condition = true;

  }
        std::cout << "Work is done!" << std::endl;
      PlacePowerup();
      
  
  invulnerable=false;
  cv.notify_one();
  }

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::PlacePowerup() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      powerup.x = x;
      powerup.y = y;
      return;
    }
  }
}



  void Game::AddPoison(std::shared_ptr<Poison> poison) {
      //std::lock_guard<std::mutex> lock(mtx);
      _poisons.push_back(poison);

  }

  


void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);
  //std::lock_guard<std::mutex> lock(mtx);
  
  for (auto point : _poisons) {
    
    auto p = (*point).GetPoint();

    if (p.x == new_x && p.y == new_y) {
      File file("score.txt");
      if (invulnerable==false) {
        score--;

        auto y = find(_poisons.begin(), _poisons.end(), point) - _poisons.begin();
        _poisons.erase(_poisons.begin() + y);
        snake.speed += 0.05;
        
        return;
      } else {
        score++;
        auto y = find(_poisons.begin(), _poisons.end(), point) - _poisons.begin();
        _poisons.erase(_poisons.begin() + y);
      }
      file.write(score, snake.size,"Player1");
    }

  }
  
  

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    File file("score.txt");
    score++;
    PlaceFood();
    Print(score);
    file.write(score, snake.size,"Player1");
    // Grow snake and increase speed.
    snake.GrowBody();
    if (snake.speed<0) {
      snake.speed = 0.08;
    } else {
      snake.speed+=0.02;
    }
  }

  if (powerup.x == new_x && powerup.y == new_y) {
    //doWork();
      invulnerable = true;
      condition = false;
      powerup.x=1000000;
      powerup.y=1000000;
      std::thread t1([this] {doWork();});
      t1.detach();
      


  }


}



int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }