#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilitaire.h"
#include "affichage.h"
#include "client.h"
#include <conio.h> // pour getch


void afficher_client(const CLIENT client){
    printf("\n");
    afficher_champ("prenom",client.prenom);
    afficher_champ("nom",client.nom);
    afficher_champ("ville",client.ville);
    afficher_champ("code postal",client.cp);
    afficher_champ("telephone",client.telephone);
    afficher_champ("adresse mail",client.adresse_mail);
    afficher_champ("profession",client.profession);
    afficher_date("date naissance",client.date_naissance);
}

void afficher_client_tab(const CLIENT client){
    afficher_champ_tableau(client.prenom);
    afficher_champ_tableau(client.nom);
    afficher_champ_tableau(client.ville);
    afficher_champ_tableau(client.cp);
    afficher_champ_tableau(client.telephone);
    afficher_adresse_mail_tableau(client.adresse_mail);
    afficher_champ_tableau(client.profession);
    afficher_date_tableau(client.date_naissance);
}
void afficher_en_tete(){
    printf("\n\n%25s %24s %24s %24s %24s %49s %24s %24s","prenom","nom","ville","cp","tel","adresse_mel","profession","date_naissance\n\n");
}
void afficher_tous_clients(const CLIENT *liste_client,int n){ //afficher les champs aligner avec le prenom le plus grand en mode formater
    char reponse;
    int i=1;
    printf("voici la taille : %d\n",n);
    afficher_en_tete();
    do {
        if (i%50==0){
            int pages = (n-i)/50+1;
            printf("appuyer sur une touche afficher la suite ( encore %d pages ) ou sur 'q' pour quitter : ",pages);
            reponse = getch(); // permet de apuyez sur une seul touche et enleve le defilement automatique
            if (reponse == 'q')
                return;
        }
        afficher_client_tab(liste_client[i-1]);
        i++;
    }while (i<=n);
}


void afficher_champ(const char *label,const char *donnees){
    if (donnees[0] == '\0')
        printf("%s : Non renseignee\n",label);
    else
        printf("%s : %s\n",label,donnees);
}

void afficher_champ_tableau(const char *donnees){
    if (donnees[0] == '\0')
        printf("%25s","Non renseignee");
    else
        printf("%25s",donnees);
}
void afficher_adresse_mail_tableau(const char *donnees){
    if (donnees[0] == '\0')
        printf("%50s","Non renseignee");
    else
        printf("%50s",donnees);
}

void afficher_date_tableau(const DATE date){
    int age[3];
    if (date.jour == 0 && date.mois == 0 && date.annee == 0)
        printf("%25s","Non renseignee\n");
    else{
        calculerage(date.annee,date.mois,date.jour,age);
        printf("%4dans, %02dmois, %02djours\n",age[2],age[1],age[0]);
    }
}

void afficher_date(const char *label,const DATE date){
    int age[3];
    if (date.jour == 0 && date.mois == 0 && date.annee == 0)
        printf("%s : Non renseignee\n", label);
    else{
        calculerage(date.annee,date.mois,date.jour,age);
        printf("vous etes nee depuis %4dannees, %02dmois et %02djours\n",age[2],age[1],age[0]);
    }
}


