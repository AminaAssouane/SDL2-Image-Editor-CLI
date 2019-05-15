/* Module qui contient les fonctions de sélection de régions */

#include "Selection.h"


void colorSelect(SDL_Renderer *renderer, SDL_Rect *rect){
  assert(SDL_SetRenderDrawColor(renderer,150,0,150,255) >= 0);
  assert(SDL_RenderDrawRect(renderer, rect) >= 0);
}

void selectWindow(structWindow *myWindow){

  /*  SDL_Renderer* renderer = myWindow->renderer;
      int largeur, hauteur;*/

  // On récupere les dimensions de la fenêtre
  /*SDL_GetRendererOutputSize(renderer,&largeur,&hauteur); // remplacer ça par la taille de la fenetre
  SDL_Rect rect = { 0,0,largeur,hauteur };
 
  // On recupere la texture et en la met en cible a la place du renderer
  SDL_Texture *texture = myWindow->texture;
  assert(texture != NULL);

  assert(SDL_SetRenderTarget(renderer, texture) >= 0);

  // On colorie le rectangle de la selection
  colorSelect(renderer,&rect);
 
  // On remet la cible sur le renderer pour pouvoir copier
  assert(SDL_SetRenderTarget(renderer, NULL) >= 0);

  // On affiche la texture (donc la selection)
  assert(SDL_RenderCopy(renderer,texture,NULL,NULL) >= 0);
  SDL_RenderPresent(renderer);
  assert(SDL_SetRenderTarget(renderer, texture) >= 0);*/
  SDL_Surface *win_surface = myWindow->surface; // (1)
  // SDL_Rect dest_rect = {0, 0, surface -> w, surface -> h); // (2)
  SDL_FillRect(win_surface, NULL, SDL_MapRGB(win_surface->format, 125,50,100));
  SDL_BlitSurface(win_surface, NULL, win_surface, NULL); // (3)
  SDL_UpdateWindowSurface(myWindow->window); // (4)
  return;
}

void selectRect(structWindow *myWindow, char* myx, char* myy, char* mylargeur, char* myhauteur){
  
  SDL_Surface *win_surface = myWindow->surface;
  int x = atoi(myx), y = atoi(myy), l = atoi(mylargeur), h = atoi(myhauteur);
  const SDL_Rect dest_rect = {x, y, l, h}; // (2)
  SDL_FillRect(win_surface, &dest_rect, SDL_MapRGB(win_surface->format, 125,50,100));
  SDL_BlitSurface(win_surface, NULL, win_surface, NULL); 
  SDL_UpdateWindowSurface(myWindow->window); // (4)

  
  /*SDL_Renderer* renderer = myWindow->renderer;
  int x = atoi(myx), y = atoi(myy), largeur = atoi(mylargeur), hauteur = atoi(myhauteur);
  
  // SDL_GetRendererOutputSize(renderer,&largeur,&hauteur);
  SDL_Rect rect = {x, y, largeur, hauteur};
  printf("%d %d %d %d",rect.x,rect.y,rect.w,rect.h);
  // On recupere la texture et on la met en cible a la place du renderer
  SDL_Texture *texture = myWindow->texture;
  assert(texture != NULL);

  assert(SDL_SetRenderTarget(renderer, texture) >= 0);
  
  // On colorie le rectangle de la selection
  colorSelect(renderer,&rect);
  
   // On remet la cible sur le renderer pour pouvoir copier
  assert(SDL_SetRenderTarget(renderer, NULL) >= 0);
  
  // On affiche la texture (donc la selection)
  assert(SDL_RenderCopy(renderer,texture,NULL,NULL) >= 0);
  SDL_RenderPresent(renderer);
  assert(SDL_SetRenderTarget(renderer, texture) >= 0);*/
  return;
}

void deselectionner(structWindow *myWindow){

  SDL_Renderer* renderer = myWindow->renderer;
  SDL_Texture *texture = myWindow->texture;
  SDL_DestroyTexture(texture);
  SDL_SetRenderTarget(renderer, NULL);
  return;
}

