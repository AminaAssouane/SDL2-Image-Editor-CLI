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

Uint8 luminosite_moins(Uint8 c, double n);
Uint8 luminosite_plus(Uint8 c, double n);
SDL_Surface ajustement_luminosite(SDL_Surface image, char *op, int n);

Uint8 contraste(Uint8 c, double n);
SDL_Surface ajustement_contraste(SDL_Surface image, int n);


SDL_Surface symetrie(SDL_Surface image, char *type);
SDL_Surface rotation(SDL_Surface image, int n);

