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


void colorSelect();
void selectWindow(SDL_Window* window);
void selectMouse(SDL_Window* myWindow);
void selectRect(SDL_Window* window);
void deselectionner(SDL_Window* window);


#endif
