/* Auxiliaires.h */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

int findWindowID(SDL_Window* tabW[], Uint32 wID, int nbWindows);
void decalWindows(SDL_Window* tabW[], int i, int nbWindows);
void help(char* commm); 