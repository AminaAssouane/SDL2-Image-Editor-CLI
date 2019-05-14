#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <stdio.h>


void help(char* comm){
  if (comm == NULL){
    printf("\nPour plus d'informations sur la commande specifique, entrez help suivie de la commande.");
    printf("\nCOPY        Copie une region de l'image.");
    printf("\nCUT         Coupe une region de l'image.");
    printf("\nHELP        Affiche des informations sur les commandes de CIMP.");
    printf("\nNEW         Ouvre une nouvelle fenetre.");
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
      printf("\OPEN                 Manuel d'utilisation CIMP                 OPEN");
      printf("\n\nNOM");
      printf("\n  open - ouvre une image existante dans l'ordinateur.");
      printf("\n\nSYNTAXE");
      printf("\n  open cheminimage");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
    }
   if(strcasecmp(comm,"select") == 0){
      printf("\SELECT                 Manuel d'utilisation CIMP                 SELECT");
      printf("\n\nNOM");
      printf("\n  select - selectionne une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  select [x] [y] [largeur] [hauteur]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
   }
   if(strcasecmp(comm,"unselect") == 0){
      printf("\UNSELECT                 Manuel d'utilisation CIMP                 UNSELECT");
      printf("\n\nNOM");
      printf("\n  unselect - deselectionne une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  unselect");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
   }
   if(strcasecmp(comm,"save") == 0){
      printf("\SAVE                 Manuel d'utilisation CIMP                 SAVE");
      printf("\n\nNOM");
      printf("\n  save - sauvegarde l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  save [format] nom");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
    }
    if(strcasecmp(comm,"copy") == 0){
      printf("\COPY                 Manuel d'utilisation CIMP                 COPY");
      printf("\n\nNOM");
      printf("\n  copy - copie une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  copy [x] [y] [largeur] [hauteur]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
    }
    if(strcasecmp(comm,"copy") == 0){
      printf("\COPY                 Manuel d'utilisation CIMP                 COPY");
      printf("\n\nNOM");
      printf("\n  copy - copie une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  copy [x] [y] [largeur] [hauteur]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
    }
    if(strcasecmp(comm,"cut") == 0){
      printf("\CUT                 Manuel d'utilisation CIMP                 CUT");
      printf("\n\nNOM");
      printf("\n  cut - coupe une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  cut [x] [y] [largeur] [hauteur]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
    }
    if(strcasecmp(comm,"PASTE") == 0){
      printf("\PASTE                 Manuel d'utilisation CIMP                 PASTE");
      printf("\n\nNOM");
      printf("\n  paste - colle une region de l'image.");
      printf("\n\nSYNTAXE");
      printf("\n  paste [x] [y] [largeur] [hauteur]");
      printf("\n\nDESCRIPTION");
      printf("\n\nEXEMPLES");
      return;
    }
  printf("\nCette commande n'est pas prise en charge par l'utilitaire d'aide.");
  return;
}
