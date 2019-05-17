/* Auxiliaires.h */

#ifndef AUXILIAIRES_H
#define AUXILIAIRES_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "Fichier.h"

int findWindowID(SDL_Window* tabW[], Uint32 wID, int nbWindows);
void decalWindows(SDL_Window* tabW[], int i, int nbWindows);
void icon(SDL_Window* myWindow, char* comm);
void help(char* commm);

#endif 