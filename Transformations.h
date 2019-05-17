#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H


#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <SDL2/SDL2_rotozoom.h>


#include "Selection.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600



SDL_Surface *mise_en_niveaux_de_gris(Selection* selection);
SDL_Surface *mise_en_negatif(Selection *image);
SDL_Surface *noir_et_blanc(Selection *image);

SDL_Color  create_color(int r, int g, int b);
SDL_Surface *remplacement_couleur(Selection *image, SDL_Color old_color, SDL_Color new_color, int marge);
SDL_Surface *remplissage_par_une_couleur(Selection *image, SDL_Color color);

Uint8 luminosite_moins(Uint8 c, double n);
Uint8 luminosite_plus(Uint8 c, double n);
SDL_Surface *ajustement_luminosite(Selection *image, char *op);

Uint8 contraste(Uint8 c, double n);
SDL_Surface *ajustement_contraste(Selection *image);


SDL_Surface *symetrie(SDL_Surface *image, char *type);
//SDL_Window *rotation(SDL_Window * window);


#endif 