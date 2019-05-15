#ifndef TYPE_H
#define TYPE_H


struct structWindow {
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Surface* surface;
  SDL_Texture* texture;
};
typedef struct structWindow structWindow;


#endif