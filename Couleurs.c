#include "Couleurs.h"

enum colors {
  BLACK, DARK_BLUE, DARK_GREEN, DARK_CYAN, DARK_RED,
  DARK_MAGENTA, DARK_YELLOW, LIGHT_GREY, GREY, BLUE, GREEN,
  CYAN, RED, MAGENTA, YELLOW, WHITE,
 
  NB_COULEURS
};

Uint32 color(SDL_Surface *image, char *string){
  int color = stringToEnum(string);
  return enumToColor(image, color);
}

Uint32 colorRGB(SDL_Surface *image, char* cr, char* cg, char* cb){
  int r = atoi(cr), g = atoi(cg), b = atoi(cb);
  return SDL_MapRGB(image->format,r,g,b);
}

Uint32 enumToColor(SDL_Surface *affichage, int color)
{
  switch (color){
  case BLACK : 
    return SDL_MapRGB(affichage->format, 0x00, 0x00, 0x00);
  case DARK_BLUE :
    return SDL_MapRGB(affichage->format, 0x00, 0x00, 0x80);
  case DARK_GREEN :
    return SDL_MapRGB(affichage->format, 0x00, 0x80, 0x00);
  case DARK_CYAN :
    return SDL_MapRGB(affichage->format, 0x00, 0x80, 0x80);
  case DARK_RED :
    return SDL_MapRGB(affichage->format, 0x80, 0x00, 0x00);
  case DARK_MAGENTA :
    return SDL_MapRGB(affichage->format, 0x80, 0x00, 0x80);
  case DARK_YELLOW :
    return SDL_MapRGB(affichage->format, 0x80, 0x80, 0x00);
  case LIGHT_GREY :
    return SDL_MapRGB(affichage->format, 0xC0, 0xC0, 0xC0);
  case GREY :
    return SDL_MapRGB(affichage->format, 0x80, 0x80, 0x80);
  case BLUE :
    return SDL_MapRGB(affichage->format, 0x00, 0x00, 0xFF);
  case GREEN :
    return SDL_MapRGB(affichage->format, 0x00, 0xFF, 0x00);
  case CYAN :
    return SDL_MapRGB(affichage->format, 0x00, 0xFF, 0xFF);
  case RED :
    return SDL_MapRGB(affichage->format, 0xFF, 0x00, 0x00);
  case MAGENTA :
    return SDL_MapRGB(affichage->format, 0xFF, 0x00, 0xFF);
  case YELLOW :
    return SDL_MapRGB(affichage->format, 0xFF, 0xFF, 0x00);
  case WHITE :
    return SDL_MapRGB(affichage->format, 0xFF, 0xFF, 0xFF);
  default :
    return SDL_MapRGB(affichage->format, 0x80, 0x80, 0x80);
  }
}

int stringToEnum(char *string){
  
  if (strcasecmp(string,"black") == 0)
    return BLACK;
  if (strcasecmp(string,"dark_blue") == 0)
    return DARK_BLUE;
  if (strcasecmp(string,"dark_green") == 0)
    return DARK_GREEN;
  if (strcasecmp(string,"dark_cyan") == 0)
    return DARK_CYAN;
  if (strcasecmp(string,"dark_red") == 0)
    return DARK_RED;
  if (strcasecmp(string,"dark_magenta") == 0)
    return DARK_MAGENTA;
  if (strcasecmp(string,"dark_yellow") == 0)
    return DARK_YELLOW;
  if (strcasecmp(string,"light_grey") == 0)
    return LIGHT_GREY;
  if (strcasecmp(string,"grey") == 0)
    return GREY;
  if (strcasecmp(string,"blue") == 0)
    return BLUE;
  if (strcasecmp(string,"green") == 0)
    return GREEN;
  if (strcasecmp(string,"cyan") == 0)
    return CYAN;
  if (strcasecmp(string,"red") == 0)
    return RED;
  if (strcasecmp(string,"magenta") == 0)
    return MAGENTA;
  if (strcasecmp(string,"yellow") == 0)
    return YELLOW;
  else
    return GREY;
}
