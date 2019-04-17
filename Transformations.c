/* Module qui contient les fonctions de transformation de l'image */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL2_rotozoom.h>//instalation de la bibliothèque SDL2_gfx
#include "Transformations.h"


///Mise en niveaux de gris
 SDL_Surface mise_en_niveaux_de_gris(SDL_Surface image){
   for (int y = 0; y < image->h; y++)
     {
       for (int x = 0; x < image->w; x++)
	 {
	   Uint32 pixel = pixels[y * image->w + x];
	   Uint8 r, g, b, a;
	   SDL_GetRGBA(pixel, image->format, &r,&g,&b,&a);
	   Uint8 v = (r + g + b) /3;
	   pixels[(y * image->w) + x] = SDL_MapRGBA(image->format, v,v, v,a);
	 }
     }
   return image;
 }



//Mise en negatif
SDL_Surface mise_en_negatif(SDL_Surface image){
  for (int y = 0; y < image->h; y++)
    {
      for (int x = 0; x < image->w; x++)
        {
	  Uint32 pixel = pixels[y * image->w + x];
 
	  Uint8 r, g, b, a;
	  SDL_GetRGBA(pixel, image->format, &r,&g,&b, &a);

	  pixels[y * image->w + x] = SDL_MapRGBA(image->format, 255-r, 255-g, 255-b, a);;
        }
    }
  return image;
}


//Mise en noir et blanc
SDL_Surface noir_et_blanc(SDL_Surface image){
  for (int y = 0; y < image->h; y++)
    {
      for (int x = 0; x < image->w; x++)
	{
	  Uint32 pixel = pixels[y * image->w + x];
 
	  Uint8 r, g, b, a;
	  SDL_GetRGBA(pixel, image->format, &r,&g,&b,&a);

	  if((r+g+b)/3 < 127)
	    pixels[y * image->w + x] = SDL_MapRGBA(image->format, 0,0,0, a);
 			
	  else 
	    pixels[y * image->w + x] = SDL_MapRGBA(image->format, 255, 255, 255, a);
	}
    }
  return image;
}



//remplacement de couleur, avec ou sans marge de tolérance
SDL_Surface remplacement_couleur(SDL_Surface image, SDL_Color old_color, SDL_Color new_color, int marge){ //marge = 0 si pas de tolérance
  for (int y = 0; y < image->h; y++)
    {
      for (int x = 0; x < image->w; x++)
	{
	  Uint32 pixel = pixels[y * image->w + x];
 				
	  Uint8 r, g, b, a;
	  SDL_GetRGBA(pixel, image->format, &r,&g,&b, &a);
            	
	  if(abs(r - old_color.r) < marge && abs(g - old_color.g) < marge && abs(b - old_color.b) < marge)
	    pixels[y * image->w + x] = SDL_MapRGBA(image->format, new_color.r, new_color.g, new_color.b, a);
	}
    }	
  return image;
}


//Remplissage par une couleur donnée
SDL_Surface remplissage_par_une_couleur(SDL_Surface image, SDL_Color color){

  SDL_FillRect(image, NULL, SDL_MapRGBA(image->format, color.r, color.g, color.b, color.a));
	
  return image;
}




Uint8 luminosite_moins(Uint8 c, double n){ 
  return (Uint8)(SDL_pow ((double) c * SDL_pow(255, n-1), 1/n)); 
}

Uint8 luminosite_plus(Uint8 c, double n){ 
  return (Uint8) (255 * SDL_pow(((double) c) / 255, n)); 
}


//Gestion de la luminosité
SDL_Surface ajustement_luminosite(SDL_Surface image, char *op, int n){
  //op : désigne "+" || "-" pour l'augmentation et la diminution de luminosité
  //n : le nombre de fois qu'on applique ces fonctions

  double c = 0.5;
  int nb = 0;

  //Diminution de la luminosité
  if (strcmp(op, "-") == 0){
    while(nb < n){

      for(int i = 0; i < image->h; i++)
	{
	  for(int j = 0; j < image->w; j++)
	    {

	      SDL_Color color;
	      SDL_GetRGBA(pixels[i * image->w + j], image->format, &color.r, &color.g, &color.b, &color.a);

	      color.r = luminosite_moins(color.r, c);
	      color.g = luminosite_moins(color.g, c);
	      color.b = luminosite_moins(color.b, c);
  	
	      pixels[i * image->w + j] = SDL_MapRGBA(image->format, color.r, color.g, color.b, color.a);

	    }
	}
      nb++;
    }
  }
    
  //Augmentation de la luminosité
  if (strcmp(op, "+") == 0){
    while(nb < n){
      for(int i = 0; i < image->h; i++)
	{
	  for(int j = 0; j < image->w; j++)
	    {
	      SDL_Color color;
	      SDL_GetRGBA(pixels[i * image->w + j], image->format, &color.r, &color.g, &color.b, &color.a);

	      color.r = luminosite_plus(color.r, c);
	      color.g = luminosite_plus(color.g, c);
	      color.b = luminosite_plus(color.b, c);
	  
	      pixels[i * image->w + j] = SDL_MapRGBA(image->format, color.r, color.g, color.b, color.a);
	    }
	}
      nb++;
    }
  }

  return image;
}

//Gestion du contraste
Uint8 contraste(Uint8 c, double n){
  if(c <= 255 / 2)
    return (Uint8)( (255/2) * SDL_pow((double) 2 * c / 255, n));
  else
    return 255 - contraste(255 - c, n);
}

SDL_Surface ajustement_contraste(SDL_Surface image, int n){
  // n : le nombre de fois qu'on applique cette fonction

  double c = 2;
  int nb = 0;
  while(nb < n){

    for(int i = 0; i < image->h; i++){
      for(int j = 0; j < image->w; j++)
	{
	  SDL_Color color;
	  SDL_GetRGB(pixels[i * image->w + j], image->format, &color.r, &color.g, &color.b);

	  color.r = contraste(color.r, c);
	  color.g = contraste(color.g, c);
	  color.b = contraste(color.b, c);
		        
	  pixels[i * image->w + j] = SDL_MapRGB(image->format, color.r, color.g, color.b);
	}
      nb++;
    }
  }
	
  return image;
}



//Symétrie verticale et horizontale
SDL_Surface symetrie(SDL_Surface image, char *type){
  //type : indique le type de la symétrie (horizontale || verticale)
  if(strcmp(type,"horizontale") == 0){ 
    Uint32 *new_pixels = malloc(image->pitch * image->h);
    for(int j=0; j<(image->h); j++){
      for(int i=0; i<image->w; i++){
	new_pixels[j*(image->w)+i] = pixels[((image->h)-1-j)*image->w+i];
      }
    }
	
    image = SDL_CreateRGBSurfaceWithFormatFrom((void*)new_pixels, image->w, image->h, 32, image->pitch, image->format->format);
  }

  if(strcmp(type,"verticale") == 0){
    Uint32 *new_pixels = malloc(image->pitch * image->h);
    for(int j=0; j<(image->h); j++)
      for(int i=0; i<image->w; i++)
	new_pixels[j*(image->w)+i] = pixels[j*(image->w)-1-i];
		
    image = SDL_CreateRGBSurfaceWithFormatFrom((void*)new_pixels, image->w, image->h, 32, image->pitch, image->format->format);
  }

  return image;
}

//Rotation d'image par un multiple de 90°
SDL_Surface rotation(SDL_Surface image, int n){
  //n : le nombre de rotation à effectuer
  image = rotateSurface90Degrees(image, n);
  return image;
}
