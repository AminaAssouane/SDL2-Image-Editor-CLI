
/* Module qui regroupe les fonctions de création d'une nouvelle fenêtre, chargement d'une image dans la mémoire, sauvegarde de l'image, etc ... */

#include "Fichier.h"



structWindow* newWindow(char* larg, char* haut){

  structWindow* myWindow = malloc(sizeof(structWindow));
  
  int largeur = atoi(larg), hauteur = atoi(haut);
  
  myWindow->window = SDL_CreateWindow("Nouvelle Fenetre",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,largeur,hauteur,SDL_WINDOW_SHOWN);
  assert(myWindow->window != NULL);
  
  myWindow->renderer = SDL_CreateRenderer(myWindow->window,-1,SDL_RENDERER_ACCELERATED);
  assert(myWindow->renderer != NULL);

  
  myWindow->texture = SDL_CreateTexture(myWindow->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,largeur,hauteur);
  assert(myWindow->texture != NULL);

  myWindow->surface = SDL_GetWindowSurface(myWindow->window);
  assert(myWindow->surface != NULL);

  // On colle une texture de couleure blanche sur l'ecran car on en aura besoin
  // pour dessiner plus tard
  /*SDL_SetRenderTarget(renderer, texture);
  SDL_SetRenderDrawColor(renderer,255,255,255,255);
  SDL_RenderClear(renderer);  
  SDL_SetRenderTarget(renderer, NULL);
  SDL_RenderCopy(renderer,texture,NULL,NULL);
  SDL_RenderPresent(renderer);
  SDL_UpdateWindowSurface(window);

  // On remet la cible pour pouvoir l'utiliser par la suite
  SDL_SetRenderTarget(renderer, texture);*/

  // On retourne la fenêtre créée*/
  return myWindow;
}

structWindow* ouvrir(char *adresse){
  
  structWindow* myWindow = malloc(sizeof(structWindow));
  assert(myWindow != NULL);
    
  myWindow->surface = IMG_Load(adresse);
  assert(myWindow->surface != NULL);  

  SDL_CreateWindowAndRenderer((myWindow->surface)->w,(myWindow->surface)->h,SDL_WINDOW_SHOWN,&(myWindow->window),&(myWindow->renderer));
  assert((myWindow->window != NULL) && (myWindow->renderer != NULL));
    
  myWindow->texture = SDL_CreateTextureFromSurface(myWindow->renderer, myWindow->surface);
  assert(myWindow->texture != NULL);
  /*
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
  */
  return myWindow;
}


void sauvegarde(structWindow* myWindow, char* opt, char* name){
  SDL_Surface* image = myWindow->surface;
  assert(image != NULL);
  
  if (opt == NULL){
    /* Par défault, on enregistre l'image en format bmp. */
    strcat(name,".bmp");
    SDL_SaveBMP(image,name);
    SDL_FreeSurface(image);
    return;
  }
  else {
    if (strcasecmp(opt,"-png") == 0){
      strcat(name,".png");
      IMG_SavePNG(image,name);
      SDL_FreeSurface(image);
      return;
    }
    if (strcasecmp(opt,"-jpg") == 0){
      strcat(name,".jpg");
      IMG_SaveJPG(image,name,1);
      SDL_FreeSurface(image);
      return;
    }
    if (strcasecmp(opt,"-bmp") == 0){
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
