#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED

#include "message.h"
#include "client.h"
#include <stdbool.h>

CLIENT recuperer_donner(CLIENT client);

void retour_chariot(char *ch);

void vider_cache(void);

bool valide_telephone(char *telephone);

void saisir_chaine(char *ch,MESSAGE msg);

bool valide_mail(char* email) ;

bool valide_code_postal(char *codePostal) ;

bool valide_ville(char *ville) ;

bool valide_prenom_nom_profession(char* prenom);

bool valide_date_naissance(DATE date);

bool estbissextile(int annee);

DATE saisir_date();

void afficher_client(CLIENT client);

void afficher_champ(char *label,char *donnees);

void afficher_date(char *label,DATE date);

void inserer_client(const char *fichier, CLIENT client);

#endif // FONCTION_H_INCLUDED
