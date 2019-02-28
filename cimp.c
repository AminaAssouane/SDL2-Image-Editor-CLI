#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>


void SDL_ExitWithError(const char *message);

int main(int argc, char const *argv[])
{
    SDL_Window *window =  NULL;
    SDL_Renderer *renderer = NULL;


    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
         SDL_ExitWithError("Initialisaion SDL");


    //creation fenetre + rendu
    if(SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer) != 0)
        SDL_ExitWithError("Impossible de créer la fenêtre et le rendu");


    SDL_RenderPresent(renderer);

    /*--------------------------------------------------------*/
    
    SDL_Delay(6000);
    /*--------------------------------------------------------*/

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}


// Gestion des erreurs
void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}