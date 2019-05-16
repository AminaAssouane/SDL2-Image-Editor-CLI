/* Fonctions intermÈdiaires (auxiliaires) du programme */

#include "Auxiliaires.h"



/* Fonction qui trouve l'indice d'une fenÍtre dans la liste "window[]" aprËs avoir cliquÈ dessus */
int findWindowID(structWindow* tabW[], Uint32 wID, int nbWindows){
  for (int i = 0; i < nbWindows; i++){
    if (SDL_GetWindowID(tabW[i]->window) == wID){
      return i;
    }
  }
  fprintf(stdout,"Echec de la recherche de la fenÍtre\n");
  exit(EXIT_FAILURE);
}

/* Fonction qui rÈarrange les fenÍtre dans la liste "window[]" aprËs la suppression d'une fenÍtre */
void decalWindows(structWindow* tabW[], int i, int nbWindows){
  tabW[i] = tabW[nbWindows];  
}

void icon(structWindow* myWindow, char* comm){
  SDL_Surface* icone = IMG_Load(comm);
  assert(icone != NULL);
  SDL_SetWindowIcon(myWindow->window,icone);
}

/* Commande "help" qui affiche les informations sur toute les commandes.*/
void help(char* comm){
  if (comm == NULL){
    printf("\nListe des commandes possibles :\n");
    printf("\n    [COPY]             Copie une region de l'image.");
    printf("\n    [CUT]              Coupe une region de l'image.");
    printf("\n    [HELP]             Affiche des informations sur les commandes de CIMP.");
    printf("\n    [ICON]             Ajoute une icone a la fenetre.");
    printf("\n    [NEW]              Ouvre une nouvelle fenetre.");
    printf("\n    [OPEN]             Charge une image en memoire.");
    printf("\n    [PASTE]            Colle dans une region de l'image.");
    printf("\n    [SELECT]           Selectionne une region de l'image.");
    printf("\n    [SAVE]             Sauvegarde l'image.");
    printf("\n    [UNSELECT]         Deselectionne la selection actuelle.");
   
    printf("\n    [GREY]             Mise en niveaux de gris.");
    printf("\n    [NEGATIVE]         Mise en negatif.");
    printf("\n    [BLACKNWHITE]      Mise en noir et blanc.");
    printf("\n    [REPLACE_COLOR]    Remplacement d'une couleur donnee.");
    printf("\n    [FILL_COLOR]       Remplissage par une couleur donnee.");
    printf("\n    [LIGHT]            Ajustement de la luminosit√©.");
    printf("\n    [CONTRAST]         Ajustement du contraste.");
    printf("\n    [SYMMETRY]         Sym√©trie verticale et horizontale");
    printf("\n    [ROTATE]           Rotation de l'image.\n");
    printf("\nPour plus d'informations sur la commande specifique, entrez help suivie de la commande.\n");
    return;
  }
  if (strcasecmp(comm,"new") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  new - Ouvre une nouvelle fenetre vide");
    printf("\n\nSYNTAXE");
    printf("\n  new [nom] largeur hauteur");
    printf("\n\nDESCRIPTION");
    printf("\n\nEXEMPLES\n");
    printf("\n******************************************************************\n");
    return;
  }
  if(strcasecmp(comm,"help") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM");
      printf("\n  help - fournit des informations d'aide sur les commandes cimp");
      printf("\n\nSYNTAXE");
      printf("\n  help [commande]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
   }
   if(strcasecmp(comm,"open") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM");
      printf("\n  open - ouvre une image existante dans l'ordinateur.");
      printf("\n\nSYNTAXE");
      printf("\n  open cheminimage");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
    }
   if(strcasecmp(comm,"select") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM");
      printf("\n  select - selectionne une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  select [x] [y] [largeur] [hauteur]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
   }
   if(strcasecmp(comm,"unselect") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM");
      printf("\n  unselect - deselectionne une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  unselect");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
   }
   if(strcasecmp(comm,"save") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM");
      printf("\n  save - sauvegarde l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  save [format] nom");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
    }
    if(strcasecmp(comm,"copy") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM");
      printf("\n  copy - copie une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  copy [x] [y] [largeur] [hauteur]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
    }
    if(strcasecmp(comm,"cut") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM");
      printf("\n  cut - coupe une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  cut [x] [y] [largeur] [hauteur]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
    }
    if(strcasecmp(comm,"PASTE") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM");
      printf("\n  paste - colle une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  paste [x] [y] [largeur] [hauteur]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
    }

    //----------------------------- * TRANSFORMATION * -----------------------------//
    if(strcasecmp(comm,"GREY") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM : [grey]");
      printf("\n\nSYNTAXE");
      printf("\n  grey ");
      printf("\n\nDESCRIPTION");
      printf("\n  Mise en niveaux de gris.");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
    }
    if(strcasecmp(comm,"NEGATIVE") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM : [negative]");
      printf("\n\nSYNTAXE");
      printf("\n  negative ");
      printf("\n\nDESCRIPTION");
      printf("\n  Mise en n√©gatif.");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
    }
    if(strcasecmp(comm,"BLACKNWHITE") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM : [blacknwhite]");
      printf("\n\nSYNTAXE");
      printf("\n  blacknwhite ");
      printf("\n\nDESCRIPTION");
      printf("\n  Mise en noir et blanc.");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
    }
    if(strcasecmp(comm,"REPLACE_COLOR") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
     printf("\n\nNOM : [replace_color]");
      printf("\n\nSYNTAXE");
      printf("\n  replace_color [old] [new] ");
      printf("\n\nDESCRIPTION");
      printf("\n  Remplacement de la couleur \"old\" par une nouvelle couleur \"new\".");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
    }
    if(strcasecmp(comm,"FILL_COLOR") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM : [FILL_COLOR]");
      printf("\n\nSYNTAXE");
      printf("\n  fill_color [color] ");
      printf("\n\nDESCRIPTION");
      printf("\n  Remplissage de la surface par la couleur \"color\".");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
    }
    if(strcasecmp(comm,"LIGHT") == 0){
      printf("\n\nNOM : [light]");
      printf("\n\nSYNTAXE");
      printf("\n  light [op] [n]");
      printf("\n\nDESCRIPTION");
      printf("\n  Ajustement de la luminosit√© de l'image:");
      printf("\n     [op] = '+' pour augmenter la luminosit√©");
      printf("\n     [op] = '-' pour augmenter la luminosit√©");
      printf("\n     [n] : le nombre de fois qu'on applique light");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
    }
    if(strcasecmp(comm,"CONTRAST") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM : [contrast]");
      printf("\n\nSYNTAXE");
      printf("\n  contrast [n] ");
      printf("\n\nDESCRIPTION");
      printf("\n  Ajustement du contrast:");
      printf("\n     [n] : le nombre de fois qu'on applique contrast");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
    }
    if(strcasecmp(comm,"SYMMETRY") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM : [symmetry]");
      printf("\n\nSYNTAXE");
      printf("\n  symmetry [type] ");
      printf("\n\nDESCRIPTION");
      printf("\n  Sym√©trie verticale ou horizontale de l'image.");
      printf("\n     [type] = 'horizontale' / 'verticale' ");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
    }
    if(strcasecmp(comm,"ROTATE") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM : [rotate]");
      printf("\n\nSYNTAXE");
      printf("\n  rotate [n] ");
      printf("\n\nDESCRIPTION");
      printf("\n  Rotation de l'image par un multiple de 90¬∞.");
      printf("\n     [n] : le nombre de rotation souhait√©");
      printf("\n\nEXEMPLES\n");
      printf("\n******************************************************************\n");
      return;
    }
     if(strcasecmp(comm,"ICON") == 0){
      printf("\n******************* Manuel d'utilisation CIMP ********************");
      printf("\n\nNOM");
      printf("\n  icon - change l'icone de la fenetre.");
      printf("\n\nSYNTAXE");
      printf("\n  icon chemin");
      printf("\n\nDESCRIPTION");
      printf("\n  Ajoute l'icone specifiee par le chemin \"chemin\" comme icone de notre fenetre.");
      printf("\n\nEXEMPLES");
      printf("\n  icon apple.png\n");  
      printf("\n******************************************************************\n");
      return;
    }
  printf("\nCette commande n'est pas prise en charge par l'utilitaire d'aide.");
  return;
}
