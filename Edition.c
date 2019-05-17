/* Module qui contient les fonctions copier, couper, coller */

#include "Edition.h"

int copier(Selection* region){
  if (region == NULL){
    printf("Aucune region selectionnee.\n");
    return 0;
  }
  if (region->selection == 0){
    printf("Aucune region selectionnee.\n");
    return 0;
  }
  else {
    region->selection = 0;
    region->copy = 1;
    return 1;
  }
}

int collerSouris(SDL_Window *window, Selection* region){
  
  SDL_Event event;
  int x = 0, y = 0;
  int quit = 0;
  char myx[10], myy[10];
  while (quit == 0){
    while (SDL_PollEvent(&event)){
      switch(event.type){	
      case SDL_MOUSEBUTTONDOWN :
	x = event.button.x;
	y = event.button.y;
	sprintf(myx,"%d",x); 
  sprintf(myy,"%d",y);
	quit = 1;
	return coller(window,region,myx,myy);
	break;
      }
    }
  }
  return 0;	
}

int coller(SDL_Window *window, Selection* region, char* x, char *y){

  if (region->copy == 0){
    printf("Aucune region copiee.\n");
    return 0;
  }
  else {
    SDL_Rect dst;
    dst.x = atoi(x);
    dst.y = atoi(y);
    dst.w = (region->rect).w;
    dst.h = (region->rect).h;
    SDL_BlitSurface(region->withoutRect,NULL,SDL_GetWindowSurface(region->window),NULL);
    SDL_BlitSurface(region->withoutRect,&(region->rect),SDL_GetWindowSurface(window),&dst);
    SDL_UpdateWindowSurface(window);
    region->copy = 0;
    deselectionner(region);
    return 1;
  }
}


int couper(Selection* region){
  
  if (region == NULL){
    printf("Aucune region selectionnee.\n");
    return 0;
  }
  if (region->selection == 0){
    printf("Aucune region selectionnee.\n");
    return 0;
  }
  else {
    region->selection = 0;
    region->copy = 1;
    
    SDL_Surface *surface = SDL_GetWindowSurface(region->window);
    assert(surface != NULL);

    SDL_FillRect(surface, &(region->rect), SDL_MapRGB(surface->format, 0xAB, 0xAB, 0xAB));
    SDL_UpdateWindowSurface(region->window);
    return 1;
  }
  
}



int couperColor(Selection* region, Uint32 color){
  
  if (region == NULL){
    printf("Aucune region selectionnee.\n");
    return 0;
  }
  if (region->selection == 0){
    printf("Aucune region selectionnee.\n");
    return 0;
  }
  else {
    region->selection = 0;
    region->copy = 1;
    
    SDL_Surface *surface = SDL_GetWindowSurface(region->window);
    assert(surface != NULL);

    SDL_FillRect(surface, &(region->rect), color);
    SDL_UpdateWindowSurface(region->window);
    return 1;
  }
  
}
 
