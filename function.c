#include "variables.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void Menu(){

    printf("1.  Gestion du profil client\n");
    printf("2.  Gestion du solde virtuel\n");
    printf("3.  Consultation des produits\n");
    printf("4.  Effectuer un achat\n");
    printf("3.  Consultation des produits\n");
    printf("5.  Mes statistiques\n");
    printf("0.  Quitter l'application\n");
    
    do{
        
        printf("enter ton choix: ");
        scanf("%d",&choix);

        if(choix >= 0 && choix <= 5){
         switch(choix){
 
      case 1:
         printf("\n===Gestion du profil client===\n");
         void gestion_client();
         break;
      case 2:
         printf("\n===Gestion du solde virtuel===\n");
         
         break;
      case 3:
         printf("\n===Consultation des produits===\n");
         
         break;
      case 4:
         printf("\n===Effectuer un achat==\n");
         
         break;
      case 5:
         printf("\n===Mes statistiques==\n");
         
         break;
      case 0:
         printf("au revoir\n");
         break;
      }
      
        }else{
           printf("introuvable dans ce menu\n");
    }

    } while (choix != 0);
    
    
}


void gestion_client(){

    if(strlen(profil.nom) == 0){
  
          printf("entrer ton nom : ");
          scanf("%[^\n]" , profil.nom);

          printf("enter ton prenom : ");
          scanf("%[^\n]" , profil.prenom);

          strcat(profil.id,profil.prenom );
          strcat(profil.id,"2025");

          strcat(profil.mail,profil.prenom);
          strcat(profil.mail,profil.nom);
          strcat(profil.mail,"@kakachi.com");

          profil.solde = 1000;
    }else{
    
           printf("1. Consultation du profil\n");
           printf("2. Modification du profil\n");
        
           printf("enter ton choix: ");
           scanf("%d",&choix);

           if(choix == 1){

              printf("\n===Vos informations==\n");
              printf("Le Prenom est : %s\n",profil.prenom);
              printf("Le Nom est : %s\n",profil.nom);
              printf("Le Email est : %s\n",profil.prenom);
              printf("Le Sold est : %d", profil.solde);

           }





    }



    
}