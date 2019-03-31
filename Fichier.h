/* Fichier.h */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

#include "interfaceFichier.h"

void menuFichier();
SDL_Window* newWindow();
SDL_Window* ouvrir(char *adresse);
