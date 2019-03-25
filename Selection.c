/* Module qui contient les fonctions de sélection de régions */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include "Selection.h"

void menuSelection(){
  printf("\nI\\ Selection\n0. Retour\n1. Toute la fenetre\n2. Region rectangulaire\n3. Trace libre (Pas encore) \n4. Par pixels (Pas encore) \n5. Deselectionner\n");
  printf("\nChoisissez un nombre entre 0 et 4 : ");
  printf("\n** INDICATION ** : Veuillez cliquez sur une des fenêtres ouvertes avant de taper votre choix.\n");
}

void colorSelect(SDL_Renderer *renderer, SDL_Rect *rect){
  int err = SDL_SetRenderDrawColor(renderer,150,0,150,255);
  if(err < 0){
    fprintf(stderr, "Erreur SDL_RenderDrawColor : %s", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  err = SDL_RenderDrawRect(renderer, rect);
  if(err < 0){
    fprintf(stderr, "Erreur SDL_RenderDrawRect : %s", SDL_GetError());
    exit(EXIT_FAILURE);
  } 
}

void selectWindow(SDL_Renderer *renderer){
  int largeur, hauteur, err = 0;

  // On récupere les dimensions de la fenêtre
  SDL_GetRendererOutputSize(renderer,&largeur,&hauteur);
  SDL_Rect rect = { 0,0,largeur,hauteur };
 
  // On crée la texture et en la met en cible a la place du renderer
  SDL_Texture *texture = SDL_GetRenderTarget(renderer);
  if(texture == NULL){
      fprintf(stderr, "Erreur SDL_GetRenderTarget : %s", SDL_GetError());
      exit(EXIT_FAILURE);
  } 

  // On colorie le rectangle de la selection
  colorSelect(renderer,&rect);

  // On remet la cible sur le renderer pour pouvoir copier
  err = SDL_SetRenderTarget(renderer, NULL);
  if(err < 0){
      fprintf(stderr, "Erreur SDL_SetRenderTarget : %s", SDL_GetError());
      exit(EXIT_FAILURE);
  }

  // On affiche la texture (donc la selection)
  err = SDL_RenderCopy(renderer,texture,NULL,NULL);
  if(err < 0){
      fprintf(stderr, "Erreur SDL_RenderCopy : %s", SDL_GetError());
      exit(EXIT_FAILURE);
  }
  SDL_RenderPresent(renderer);
  err = SDL_SetRenderTarget(renderer, texture);
  if(err < 0){
      fprintf(stderr, "Erreur SDL_SetRenderTarget : %s", SDL_GetError());
      exit(EXIT_FAILURE);
  }
}

void selectRect(SDL_Renderer *renderer){
  int x = 0, y = 0, largeur = 0, hauteur = 0,err;

  // On selectionne les valeurs du rectangle
  printf("\nSaisissez l'abscisse du coin en haut à gauche du rectangle : ");
  scanf("%d",&x);
  printf("\nSaisissez l'ordonnée du coin en haut à gauche du rectangle : ");
  scanf("%d",&y);
  printf("\nSaisissez la largeur : ");
  scanf("%d",&largeur);
  printf("\nSaisissez la hauteur : ");
  scanf("%d",&hauteur);
  
  // SDL_GetRendererOutputSize(renderer,&largeur,&hauteur);
  SDL_Rect rect = {0, 0, largeur, hauteur};

  // On crée la texture et on la met en cible a la place du renderer
  SDL_Texture *texture = SDL_GetRenderTarget(renderer);
  if(texture == NULL){
      fprintf(stderr, "Erreur SDL_GetRenderTarget : %s", SDL_GetError());
      exit(EXIT_FAILURE);
  } 
  
  // On colorie le rectangle de la selection
  colorSelect(renderer,&rect);

   // On remet la cible sur le renderer pour pouvoir copier
  err = SDL_SetRenderTarget(renderer, NULL);
  if(err < 0){
      fprintf(stderr, "Erreur SDL_SetRenderTarget : %s", SDL_GetError());
      exit(EXIT_FAILURE);
  }
  
  // On affiche la texture (donc la selection)
  err = SDL_RenderCopy(renderer,texture,NULL,&rect);
  if(err < 0){
      fprintf(stderr, "Erreur SDL_RenderCopy : %s", SDL_GetError());
      exit(EXIT_FAILURE);
  }
  SDL_RenderPresent(renderer);
  err = SDL_SetRenderTarget(renderer, texture);
  if(err < 0){
      fprintf(stderr, "Erreur SDL_SetRenderTarget : %s", SDL_GetError());
      exit(EXIT_FAILURE);
  }
}

void deselectionner(SDL_Renderer *renderer){
  SDL_Texture *texture = SDL_GetRenderTarget(renderer);
  SDL_DestroyTexture(texture);
  SDL_SetRenderTarget(renderer, NULL);
}
