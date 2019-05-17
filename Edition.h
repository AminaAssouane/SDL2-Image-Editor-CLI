#ifndef EDITION_H
#define EDITION_H


#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <assert.h>

#include "Selection.h"

int copier(Selection* region);
int coller(SDL_Window *window, Selection* region, char* x, char *y);
int collerSouris(SDL_Window *window, Selection* region);
int couper(Selection* region);
int couperColor(Selection* region, Uint32 color);


#endif
