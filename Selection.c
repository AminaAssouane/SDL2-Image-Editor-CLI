/* Module qui contient les fonctions de sélection de régions */

#include "Selection.h"



void colorSelect(SDL_Renderer *renderer, SDL_Rect *rect){
  assert(SDL_SetRenderDrawColor(renderer,150,0,150,255) >= 0);
  assert(SDL_RenderDrawRect(renderer, rect) >= 0);
}


Selection* selectMouse(SDL_Window* myWindow){

  SDL_Event event;
  int x = 0, y = 0, largeur = 0, hauteur = 0;
  int pushedDown = 0, quit = 0;
  while (quit == 0){
    while (SDL_PollEvent(&event)){
      switch(event.type){	
      case SDL_MOUSEBUTTONDOWN :
	x = event.button.x;
	y = event.button.y;
	pushedDown = 1;
	break;
	
      case SDL_MOUSEBUTTONUP : 
	if (pushedDown == 1){
	  largeur = event.button.x - x;
    
	  hauteur = event.button.y - y;
	  return selectRect(myWindow,x,y,largeur,hauteur);
	}
	break;
      
      case SDL_KEYDOWN :
	if (event.key.keysym.sym == SDLK_ESCAPE){
	  quit = 1;
	}
	break;
	
      default :
	continue;
	break;
      }
    }
  }
  return NULL;
}

Selection* selectWindow(SDL_Window *myWindow){

  Selection* selection = malloc(sizeof(Selection));
  assert(selection != NULL);
    
  int largeur, hauteur;
  SDL_GetWindowSize(myWindow,&largeur,&hauteur);

  SDL_Rect sel = {0,0,largeur,hauteur};
  selection->window = myWindow;
  selection->withoutRect = SDL_CreateRGBSurface(0,largeur,hauteur,32,0,0,0,0);
  SDL_BlitSurface(SDL_GetWindowSurface(selection->window),NULL,selection->withoutRect,NULL);
  selection->rect = sel;
  selection->selection = 1;
  selection->copy = 0;

  /* On affiche le rectangle de selection */
  SDL_Surface *win_surface = SDL_GetWindowSurface(myWindow);
  assert(win_surface != NULL);
  rectangle(win_surface, 0, 0, largeur, hauteur, SDL_MapRGB(win_surface->format, 125,50,100));
  assert(SDL_UpdateWindowSurface(myWindow)>= 0);

  return selection; 
}

Selection* selectRect(SDL_Window *myWindow, int x, int y, int l, int h){

  Selection* selection = malloc(sizeof(Selection));
  assert(selection != NULL);

  int largeur, hauteur;
  SDL_GetWindowSize(myWindow,&largeur,&hauteur);
  SDL_Rect sel = {x,y,l,h};
  selection->window = myWindow;
  selection->withoutRect = SDL_CreateRGBSurface(0,largeur,hauteur,32,0,0,0,0);
  SDL_BlitSurface(SDL_GetWindowSurface(selection->window),NULL,selection->withoutRect,NULL);
  selection->rect = sel;
  selection->selection = 1;
  selection->copy = 0;


   /* On affiche le rectangle de selection */
  SDL_Surface* surface = SDL_GetWindowSurface(myWindow);
  rectangle(surface, x, y, l, h, SDL_MapRGB(surface->format, 125,50,100));
  assert(SDL_UpdateWindowSurface(myWindow) >= 0);
  
  return selection;
}

void deselectionner(Selection *sel){
  if (sel == NULL){
    return;
  }
  if (sel->selection == 0){
    return;
  }
  SDL_BlitSurface(sel->withoutRect,NULL,SDL_GetWindowSurface(sel->window),NULL);
  SDL_UpdateWindowSurface(sel->window);
  sel->selection = 0;
  free(sel);
  return;
}

