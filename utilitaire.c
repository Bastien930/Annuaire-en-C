#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilitaire.h"
#include "validation.h"
#include <time.h>



struct tm date_act;


// Fonction de support d'entrée/sortie
void retour_chariot(char *ch){
    int i =0;
    while (ch[i] !='\n' && ch[i] !='\0')
        i++;
    if (ch[i] == '\n')
        ch[i] = '\0';
}

void vider_cache(void){
    char c=0;
    while (c!='\n' && c!=EOF)
        c=getchar();
}

//fonction pour gerer l'age en fonction de la date actuelle.
void calculerage(int annee,int mois,int jour,int tab[3]){
    int mois_prec;
    int jour_act = date_act.tm_mday;
    int mois_act = date_act.tm_mon+1;
    int annee_act = date_act.tm_year +1900;
    int jour_mois[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (estbissextile(annee_act))
        jour_mois[1] = 29;
    annee = annee_act - annee;
    mois = mois_act - mois;
    jour = jour_act - jour;
    if (jour < 0) {// probleme
        mois_prec = mois_act-1;
        if (mois_prec == 0)
            mois_prec =12;
        jour+=jour_mois[mois_prec-1];
        mois--;
    }
    if (mois <0){
        annee--;
        mois +=12;
    }
    tab[0] = jour;
    tab[1] = mois;
    tab[2] = annee;
}
void init_date(){
    time_t temp = time(NULL);
    date_act = *localtime(&temp);
}
