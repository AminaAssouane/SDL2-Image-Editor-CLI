/* Module qui contient les fonctions de sélection de régions */

#include "Selection.h"


void colorSelect(SDL_Renderer *renderer, SDL_Rect *rect){
  assert(SDL_SetRenderDrawColor(renderer,150,0,150,255) >= 0);
  assert(SDL_RenderDrawRect(renderer, rect) >= 0);
}


void selectWindow(structWindow *myWindow){

  SDL_Surface *win_surface = myWindow->surface; 
  SDL_FillRect(win_surface, NULL, SDL_MapRGB(win_surface->format, 125,50,100));
  SDL_BlitSurface(win_surface, NULL, win_surface, NULL);  
  SDL_UpdateWindowSurface(myWindow->window); 
  
  return;
}

void selectRect(structWindow *myWindow){
  
  SDL_Surface *win_surface = myWindow->surface;
  int x = 10, y = 20, l = 200, h = 200;
  SDL_Rect dest_rect = {x, y, l, h}; 
  assert(SDL_FillRect(SDL_GetWindowSurface(myWindow->window), &dest_rect, SDL_MapRGB(win_surface->format, 125,50,100)) >= 0);
  assert(SDL_BlitSurface(win_surface, NULL, win_surface, NULL) >= 0); 
  assert(SDL_UpdateWindowSurface(myWindow->window) >= 0);
  
  printf("\nRectangle normalement dessiné");
  return;
}

void deselectionner(structWindow *myWindow){

  SDL_Renderer* renderer = myWindow->renderer;
  SDL_Texture *texture = myWindow->texture;
  SDL_DestroyTexture(texture);
  SDL_SetRenderTarget(renderer, NULL);
  return;
}

