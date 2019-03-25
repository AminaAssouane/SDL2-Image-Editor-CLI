/* Fonctions intermédiaires (auxiliaires) du programme */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "Fichier.h"
#include "Auxiliaires.h"

/* Menu principal */
void menu(){
  printf("\nConsole Image Manipulation Program");
  printf("\n\n1. Fichier");
  printf("\n\n2. Selections");
  printf("\n\n3. Edition (Pas encore) ");
  printf("\n\n4. Transformations (Pas encore)");
  printf("\n\n0. Quitter\n");
  printf("\n\nChoisissez un nombre entre 0 et 4 : ");
  printf("\n** INDICATION ** : Veuillez cliquer sur une des fenêtres ouvertes avant de taper votre choix.\n");
}

/* Fonction appelée au début quand il n'y a aucune fenêtre ouverte (donc n'a pas recours à SDL */ 
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

/* Fonction qui trouve l'indice d'une fenêtre dans la liste "window[]" après avoir cliqué dessus */
int findWindowID(SDL_Window* tabW[], Uint32 wID, int nbWindows){
  for (int i = 0; i < nbWindows; i++){
    if (SDL_GetWindowID(tabW[i]) == wID){
      return i;
    }
  }
  fprintf(stdout,"Echec de la recherche de la fenêtre\n");
  exit(EXIT_FAILURE);
}

/* Fonction qui réarrange les fenêtre dans la liste "window[]" après la suppression d'une fenêtre */
void decalWindows(SDL_Window* tabW[], int i, int nbWindows){
  tabW[i] = tabW[nbWindows];  
}
