/* Fonctions intermédiaires (auxiliaires) du programme */

#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "Fichier.h"
#include "Auxiliaires.h"



/* Fonction qui trouve l'indice d'une fenêtre dans la liste "window[]" après avoir cliqué dessus */
int findWindowID(SDL_Window* tabW[], Uint32 wID, int nbWindows){
  for (int i = 0; i < nbWindows; i++){
    if (SDL_GetWindowID(tabW[i]) == wID){
      return i;
    }
  }
  fprintf(stdout,"Echec de la recherche de la fenêtre\n");
  exit(EXIT_FAILURE);
}

/* Fonction qui réarrange les fenêtre dans la liste "window[]" après la suppression d'une fenêtre */
void decalWindows(SDL_Window* tabW[], int i, int nbWindows){
  tabW[i] = tabW[nbWindows];  
}


/* Commande "help" qui affiche les informations sur toute les commandes.*/
void help(char* comm){
  if (comm == NULL){
    printf("\nPour plus d'informations sur la commande specifique, entrez help suivie de la commande.\n");
    printf("\nCOPY        Copie une region de l'image.");
    printf("\nCUT         Coupe une region de l'image.");
    printf("\nHELP        Affiche des informations sur les commandes de CIMP.");
    printf("\nNEW         Ouvre une nouvelle fenetre.");
    printf("\nQUIT        Quitte le programme CIMP.");
    printf("\nOPEN        Charge une image en memoire.");
    printf("\nPASTE       Colle dans une region de l'image.");
    printf("\nSELECT      Selectionne une region de l'image.");
    printf("\nSAVE        Sauvegarde l'image.");
    printf("\nUNSELECT    Deselectionne la selection actuelle.");
    return;
  }
  if (strcasecmp(comm,"new") == 0){
    printf("\nNEW                 Manuel d'utilisation CIMP                 NEW");
    printf("\n\nNOM");
    printf("\n  new - Ouvre une nouvelle fenetre vide");
    printf("\n\nSYNTAXE");
    printf("\n  new [nom] largeur hauteur");
    printf("\n\nDESCRIPTION");
    printf("\n\nEXEMPLES");
    return;
  }
  if(strcasecmp(comm,"help") == 0){
      printf("\nHELP                 Manuel d'utilisation CIMP                 HELP");
      printf("\n\nNOM");
      printf("\n  help - fournit des informations d'aide sur les commandes cimp");
      printf("\n\nSYNTAXE");
      printf("\n  help [commande]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
   }
   if(strcasecmp(comm,"open") == 0){
      printf("\nOPEN                 Manuel d'utilisation CIMP                 OPEN");
      printf("\n\nNOM");
      printf("\n  open - ouvre une image existante dans l'ordinateur.");
      printf("\n\nSYNTAXE");
      printf("\n  open cheminimage");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
    }
   if(strcasecmp(comm,"select") == 0){
      printf("\nSELECT                 Manuel d'utilisation CIMP                 SELECT");
      printf("\n\nNOM");
      printf("\n  select - selectionne une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  select [x] [y] [largeur] [hauteur]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
   }
   if(strcasecmp(comm,"unselect") == 0){
      printf("\nUNSELECT                 Manuel d'utilisation CIMP                 UNSELECT");
      printf("\n\nNOM");
      printf("\n  unselect - deselectionne une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  unselect");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
   }
   if(strcasecmp(comm,"save") == 0){
      printf("\nSAVE                 Manuel d'utilisation CIMP                 SAVE");
      printf("\n\nNOM");
      printf("\n  save - sauvegarde l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  save [format] nom");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
    }
    if(strcasecmp(comm,"copy") == 0){
      printf("\nCOPY                 Manuel d'utilisation CIMP                 COPY");
      printf("\n\nNOM");
      printf("\n  copy - copie une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  copy [x] [y] [largeur] [hauteur]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
    }
    if(strcasecmp(comm,"cut") == 0){
      printf("\nCUT                 Manuel d'utilisation CIMP                 CUT");
      printf("\n\nNOM");
      printf("\n  cut - coupe une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  cut [x] [y] [largeur] [hauteur]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
    }
    if(strcasecmp(comm,"PASTE") == 0){
      printf("\nPASTE                 Manuel d'utilisation CIMP                 PASTE");
      printf("\n\nNOM");
      printf("\n  paste - colle une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  paste [x] [y] [largeur] [hauteur]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
    }
    if(strcasecmp(comm,"quit") == 0){
      printf("\nQUIT                 Manuel d'utilisation CIMP                 QUIT");
      printf("\n\nNOM");
      printf("\n  quit - quitte le programme cimp.");
      printf("\n\nSYNTAXE");
      printf("\n  quit");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
    }
  printf("\nCette commande n'est pas prise en charge par l'utilitaire d'aide.");
  return;
}
