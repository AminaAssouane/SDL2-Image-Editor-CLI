#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600



void loop();
void SDL_ExitWithError(const char *message);

int main(int argc, char const *argv[])
{
    SDL_Window *window =  NULL;
    SDL_Renderer *renderer = NULL;


    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
         SDL_ExitWithError("Initialisaion SDL");


    //creation fenetre + rendu
    if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) != 0)
        SDL_ExitWithError("Impossible de créer la fenêtre et le rendu");


    SDL_RenderPresent(renderer);

    loop();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
}


//Permet au programme de tourner en boucle
void loop ()
{
    SDL_bool program_launched = SDL_TRUE;
    while(program_launched)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))//Pour capturer tout les événements
        {
            switch(event.type)
            {
                case SDL_QUIT : //si on veut fermer la fenetre en cliquant sur la croix
                    program_launched = SDL_FALSE;
                    break;

                default:
                    break;
            }
        }
    }
}

// Gestion des erreurs
void SDL_ExitWithError(const char *message)
{
    SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}