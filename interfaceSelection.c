/* Module qui regroupe les fonctions de cr�ation d'une nouvelle fen�tre, chargement d'une image dans la m�moire, sauvegarde de l'image, etc ... */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

#include "Selection.h"
#include "interfaceSelection.h"


void selectRectInterface(int *x, int *y, int *largeur, int *hauteur){
  printf("\nSaisissez l'abscisse du coin en haut � gauche du rectangle : ");
  scanf("%d",x);
  printf("\nSaisissez l'ordonn�e du coin en haut � gauche du rectangle : ");
  scanf("%d",y);
  printf("\nSaisissez la largeur : ");
  scanf("%d",largeur);
  printf("\nSaisissez la hauteur : ");
  scanf("%d",hauteur);
}
   
