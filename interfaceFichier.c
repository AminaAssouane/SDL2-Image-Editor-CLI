#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

#include "interfaceFichier.h"

void newWindowInterface(int *largeur, int *hauteur){
  printf("\nSaisissez la largeur de votre nouvelle fenetre : ");
  scanf("%d",largeur);
  printf("\nSaisissez la hauteur de votre nouvelle fenetre: ");
  scanf("%d",hauteur);
}
   
