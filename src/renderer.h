#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include <memory>
#include "poison.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food, SDL_Point const &powerup, std::vector<std::shared_ptr<Poison>> const _poisons);
  void UpdateWindowTitle(int score, int fps);
  void UpdateTextInput(float sp);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
    SDL_Surface *surface;
          SDL_Surface* background_surface;
    SDL_Texture* background_texture;
    SDL_Renderer* background_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif