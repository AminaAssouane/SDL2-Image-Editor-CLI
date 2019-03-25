#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

#include "Auxiliaires.h"
#include "Fichier.h"
#include "Edition.h"
#include "Selection.h"
#include "Transformations.h"

#define MAX_WIN 100


int main(int argc, char *argv[])
{
  SDL_Event event,event2;
  SDL_Window* window[MAX_WIN];
  SDL_Renderer *renderer;
  int largeur, hauteur, nbWindows = 0, iWindow = 0;
  int bool1 = 1,bool2 = 1;
  char adresse[100];

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0){
    fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
    exit(EXIT_FAILURE);
  }
  while (bool1 == 1){
    /* S'il n'y a pas de fenêtre ouverte, on doit d'abord en ouvrir une, car SDL_Event ne marche pas sans */
    if (nbWindows == 0){
      window[0] = debut();
      nbWindows = 1;
      menu();
    }
    
    while (SDL_PollEvent(&event)){
      bool2=1;
      switch(event.type){
      case SDL_WINDOWEVENT :
	if (event.window.event == SDL_WINDOWEVENT_CLOSE){
	  iWindow = findWindowID(window,event.window.windowID,nbWindows);
	  SDL_DestroyWindow(window[iWindow]);
	  nbWindows--;
	  decalWindows(window,iWindow,nbWindows);
	}
	break;
      case SDL_KEYDOWN :
	switch (event.key.keysym.sym){
	case SDLK_KP_1 :
	  menuFichier();
	  while (bool2 == 1){
	    while (SDL_PollEvent(&event2)){
	      switch(event2.type){
	      case SDL_WINDOWEVENT :
		if (event2.window.event == SDL_WINDOWEVENT_CLOSE){
		  iWindow = findWindowID(window,event2.window.windowID,nbWindows);
		  SDL_DestroyWindow(window[iWindow]);
		  nbWindows--;
		  decalWindows(window,iWindow,nbWindows);
		}
		break;
	      case SDL_KEYDOWN :
		switch (event2.key.keysym.sym){
		case SDLK_KP_0:
		  bool2 = 0;
		  menu();
		  break;
		case SDLK_KP_1:
		  printf("\n** INDICATION ** : Cliquez sur la console avant de taper les valeurs.");
		  printf("\nSaisissez la largeur : ");
		  scanf("%d",&largeur);
		  printf("\nSaisissez la hauteur : ");
		  scanf("%d",&hauteur);
		  window[nbWindows] = newWindow(largeur,hauteur);
		  nbWindows++;
		  menuFichier();
		  break;
		case SDLK_KP_2:
		  printf("\n** INDICATION ** : Cliquez sur la console avant de taper la valeur.");
		  printf("\nSaisissez le chemin absolu : ");
		  scanf("%s",adresse);
		  window[nbWindows] = ouvrir(adresse);
		  nbWindows++;
		  menuFichier();
		  break;
		case SDLK_KP_3:
		break;
	      default :
		printf("\nTapez un nombre entre 0 et 2.");
		break;
	      }
	    }
	  }
	  }
	  break;
	case SDLK_KP_2 :
	  menuSelection();
	  while (bool2 == 1){
	    while (SDL_PollEvent(&event2)){
	      switch(event2.type){
	      case SDL_WINDOWEVENT :
		if (event2.window.event == SDL_WINDOWEVENT_CLOSE){
		  iWindow = findWindowID(window,event2.window.windowID,nbWindows);
		  SDL_DestroyWindow(window[iWindow]);
		  nbWindows--;
		  decalWindows(window,iWindow,nbWindows);
		}
		break;
	      case SDL_KEYDOWN :
		switch (event2.key.keysym.sym){
		case SDLK_KP_0:
		  bool2 = 0;
		  menu();
		  break;
		case SDLK_KP_1:
		  iWindow = findWindowID(window,event2.window.windowID,nbWindows);
		  selectWindow(SDL_GetRenderer(window[iWindow]));
		  menuSelection();
		  break;
		case SDLK_KP_2:
		  iWindow = findWindowID(window,event2.window.windowID,nbWindows);
		  renderer = SDL_GetRenderer(window[iWindow]);
		  printf("\n** INDICATION ** : Cliquez sur la console avant de taper les valeurs.");
		  selectRect(renderer);
		  menuSelection();
		  break;
		case SDLK_KP_5:
		  iWindow = findWindowID(window,event2.window.windowID,nbWindows);
		  deselectionner(SDL_GetRenderer(window[iWindow]));
		  menuSelection();
		  break;
		default :
		  printf("\nTapez une touche entre 0 et 5 (sauf 3 ou 4).");
		  continue;
		  break;
		}
	      }
	    }
	  }
	  break; 
	case SDLK_KP_0 :
	  printf("\nAurevoir !");
	  bool1 = 0;
	  break;
	default :
	  printf("\nTapez 0, 1 ou 2.");
	  continue;
	  break;
	}
	break;
      default :
	continue;
	break;
      }
    }
  }
  SDL_Quit();
  return 1;   
}
 
