/* Module qui contient les fonctions copier, couper, coller */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "Edition.h"

int copier(SDL_Texture* texture){
  if (texture == NULL){
    printf("\nVeuillez d'abord selectionner une region de l'image");
    return 0;
  }
  return 1;
}

int coller(SDL_Window *window, SDL_Texture* texture, char* x, char *y, char *myl, char* myh){
  
  SDL_Renderer* renderer = SDL_GetRenderer(window);
  SDL_Rect* dst = {x, y, myl, myh};
  SDL_RenderCopy(renderer, texture, NULL, dst);
  SDL_RenderPresent(renderer);
  return 1;
}
 
