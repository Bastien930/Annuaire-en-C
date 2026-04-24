#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define WIN32_LEAN_AND_MEAN  // Exclut certaines parties de windows.h, y compris wtypes.h
#include <windows.h>
//groupe 7
#include "message.h"
#include "client.h"
#include "affichage.h"
#include "tri.h"
#include "validation.h"
#include "utilitaire.h"


#define chemin5 "./annuaire_5000_entrees.csv"
#define chemin4 "./annuaire_1000_entrees.csv"
#define chemin3 "./annuaire_500_entrees.csv"
#define chemin2 "./annuaire_100_entrees.csv"
#define chemin "./annuaire_50_entrees.csv"

int main()
{
    int taille_max = 6000;
    int taille_actuelle = 0;
    char option;
    bool flag=true;
    bool valide_reponse;
    int nb=0;
    int *pt=&nb;
    init_date();
    printf("la date actuelle : %danne %dmois %djour\n",date_act.tm_year+1900,date_act.tm_mon+1,date_act.tm_mday);
    FILE *fic = fopen(chemin, "r") ; // a pour ajout
    if( fic == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE) ;
    }
    taille_actuelle = compte_ligne(fic);
    CLIENT liste_clients[taille_actuelle];
    remplir_liste_clients(fic,liste_clients,taille_actuelle);
    int complexite = tri_avec_deplacement_vide(liste_clients,taille_actuelle,CRITERE_NOM);
    printf("la complexite est de %d et la recherche de %d pour un fichier de %d clients\n",complexite,rechercher_des_clients(liste_clients,taille_actuelle,pt,NULL,NULL,"franck",NULL),taille_actuelle);
    fclose(fic) ;
    complexite=0;
    nb=0;

    FILE *fic2 = fopen(chemin2, "r") ; // a pour ajout
    if( fic2 == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE) ;
    }
    taille_actuelle = compte_ligne(fic2);
    CLIENT liste_clients_2[taille_actuelle];
    remplir_liste_clients(fic2,liste_clients_2,taille_actuelle);
    complexite = tri_avec_deplacement_vide(liste_clients_2,taille_actuelle,CRITERE_NOM);
    printf("la complexite est de %d et la recherche de %d pour un fichier de %d clients\n",complexite,rechercher_des_clients(liste_clients_2,taille_actuelle,pt,NULL,NULL,"franck",NULL),taille_actuelle);
    fclose(fic2) ;
    complexite=0;
    nb=0;

    FILE *fic3 = fopen(chemin3, "r") ; // a pour ajout
    if( fic3 == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE) ;
    }
    taille_actuelle = compte_ligne(fic3);
    CLIENT liste_clients_3[taille_actuelle];
    remplir_liste_clients(fic3,liste_clients_3,taille_actuelle);
    complexite = tri_avec_deplacement_vide(liste_clients_3,taille_actuelle,CRITERE_NOM);
    printf("la complexite est de %d et la recherche de %d pour un fichier de %d clients\n",complexite,rechercher_des_clients(liste_clients_3,taille_actuelle,pt,NULL,NULL,"franck",NULL),taille_actuelle);
    fclose(fic3) ;
    complexite=0;
    nb=0;

    FILE *fic4 = fopen(chemin4, "r") ; // a pour ajout
    if( fic4 == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE) ;
    }
    taille_actuelle = compte_ligne(fic4);
    CLIENT liste_clients_4[taille_actuelle];
    remplir_liste_clients(fic4,liste_clients_4,taille_actuelle);
    complexite = tri_avec_deplacement_vide(liste_clients_4,taille_actuelle,CRITERE_NOM);
    printf("la complexite est de %d et la recherche de %d pour un fichier de %d clients\n",complexite,rechercher_des_clients(liste_clients_4,taille_actuelle,pt,NULL,NULL,"franck",NULL),taille_actuelle);
    fclose(fic4) ;
    complexite=0;
    nb=0;

    FILE *fic5= fopen(chemin5, "r") ; // a pour ajout
    if( fic5 == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE) ;
    }
    taille_actuelle = compte_ligne(fic5);
    CLIENT liste_clients_5[taille_actuelle];
    remplir_liste_clients(fic5,liste_clients_5,taille_actuelle);
    complexite = tri_avec_deplacement_vide(liste_clients_5,taille_actuelle,CRITERE_NOM);
    printf("la complexite est de %d et la recherche de %d pour un fichier de %d clients\n",complexite,rechercher_des_clients(liste_clients_5,taille_actuelle,pt,"f","f","fr","fr"),taille_actuelle);
    fclose(fic5) ;

    return 0;
}






