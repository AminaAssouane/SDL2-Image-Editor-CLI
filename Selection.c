/* Module qui contient les fonctions de sélection de régions */

#include "Selection.h"


void colorSelect(SDL_Renderer *renderer, SDL_Rect *rect){
  assert(SDL_SetRenderDrawColor(renderer,150,0,150,255) >= 0);
  assert(SDL_RenderDrawRect(renderer, rect) >= 0);
}


void selectMouse(SDL_Window* myWindow){

  SDL_Event event;
  int x = 0, y = 0, largeur = 0, hauteur = 0;
  char myx[10], myy[10], myl[10], myh[10];
  int pushedDown = 0, quit = 0;
  while (quit == 0){
    while (SDL_PollEvent(&event)){
      switch(event.type){	
      case SDL_MOUSEBUTTONDOWN :
	x = event.button.x;
	y = event.button.y;
	pushedDown = 1;
	printf("\nbutton pressed");
	break;
	
      case SDL_MOUSEBUTTONUP : 
	if (pushedDown == 1){
	  largeur = event.button.x - x;
	  hauteur = event.button.y - y;
	  sprintf(myx,"%d",x); sprintf(myy,"%d",y); sprintf(myl,"%d",largeur); sprintf(myh,"%d",hauteur);
	  printf("\nbutton relached");
	  return selectRect(myWindow);
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
}

void selectWindow(SDL_Window *myWindow){

  SDL_Surface *win_surface = SDL_GetWindowSurface(myWindow); 
  SDL_FillRect(win_surface, NULL, SDL_MapRGB(win_surface->format, 125,50,100));
  SDL_UpdateWindowSurface(myWindow); 
  
  return;
}

void selectRect(SDL_Window *myWindow){
  
  SDL_Surface* surface = SDL_GetWindowSurface(myWindow);
  int x = 10, y = 20, l = 200, h = 200;
  SDL_Rect dest_rect = {x, y, l, h}; 
  assert(SDL_FillRect(surface, &dest_rect, SDL_MapRGB(surface->format, 125,50,100)) >= 0);
  assert(SDL_UpdateWindowSurface(myWindow) >= 0);
  
  printf("\nRectangle normalement dessiné");
  return;
}

void deselectionner(SDL_Window *myWindow){


  return;
}

