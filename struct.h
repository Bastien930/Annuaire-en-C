#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#define TAILLE 50

typedef struct {
    int jour;
    int mois;
    int annee;
} DATE;

typedef struct{
    char prenom[TAILLE],nom[TAILLE];
    char ville[TAILLE];
    char cp[6];
    char telephone[15];
    char address_mail[TAILLE];
    char profession[TAILLE];
    DATE date_naissance;

}CLIENT;

typedef enum {
    MSG_PRENOM,
    MSG_NOM,
    MSG_VILLE,
    MSG_CP,
    MSG_TELEPHONE,
    MSG_PROFESSION,
    MSG_ADRESSE_MAIL,
    MSG_DATE_NAISSANCE,
} MESSAGE;



#endif // STRUCT_H_INCLUDED
