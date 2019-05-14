#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>

void colorSelect();
void selectWindow(SDL_Window *window);
void selectRect(SDL_Window *window, char* x, char* y, char* largeur, char* hauteur);
void deselectionner(SDL_Window *window);
