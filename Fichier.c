/* Module qui regroupe les fonctions de création d'une nouvelle fenêtre, chargement d'une image dans la mémoire, sauvegarde de l'image, etc ... */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

int newWindow(int largeur, int hauteur){
  
  if (SDL_Init(SDL_INIT_VIDEO) != 0){
    fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
    exit(EXIT_FAILURE);
  }
  
  SDL_Window* pWindow = pWindow = SDL_CreateWindow("Ma première application SDL2",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,largeur,hauteur,SDL_WINDOW_SHOWN);

  if(pWindow = NULL){
    fprintf(stderr, "Erreur SDL_CreateWindow : %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_DestroyWindow(pWindow);
  SDL_Quit();
}

int ouvrir(char *adresse){
   if (SDL_Init(SDL_INIT_VIDEO) != 0){
      fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
      exit(EXIT_FAILURE);
    }
    
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
      return EXIT_SUCCESS;
    }
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    while(1);
    SDL_Quit();
    return EXIT_SUCCESS;
}

