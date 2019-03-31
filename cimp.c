#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "fcntl.h"
#include <unistd.h>
#include <readline/readline.h>
#include <strings.h>
#include <assert.h>

#include "cimp.h"
#include "Auxiliaires.h"
#include "Fichier.h"
#include "Edition.h"
#include "Selection.h"
#include "Transformations.h"


SDL_Event event;
SDL_Window* window[MAX_WIN];
SDL_Renderer *renderer;
SDL_Texture *texture;
int  nbWindows = 0, iWindow = 0;

void init_cimp()
{
    printf("\n\n\n                     **********************************\n");
    printf("\n\n\n                 Bienvenue sur votre editeur d'image CIMP     \n\n\n");
    printf("\n\n                     **********************************\n\n");

    printf("\n. Fichier : pour affichier le menu \"Fichier\"");
    printf("\n. Selections : pour afficher le menu \"Selection\"");
    printf("\n. Edition (Pas encore) ");
    printf("\n. Transformations (Pas encore)");
    printf("\n. Quitter : pour quitter CIMP\n");
    

}

//renvoie la taille de la ligne de commande
int args_length(char *args[]) {
    int i = 0;
    for (i = 0; args[i] != NULL; i++) {}
    return i;
}

// split_line la ligne de commande pour obtenir les arguments
char **split_line(char *line) {
    int pos = 0;
    char **tab;
    char *s;
    
    // alloue un tableau qui contiendra les arguments
    if ((tab = malloc(sizeof(char*) * SIZE_CMD)) == NULL)
        exit(1);

    s = strtok(line, SEPARATEUR);
    while (s != NULL) {
        tab[pos++] = s;
        s = strtok(NULL, SEPARATEUR);
    }

    tab[pos] = NULL;
    return tab;
}


int parse(char **cmd){
  // Si l'utilisateur n'a rien tapé, on sort
  if (args_length(cmd) == 0)
    return 0;
  if (strcasecmp(cmd[0],"fichier") == 0)
    menuFichier();
  if (strcasecmp(cmd[0],"nouvelle") == 0){
    window[nbWindows] = newWindow();
    nbWindows++;
    return 1;
  }
  if (strcasecmp(cmd[0],"ouvrir") == 0){
    if (args_length(cmd) < 2)
      return 0;
    window[nbWindows] = ouvrir(cmd[1]);
    nbWindows++;
    return 1;
  }
  if ((strcasecmp(cmd[0],"selection") == 0) && (args_length(cmd) == 1))
    menuSelection();
  if ((strcasecmp(cmd[0],"selection") == 0) && (args_length(cmd) == 2)){
    if (strcasecmp(cmd[1],"fenetre") == 0){ 
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      selectWindow(window[iWindow]);
    }
    if (strcasecmp(cmd[1],"rectangle") == 0){
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      selectRect(window[iWindow]);
    }
  }
  if (strcasecmp(cmd[0],"deselectionner") == 0){
    iWindow = findWindowID(window,event.window.windowID,nbWindows);
    deselectionner(window[iWindow]);
  }
  return 2;
}

void cimp() {

  assert(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) >= 0);
  
  char *line, **args;
  init_cimp();  
  do {
    /* S'il n'y a pas de fenêtre ouverte, on doit d'abord en ouvrir une, car SDL_Event ne marche pas sans */
    while (nbWindows == 0){
      line = readline("<cimp>: ");
      args = split_line(line);
      parse(args);
    }
    /* Ensuite, on peut executer notre programme normalement */
    while (SDL_PollEvent(&event)){
      switch(event.type){
      case SDL_WINDOWEVENT :
	if (event.window.event == SDL_WINDOWEVENT_CLOSE){
	  iWindow = findWindowID(window,event.window.windowID,nbWindows);
	  SDL_DestroyWindow(window[iWindow]);
	  nbWindows--;
	  decalWindows(window,iWindow,nbWindows);
	}
	break;
	
      case SDL_KEYDOWN :
	// on recupere la ligne de commande
	line = readline("<cimp>: ");
	args = split_line(line);
	parse(args);
	free(line);
	break;
   
      default :
	continue;
	break;
      }
    }
  } while(strcasecmp(args[0],"quitter") != 0);
  free(args);
  SDL_Quit();
}



