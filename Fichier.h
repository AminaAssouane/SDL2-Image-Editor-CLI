/* Fichier.h */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

void menuFichier();
SDL_Window* newWindow(int largeur, int hauteur);
SDL_Window* ouvrir(char *adresse);
