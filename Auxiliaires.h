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
#include "Types.h"

int findWindowID(structWindow* tabW[], Uint32 wID, int nbWindows);
void decalWindows(structWindow* tabW[], int i, int nbWindows);
void help(char* commm);

#endif 