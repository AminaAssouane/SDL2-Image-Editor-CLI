
#include "Dessin.h"

/* Dessine un point */ 
void drawPoint(SDL_Surface* image, int x, int y, Uint32 coul)
{
  *((Uint32*)(image->pixels) + x + y * image->w) = coul;
}

/* Dessine un point après s'être assuré que les coordonnées sont bien dans l'image */
void drawPointSafe(SDL_Surface* image, int x, int y, Uint32 coul)
{
  if (x >= 0 && x < image->w &&
      y >= 0 && y < image->h)
    drawPoint(image, x, y, coul);
}

/* Efface notre fenetre */
void clear(SDL_Surface* image, Uint32 coul)
{
  SDL_FillRect(image, NULL, coul);
}

/* Dessine une ligne horizontale */
void ligneHorizontale(SDL_Surface* image, int x, int y, int w, Uint32 coul)
{
  SDL_Rect r;
 
  r.x = x;
  r.y = y;
  r.w = w;
  r.h = 1;
 
  SDL_FillRect(image, &r, coul);
}

/* Dessine une ligne verticale */
void ligneVerticale(SDL_Surface* image, int x, int y, int h, Uint32 coul)
{
  SDL_Rect r;
 
  r.x = x;
  r.y = y;
  r.w = 1;
  r.h = h;
 
  SDL_FillRect(image, &r, coul);
}

/* Dessine un rectangle */
void rectangle(SDL_Surface* image, int x, int y, int w, int h, Uint32 coul)
{
  ligneHorizontale(image, x, y, w, coul);
  ligneHorizontale(image, x, y + h - 1, w, coul);
  ligneVerticale(image, x, y + 1, h - 2, coul);
  ligneVerticale(image, x + w - 1, y + 1, h - 2, coul);
}

/* Dessine un cercle */
void cercle(SDL_Surface* image, int cx, int cy, int rayon, Uint32 coul)
{
  int d, y, x;
 
  d = 3 - (2 * rayon);
  x = 0;
  y = rayon;
 
  while (y >= x) {
    drawPointSafe(image, cx + x, cy + y, coul);
    drawPointSafe(image, cx + y, cy + x, coul);
    drawPointSafe(image, cx - x, cy + y, coul);
    drawPointSafe(image, cx - y, cy + x, coul);
    drawPointSafe(image, cx + x, cy - y, coul);
    drawPointSafe(image, cx + y, cy - x, coul);
    drawPointSafe(image, cx - x, cy - y, coul);
    drawPointSafe(image, cx - y, cy - x, coul);
 
    if (d < 0)
      d = d + (4 * x) + 6;
    else {
      d = d + 4 * (x - y) + 10;
      y--;
    }
 
    x++;
  }
}

/* Dessine un disque */
void disque(SDL_Window* window, int cx, int cy, int rayon, Uint32 coul)
{
  SDL_Surface* image = SDL_GetWindowSurface(window);
  int d, y, x;
 
  d = 3 - (2 * rayon);
  x = 0;
  y = rayon;
 
  while (y >= x) {
    ligneHorizontale(image, cx - x, cy - y, 2 * x + 1, coul);
    ligneHorizontale(image, cx - x, cy + y, 2 * x + 1, coul);
    ligneHorizontale(image, cx - y, cy - x, 2 * y + 1, coul);
    ligneHorizontale(image, cx - y, cy + x, 2 * y + 1, coul);
 
    if (d < 0)
      d = d + (4 * x) + 6;
    else {
      d = d + 4 * (x - y) + 10;
      y--;
    }
 
    x++;
  }
  SDL_UpdateWindowSurface(window);
}
