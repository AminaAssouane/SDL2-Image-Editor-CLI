/* Module qui contient les fonctions de sélection de régions */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "Selection.h"


void colorSelect(SDL_Renderer *renderer, SDL_Rect *rect){
  assert(SDL_SetRenderDrawColor(renderer,150,0,150,255) >= 0);
  assert(SDL_RenderFillRect(renderer, rect) >= 0);
}

void selectWindow(SDL_Window *window){

  SDL_Renderer* renderer = SDL_GetRenderer(window);
  int largeur, hauteur;

  // On récupere les dimensions de la fenêtre
  SDL_GetRendererOutputSize(renderer,&largeur,&hauteur); // remplacer ça par la taille de la fenetre
  SDL_Rect rect = { 0,0,largeur,hauteur };
 
  // On crée la texture et en la met en cible a la place du renderer
  SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,largeur,hauteur);
  assert(texture != NULL);

  assert(SDL_SetRenderTarget(renderer, texture) >= 0);

  // On colorie le rectangle de la selection
  colorSelect(renderer,&rect);
 
  // On remet la cible sur le renderer pour pouvoir copier
  assert(SDL_SetRenderTarget(renderer, NULL) >= 0);

  // On affiche la texture (donc la selection)
  assert(SDL_RenderCopy(renderer,texture,NULL,NULL) >= 0);
  SDL_RenderPresent(renderer);
  assert(SDL_SetRenderTarget(renderer, texture) >= 0);
}

void selectRect(SDL_Window *window, char* myx, char* myy, char* mylargeur, char* myhauteur){
  
  SDL_Renderer* renderer = SDL_GetRenderer(window);
  int x = atoi(myx), y = atoi(myy), largeur = atoi(mylargeur), hauteur = atoi(myhauteur);
  
  // SDL_GetRendererOutputSize(renderer,&largeur,&hauteur);
  SDL_Rect rect = {x, y, largeur, hauteur};

  // On crée la texture et on la met en cible a la place du renderer
  SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,largeur,hauteur);
  assert(texture != NULL);

  assert(SDL_SetRenderTarget(renderer, texture) >= 0);
  
  // On colorie le rectangle de la selection
  colorSelect(renderer,&rect);

   // On remet la cible sur le renderer pour pouvoir copier
  assert(SDL_SetRenderTarget(renderer, NULL) >= 0);
  
  // On affiche la texture (donc la selection)
  assert(SDL_RenderCopy(renderer,texture,NULL,&rect) >= 0);
  SDL_RenderPresent(renderer);
  assert(SDL_SetRenderTarget(renderer, texture) >= 0);
}

void deselectionner(SDL_Window *window){

  SDL_Renderer* renderer = SDL_GetRenderer(window);
  SDL_Texture *texture = SDL_GetRenderTarget(renderer);
  SDL_DestroyTexture(texture);
  SDL_SetRenderTarget(renderer, NULL);
}
