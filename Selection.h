#ifndef SELECTION_H
#define SELECTION_H


#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "Types.h"

void colorSelect();
void selectWindow(structWindow* window);
void selectRect(structWindow* window, char* x, char* y, char* largeur, char* hauteur);
void deselectionner(structWindow* window);


#endif
