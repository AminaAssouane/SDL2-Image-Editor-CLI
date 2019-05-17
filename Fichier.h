/* Fichier.h */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <assert.h>


SDL_Window* newWindow();
SDL_Window* ouvrir(char *adresse);
void sauvegarde(SDL_Window* window, char* opt, char* name);
