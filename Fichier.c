/* Module qui regroupe les fonctions de création d'une nouvelle fenêtre, chargement d'une image dans la mémoire, sauvegarde de l'image, etc ... */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "Fichier.h"

void menuFichier(){
  printf("\nI\\ Fichier\n0. Retour\n1. Nouvelle Fenetre\n2. Charger image\n3. Sauvegarder image (Pas encore)\n");
  printf("\nChoisissez un nombre entre 0 et 3 : ");
  printf("\n** INDICATION ** : Veuillez cliquez sur une des fenêtres ouvertes avant de taper votre choix.\n");
}

SDL_Window* newWindow(int largeur, int hauteur){
  
  SDL_Window* window  = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,largeur,hauteur,SDL_WINDOW_SHOWN);
  if(window == NULL){
    fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  
  SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
  if(renderer == NULL)
  {
    fprintf(stderr, "Erreur SDL_CreateRenderer : %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  // On colle une texture de couleure blanche sur l'ecran car on en aura besoin
  // pour dessiner plus tard
  SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,largeur,hauteur);
  SDL_SetRenderTarget(renderer, texture);
  SDL_SetRenderDrawColor(renderer,255,255,255,255);
  SDL_RenderClear(renderer);  
  SDL_SetRenderTarget(renderer, NULL);
  SDL_RenderCopy(renderer,texture,NULL,NULL);
  SDL_RenderPresent(renderer);

  // On remet la cible pour pouvoir l'utiliser par la suite
  SDL_SetRenderTarget(renderer, texture);

  // On retourne la fenêtre créée
  return window;
}

SDL_Window* ouvrir(char *adresse){
    SDL_Surface *tmp = NULL; 
    SDL_Texture *texture = NULL;
    tmp = IMG_Load(adresse);
    if(tmp == NULL){
      fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
      return EXIT_SUCCESS;
    }    

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_CreateWindowAndRenderer(tmp->w,tmp->h,SDL_WINDOW_SHOWN,&window,&renderer);
    if((window == NULL) || (renderer == NULL)){
      fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
      exit(EXIT_FAILURE);
    }
    
    texture = SDL_CreateTextureFromSurface(renderer, tmp);

    SDL_FreeSurface(tmp); 
    if(texture == NULL){
      fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
      exit(EXIT_FAILURE);
    }
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    return window;
}

