/* Fichier.h */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <assert.h>

#include "Types.h"

structWindow* newWindow();
structWindow* ouvrir(char *adresse);
void sauvegarde(structWindow* window, char* opt, char* name);
