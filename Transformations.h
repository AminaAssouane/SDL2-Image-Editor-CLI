#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H


#include <SDL.h>
#include <SDL_image.h>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Selection.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600



void mise_en_niveaux_de_gris(SDL_Surface *image);
void mise_en_negatif(SDL_Surface *image);
void noir_et_blanc(SDL_Surface *image);
void remplacement_couleur(SDL_Surface *image, SDL_Color old_color, SDL_Color new_color, int marge);
void remplissage_par_une_couleur(Selection *image, Uint32 color);

Uint8 luminosite_moins(Uint8 c, double n);
Uint8 luminosite_plus(Uint8 c, double n);
void ajustement_luminosite(SDL_Surface *image, char *op);

Uint8 contraste(Uint8 c, double n);
void ajustement_contraste(SDL_Surface *image);

void symetrie(SDL_Surface *image, char *type);
SDL_Window *rotation(SDL_Window * window);


#endif 