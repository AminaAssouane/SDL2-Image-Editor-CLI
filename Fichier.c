
/* Module qui regroupe les fonctions de création d'une nouvelle fenêtre, chargement d'une image dans la mémoire, sauvegarde de l'image, etc ... */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <assert.h>

#include "Fichier.h"



SDL_Window* newWindow(char* larg, char* haut){

  int largeur = atoi(larg), hauteur = atoi(haut);
  //printf("%d %d",largeur,hauteur);
  
  SDL_Window* window  = SDL_CreateWindow("Nouvelle Fenetre",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,largeur,hauteur,SDL_WINDOW_SHOWN);
  assert(window != NULL);
  
  /*SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
  assert(renderer != NULL);

  // On colle une texture de couleure blanche sur l'ecran car on en aura besoin
  // pour dessiner plus tard
  SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,largeur,hauteur);
  assert(texture != NULL);
  
  SDL_SetRenderTarget(renderer, texture);
  SDL_SetRenderDrawColor(renderer,255,255,255,255);
  SDL_RenderClear(renderer);  
  SDL_SetRenderTarget(renderer, NULL);
  SDL_RenderCopy(renderer,texture,NULL,NULL);
  SDL_RenderPresent(renderer);
  SDL_UpdateWindowSurface(window);

  // On remet la cible pour pouvoir l'utiliser par la suite
  SDL_SetRenderTarget(renderer, texture);*/

  // On retourne la fenêtre créée
  return window;
}

SDL_Window* ouvrir(char *adresse){
  
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *tmp = NULL; 
    SDL_Texture *texture = NULL;
    
    tmp = IMG_Load(adresse);
    assert(tmp != NULL);  

    SDL_CreateWindowAndRenderer(tmp->w,tmp->h,SDL_WINDOW_SHOWN,&window,&renderer);
    assert((window != NULL) && (renderer != NULL));
    
    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    assert(texture != NULL);
    
    SDL_FreeSurface(tmp);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    return window;
}


void sauvegarde(SDL_Window* window, char* opt, char* name){
  if (opt == NULL){
    /* Par défault, on enregistre l'image en format bmp. */
    SDL_Surface* image = SDL_GetWindowSurface(window);
    strcat(name,".bmp");
    SDL_SaveBMP(image,name);
    SDL_FreeSurface(image);
    return;
  }
  else {
    if (strcasecmp(opt,"-png") == 0){
      SDL_Surface* image = SDL_GetWindowSurface(window);
      strcat(name,".png");
      IMG_SavePNG(image,name);
      SDL_FreeSurface(image);
      return;
    }
    if (strcasecmp(opt,"-jpg") == 0){
      SDL_Surface* image = SDL_GetWindowSurface(window);
      strcat(name,".jpg");
      IMG_SaveJPG(image,name,1);
      SDL_FreeSurface(image);
      return;
    }
    if (strcasecmp(opt,"-bmp") == 0){
      SDL_Surface* image = SDL_GetWindowSurface(window);
      strcat(name,".bmp");
      SDL_SaveBMP(image,name);
      SDL_FreeSurface(image);
      return;
    }
    else {
      printf("\nL'option que vous avez specifie n'est pas prise en charge.");
    }
  }
}
