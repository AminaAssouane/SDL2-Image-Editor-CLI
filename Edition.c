/* Module qui contient les fonctions copier, couper, coller */

#include "Edition.h"

int copier(SDL_Window* window, Selection* region){
  if (region == NULL){
    printf("\nAucune region selectionnee");
    return 0;
  }
  if (region->selection == 0){
    printf("\nAucune region selectionnee");
    return 0;
  }
  else {
    region->selection = 0;
    region->copy = 1;
    return 1;
  }
}

int coller(SDL_Window *window, Selection* region, char* x, char *y){

  if (region->copy == 0){
    printf("\nAucune region copiee.");
    return 0;
  }
  else {
    SDL_Rect dst;
    dst.x = atoi(x);
    dst.y = atoi(y);
    dst.w = (region->rect)->w;
    dst.h = (region->rect)->h;
    SDL_BlitSurface(SDL_GetWindowSurface(region->window),region->rect,SDL_GetWindowSurface(window),&dst);
    SDL_UpdateWindowSurface(window);
    region->copy = 0;
    printf("\ncopie effectuee");
    return 1;
  }
}

int couper(SDL_Window* window, Selection* region){
  if (region == NULL){
    printf("\nAucune region selectionnee");
    return 0;
  }
  if (region->selection == 0){
    printf("\nAucune region selectionnee");
    return 0;
  }
  else {
    region->selection = 0;
    region->copy = 1;
    SDL_Surface *surface = SDL_GetWindowSurface(region->window);
    SDL_FillRect(surface, region->rect, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));
    SDL_UpdateWindowSurface(region->window);
    return 1;
  }
}

 
