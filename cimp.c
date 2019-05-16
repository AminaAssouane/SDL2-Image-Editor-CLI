
#include "cimp.h"

SDL_Event event;
structWindow* window[MAX_WIN];
SDL_Renderer *rendererCache;
int  nbWindows = 0, iWindow = 0;

void init_cimp()
{
    printf("\n\n\n                     **********************************\n");
    printf("\n\n\n                 Bienvenue sur votre editeur d'image CIMP     \n\n\n");
    printf("\n\n                     **********************************\n\n");
    

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
    assert ((tab = malloc(sizeof(char*) * SIZE_CMD)) != NULL);


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
  
  if (strcasecmp(cmd[0],"help") == 0){
    if (args_length(cmd) > 2)
      printf("\nLa syntaxe de la commande n'est pas correcte");
    else
      help(cmd[1]);
    return 1;
  }

  if (strcasecmp(cmd[0],"icon") == 0){
    if (args_length(cmd) != 2)
      printf("\nLa syntaxe de la commande n'est pas correcte");
    else {      
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      icon(window[iWindow],cmd[1]);
    }
    return 1;
  }
  
  if (strcasecmp(cmd[0],"new") == 0){
    if (args_length(cmd) < 3){
      printf("\nLa syntaxe de la commande n'est pas correcte");
      return 0;
    }
    else {
      window[nbWindows] = newWindow(cmd[1],cmd[2]);
      nbWindows++;
    }
    return 1;
  }
  
  if (strcasecmp(cmd[0],"open") == 0){
    if (args_length(cmd) < 2){
      printf("\nLa syntaxe de la commande n'est pas correcte");
      return 0;
    }
    else {
      window[nbWindows] = ouvrir(cmd[1]);
      nbWindows++;
      return 1;
    }
  }
  
  if (strcasecmp(cmd[0],"save") == 0){
    if ((args_length(cmd) < 2) || (args_length(cmd) > 3)){
      printf("\nLa syntaxe de la commande n'est pas correcte");
      return 0;
    }
    else {
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      if (args_length(cmd) == 2){
	sauvegarde(window[iWindow], NULL, cmd[1]);
	return 1;
      }
      else {
	sauvegarde(window[iWindow], cmd[1], cmd[2]);
	return 1;
      }	
    }
  }

  if (strcasecmp(cmd[0],"select") == 0){
    if (args_length(cmd) == 1){ 
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      selectRect(window[iWindow]);
      return 1;
    }
    if (args_length(cmd) == 2){
      printf("\ntwo arguments");
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      selectMouse(window[iWindow]);
      printf("\ndone");
      return 1;
    }
    if (args_length(cmd) == 5){
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      selectRect(window[iWindow]);
      return 1;
    }
    else {
      printf("\nLa syntaxe de la commande n'est pas correcte.");
      return 0;
    }
  }
  
  if (strcasecmp(cmd[0],"unselect") == 0){
    if (args_length(cmd) > 1){
      printf("\nLa syntaxe de la commande n'est pas correcte");
      return 0;
    }
    else {
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      deselectionner(window[iWindow]);
    }
  }

  if (strcasecmp(cmd[0],"quit") == 0){
    if (args_length(cmd) > 1){
      printf("\nLa syntaxe de la commande n'est pas correcte");
      return 0;
    }
    else {
      exit(0);
    }
  }

  //------------------------------ * TRANSFORMATIONS * -------------------------------//

  if(strcasecmp(cmd[0], "grey") == 0){
    if(args_length(cmd) > 1){
      printf("\nLa syntaxe de la commande n'est pas correcte");
      return 0;
    }
    else{
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      //mise_en_niveaux_de_gris();
      return 0;
    }
  }

  if(strcasecmp(cmd[0], "negative") == 0){
    if(args_length(cmd) > 1){
      printf("\nLa syntaxe de la commande n'est pas correcte");
      return 0;
    }
    else{
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      //mise_en_negatif();
      return 0;
    }
  }

  if(strcasecmp(cmd[0], "blacknwhite") == 0){
    if(args_length(cmd) > 1){
      printf("\nLa syntaxe de la commande n'est pas correcte");
      return 0;
    }
    else{
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      //noir_et_blanc();
      return 0;
    }
  }

  if(strcasecmp(cmd[0], "replace_color") == 0){
    if(args_length(cmd) > 1){
      printf("\nLa syntaxe de la commande n'est pas correcte");
      return 0;
    }
    else{
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      //remplacement_couleur();
      return 0;
    }
  }

  if(strcasecmp(cmd[0], "fill_color") == 0){
    if(args_length(cmd) > 1){
      printf("\nLa syntaxe de la commande n'est pas correcte");
      return 0;
    }
    else{
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      //remplissage_par_une_couleur();
      return 0;
    }
  }

  if(strcasecmp(cmd[0], "light") == 0){
    if(args_length(cmd) > 1){
      printf("\nLa syntaxe de la commande n'est pas correcte");
      return 0;
    }
    else{
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      //ajustement_luminosite();
      return 0;
    }
  }

  if(strcasecmp(cmd[0], "contrast") == 0){
    if(args_length(cmd) > 1){
      printf("\nLa syntaxe de la commande n'est pas correcte");
      return 0;
    }
    else{
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      //remplacement_contraste();
      return 0;
    }
  }

  if(strcasecmp(cmd[0], "symmetry") == 0){
    if(args_length(cmd) > 1){
      printf("\nLa syntaxe de la commande n'est pas correcte");
      return 0;
    }
    else{
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      //symmetry();
      return 0;
    }
  }

  if(strcasecmp(cmd[0], "rotate") == 0){
    if(args_length(cmd) > 1){
      printf("\nLa syntaxe de la commande n'est pas correcte");
      return 0;
    }
    else{
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      //rotation();
      return 0;
    }
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
      line = readline("\n<cimp>: ");
      args = split_line(line);
      parse(args);
    }
    /* Ensuite, on peut executer notre programme normalement */
    while (SDL_PollEvent(&event)){
      switch(event.type){
      case SDL_WINDOWEVENT :
	if (event.window.event == SDL_WINDOWEVENT_CLOSE){
	  iWindow = findWindowID(window,event.window.windowID,nbWindows);
	  SDL_DestroyWindow(window[iWindow]->window);
	  nbWindows--;
	  decalWindows(window,iWindow,nbWindows);
	}
	break;
	
      case SDL_KEYDOWN :
	// on recupere la ligne de commande
	line = readline("\n<cimp>: ");
	args = split_line(line);
	parse(args);
	free(line);
	free(args);
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



