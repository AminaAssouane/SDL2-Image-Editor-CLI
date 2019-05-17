
/* Module qui regroupe les fonctions de création d'une nouvelle fenêtre, chargement d'une image dans la mémoire, sauvegarde de l'image, etc ... */

#include "Fichier.h"



SDL_Window* newWindow(char* larg, char* haut){
  
  int largeur = atoi(larg), hauteur = atoi(haut);
  
  SDL_Window* myWindow = SDL_CreateWindow("Nouvelle Fenetre",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,largeur,hauteur,SDL_WINDOW_SHOWN);
  assert(myWindow != NULL);

  SDL_Surface* surface = SDL_GetWindowSurface(myWindow);
  assert(surface != NULL);

  SDL_Surface* whiteCanvas = SDL_CreateRGBSurface(0,largeur,hauteur,32,0,0,0,0);
  assert(whiteCanvas != NULL);
  
  
  SDL_FillRect(whiteCanvas, NULL, SDL_MapRGB(whiteCanvas->format, 255, 255, 255));
  SDL_BlitSurface(whiteCanvas,NULL,surface,NULL);
  SDL_UpdateWindowSurface(myWindow);

  return myWindow;
}

SDL_Window* ouvrir(char *adresse){
  
  SDL_Surface* image = IMG_Load(adresse);
  assert(image != NULL);

  SDL_Window* myWindow = SDL_CreateWindow(adresse,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,image->w,image->h,SDL_WINDOW_SHOWN);
  assert(myWindow != NULL);
  
  SDL_Surface* surface = SDL_GetWindowSurface(myWindow);
  assert(surface != NULL);  
  
  SDL_BlitSurface(image, NULL, surface, NULL);
  SDL_UpdateWindowSurface(myWindow);
  
  return myWindow;
}


void sauvegarde(SDL_Window* myWindow, char* opt, char* name){
  SDL_Surface* image = SDL_GetWindowSurface(myWindow);
  assert(image != NULL);
  
  if (opt == NULL){
    /* Par défault, on enregistre l'image en format bmp. */
    strcat(name,".bmp");
    SDL_SaveBMP(image,name);
    return;
  }
  else {
    if (strcasecmp(opt,"-png") == 0){
      strcat(name,".png");
      IMG_SavePNG(image,name);
      return;
    }
    if (strcasecmp(opt,"-jpg") == 0){
      strcat(name,".jpg");
      IMG_SaveJPG(image,name,100);
      return;
    }
    if (strcasecmp(opt,"-bmp") == 0){
      strcat(name,".bmp");
      SDL_SaveBMP(image,name);
      return;
    }
    else {
      printf("\nL'option que vous avez specifie n'est pas prise en charge.");
    }
  }
}
