#include <stdio.h>
#include <string.h>
#include <stdbool.h>

 struct creation{

    char prenom[30];
    char nom[30];
    char id[30];
    char mail[60];
    int solde;

};
bool check = false;
struct creation profil;
char dh[2]= "dh";
int choix;
void gestion_client(){

     
     
if(strlen(profil.nom) == 0){
  
          printf("entrer ton nom : ");
          scanf(" %s" , profil.nom);
          getchar();
          printf("enter ton prenom : ");
          scanf(" %s" , profil.prenom);
          getchar();
          profil.id[0] = '\0';  
          profil.mail[0] = '\0';

          strcat(profil.id,profil.prenom );
          strcat(profil.id,"2025");

          strcat(profil.mail,profil.prenom);
          strcat(profil.mail,profil.nom);
          strcat(profil.mail,"@kakachi.com");

          profil.solde = 1000;

          printf("\n===Profil cree avec succes===\n");
          
          
    }else if(strlen(profil.nom) != 0){
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
int main(){
    
    gestion_client();
    

}