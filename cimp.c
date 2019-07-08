
#include "cimp.h"

SDL_Event event;
SDL_Window* window[MAX_WIN];
Uint32 couleur;
Selection* selection;
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
  

  //------------------------------ * FICHIER * -------------------------------//
  
  else if (strcasecmp(cmd[0],"new") == 0){
    if (args_length(cmd) < 3){
      printf("Syntaxe incorrecte ! Consultez [help new]\n");
      return 0;
    }
    else {
      window[nbWindows] = newWindow(cmd[1],cmd[2]);
      nbWindows++;
    }
    return 1;
  }
  
  else if (strcasecmp(cmd[0],"open") == 0){
    if (args_length(cmd) < 2){
      printf("Syntaxe incorrecte ! Consultez [help open]\n");
      return 0;
    }
    else {
      window[nbWindows] = ouvrir(cmd[1]);
      nbWindows++;
      return 1;
    }
  }
  else if (strcasecmp(cmd[0],"reload") == 0){
    if (args_length(cmd) != 1){
      printf("Syntaxe incorrecte ! Consultez [help reload]\n");
      return 0;
    }
    else {
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
    }
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      window[iWindow] = reload(window[iWindow]);
      return 1;
    }
  }
  
  else if (strcasecmp(cmd[0],"save") == 0){
    if ((args_length(cmd) < 2) || (args_length(cmd) > 3)){
      printf("Syntaxe incorrecte ! Consultez [help save]\n");
      return 0;
    }
    else {
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
    }
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

  //------------------------------ * SELECTION * -------------------------------//

  else if (strcasecmp(cmd[0],"select") == 0){
    if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
    }
    if (args_length(cmd) == 1){ 
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      deselectionner(selection);
      selection = selectMouse(window[iWindow]);
      return 1;
    }
    if ((args_length(cmd) == 2) && (strcasecmp(cmd[1],"all") == 0)){
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      deselectionner(selection);
      selection = selectWindow(window[iWindow]);
      return 1;
    }
    if (args_length(cmd) == 5){
      int x = atoi(cmd[1]), y = atoi(cmd[2]), l = atoi(cmd[3]), h = atoi(cmd[4]);
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      deselectionner(selection);
      selection = selectRect(window[iWindow],x,y,l,h);
      return 1;
    }
    else {
      printf("Syntaxe incorrecte ! Consultez [help select]\n");
      return 0;
    }
  }
  
  else if (strcasecmp(cmd[0],"unselect") == 0){
    if (args_length(cmd) > 1){
      printf("Syntaxe incorrecte ! Consultez [help unselect]\n");
      return 0;
    }
    else {
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
    }
      deselectionner(selection);
      selection = NULL;
      return 1;
    }
  }

  //-------------------------------- * EDITION * ---------------------------------//

  else if (strcasecmp(cmd[0],"copy") == 0){
    if (args_length(cmd) > 1){
      printf("Syntaxe incorrecte ! Consultez \"help copy\".\n");
      return 0;
    }
    else {
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      copier(selection);
      return 1;
    }
  }

  else if (strcasecmp(cmd[0],"paste") == 0){
    if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
    }
    if (args_length(cmd) == 3){
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      coller(window[iWindow],selection,cmd[1],cmd[2]);
      return 1;
    }
    if (args_length(cmd) == 1){
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      collerSouris(window[iWindow],selection);
      return 1;
    }
    else {     
      printf("Syntaxe incorrecte ! Consultez \"help paste\"\n");
      return 0;
    }
  }

  else if (strcasecmp(cmd[0],"cut") == 0){
    if (args_length(cmd) == 1){
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      couper(selection);
      return 1;
    }
    else {     
      printf("Syntaxe incorrecte ! Consultez \"help cut\"\n");
      return 0;
    }
  }

  else if (strcasecmp(cmd[0],"cutColor") == 0){
    if (args_length(cmd) == 1){
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      couperColor(selection,couleur);
      return 1;
    }
    else {     
      printf("Syntaxe incorrecte ! Consultez \"help cutColor\"\n");
      return 0;
    }
  }

  //-------------------------------- * DESSIN * ---------------------------------//

  else if (strcasecmp(cmd[0],"color") == 0){
    if (args_length(cmd) == 2){
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      couleur = color(SDL_GetWindowSurface(window[iWindow]),cmd[1]);
      return 1;
    }
    if (args_length(cmd) == 4){
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      couleur = colorRGB(SDL_GetWindowSurface(window[iWindow]),cmd[1],cmd[2],cmd[3]);
      return 1;
    }
    else {
      printf("\nSyntaxe incorrecte ! Consultez \"help color\".\n");
      return 0;
    }
  }

  else if (strcasecmp(cmd[0],"clear") == 0){
    if (args_length(cmd) == 1){
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      clear(SDL_GetWindowSurface(window[iWindow]), color(SDL_GetWindowSurface(window[iWindow]),"red"));
      SDL_UpdateWindowSurface(window[iWindow]);
      return 1;
    }
    else {
      printf("\nSyntaxe incorrecte ! Consultez \"help clear\".\n");
      return 0;
    }
  }

  else if (strcasecmp(cmd[0],"point") == 0){
    if (args_length(cmd) == 3){
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      int x = atoi(cmd[1]), y = atoi(cmd[2]);
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      drawPointSafe(SDL_GetWindowSurface(window[iWindow]),x,y,couleur);
      SDL_UpdateWindowSurface(window[iWindow]);
      return 1;
    }
    else {
      printf("\nSyntaxe incorrecte ! Consultez \"help point\".\n");
      return 0;
    }
  }

  else if (strcasecmp(cmd[0],"horizontal") == 0){
    if (args_length(cmd) == 4){
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }      
      int x = atoi(cmd[1]), y = atoi(cmd[2]), l = atoi(cmd[3]);
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      ligneHorizontale(SDL_GetWindowSurface(window[iWindow]),x,y,l,couleur);
      SDL_UpdateWindowSurface(window[iWindow]);
      return 1;
    }
    else {
      printf("\nSyntaxe incorrecte ! Consultez \"help horizontal\".\n");
      return 0;
    }
  }

  else if (strcasecmp(cmd[0],"vertical") == 0){
    if (args_length(cmd) == 4){
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      int x = atoi(cmd[1]), y = atoi(cmd[2]), l = atoi(cmd[3]);
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      ligneVerticale(SDL_GetWindowSurface(window[iWindow]),x,y,l,couleur);
      SDL_UpdateWindowSurface(window[iWindow]);
      return 1;
    }
    else {
      printf("\nSyntaxe incorrecte ! Consultez \"help vertical\".\n");
      return 0;
    }
  }
  
  else if (strcasecmp(cmd[0],"rectangle") == 0){
    if (args_length(cmd) == 5){  
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }   
      int x = atoi(cmd[1]), y = atoi(cmd[2]), l = atoi(cmd[3]), h = atoi(cmd[4]);
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      rectangle(SDL_GetWindowSurface(window[iWindow]),x,y,l,h,couleur);
      SDL_UpdateWindowSurface(window[iWindow]);
      return 1;
    }
    else {
      printf("\nSyntaxe incorrecte ! Consultez \"help rectangle\".\n");
      return 0;
    }
  }

  else if (strcasecmp(cmd[0],"circle") == 0){
    if (args_length(cmd) == 4){
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      int x = atoi(cmd[1]), y = atoi(cmd[2]), l = atoi(cmd[3]);
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      cercle(SDL_GetWindowSurface(window[iWindow]),x,y,l,couleur);
      SDL_UpdateWindowSurface(window[iWindow]);
      printf("\nupdated");
      return 1;
    }
    else {
      printf("\nSyntaxe incorrecte ! Consultez \"help circle\".\n");
      return 0;
    }
  }

  else if (strcasecmp(cmd[0],"disk") == 0){
    if (args_length(cmd) == 4){
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      int x = atoi(cmd[1]), y = atoi(cmd[2]), l = atoi(cmd[3]);
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      disque(window[iWindow],x,y,l,couleur);
      SDL_UpdateWindowSurface(window[iWindow]);
      return 1;
    }
    else {
      printf("\nSyntaxe incorrecte ! Consultez \"help disk\".\n");
      return 0;
    }
  }
  
  //------------------------------ * TRANSFORMATIONS * -------------------------------//
  
  else if(strcasecmp(cmd[0], "grey") == 0){
    if(args_length(cmd) != 1){
      printf("Syntaxe incorrecte ! Consultez [help grey]\n");
      return 0;
    }
    else{
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      if ((selection == NULL) || (selection->selection == 0)){
      	printf("Aucune region selectionnee. Veuillez d'abord selectionner une region.\n");
      	return 0;
      }
      mise_en_niveaux_de_gris(selection);
      SDL_UpdateWindowSurface(selection->window);     
      free(selection);
      selection = NULL;
      return 1;
    }
  }

  else if(strcasecmp(cmd[0], "negative") == 0){
    if(args_length(cmd) != 1){
      printf("Syntaxe incorrecte ! Consultez [help negative]\n");
      return 0;
    }
    else{
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      if ((selection == NULL) || (selection->selection == 0)){
      	printf("Aucune region selectionnee. Veuillez d'abord selectionner une region.\n");
      	return 0;
      }
      mise_en_negatif(selection); 
      SDL_UpdateWindowSurface(selection->window);
      free(selection);
      selection = NULL;
      return 1;
    }
  }

  else if(strcasecmp(cmd[0], "blacknwhite") == 0){
    if(args_length(cmd) != 1){
      printf("Syntaxe incorrecte ! Consultez [help blacknwhite]\n");
      return 0;
    }
    else{
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      if ((selection == NULL) || (selection->selection == 0)){
        	printf("Aucune region selectionnee. Veuillez d'abord selectionner une region.\n");
        	return 0;
      }
      noir_et_blanc(selection); 
      SDL_UpdateWindowSurface(selection->window);
      free(selection);
      selection = NULL;
      return 1;
    }
  }

  else if(strcasecmp(cmd[0], "replace_color") == 0){
    if(args_length(cmd) != 8){
      printf("Syntaxe incorrecte ! Consultez [help replace_color]\n");
      return 0;
    }
    else{
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      if ((selection == NULL) || (selection->selection == 0)){
      	printf("Aucune region selectionnee. Veuillez d'abord selectionner une region.\n");
      	return 0;
      }
      int r_old = atoi(cmd[1]);
      int g_old = atoi(cmd[2]);
      int b_old = atoi(cmd[3]);
      
      int r_new = atoi(cmd[4]);
      int g_new = atoi(cmd[5]);
      int b_new = atoi(cmd[6]);

      int marge = atoi(cmd[7]);

      SDL_Color color_old = create_color(r_old, g_old, b_old);
      SDL_Color color_new = create_color(r_new,g_new,b_new);
      remplacement_couleur(selection, color_old, color_new, marge);
      SDL_UpdateWindowSurface(selection->window);
      free(selection);
      selection = NULL;
      return 1;
    }
  }

  else if(strcasecmp(cmd[0], "fill_color") == 0){
    if(args_length(cmd) != 4){
      printf("Syntaxe incorrecte ! Consultez [help fill_color]\n");
      return 0;
    }
    else
      {
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      if ((selection == NULL) || (selection->selection == 0)){
      	printf("Aucune region selectionnee. Veuillez d'abord selectionner une region.\n");
      	return 0;
      }
      
      int r = atoi(cmd[1]);
      int g = atoi(cmd[2]);
      int b = atoi(cmd[3]);
      printf("%d\n", b);
      SDL_Color color = create_color(r,g,b);

      remplissage_par_une_couleur(selection, color); 
      SDL_UpdateWindowSurface(selection->window);
      free(selection);
      selection = NULL;     
      return 1;
    }
  }

  else if(strcasecmp(cmd[0], "light") == 0){
    if(args_length(cmd) == 2){
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
       if ((selection == NULL) || (selection->selection == 0)){
      	printf("Aucune region selectionnee. Veuillez d'abord selectionner une region.\n");
      	return 0;
      }
      
      ajustement_luminosite(selection, cmd[1]); 
      SDL_UpdateWindowSurface(selection->window);
      free(selection);
      selection = NULL;
      return 1;
    }
    else{
      printf("Syntaxe incorrecte ! Consultez [help light]\n");
      return 0;
    }
  }

  else if(strcasecmp(cmd[0], "contrast") == 0){
    if(args_length(cmd) != 1){
      printf("Syntaxe incorrecte ! Consultez [help contrast]\n");
      return 0;
    }
    else{
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
       if ((selection == NULL) || (selection->selection == 0)){
      	printf("Aucune region selectionnee. Veuillez d'abord selectionner une region.\n");
      	return 0;
      }
       
      ajustement_contraste(selection); 
      SDL_UpdateWindowSurface(selection->window);
      free(selection);
      selection = NULL;
      return 1;
    }
  }

  else if(strcasecmp(cmd[0], "symmetry") == 0){
    if(args_length(cmd) == 2){
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      if(strcasecmp("h", cmd[1]) != 0 && strcasecmp("v", cmd[1])){
           printf("Syntaxe incorrecte ! Consultez [help symmetry]\n");
            return 0;
      }
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      window[iWindow] = symetrie(window[iWindow], cmd[1]);
      return 0;
    }
    else{
      printf("Syntaxe incorrecte ! Consultez [help symmetry]\n");
      return 0;
    }
  }
  
  else if(strcasecmp(cmd[0], "rotate") == 0){
    if(args_length(cmd) != 1){
      printf("Syntaxe incorrecte ! Consultez \"help rotate\"\n");
      return 0;
    }
    else{
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      iWindow = findWindowID(window,event.window.windowID,nbWindows);

      window[iWindow] = rotation(window[iWindow]);
      
      return 0;
    }
    }
    

  //------------------------------ * AUXILIAIRES * -------------------------------//

  else if (strcasecmp(cmd[0],"help") == 0){
    if (args_length(cmd) > 2)
      printf("Syntaxe incorrecte ! Consultez [help help]\n");
    else
      help(cmd[1]);
    return 1;
  }


  else if (strcasecmp(cmd[0],"quit") == 0){
    if (args_length(cmd) > 1){
      printf("Syntaxe incorrecte ! Consultez [help quit]\n");
      return 0;
    }
    else {
      exit(0);
    }
  }

  else if (strcasecmp(cmd[0],"close") == 0){
    if (args_length(cmd) > 1){
      printf("\nSyntaxe incorrecte ! Consultez \"help close\"");
      return 0;
    }
    else {
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      SDL_DestroyWindow(window[iWindow]);
      nbWindows--;
      decalWindows(window,iWindow,nbWindows);
    }
  }
 
  else if (strcasecmp(cmd[0],"icon") == 0){
    if (args_length(cmd) != 2)
      printf("Syntaxe incorrecte ! Consultez [help icon]\n");
    else {   
      if(nbWindows <= 0){
        printf("Aucune fenetre pour executer la commande\n");
        return 0;
      }   
      iWindow = findWindowID(window,event.window.windowID,nbWindows);
      icon(window[iWindow],cmd[1]);
    }
    return 1;
  }

  else{
    printf("Commande non valide ! consultez le menu help\n");
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
	  SDL_DestroyWindow(window[iWindow]);
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
  } while(strcasecmp(args[0],"quit") != 0);
  SDL_Quit();
}



