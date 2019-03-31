/* Module qui regroupe les fonctions de création d'une nouvelle fenêtre, chargement d'une image dans la mémoire, sauvegarde de l'image, etc ... */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

#include "Selection.h"
#include "interfaceSelection.h"


void selectRectInterface(int *x, int *y, int *largeur, int *hauteur){
  printf("\nSaisissez l'abscisse du coin en haut à gauche du rectangle : ");
  scanf("%d",x);
  printf("\nSaisissez l'ordonnée du coin en haut à gauche du rectangle : ");
  scanf("%d",y);
  printf("\nSaisissez la largeur : ");
  scanf("%d",largeur);
  printf("\nSaisissez la hauteur : ");
  scanf("%d",hauteur);
}
   
