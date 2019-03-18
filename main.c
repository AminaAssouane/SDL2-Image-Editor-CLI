#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

#include "Fichier.h"
#include "Edition.h"
#include "Selection.h"
#include "Transformations.h"

#define MAX_WIN 100

void menu(){
  printf("\nConsole Image Manipulation Program");
  printf("\n\n1. Fichier");
  printf("\n\n2. Selections");
  printf("\n\n3. Edition ");
  printf("\n\n4. Transformations");
  printf("\n\n5. Quitter\n");
  printf("\n\nChoisissez un nombre entre 1 et 5 : ");
  printf("\n** INDICATION **  : Veuillez cliquer sur une des fenêtres ouvertes avant de taper votre choix.\n");
}

void menuFichier(){
  printf("\nI\\ Fichier\n0. Retour\n1. Nouvelle Fenetre\n2. Charger image\n3. Sauvegarder image\n");
  printf("\nChoisissez un nombre entre 0 et 3 : ");
  printf("\nINDICATION : Veuillez cliquez sur une des fenêtres ouvertes avant de taper votre choix.\n");
}

SDL_Window* debut(){
  int choix = 0, bool = 1, largeur, hauteur;
  char adresse[100];
  printf("\nConsole Image Manipulation Program");
  printf("\n----------------------------------------");
  printf("\n1. Nouvelle Fenetre");
  printf("\n2. Charger Image");
  printf("\n\nEntrez votre choix : ");
  while (bool == 1){
    scanf("%d",&choix);
    switch (choix){
    case 1:
      printf("\nSaisissez la largeur : ");
      scanf("%d",&largeur);
      printf("\nSaisissez la hauteur : ");
      scanf("%d",&hauteur);
      return newWindow(largeur,hauteur);
    case 2:
      printf("\nSaisissez le chemin absolu : ");
      scanf("%s",adresse);
      return ouvrir(adresse);
    default:
      printf("\nVeuillez entrer 1 ou 2 : ");
      break;
    }
  }
  return NULL;
}

int findWindowID(SDL_Window* tabW[], Uint32 wID, int nbWindows){
  for (int i = 0; i < nbWindows; i++){
    if (SDL_GetWindowID(tabW[i]) == wID)
      return i;
  }
  fprintf(stdout,"Echec de la recherche de la fenêtre\n");
  exit(EXIT_FAILURE);
}

void decalWindows(SDL_Window* tabW[], int i, int nbWindows){
  tabW[i] = tabW[nbWindows];  
}

int main(int argc, char *argv[])
{
  SDL_Event event,event2;
  SDL_Window* window[MAX_WIN];
  int largeur, hauteur, nbWindows = 0, iWindow = 0;
  int bool = 1,bool1 = 1;
  int afficheMenu = 1;
  char adresse[100];

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0){
    fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
    exit(EXIT_FAILURE);
  }
  
  while (bool == 1){
    /* S'il n'y a pas de fenêtre ouverte, on doit d'abord en ouvrir une, car SDL_Event ne marche pas sans */
    if (nbWindows == 0){
      window[0] = debut();
      nbWindows = 1;
      menu();
    }
    
    while (SDL_PollEvent(&event)){
      bool1=1;
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
	  while (bool1 == 1){
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
		  bool1 = 0;
		  menu();
		  break;
		case SDLK_KP_1:
		  printf("\nSaisissez la largeur : ");
		  scanf("%d",&largeur);
		  printf("\nSaisissez la hauteur : ");
		  scanf("%d",&hauteur);
		  window[nbWindows] = newWindow(largeur,hauteur);
		  nbWindows++;
		  menuFichier();
		  break;
		case SDLK_KP_2:
		  printf("\nSaisissez le chemin absolu : ");
		  scanf("%s",adresse);
		  window[nbWindows] = ouvrir(adresse);
		  nbWindows++;
		  menuFichier();
		  break;
		case SDLK_KP_3:
		  break;
		default :
		  break;
		}
	      }
	    }
	  }
	  break;
	case SDLK_KP_5 :
	  printf("\nAurevoir !");
	  bool = 0;
	  break;
	default :
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
