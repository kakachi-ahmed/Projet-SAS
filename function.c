#include "header.h"
#include "variables.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void gestion_client()
{

   if (strlen(profil.nom) == 0)
   {

      printf("\n===Creer un compte==\n");

      printf("enter ton prenom : ");
      scanf(" %[^\n]", profil.prenom);

      printf("enter ton nom : ");
      scanf(" %[^\n]", profil.nom);

      strcpy(prenomnom, profil.prenom);
      strcat(prenomnom, ".");
      strcat(prenomnom, profil.nom);

      for (int i = 0; prenomnom[i] != '\0'; i++)
      {
         if (prenomnom[i] != ' ')
         {
            sansspace[j] = prenomnom[i];
            j++;
         }
      }
      sansspace[j] = '\0';

      profil.id[0] = sansspace[0];
      strcat(profil.id, "2025");

      strcpy(profil.mail, sansspace);
      strcat(profil.mail, "@kakachi.com");

      profil.solde = 1000;

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
      printf("2. Depot d'argent\n");

      printf("entrer ton  choix : ");
      scanf("%d", &choix);

      if (choix == 1)
      {

         printf("le sold est %.2fdh", profil.solde);
      }
      else if (choix == 2)
      {

         printf("Il vous reste %d fois pour utiliser le credit virtuel de 500dh\n", soldplus);

         printf("1. utiliser le credit virtuel\n");
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

            printf("Retour a menu\n");
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
   if (strlen(profil.nom) != 0)
   {
      printf("\n1. pour acheter un produit \n 2. pour quitter\n===");

      printf("enter ton choix: ");
      scanf("%d", &choix2);

      if (choix2 == 1)
      {
         printf("enter le id de produit : ");
         scanf("%d", &choix);
         check = false;
         for (int i = 0; i < 16; i++)
         {

            if (choix == produits[i].idproduit)
            {
               achat = i;
               check = true;
               break;
            }

         }if(!check)
            {

               printf("le id de produit n'pas trouver");
            }

         if (achat >= 0 && achat <= 15)
         {

            printf("Combien voulez-vous acheter : ");
            scanf("%d", &quantite);

            if (quantite <= produits[achat].stock)
            {

               total = quantite * produits[achat].prix;

               printf("pour acheter %s prix : %.2f quantite : %d total de : %.2f \n", produits[achat].nom, produits[achat].prix, quantite, total);

               printf("1. pour confirmation\n 2. pour annulation\n");
               printf("enter ton choix : ");
               scanf("%d", &choix);

               if (choix == 1)
               {

                  if (total <= profil.solde)
                  {

                     profil.solde -= total;
                     produits[achat].stock -= quantite;

                     achatproduits += quantite;
                     achatprix += total;

                     strcpy(nomchat[a], produits[achat].nom);
                     prixchat[a] = produits[achat].prix;
                     quantitechat[a] = quantite;
                     a++;

                     printf("***Achat reussi***");


                  }
                  else
                  {

                     printf("Votre solde n'est pas suffisant pour finaliser l'achat");
                  }
               }
               else if (choix == 2)
               {

                  printf("annulation");
               }
               else
               {

                  printf("introuvable dans ce menu\n");
               }
            }
            else
            {

               printf("Nous n'avons pas cette quantite");
            }
         }
      }
      else if (choix2 == 2)
      {
         printf("quitter");
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

// menu 3
void affichage_catalogue()
{

   for (int i = 0; i < 16; i++)
   {

      printf("categorie : %s | id : %d |nom : %s | prix : %.2fdh | stock : %d\n", produits[i].categorie,produits[i].idproduit,produits[i].nom, produits[i].prix, produits[i].stock);
   }
   acheter();
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

   printf("recherche par\n 1-nom\n 2-categorie\n 3. prix\n");

   printf("entrer ton choix : ");
   scanf("%d", &choix);

   if (choix == 1)
   {
      check = false;
      printf("entrer le nom de produits : ");
      scanf(" %[^\n]", recherche);

      for (x = 0; recherche[x] != '\0'; x++)
      {
         if (recherche[x] >= 'A' && recherche[x] <= 'Z')
            lowercherche[x] = recherche[x] + 32;
         else
            lowercherche[x] = recherche[x];
      }
      lowercherche[x] = '\0';

      for (int i = 0; i < 16; i++)
      {

         if (strstr(produits[i].nom, lowercherche) != NULL)
         {

            printf("|idproduit : %d|categorie : %s|nom : %s|prix : %.2fdh|stock : %d|description : %s|date dajoute : %d/%d/%d\n", produits[i].idproduit, produits[i].categorie, produits[i].nom, produits[i].prix, produits[i].stock, produits[i].description, produits[i].dateAjout.jour, produits[i].dateAjout.mois, produits[i].dateAjout.annee);
            check = true;
         }
      }
      if (check)
         acheter();
      if (!check)
         printf("le nom de produits n'est pas trouver\n");
   }
   else if (choix == 2)
   {
      check = false;
      printf("entrer le nom de categorie : ");
      scanf(" %[^\n]", recherche);

      for (x = 0; recherche[x] != '\0'; x++)
      {
         if (recherche[x] >= 'A' && recherche[x] <= 'Z')
            lowercherche[x] = recherche[x] + 32;
         else
            lowercherche[x] = recherche[x];
      }
      lowercherche[x] = '\0';

      for (int i = 0; i < 16; i++)
      {

         if (strstr(produits[i].categorie, lowercherche) != NULL)
         {

            printf("|idproduit : %d|categorie : %s|nom : %s|prix : %.2fdh|stock : %d|description : %s|date dajoute : %d/%d/%d\n", produits[i].idproduit, produits[i].categorie, produits[i].nom, produits[i].prix, produits[i].stock, produits[i].description, produits[i].dateAjout.jour, produits[i].dateAjout.mois, produits[i].dateAjout.annee);
            check = true;

         }
      }
      if (check)
         acheter();
      if (!check)
         printf("le nom de categorie n'est pas trouver\n");
   }
   else if (choix == 3)
   {

      printf("enter min prix : ");
      scanf("%d", &minprix);

      printf("enter max prix : ");
      scanf("%d", &minprix);

      for (int i = 0; i < 16; i++)
      {

         if (minprix >= produits[i].prix && maxprix <= produits[i].prix)
         {

            printf("|idproduit : %d|categorie : %s|nom : %s|prix : %.2fdh|stock : %d|description : %s|date dajoute : %d/%d/%d\n", produits[i].idproduit, produits[i].categorie, produits[i].nom, produits[i].prix, produits[i].stock, produits[i].description, produits[i].dateAjout.jour, produits[i].dateAjout.mois, produits[i].dateAjout.annee);
            check = true;
         }
      }
      if (check)
         acheter();
      if (!check)
         printf("Il n'y a pas de produit à ce prix \n");
   }
   else
   {
      printf("introuvable dans ce menu\n");
   }
}

void Tri_produits()
{

   printf("tri par\n 1-prix\n 2-nom\n");
   printf("entrer ton choix : ");
   scanf("%d", &choix);

   if (choix == 1)
   {

      printf("tri par\n 1.croissant\n 2.décroissant\n");
      printf("entrer ton choix : ");
      scanf("%d", &choix);

      for (int i = 0; i < 16 - 1; i++)
      {
         sort = i;
         for (int j = i + 1; j < 16; j++)
         {

            if ((choix == 1 && produits[j].prix < produits[sort].prix) || (choix == 2 && produits[j].prix > produits[sort].prix))
            {

               sort = j;
            }
         }
         if (sort != i)
         {
            Produit temp = produits[i];
             produits[i] = produits[sort];
                  produits[sort] = temp;
         }
      }
   }
   else if (choix == 2)
   { 

      printf("tri par\n 1.croissant (a->z)\n 2.décroissant (z->a)\n");
      printf("entrer ton choix : ");
      scanf("%d", &choix);

      for (int i = 0; i < 16 - 1; i++)
      {
         sort = i;
         for (int j = i + 1; j < 16; j++)
         {

            if ((choix == 1 && strcmp(produits[j].nom, produits[sort].nom) < 0) || (choix == 2 && strcmp(produits[j].nom, produits[sort].nom) > 0))
                
            {
               sort = j;
            }
         }
         if (sort != i)
         {
             Produit temp = produits[i];
             produits[i] = produits[sort];
             produits[sort] = temp;
          
         }
      }
   }
   else
   {
      printf("introuvable dans ce menu\n");
   }

   for (int i = 0; i < 16; i++)
   {
      printf("|%d| %s | %.2f DH | %s | stock:%d\n",
      produits[i].idproduit, produits[i].nom, produits[i].prix, produits[i].categorie, produits[i].stock);
   }
}

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
   case 4:
      Tri_produits();
   default:
      printf("introuvable dans ce menu\n");
   }
}

void statistiques()
{

   if (strlen(profil.nom) != 0)
   {
      for (int i = 0; i < a; i++)
      {

      printf("jai achete le produit %s de prix %.2f le quantite est %d\n", nomchat[i], prixchat[i], quantitechat[i]);
      }
      printf("J'ai achete %d produits  \n", achatproduits);
      printf("Le prix total que j'ai achete est de %d dirhams \n", achatprix);
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
      case 0:
         printf("au revoir\n");
         break;
      default:
         printf("introuvable dans ce menu\n");
         break;
      }
   } while (choix != 0);
}
