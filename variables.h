
struct creation{

    char prenom[50];
    char nom[50];
    char id[50];
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

Produit produits[16] = {
    {1, "Carte Amazon", "Amazon", 50.0, 10, "Carte cadeau Amazon 50dh", {1,1,2025}},
    {2, "Carte Amazon", "Amazon", 100.0, 10, "Carte cadeau Amazon 100dh", {1,1,2025}},
    {3, "Carte Amazon", "Amazon", 200.0, 10, "Carte cadeau Amazon 200dh", {1,1,2025}},
    {4, "Carte Amazon", "Amazon", 500.0, 10, "Carte cadeau Amazon 500dh", {1,1,2025}},

    {5, "Carte Google Play", "Google Play", 50.0, 10, "Carte cadeau Google Play 50dh", {1,1,2025}},
    {6, "Carte Google Play", "Google Play", 100.0, 10, "Carte cadeau Google Play 100dh", {1,1,2025}},
    {7, "Carte Google Play", "Google Play", 200.0, 10, "Carte cadeau Google Play 200dh", {1,1,2025}},
    {8, "Carte Google Play", "Google Play", 500.0, 10, "Carte cadeau Google Play 500dh", {1,1,2025}},

    {9, "Carte Apple", "Apple", 50.0, 10, "Carte cadeau Apple 50dh", {1,1,2025}},
    {10, "Carte Apple", "Apple", 100.0, 10, "Carte cadeau Apple 100dh", {1,1,2025}},
    {11, "Carte Apple", "Apple", 200.0, 10, "Carte cadeau Apple 200dh", {1,1,2025}},
    {12, "Carte Apple", "Apple", 500.0, 10, "Carte cadeau Apple 500dh", {1,1,2025}},

    {13, "Carte PlayStation", "PlayStation", 50.0, 10, "Carte cadeau PlayStation 50dh", {1,1,2025}},
    {14, "Carte PlayStation", "PlayStation", 100.0, 10, "Carte cadeau PlayStation 100dh", {1,1,2025}},
    {15, "Carte PlayStation", "PlayStation", 200.0, 10, "Carte cadeau PlayStation 200dh", {1,1,2025}},
    {16, "Carte PlayStation", "PlayStation", 500.0, 10, "Carte cadeau PlayStation 500dh", {1,1,2025}}
};