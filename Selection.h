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

#include "Dessin.h"


typedef struct Selection Selection;
struct Selection {
	SDL_Window* window;
	SDL_Rect* rect;
	int selection;
	int copy;
};

void colorSelect();
Selection* selectWindow(SDL_Window* window);
Selection* selectMouse(SDL_Window* myWindow);
Selection* selectRect(SDL_Window* window, int x, int y, int largeur, int hauteur);
void deselectionner(Selection* window);


#endif
