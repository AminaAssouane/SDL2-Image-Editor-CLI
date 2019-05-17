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

int coller(SDL_Window *window, Selection* region, char* x, char *y, char *myl, char* myh){

  if (region->copy == 0){
    printf("\nAucune region copiee.");
    return 0;
  }
  else {
    SDL_Rect dst;
    dst.x = atoi(x);
    dst.y = atoi(y);
    dst.w = atoi(myl);
    dst.h = atoi(myh);
    SDL_BlitSurface(SDL_GetWindowSurface(region->window),region->rect,SDL_GetWindowSurface(window),&dst);
    SDL_UpdateWindowSurface(window);
    region->copy = 0;
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
    SDL_Surface *surface = SDL_GetWindowSurface(
    SDL_FillSurface(SDL_GetWindowSurface(region->window),region->rect, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(region->window);
    return 1;
  }
}

 
