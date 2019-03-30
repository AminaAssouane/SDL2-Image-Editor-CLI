/* Module qui contient les fonctions de transformation de l'image */

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "Transformations.h"


///Mise en niveaux de gris
SDL_Surface mise_en_niveaux_de_gris(SDL_Surface image){
	for (int y = 0; y < image->h; y++)
	{
	    for (int x = 0; x < image->w; x++)
	  	{
	          	
	    	Uint32 pixel = pixels[y * image->w + x];
			Uint8 r = pixel >> 16 & 0xFF;
			Uint8 g = pixel >> 8 & 0xFF;
			Uint8 b = pixel & 0xFF;
			Uint8 v = (r + g + b) /3;
			pixel = (0xFF << 24) | (v << 16) | (v << 8) | v;
			pixels[(y * image->w) + x] = pixel;
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
 
            Uint8 r = pixel >> 16 & 0xFF;
            Uint8 g = pixel >> 8 & 0xFF;
            Uint8 b = pixel & 0xFF;
 
            r = 255 - r;
            g = 255 - g;
            b = 255 - b;
 
            pixel = (0xFF << 24) | (r << 16) | (g << 8) | b;
            pixels[y * image->w + x] = pixel;
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
 
           	Uint8 r = pixel >> 16 & 0xFF;
           	Uint8 g = pixel >> 8 & 0xFF;
           	Uint8 b = pixel & 0xFF;
 			if((r+g+b)/3 < 127){ 
 				r = 0;
 				g = 0;
 				b = 0;
 			}
 			else{ 
 				r = 255;
 				g = 255;
 				b = 255; 
 			}
            	
 
            pixel = (0xFF << 24) | (r << 16) | (g << 8) | b;
            pixels[y * image->w + x] = pixel;
	    }
	}

}



//Remplissage par une couleur donnée
SDL_Surface remplissage_par_une_couleur(SDL_Surface image){

	SDL_FillRect(image, NULL, SDL_MapRGB(image->format, 255, 110, 100));
	
	return image;
}