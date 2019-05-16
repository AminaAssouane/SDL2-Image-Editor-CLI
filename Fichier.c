
/* Module qui regroupe les fonctions de création d'une nouvelle fenêtre, chargement d'une image dans la mémoire, sauvegarde de l'image, etc ... */

#include "Fichier.h"



structWindow* newWindow(char* larg, char* haut){

  structWindow* myWindow = malloc(sizeof(structWindow));
  
  int largeur = atoi(larg), hauteur = atoi(haut);
  
  myWindow->window = SDL_CreateWindow("Nouvelle Fenetre",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,largeur,hauteur,SDL_WINDOW_SHOWN);
  assert(myWindow->window != NULL);

  myWindow->surface = SDL_GetWindowSurface(myWindow->window);
  assert(myWindow->surface != NULL);

  SDL_Surface* whiteCanvas = SDL_CreateRGBSurface(0,largeur,hauteur,32,0,0,0,0);
  assert(whiteCanvas != NULL);
  
  
  SDL_FillRect(whiteCanvas, NULL, SDL_MapRGB(whiteCanvas->format, 255, 255, 255));
  SDL_BlitSurface(whiteCanvas,NULL,myWindow->surface,NULL);
  SDL_UpdateWindowSurface(myWindow->window);

  return myWindow;
}

structWindow* ouvrir(char *adresse){
  
  structWindow* myWindow = malloc(sizeof(structWindow));
  assert(myWindow != NULL);

  SDL_Surface* image = IMG_Load(adresse);
  assert(image != NULL);

  myWindow->window = SDL_CreateWindow(adresse,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,image->w,image->h,SDL_WINDOW_SHOWN);
  assert(myWindow->window != NULL);
  
  myWindow->surface = SDL_GetWindowSurface(myWindow->window);
  assert(myWindow->surface != NULL);  
  
  SDL_BlitSurface(image, NULL, myWindow->surface, NULL);
  SDL_UpdateWindowSurface(myWindow->window);
  
  return myWindow;
}


void sauvegarde(structWindow* myWindow, char* opt, char* name){
  SDL_Surface* image = myWindow->surface;
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
      IMG_SaveJPG(image,name,1);
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
