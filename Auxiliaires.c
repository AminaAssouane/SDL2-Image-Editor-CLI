/* Fonctions intermédiaires (auxiliaires) du programme */

#include "Auxiliaires.h"



/* Fonction qui trouve l'indice d'une fenêtre dans la liste "window[]" après avoir cliqué dessus */
int findWindowID(SDL_Window* tabW[], Uint32 wID, int nbWindows){
  for (int i = 0; i < nbWindows; i++){
    if (SDL_GetWindowID(tabW[i]) == wID){
      return i;
    }
  }
  printf("Echec de la recherche de la fenêtre\n");
  return 0;
}

/* Fonction qui réarrange les fenêtre dans la liste "window[]" après la suppression d'une fenêtre */
void decalWindows(SDL_Window* tabW[], int i, int nbWindows){
  tabW[i] = tabW[nbWindows];  
}

void icon(SDL_Window* myWindow, char* comm){
  SDL_Surface* icone = IMG_Load(comm);
  assert(icone != NULL);
  SDL_SetWindowIcon(myWindow,icone);
}

/* Commande "help" qui affiche les informations sur toute les commandes.*/
void help(char* comm){
  if (comm == NULL){
    printf("\nListe des commandes possibles :\n");
    
    printf("\n    BLACKNWHITE       Mise en noir et blanc.");
    printf("\n    CIRCLE            Dessine un cercle sur la fenetre. ");
    printf("\n    COLOR             Choisir une couleur.");  
    printf("\n    CONTRAST          Ajustement du contraste.");
    printf("\n    COPY              Copie une region de l'image.");
    printf("\n    CUT               Coupe une region de l'image.");
    printf("\n    DRAW              Permet de dessiner avec la souris.");
    printf("\n    DISK              Dessine un disque sur l'image.");
    printf("\n    FILL_COLOR        Remplissage par une couleur donnee.");
    printf("\n    GREY              Mise en niveaux de gris.");
    printf("\n    HELP              Affiche des informations sur les commandes de CIMP.");
    printf("\n    HORIZONTAL        Dessine une ligne horizontale sur l'image.");
    printf("\n    ICON              Ajoute une icone a la fenetre.");
    printf("\n    LIGHT             Ajustement de la luminosite.");
    printf("\n    NEGATIVE          Mise en negatif.");
    printf("\n    NEW               Ouvre une nouvelle fenetre.");
    printf("\n    OPEN              Charge une image en memoire.");
    printf("\n    PASTE             Colle dans une region de l'image.");
    printf("\n    REPLACE_COLOR     Remplacement d'une couleur donnee.");
    printf("\n    ROTATE            Rotation de l'image.\n");
    printf("\n    SAVE              Sauvegarde l'image.");
    printf("\n    SELECT            Selectionne une region de l'image.");
    printf("\n    SYMMETRY          SymÃ©trie verticale et horizontale");
    printf("\n    UNSELECT          Deselectionne la selection actuelle.");    
    printf("\n    QUIT              Quitte le programme CIMP.");
    printf("\n\nPour plus d'informations sur une commande specifique, entrez help suivie de la commande.\n");
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
    printf("\n  Sauvegarde la fenetre selectionnee sur le disque au format specifie par l'option [format].\n  Quand aucun format n'est specifie, sauvagarde l'image au format BMP.");
    printf("\n\n  -PNG : Sauvegarde la fenetre selectionnee au format PNG, au chemin \"nom\".");
    printf("\n  -JPG : Sauvegarde la fenetre selectionnee au format JPG, au chemin \"nom\".");
    printf("\n  -BMP : Sauvegarde la fenetre selectionnee au format BMP, au chemin \"nom\".");
    printf("\n\nEXEMPLES");
    printf("\n  save ../apple");
    printf("\n          Sauvegarde la fenetre selectionnee sous le nom \"apple.bmp\" dans le repertoire parent du repertoire actuel.");
    printf("\n  save -png myimage");
    printf("\n          Sauvegarde la fenetre selectionnee sous le nom \"myimage.png\" dans le repertoire actuel.\n");
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
  if(strcasecmp(comm,"paste") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  paste - colle une region de l'image.");
    printf("\n\nSYNTAXE");
    printf("\n  paste [x] [y]");
    printf("\n\nDESCRIPTION");
    printf("\n\nEXEMPLES\n");
    printf("\n******************************************************************\n");
    return;
  }


  
    
  //------------------------------- * DESSIN * -------------------------------//

  if(strcasecmp(comm,"color") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  color - choisir une couleur.");
    printf("\n\nSYNTAXE");
    printf("\n  color nomcouleur ");
    printf("\n  color R G B");
    printf("\n\nDESCRIPTION");
    printf("\n  Permet de choisir une couleur pour dessinger sur l'image en specifiant soit : \n1. Son nom. \n2. Ses valeurs RGB.");
    printf("\n  Les couleurs disponibles sont : ");
    printf("\n\nEXEMPLES\n");
    printf("\n  color dark_green");
    printf("\n******************************************************************\n");
    return;
  }

  if(strcasecmp(comm,"point") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  point - dessine un point sur l'image.");
    printf("\n\nSYNTAXE");
    printf("\n  point [x] [y] ");
    printf("\n\nDESCRIPTION");
    printf("\n\nEXEMPLES\n");
    printf("\n******************************************************************\n");
    return;
  }

  if(strcasecmp(comm,"clear") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  clear - efface tout l'ecran.");
    printf("\n\nSYNTAXE");
    printf("\n  clear");
    printf("\n\nDESCRIPTION");
    printf("\n\nEXEMPLES\n");
    printf("\n******************************************************************\n");
    return;
  }    

  if(strcasecmp(comm,"horizontal") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  horizontal - dessine une ligne horizontale sur l'image.");
    printf("\n\nSYNTAXE");
    printf("\n  horizontal [x] [y] [largeur] ");
    printf("\n\nDESCRIPTION");
    printf("\n\nEXEMPLES\n");
    printf("\n******************************************************************\n");
    return;
  }
    
  if(strcasecmp(comm,"vertical") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  vertical - dessine une ligne verticale sur l'image.");
    printf("\n\nSYNTAXE");
    printf("\n  vertical [x] [y] [hauteur]");
    printf("\n\nDESCRIPTION");
    printf("\n\nEXEMPLES\n");
    printf("\n******************************************************************\n");
    return;
  }

  if(strcasecmp(comm,"rectangle") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  rectangle - dessine un rectangle sur l'image.");
    printf("\n\nSYNTAXE");
    printf("\n  rectangle [x] [y] [largeur] [hauteur]");
    printf("\n\nDESCRIPTION");
    printf("\n\nEXEMPLES\n");
    printf("\n******************************************************************\n");
    return;
  }

  if(strcasecmp(comm,"circle") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  circle - dessine un cercle sur l'image.");
    printf("\n\nSYNTAXE");
    printf("\n  circle [cx] [cy] [rayon]");
    printf("\n\nDESCRIPTION");
    printf("\n\nEXEMPLES\n");
    printf("\n******************************************************************\n");
    return;
  }
    
  if(strcasecmp(comm,"disk") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  disk - dessine un disque sur l'image.");
    printf("\n\nSYNTAXE");
    printf("\n  disk [cx] [cy] [rayon]");
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
    printf("\n  Mise en nÃ©gatif.");
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
    printf("\n  Ajustement de la luminositÃ© de l'image:");
    printf("\n     [op] = '+' pour augmenter la luminositÃ©");
    printf("\n     [op] = '-' pour augmenter la luminositÃ©");
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
    printf("\n  SymÃ©trie verticale ou horizontale de l'image.");
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
    printf("\n  Rotation de l'image par un multiple de 90Â°.");
    printf("\n     [n] : le nombre de rotation souhaitÃ©");
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
