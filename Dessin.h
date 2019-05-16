#ifndef DESSIN_H
#define DESSIN_H


#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <assert.h>

#include "Types.h"


void drawPoint(SDL_Surface* image, int x, int y, Uint32 coul);
void drawPointSafe(SDL_Surface* image, int x, int y, Uint32 coul);
void clear(SDL_Surface* image);
void ligneHorizontale(SDL_Surface* image, int x, int y, int w, Uint32 coul);
void ligneVerticale(SDL_Surface* image, int x, int y, int h, Uint32 coul);
void rectangle(SDL_Surface* image, int x, int y, int w, int h, Uint32 coul);
void cercle(SDL_Surface* image, int cx, int cy, int rayon, int coul);
void disque(SDL_Surface* image, int cx, int cy, int rayon, int coul);



#endif