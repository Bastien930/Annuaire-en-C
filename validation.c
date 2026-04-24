#include <stdio.h>
#include <stdlib.h>
#include "validation.h"
#include <ctype.h> // isaplha
#include <stdbool.h> // true et false
#include <string.h>

bool valide_prenom_nom_profession_ville(const char* ch) {
    bool code=true;
    while (code && *ch !='\0') {
        if (!isalpha(*ch) && *ch !=' ' && *ch !='-' && *ch != '\'')
            code = false;
        ch++;
    }
    return code;
}


bool valide_code_postal(const char *codePostal) {
    bool code=true;
    int i=0,len=strlen(codePostal);
    if (len !=5 && len != 0 && len!=4)
        code =false;
    while (code && i<len){
        if (codePostal[i] < '0' || codePostal[i] > '9')
            code =false;
        i++;
    }
    return code;
}

bool valide_telephone(const char *telephone) {
    bool code=true;
    int i=0,len=strlen(telephone);
    if (len !=14)
        code =false;
    while (code && i<len){
        if (i % 3 == 2) {
            if (telephone[i] != '.')
                code = false;
        } else {
            if (telephone[i] < '0' || telephone[i] > '9')
                code = false;
        }
        i++;
    }
    if (len > 0 && telephone[0] != '0')
        code = false;

    return code;
}
bool valide_telephone_facultatif(const char *telephone) {
    bool code=true;
    int i=0,len=strlen(telephone);
    if (len !=14 && len!=0)
        code =false;
    while (code && i<len){
        if (i % 3 == 2) {
            if (telephone[i] != '.')
                code = false;
        } else {
            if (telephone[i] < '0' || telephone[i] > '9')
                code = false;
        }
        i++;
    }
    if (len > 0 && telephone[0] != '0')
        code = false;
    return code;
}

bool valide_mail(const char* email) {
    int arobase = 0,point = 0,i=0;
    bool flag=true;
    while (email[i] !='\0' && flag) {
        char carac=email[i];
        if (carac == ' ')
            flag = false;
        if ( carac == '@')
            arobase++;
        if (arobase && carac == '.')
            point++;
        i++;
    }
    if (arobase ==1 && point ==1 && valide_compt_carac(email))
        flag=true;
    else if (strlen(email) == 0)
        flag=true;
    else
        flag=false;
    return flag;
}

bool valide_compt_carac(const char* email){
    int compteur=0;
    while (*email!='\0' && *email!='@'){
        compteur++;
        email++;
    }
    if (compteur<1)
        return false;
    compteur=0;
    email++;//passe le '@'
    while (*email!='\0' && *email!='.'){
        compteur++;
        email++;
    }
    if (compteur<1)
        return false;
    compteur=0;
    email++;//passe le '.'
    while (*email!='\0'){
        compteur++;
        email++;
    }
    if (compteur<1)
        return false;
    return true;
}
bool estbissextile(int annee) {
    bool bisextil = false;
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0))
        bisextil=true;
    return bisextil;
}

bool valide_date_naissance(const DATE date) { // modifier avec la date actuelle
    int joursParMois[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     if (date.jour == 0 && date.mois == 0 && date.annee == 0)
        return true;
    if (date.annee < 1900 || date.annee > 2025) // juge que 124 ans plus personne est vivant a cette age la
        return false;

    if (date.mois < 1 || date.mois > 12)
        return false;

    if (estbissextile(date.annee))
        joursParMois[1] = 29; // Février a 29 jours si bissextile

    if (date.jour < 1 || date.jour > joursParMois[date.mois - 1])
        return false;

    return true;
}

bool donne_manquante(const CLIENT client){
    return (client.prenom[0]=='\0' || client.nom[0]=='\0' || client.ville[0]=='\0' || client.cp[0]=='\0' || client.telephone[0]=='\0' || client.adresse_mail[0]=='\0' || client.date_naissance.annee==0);
}

bool existe_telephone(const CLIENT *liste_client,const char * telephone,int taille_actuelle){
    int i=0;
    bool existe=false;
    while (!existe && i<taille_actuelle){
        if (_strcmpi(telephone,liste_client[i].telephone) == 0)
            existe = true;
        i++;
    }
    return existe;
}



