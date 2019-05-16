#ifndef SELECTION_H
#define SELECTION_H


#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

#include "Types.h"

void colorSelect();
void selectWindow(structWindow* window);
void selectMouse(structWindow* myWindow);
void selectRect(structWindow* window);
void deselectionner(structWindow* window);


#endif
