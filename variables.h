#include <stdbool.h>

struct creation{

    char prenom[50];
    char nom[50];
    char id[100];
    char mail[100];
    float solde;

};
struct creation profil;

typedef struct{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct{
    int idproduit;
    char nom[50];
    char categorie[30];
    float prix;
    int stock;
    char description[100];
    Date dateAjout;
}Produit;

char nvprenom[50];
char nvnom[50];
int soldplus = 3;
int choix;
char recherche[50];
int triprix = 0;
int achat = 0;
float total;
int quantite;

int achatproduits = 0;
int achatprix = 0;

char prenomnom[100];
char sansspace[100];

int j = 0;

int choix2;

int a = 0;
int idchat[160];
char nomchat[160][30];
float prixchat[160];
int quantitechat[160];

bool check = false;

char lowercherche[50];
int x , y;

int minprix;
int maxprix;

int sort;
Produit produits[16] = {
    {1, "carte amazon", "amazon", 50.0, 10, "Carte cadeau Amazon 50dh", {1,1,2025}},
    {2, "Carte Amazon", "amazon", 100.0, 10, "Carte cadeau Amazon 100dh", {1,1,2025}},
    {3, "Carte Amazon", "amazon", 200.0, 10, "Carte cadeau Amazon 200dh", {1,1,2025}},
    {4, "carte amazon", "amazon", 500.0, 10, "Carte cadeau Amazon 500dh", {1,1,2025}},

    {5, "carte google play", "google play", 50.0, 10, "Carte cadeau Google Play 50dh", {1,1,2025}},
    {6, "carte google play", "google play", 100.0, 10, "Carte cadeau Google Play 100dh", {1,1,2025}},
    {7, "carte google play", "google play", 200.0, 10, "Carte cadeau Google Play 200dh", {1,1,2025}},
    {8, "carte google play", "google play", 500.0, 10, "Carte cadeau Google Play 500dh", {1,1,2025}},

    {9, "carte apple", "apple", 50.0, 10, "Carte cadeau Apple 50dh", {1,1,2025}},
    {10, "carte apple", "apple", 100.0, 10, "Carte cadeau Apple 100dh", {1,1,2025}},
    {11, "carte apple", "apple", 200.0, 10, "Carte cadeau Apple 200dh", {1,1,2025}},
    {12, "carte apple", "apple", 500.0, 10, "Carte cadeau Apple 500dh", {1,1,2025}},

    {13, "carte playStation", "playStation", 50.0, 10, "Carte cadeau PlayStation 50dh", {1,1,2025}},
    {14, "carte playStation", "playStation", 100.0, 10, "Carte cadeau PlayStation 100dh", {1,1,2025}},
    {15, "carte playStation", "playStation", 200.0, 10, "Carte cadeau PlayStation 200dh", {1,1,2025}},
    {16, "carte playStation", "playStation", 500.0, 10, "Carte cadeau PlayStation 500dh", {1,1,2025}}
};