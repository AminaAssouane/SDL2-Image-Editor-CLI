#include <SDL.h>
#include <stdlib.h>
#include <stdio.h>

void menu(){
  printf("\nConsole Image Manipulation Program");
  printf("\n\n1. Fichier");
  printf("\n\n2. Selections");
  printf("\n\n3. Edition ");
  printf("\n\n4. Transformations\n\n");
}


int main(int argc, char** argv)
{
  int choix, choix2, still = 1;
  while (still == 1){
    menu();
    printf("\nChoisissez un nombre entre 1 et 4 : ");
    scanf("%d",&choix);
    switch(choix){
    case 1 :
      printf("\nI\\ Fichier\n0. Retour\n1. Nouvelle Fenetre\n2. Charger image\n3. Sauvegarder image\n");
      printf("\nChoisissez un nombre entre 0 et 3 : ");
      scanf("%d",&choix2);
      switch(choix2){
      case 0 :
	continue;
	break;
      case 1:
	break;
      case 2:
	break;
      case 3:
	break;
      }
      break;
    case 2 :
      printf("\nII\\ Selection\n0. Retour\n1. Fenetre entiere\n2. Selection rectangulaire\n3. A la souris\n4. Pixels regroupes\n");
      printf("\nChoisissez un nombre entre 0 et 4 : ");
      scanf("%d",&choix2);
      switch(choix2){
      case 0 :
	continue;
	break;
      case 1:
	break;
      case 2:
	break;
      case 3:
	break;
      case 4:
	break;
      }
      break;
    case 3 :
      printf("\nIII\\ Edition\n0. Retour\n1. Copier\n2. Couper\n3. Coller\n");
      printf("\nChoisissez un nombre entre 0 et 3 : ");
      scanf("%d",&choix2);
      switch(choix2){
      case 0 :
	continue;
	break;
      case 1:
	break;
      case 2:
	break;
      case 3:
	break;
      case 4:
	break;
      }
      break;
    case 4 :
      printf("\nIV\\ Transformations\n0. Retour\n1. Symetrie\n2. Rotation\n3. Recadrage\n4. Modification de la taille\n5. Remplissage\n6. Remplacement de couleur\n7. Negatif\n8. Niveaux de gris\n9. Noir et blanc\n10. Luminosite et contraste\n");
      printf("\nChoisissez un nombre entre 0 et 3 : ");
      scanf("%d",&choix2);
      switch(choix2){
      case 0 :
	continue;
	break;
      case 1:
	break;
      case 2:
	break;
      case 3:
	break;
      case 4:
	break;
      }
      break;
    default :
      break;
    }
  }
}
