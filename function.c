#include "variables.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

 
void gestion_client(){

     
    if(strlen(profil.nom) == 0){

         printf("\n===Creer un compte==\n");

          printf("enter ton prenom : ");
          scanf(" %[^\n]" , profil.prenom);
        
          printf("entrer ton nom : ");
          scanf(" %[^\n]" , profil.nom);

          strcpy(profil.id,profil.prenom );
          strcat(profil.id,"2025");

          strcpy(profil.mail,profil.prenom);
          strcat(profil.mail,".");
          strcat(profil.mail,profil.nom);
          strcat(profil.mail,"@kakachi.com");

          profil.solde = 1000.00;

          printf("\n===Profil cree avec succes===\n");
          
          
    }else if(strlen(profil.nom) != 0){
           printf("1. Consultation du profil\n");
           printf("2. Modification du profil\n");
        
           printf("enter ton choix: ");
           scanf("%d",&choix);

      if(choix == 1){

              printf("\n===Vos informations==\n");
              printf("Le id est : %s\n",profil.id);
              printf("Le Prenom est : %s\n",profil.prenom);
              printf("Le Nom est : %s\n",profil.nom);
              printf("Le Email est : %s\n",profil.mail);
              printf("Le Sold est : %.2fdh\n", profil.solde);

      }else if(choix == 2){
           
              printf("\n===Modification du profil==\n");

              printf("enter le nouveau prenom : ");
              scanf(" %[^\n]" , nvprenom);

              printf("enter le nouveau nom : ");
              scanf(" %[^\n]" , nvnom);

              strcpy(profil.prenom,nvprenom);
              strcpy(profil.nom,nvnom);

      }else{
              printf("introuvable dans ce menu\n"); 
      }
   }
}

void Gestion_solde(){
   
   if(strlen(profil.nom) != 0){

         printf("1. Consultation du solde\n");
         printf("2. Dépôt d'argent\n");

         printf("entrer ton  choix : ");
         scanf("%d",&choix);
   
   if(choix == 1){
         
          printf("le sold est %.2fdh",profil.solde);

   }else if(choix == 2){

    printf("Il vous reste %d fois pour utiliser le crédit virtuel de 500dh\n",soldplus);

         printf("1. utiliser le crédit virtuel\n");
         printf("2. quitter\n");

         printf("entrer ton  choix : ");
         scanf("%d",&choix);

      if(choix == 1){
         
         if(soldplus != 0){

         soldplus--;
         profil.solde += 500.00;

         }else{

            printf("Vous navez plus aucun droit dutilisation du solde virtuel\n");
         }
         }else if (choix == 2){

         printf("Retour a la liste");
      }else{
         
         printf("introuvable dans ce menu\n"); 
      }
    }else{

         printf("introuvable dans ce menu\n"); 
    }
   }else{
       
         printf("créer d'abord un compte");
   }
}


void Menu(){

    
    do{
          printf("\n===Bienvenue Au Kakachi Store===\n");
          printf("1.  Gestion du profil client\n");
          printf("2.  Gestion du solde virtuel\n");
          printf("3.  Consultation des produits\n");
          printf("4.  Effectuer un achat\n");
          printf("3.  Consultation des produits\n");
          printf("5.  Mes statistiques\n");
          printf("0.  Quitter l'application\n");

        printf("enter ton choix: ");
        scanf("%d",&choix);

         switch(choix){
 
      case 1:
         printf("\n===Gestion du profil client===\n");
         gestion_client();
         break;
      case 2:
         printf("\n===Gestion du solde virtuel===\n");
         Gestion_solde();
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
      default:
         printf("introuvable dans ce menu\n"); 
         break;
       }
    } while (choix != 0);
}
