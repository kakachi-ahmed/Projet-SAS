#include "variables.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void gestion_client()
{

   if (strlen(profil.nom) == 0)
   {

      printf("\n===Creer un compte==\n");

      printf("enter ton prenom : ");
      scanf(" %[^\n]", profil.prenom);

      printf("entrer ton nom : ");
      scanf(" %[^\n]", profil.nom);

      strcpy(profil.id, profil.prenom);
      strcat(profil.id, "2025");

      strcpy(profil.mail, profil.prenom);
      strcat(profil.mail, ".");
      strcat(profil.mail, profil.nom);
      strcat(profil.mail, "@kakachi.com");

      profil.solde = 1000.00;

      printf("\n===Profil cree avec succes===\n");
   }
   else if (strlen(profil.nom) != 0)
   {

      printf("1. Consultation du profil\n");
      printf("2. Modification du profil\n");

      printf("enter ton choix: ");
      scanf("%d", &choix);

      if (choix == 1)
      {

         printf("\n===Vos informations==\n");
         printf("Le id est : %s\n", profil.id);
         printf("Le Prenom est : %s\n", profil.prenom);
         printf("Le Nom est : %s\n", profil.nom);
         printf("Le Email est : %s\n", profil.mail);
         printf("Le Sold est : %.2fdh\n", profil.solde);
      }
      else if (choix == 2)
      {

         printf("\n===Modification du profil==\n");

         printf("enter le nouveau prenom : ");
         scanf(" %[^\n]", nvprenom);

         printf("enter le nouveau nom : ");
         scanf(" %[^\n]", nvnom);

         strcpy(profil.prenom, nvprenom);
         strcpy(profil.nom, nvnom);
      }
      else
      {
         printf("introuvable dans ce menu\n");
      }
   }
}

void Gestion_solde()
{

   if (strlen(profil.nom) != 0)
   {

      printf("1. Consultation du solde\n");
      printf("2. Dépôt d'argent\n");

      printf("entrer ton  choix : ");
      scanf("%d", &choix);

      if (choix == 1)
      {

         printf("le sold est %.2fdh", profil.solde);
      }
      else if (choix == 2)
      {

         printf("Il vous reste %d fois pour utiliser le crédit virtuel de 500dh\n", soldplus);

         printf("1. utiliser le crédit virtuel\n");
         printf("2. quitter\n");

         printf("entrer ton  choix : ");
         scanf("%d", &choix);

         if (choix == 1)
         {

            if (soldplus != 0)
            {

               soldplus--;
               profil.solde += 500.00;
            }
            else
            {

               printf("Vous navez plus aucun droit dutilisation du solde virtuel\n");
            }
         }
         else if (choix == 2)
         {

            printf("Retour a la liste");
         }
         else
         {

            printf("introuvable dans ce menu\n");
         }
      }
      else
      {

         printf("introuvable dans ce menu\n");
      }
   }
   else
   {

      printf("créer d'abord un compte");
   }
}

void acheter()
{
   printf("===pour acheter un produit entrer 1\n pour quitter enter 0\n===");

   printf("enter ton choix: ");
   scanf("%d", &choix);

   if (choix == 1)
   {
      printf("enter le id de produit : ");
      scanf("%d", &choix);

      for (int i = 0; i < 16; i++)
      {

         if (choix == produits[i].idproduit)
         {
            achat = i;
            break;
         }
      }

      if (achat >= 0 && achat <= 15)
      {

         printf("Combien voulez-vous acheter : ");
         scanf("%d", &quantite);

         if (quantite <= produits[achat].stock)
         {

            total = quantite * produits[achat].prix;

            printf("pour acheter %s prix : %.2f quantite : %d total de : %.2f \n", produits[achat].nom, produits[achat].prix, quantite, total);

            printf("1. pour confirmation\n 0. pour annulation\n");
            printf("enter ton choix : ");
            scanf("%d", &choix);

            if (choix == 1)
            {

               if (total <= profil.solde)
               {

                  printf("***Achat réussi***");

                  profil.solde -= total;
                  produits[achat].stock -= quantite;

                  achatproduits += quantite;
                  achatprix += total;
               }
            }
         }
         else
         {

            printf("Nous n'avons pas cette quantite");
         }
      }
   }else{
          Menu();
   }
}

// menu 3
void affichage_catalogue()
{

   for (int i = 0; i < 16; i++)
   {

      printf("categorie : %s | nom : %s | prix : %.2fdh | stock : %d\n", produits[i].categorie, produits[i].nom, produits[i].prix, produits[i].stock);
   }
}
void details_produit()
{

   printf("| idproduit > categorie > nom > prix > stock > description > date dajoute |\n");

   for (int i = 0; i < 16; i++)
   {

      printf("|%d|%s|%s|%.2fd|%d|%s|%d/%d/%d\n", produits[i].idproduit, produits[i].categorie, produits[i].nom, produits[i].prix, produits[i].stock, produits[i].description, produits[i].dateAjout.jour, produits[i].dateAjout.mois, produits[i].dateAjout.annee);
   }
   acheter();
}
void recherche_produits()
{

   printf("recherche par\n 1-nom\n 2-categorie\n");

   printf("entrer ton choix : ");
   scanf("%d", &choix);

   if (choix == 1)
   {

      printf("entrer le nom de produits : ");
      scanf(" %[^\n]", recherche);

      for (int i = 0; i < 16; i++)
      {

         if (strcmp(produits[i].nom, recherche) == 0)
         {

            printf("|idproduit : %d|categorie : %s|nom : %s|prix : %.2fd|stock : %d|description : %s|date dajoute : %d/%d/%d\n", produits[i].idproduit, produits[i].categorie, produits[i].nom, produits[i].prix, produits[i].stock, produits[i].description, produits[i].dateAjout.jour, produits[i].dateAjout.mois, produits[i].dateAjout.annee);
         }
      }
   }
   else if (choix == 2)
   {

      printf("entrer le nom de categorie : ");
      scanf(" %[^\n]", recherche);

      for (int i = 0; i < 16; i++)
      {

         if (strcmp(produits[i].categorie, recherche) == 0)
         {

            printf("|idproduit : %d|categorie : %s|nom : %s|prix : %.2fd|stock : %d|description : %s|date dajoute : %d/%d/%d\n", produits[i].idproduit, produits[i].categorie, produits[i].nom, produits[i].prix, produits[i].stock, produits[i].description, produits[i].dateAjout.jour, produits[i].dateAjout.mois, produits[i].dateAjout.annee);
         }
      }
   }
   else
   {
      printf("introuvable dans ce menu\n");
   }
}

/*void Tri_produits(){

        printf("tri par\n 1-prix\n 2-nom\n");

        printf("entrer ton choix : ");
        scanf("%d",&choix);

      if(choix == 1){

        printf("tri par\n 1.croissant\n 2.décroissant\n");

        printf("entrer ton choix : ");
        scanf("%d",&choix);

          if(choix == 1){

            for(int i = 0; i < 15; i++){

               for(int j = i + 1 ; i < 16 ; j++){

                   if(produits[i].prix > produits[j].prix){

                       triprix = j;

              }
            }
          }
        }
}*/

void catalogue_produits()
{

   printf("\n===Catalogue des Produits===\n");

   printf("1.affichage catalogue \n2.details produit\n3.recherche produits\n ");

   printf("enter ton choix: ");
   scanf("%d", &choix);

   switch (choix)
   {

   case 1:
      affichage_catalogue();
      break;
   case 2:
      details_produit();
      break;
   case 3:
      recherche_produits();
      break;
   }
}

void statistiques()
{

   if (strlen(profil.nom) != 0)
   {

      printf("J'ai achete %d produits : ", achatproduits);
      printf("Le prix total que j'ai achete est de %d dirhams. : ", achatprix);
   }
   else
   {

      printf("créer d'abord un compte");
   }
}

void Menu()
{

   do
   {
      printf("\n===Bienvenue Au Kakachi Store===\n");
      printf("1.  Gestion du profil client\n");
      printf("2.  Gestion du solde virtuel\n");
      printf("3.  Consultation des produits\n");
      ;
      printf("4.  Mes statistiques\n");
      printf("0.  Quitter l'application\n");

      printf("enter ton choix: ");
      scanf("%d", &choix);

      switch (choix)
      {

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
         catalogue_produits();
         break;
      case 4:
         printf("\n===Mon Statistique==\n");
         statistiques();
         break;
      case 5:
         acheter();
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
