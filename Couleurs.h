#ifndef COULEURS_H
#define COULEURS_H

#include <SDL.h>
#include <SDL_Image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>


Uint32 color(SDL_Surface *image, char *string);
Uint32 colorRGB(SDL_Surface *image, char* cr, char* cg, char* cb);
Uint32 enumToColor(SDL_Surface *affichage, int color);
int stringToEnum(char *string);


#endif