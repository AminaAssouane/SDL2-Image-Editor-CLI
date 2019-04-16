#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL2_rotozoom.h>



#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600




SDL_Surface mise_en_niveaux_de_gris(SDL_Surface image);
SDL_Surface mise_en_negatif(SDL_Surface image);
SDL_Surface noir_et_blanc(SDL_Surface image);
SDL_Surface remplacement_couleur(SDL_Surface image, SDL_Color old_color, SDL_Color new_color, int marge);
SDL_Surface remplissage_par_une_couleur(SDL_Surface image, SDL_Color color);


SDL_Surface symetrie(SDL_Surface image, char *type);
SDL_Surface rotation(SDL_Surface image, int n);