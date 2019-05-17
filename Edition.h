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

int couper(SDL_Window* window, Selection* region);
int copier(SDL_Window* window, Selection* region);
int coller(SDL_Window *window, Selection* region, char* x, char *y);


#endif
