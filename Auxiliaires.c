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
    printf("\n    CLOSE             Ferme la fenetre.");
    printf("\n    CIRCLE            Dessine un cercle sur la fenetre. ");
    printf("\n    COLOR             Choisir une couleur.");  
    printf("\n    CONTRAST          Ajustement du contraste.");
    printf("\n    COPY              Copie une region de l'image.");
    printf("\n    CUT               Coupe une region de l'image.");
    printf("\n    CUTCOLOR          Coupe une region de l'image avec une couleur determinee.");
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
    printf("\n    RELOAD            Réinitialise l'image.");
    printf("\n    REPLACE_COLOR     Remplacement d'une couleur donnee.");
    printf("\n    ROTATE            Rotation de l'image.");
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
    printf("\n  new largeur hauteur");
    printf("\n\nDESCRIPTION");
    printf("\n  Ouvre une nouvelle fenetre avec la largeur et la hauteur");
    printf("\n\nEXEMPLES");
    printf("\n  new 500 600");
    printf("\n\n******************************************************************\n");
    return;
  }
  if(strcasecmp(comm,"help") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  help - fournit des informations d'aide sur les commandes cimp");
    printf("\n\nSYNTAXE");
    printf("\n  help [commande]");
    printf("\n\nDESCRIPTION");
    printf("\n  help : affiche toute les commandes possibles.");
    printf("\n  help commande : affiche les informations sur la commande en question.");
    printf("\n\nEXEMPLES");
    printf("\n  help select");
    printf("\n\n******************************************************************\n");
    return;
  }
  if(strcasecmp(comm,"open") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  open - ouvre une image existante dans l'ordinateur.");
    printf("\n\nSYNTAXE");
    printf("\n  open cheminimage");
    printf("\n\nDESCRIPTION");
    printf("\n  open cheminimage ");
    printf("\n\nEXEMPLES");
    printf("\n  open terre.bmp");
    printf("\n  open ../apple.png");
    printf("\n\n******************************************************************\n");
    return;
  }
  if(strcasecmp(comm,"RELOAD") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM : [reload]");
    printf("\n\nSYNTAXE");
    printf("\n  reload ");
    printf("\n\nDESCRIPTION");
    printf("\n  Réinitialise l'image.");
    printf("\n\nEXEMPLES\n");
    printf("\n******************************************************************\n");
    return;
  }
  
  if(strcasecmp(comm,"select") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  select - selectionne une region de l'image.");
    printf("\n\nSYNTAXE");
    printf("\n  select");
    printf("\n  select all");
    printf("\n  select [x] [y] [largeur] [hauteur]");
    printf("\n\nDESCRIPTION");
    printf("\n  select : permet de selectionner notre region a la souris. ");
    printf("\n    /!\\ WARNING : Selectionnez avec la souris de haut en bas, et de gauche a droite. /!\\");
    printf("\n  select all : permet de selectinner toute la fenetre.");
    printf("\n  select [x] [y] [largeur] [hauteur] : permet de selectionner un rectangle en entrant ces coordonnees directement dans le prompt.");
    printf("\n\nEXEMPLES");
    printf("\n  select 50 50 100 100\n");
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
    printf("\n  unselect : deselectionne la region selectionnee (et supprime ainsi le rectangle de selection)");
    printf("\n\nEXEMPLES");
    printf("\n\n******************************************************************\n");
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
    printf("\n  copy ");
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
    printf("\n  copy ");
    printf("\n\nDESCRIPTION");
    printf("\n  Copie la region de l'image qui est couramment selectionnee.");
    printf("\n  Si aucune region n'est selectionnee, copy retourne une erreure.");
    printf("\n\nEXEMPLES");
    printf("\n\n******************************************************************\n");
    return;
  }
  if(strcasecmp(comm,"cut") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  cut - coupe une region de l'image.");
    printf("\n\nSYNTAXE");
    printf("\n  cut");
    printf("\n\nDESCRIPTION");
    printf("\n  Coupe la region de l'image selectionnee, et la rempli avec la couleur par default, qui est le GRIS.\n  Si aucune region n'est selectionnee, cut renvoie une erreure.");
    printf("\n\nEXEMPLES\n");
    printf("\n******************************************************************\n");
    return;
  }
  if(strcasecmp(comm,"cutColor") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  curColor - coupe une region de l'image et la remplit avec une couleur choisie au prealable.");
    printf("\n\nSYNTAXE");
    printf("\n  cutColor ");
    printf("\n\nDESCRIPTION");
    printf("\n  Apres avoir choisit une couleur avec la commande COLOR, appeler cutColor remplit le rectangle selectionne avec cette couleur et le copie.");
    printf("\n\nEXEMPLES\n");
    printf("\n  color red, puis cutColor");
    printf("\n******************************************************************\n");
    return;
  }
  if(strcasecmp(comm,"paste") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  paste - colle une region de l'image.");
    printf("\n\nSYNTAXE");
    printf("\n  paste");
    printf("\n  paste [x] [y]");
    printf("\n\nDESCRIPTION");
    printf("\n  paste : colle la selection copiee apres un CLIC SOURIS.");
    printf("\n  paste [x] [y] : colle la selection copiee aux coordonnees (x,y)");
    printf("\n\nEXEMPLES\n");
    printf("\n  paste\n  paste 50 50");
    printf("\n\n******************************************************************\n");
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
    printf("\n  Permet de choisir une couleur pour dessinger sur l'image en specifiant soit : \n1. Son nom. \n2. Ses valeurs R, G & B.");
    printf("\n  Les couleurs disponibles sont : ");
    printf("\n    BLACK, DARK_BLUE, DARK_GREEN, DARK_CYAN, DARK_RED, ");
    printf("\n    DARK_MAGENTA, DARK_YELLOW, LIGHT_GREY, GREY, BLUE, ");
    printf("\n    GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE");
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
    printf("\n  Dessine un point de coordonnees [x,y].");
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
    printf("\n  Dessine un rectangle de commencant par les coordonnees [x,y], de largeur [largeur] et de hauteur [hauteur].");
    printf("\n\nEXEMPLES");
    printf("\n  rectangle 50 50 200 350");
    printf("\n\n******************************************************************\n");
    return;
  }

  if(strcasecmp(comm,"circle") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  circle - dessine un cercle sur l'image.");
    printf("\n\nSYNTAXE");
    printf("\n  circle [cx] [cy] [rayon]");
    printf("\n\nDESCRIPTION");
    printf("\n  Dessine un cercle de centre de coordonnees [cx,cy] et de rayon [rayon].");
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
    printf("\n  Dessine un disque de centre de coordonnees [cx,cy] et de rayon [rayon].");
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
    printf("\n  Mise en niveaux de gris de la region de l'image selectionnee.");
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
    printf("\n  Mise en negatif de la region de l'image selectionnee.");
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
    printf("\n  Mise en noir et blanc de la region de l'image selectionnee.");
    printf("\n\nEXEMPLES\n");
    printf("\n******************************************************************\n");
    return;
  }
  if(strcasecmp(comm,"REPLACE_COLOR") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM : [replace_color]");
    printf("\n\nSYNTAXE");
    printf("\n  replace_color [r1] [g1] [b1] [r2] [g2] [b2] [marge] ");
    printf("\n\nDESCRIPTION");
    printf("\n  Remplacement de la couleur {r1, g1, b1} par une nouvelle couleur {r2, g2, b2} avec ou sans marge.");
    printf("\n     0 <= r, g, b <= 255 ");
    printf("\n\nEXEMPLES\n");
    printf("\n******************************************************************\n");
    return;
  }
  if(strcasecmp(comm,"FILL_COLOR") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM : [FILL_COLOR]");
    printf("\n\nSYNTAXE");
    printf("\n  fill_color [r] [g] [b] ");
    printf("\n\nDESCRIPTION");
    printf("\n  Remplissage de la surface selectionnee par une couleur représentée en RGB .");
    printf("\n     0 <= r, g, b <= 255 ");
    printf("\n\nEXEMPLES\n");
    printf("\n******************************************************************\n");
    return;
  }
  if(strcasecmp(comm,"LIGHT") == 0){
    printf("\n\nNOM : [light]");
    printf("\n\nSYNTAXE");
    printf("\n  light [op] [n]");
    printf("\n\nDESCRIPTION");
    printf("\n  Ajustement de la luminosite de l'image:");
    printf("\n     [op] = '+' pour augmenter la luminosite");
    printf("\n     [op] = '-' pour augmenter la luminosite");
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
    printf("\n     [n] : le nombre de rotation souhaites");
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
  if(strcasecmp(comm,"CLOSE") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  close - ferme la fenetre.");
    printf("\n\nSYNTAXE");
    printf("\n  close");
    printf("\n\nDESCRIPTION");
    printf("\n  Ferme la fenetre sur laquelle nous avons le focus.");
    printf("\n\nEXEMPLES");  
    printf("\n\n******************************************************************\n");
    return;
  }
  if (strcasecmp(comm,"quit") == 0){
    printf("\n******************* Manuel d'utilisation CIMP ********************");
    printf("\n\nNOM");
    printf("\n  quit - quitte le programme");
    printf("\n\nSYNTAXE");
    printf("\n  quit");
    printf("\n\nDESCRIPTION");
    printf("\n  Permet a tout moment de quitter CIMP.");
    printf("\n\nEXEMPLES");
    printf("\n\n******************************************************************\n");
    return;
  }
  printf("\nCette commande n'est pas prise en charge par l'utilitaire d'aide.");
  return;
}
