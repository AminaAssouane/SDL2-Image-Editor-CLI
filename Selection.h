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
void selectRect(structWindow* window);
void deselectionner(structWindow* window);


#endif
