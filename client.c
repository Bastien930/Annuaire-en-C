#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "message.h"
#include "client.h"
#include "utilitaire.h"
#include "validation.h"
#include "affichage.h"
#include "tri.h"
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>
#include <conio.h> // pour getch

#define TAILLE 25
#define TAILLE_TABLEAU_ERREURS 9


const char *const TABLEAU_CHAINES[] = {
    "un prenom ",
    "un nom ",
    "une ville ",
    "un code Postal de la forme XXXXX ",
    "un numero de telephone de la forme XX.XX.XX.XX.XX  (*champ obligatoire) ",
    "une profession ",
    "une adresse mail de la forme exemple@gmail.com ",
    "une date de naissance ",
    "un numero  de telephone de la forme XX.XX.XX.XX.XX"
};

const char *const TABLEAU_ERREURS[] = {
    "Le prénom est invalide. Veuillez entrer un prénom avec uniquement des lettres alphabétiques. Ce champ peut etre vide.",
    "Le nom est invalide. Veuillez entrer un nom avec uniquement des lettres, des tirets ou des espaces. Ce champ peut etre vide.",
    "La ville est invalide. Veuillez entrer une ville avec uniquement des lettres, des tirets ou des espaces. Ce champ peut etre vide.",
    "Le code postal est invalide. Le format attendu est : XXXXX. Champs obligatoire !",
    "Le numéro de téléphone est invalide. Le format attendu est : XX.XX.XX.XX.XX. Ce champ peut être vide.",
    "La profession est invalide. Veuillez entrer une profession avec uniquement des lettres, des tirets ou des espaces. Ce champ peut etre vide.",
    "L'adresse email est invalide. Le format attendu est : exemple@gmail.com. Ce champ peut etre vide.",
    "La date de naissance est invalide. Le format attendu est : JJ MM AAAA. Ce champ peut etre vide.",
    "Le numéro de téléphone est invalide. Le format attendu est : XX.XX.XX.XX.XX. Ce champ peut etre vide."
};

//***********************************************************************************************************
//fonction de saisie

CLIENT recuperer_donner(CLIENT client){
    saisir_chaine(client.prenom,MSG_PRENOM);
    saisir_chaine(client.nom,MSG_NOM);
    saisir_chaine(client.ville,MSG_VILLE);
    saisir_chaine(client.cp,MSG_CP);
    saisir_chaine(client.telephone,MSG_TELEPHONE);
    saisir_chaine(client.adresse_mail,MSG_ADRESSE_MAIL);
    saisir_chaine(client.profession,MSG_PROFESSION);
    client.date_naissance= saisir_date();
    return client;
}

DATE saisir_date(){
    DATE date;
    char buffer[100];
    bool valide = true;
    do {
        valide = true;
        printf("Entrez la date de naissance (JJ MM AAAA) : ");
        if (fgets(buffer,100,stdin) ==NULL){
            perror("Erreur lors de l'ouverture du fichier");
            exit(EXIT_FAILURE) ;
        }
        else {
            if (strchr(buffer, '\n') == NULL ) //il y a un exedent de donner
                vider_cache();

            else
                retour_chariot(buffer);
            if (strlen(buffer) == 0){ // si l'utilisateur a pas rentrer de date
                date.jour = 0;
                date.mois =0;
                date.annee = 0;
            }
            else if (sscanf(buffer, "%d %d %d", &date.jour, &date.mois, &date.annee) == 3)
                ;
            else
                valide = false;
        }

        if (valide && !valide_date_naissance(date)) { // si jamais la date a deja ete invalider du au sscanf alors ne pa faire la fonction valide date naissance sous peine de valeur indefini.
            valide = false;
            printf("%s\n",TABLEAU_ERREURS[MSG_DATE_NAISSANCE]);
        }
    } while (!valide);

    return date;
}



void saisir_chaine(char *ch,MESSAGE msg){
    bool valide = false;
    do {
        printf("entrez %s :",TABLEAU_CHAINES[msg]);
        if (fgets(ch,TAILLE,stdin)==NULL){
            perror("Erreur lors de l'ouverture du fichier");
            exit(EXIT_FAILURE) ;
        }
        else {
            if (strchr(ch, '\n') == NULL ) //il y a un exedent de donner
                vider_cache();

            else
                retour_chariot(ch);
            switch (msg) {
                case 0:  // Prénom et nom et profession et ville
                case 1:
                case 2:
                case 5:
                    valide = valide_prenom_nom_profession_ville(ch);
                    break;
                case 3:  // Code postal
                    valide = valide_code_postal(ch);
                    break;
                case 4:  // telephone
                    valide = valide_telephone(ch);
                    break;
                case 6:  // adresse mail
                    valide = valide_mail(ch);
                    break;
                case 8:
                    valide =valide_telephone_facultatif(ch);
                    break;
                default:
                    valide = false;
                    break;
                }
        }
        if (!valide && msg>=0 && msg <= TAILLE_TABLEAU_ERREURS-1)
            printf("%s\n",TABLEAU_ERREURS[msg]);
    }while (!valide);

}

//***********************************************************************************************************
//fonction de lecture du fichier

int compte_ligne(FILE * fichier){
    if( fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE) ;
    }
    int ligne=0;
    char buffer[256];
    rewind(fichier);
    while (fgets(buffer,256,fichier) !=NULL)
        ligne++;
    return ligne;
}

void remplir_liste_clients(FILE *fichier,CLIENT *liste_clients,int taille_clients){
    if (fichier == NULL || liste_clients == NULL || taille_clients <= 0) {
        perror("Erreur arguments invalides");
        exit(EXIT_FAILURE) ;
    }
    char ligne[256];
    rewind(fichier);
    int i=0;
    while (i < taille_clients && ! feof(fichier)){
        if (fgets(ligne,256,fichier)){
            liste_clients[i] = line_to_client(ligne);
            i++;
        }
        else
            printf("echec de fgets");
    }
}

//***********************************************************************************************************
//Fonction de parsing
CLIENT line_to_client(char str[200]){ //changer car il y a des villes ou il y a des espaces
    CLIENT c;
    int i = 0, j = 0;
    while (str[i] && str[i] != ','){
        if (j<TAILLE-1){
            c.prenom[j]=str[i];
            j++;
        }
        i ++;
    }
    c.prenom[j] = 0;
    j = 0;
    i++;
    while (str[i] && str[i] != ','){
        if (j<TAILLE-1){
            c.nom[j]=str[i];
            j++;
        }
        i++;
    }
    c.nom[j] = 0;
    j = 0;
    i++;
    bool ville_fini=false;
    while (str[i] && str[i] !=','){ // recuperer ville et code postal et les scinder apres
        if (!ville_fini && str[i] >'0' && str[i] <'9'){
            ville_fini=true;
            c.ville[j-1] = '\0';
            j=0;
        }
        if (ville_fini){
            if (j<6-1){
                c.cp[j]=str[i];
                j++;
            }
        }
        else{
            if (j<TAILLE-1){
                c.ville[j]=str[i];
                j++;
            }
        }
        i++;
    }
    if (ville_fini)
        c.cp[j] = '\0';
    else {
        c.ville[j]='\0';
        c.cp[0] = '\0';
    }
    j = 0;
    i++;
    while (str[i] && str[i] != ','){
        if (j<15-1){
            c.telephone[j]=str[i];
            j++;
        }
        i++;
    }
    c.telephone[j] = 0;
    j = 0;
    i++;
    while (str[i] && str[i] != ','){
        if (j<TAILLE-1){
            c.adresse_mail[j]=str[i];
            j++;
        }
        i++;
    }
    c.adresse_mail[j] = 0;
    j = 0;
    i++;
    while (str[i] && str[i] != ','){
        if (j<TAILLE-1){
            c.profession[j]=str[i];
            j++;
        }
        i++;
    }
    c.profession[j] = 0;
    i++;
    const char *str_num = &str[i]; // ne doit pas changer de valeur
    if (sscanf(str_num, "%d/%d/%d", &c.date_naissance.jour, &c.date_naissance.mois, &c.date_naissance.annee) == 3);
    else {
        c.date_naissance.jour=0;
        c.date_naissance.mois=0;
        c.date_naissance.annee=0;
    }
    return c;
}


//***********************************************************************************************************
//fonction de recherche

int rechercher_indice_client(CLIENT *liste_clients, int taille_actuelle, char *numero_telephone, char *adresse_mail,
                       char *prenom,  char *nom) {
    int i=0,indice =-1;
    while (indice < 0 && i<taille_actuelle){
        bool correspondance=true ;
        if (numero_telephone && _stricmp(liste_clients[i].telephone, numero_telephone) != 0)
            correspondance = false;
        if (correspondance && prenom && _stricmp(liste_clients[i].prenom, prenom) != 0)
            correspondance = false;
        if (correspondance && nom && _stricmp(liste_clients[i].nom, nom) != 0)
            correspondance = false;
        if (correspondance && adresse_mail && _stricmp(liste_clients[i].adresse_mail, adresse_mail) != 0)
            correspondance = false;
        if (correspondance)
            indice=i;  // Client trouvé
        i++;
    }
    return indice;
}


//***********************************************************************************************************
//fonction de gestion (ajout,supression,modif)

void ajouter_client(CLIENT *liste_clients,int taille_max,int *taille_actuel,CLIENT client){
    if (*taille_actuel <=taille_max){
        (*taille_actuel)++;
        liste_clients[(*taille_actuel)-1] = client;
    }
    else
        printf("taille maximal\n");
}

void suprimer_client(int *taille_actuel,CLIENT *liste_clients,int indice){
    if (indice<0 || indice>=*taille_actuel)
        printf("erreur l'indice du client est invalide \n");
    else {
        for (int i=indice;i<*taille_actuel-1;i++){
            liste_clients[i] = liste_clients[i+1];
        }
        (*taille_actuel)--;
    }
}


//***********************************************************************************************************
//Fonction de contrôle de tri
void tri_liste_clients(CLIENT *liste_client,int taille_actuelle){
    char option;
    printf("(0) pour trie sur le nom\n");
    printf("(1) pour trie sur la profession\n");
    printf("(2) pour trie sur le code postal\n");
    printf("(3) pour trie sur la date de naissance\n");
    printf("(autre) pour ne pas trie les donnees\n");
    scanf("%c",&option);
    printf("option :%c\n",option);
    if (option!='\n')
            vider_cache();
    if (option =='0')
        tri_avec_deplacement_vide(liste_client,taille_actuelle,CRITERE_NOM);
    else if (option =='1')
        tri_avec_deplacement_vide(liste_client,taille_actuelle,CRITERE_PROFESSION);
    else if (option =='2')
        tri_avec_deplacement_vide(liste_client,taille_actuelle,CRITERE_CP);
    else if (option =='3')
        tri_avec_deplacement_vide(liste_client,taille_actuelle,CRITERE_DATE_NAISSANCE);
}




//***********************************************************************************************************
//fonction des options du menu

void option_0(int *taille_actuelle,int taille_max,CLIENT *liste_client){
    char reponse;
    bool existe_tel;
    CLIENT new_client;
    if (*taille_actuelle == taille_max){
        printf("erreur de taille de la structure \n");
    }
    else {
        do {
            new_client = recuperer_donner(new_client);
            existe_tel = existe_telephone(liste_client,new_client.telephone,*taille_actuelle);
            if (existe_tel){
                printf("oups il s'emble que le numeros de telephone existe deja dans notre base de donnees...\n");
                printf("Voulez-vous reessayer ? (O/N) : ");
                scanf("%c", &reponse);
                if (reponse !='\n'){
                    vider_cache();
                    if (reponse == 'N' ) {
                        printf("Operation d'ajout annule.\n");
                        return;
                    }
                }
            }
        }while (existe_tel);
        printf("vos donnees ont bien ete receptionner. Voulez vous les voirs ? O/N : ");
        scanf("%c",&reponse);
        if (reponse !='\n'){
            vider_cache();
            if (reponse =='O')
                afficher_client(new_client);
        }
        printf("voulez vous enregistrer la saisie ? (O/N) : ");
        scanf("%c",&reponse);
        if (reponse !='\n'){
            vider_cache();
            if (reponse =='O'){
                ajouter_client(liste_client,taille_max,taille_actuelle,new_client);
                printf("modification enregistrer il y a maintenant %d clients\n",*taille_actuelle);
            }
        }
    }
}

void option_2(int *taille_actuelle,CLIENT *liste_client){
    char chaine[50];
    int indice;
    char reponse;
    printf("pour suprimer le client il faut obligatoirement un numeros de telephone\n");
    saisir_chaine(chaine,MSG_TELEPHONE); // telephone
    indice = rechercher_indice_client(liste_client,*taille_actuelle,chaine,NULL,NULL,NULL);
    printf("indice du client %d\n",indice);
    if (indice <=-1)
        printf("client non trouver \n");
    else {
        printf("Voulez vous vraiment suprimer (O/N) : "); // en faite la fnct suprimer un client le premier trouver ...
        scanf("%c",&reponse);
        if (reponse !='\n'){
            vider_cache();
            if (reponse =='O'){
                suprimer_client(taille_actuelle,liste_client,indice);
                printf("client bien suprimer nouvelle taille : %d\n",*taille_actuelle);
            }
        }
    }
}

void option_4(int taille_actuelle,CLIENT *liste_client){
    tri_liste_clients(liste_client,taille_actuelle);
    afficher_tous_clients(liste_client,taille_actuelle);
}

void option_5(int taille_actuelle,CLIENT *liste_client){
    char chaine[4][50];
    char *tab[] = {NULL,NULL,NULL,NULL};
    char reponse;
    int indice;
    bool valide;
    printf("Attention pour cette recherche veuillez au moins fournir un telephone ou une adresse mail\n");
    do {
        valide=false;
        printf("saisir un nom, un prenom et un telephone ou une adresse mail\n");
        saisir_chaine(chaine[0],MSG_PRENOM); // prenom
        saisir_chaine(chaine[1],MSG_NOM); // nom
        saisir_chaine(chaine[2],MSG_TELEPHONE_FACULTATIF); // telephone
        saisir_chaine(chaine[3],MSG_ADRESSE_MAIL); // mail
        if (strlen(chaine[2]) !=0  || strlen(chaine[3]) !=0)
            valide = true;

        else {
            printf("Attention l'adresse mail ou le telephone est obligatoire... \nVoulez-vous reessayer ? (O/N) : ");
            scanf("%c", &reponse);
                if (reponse !='\n'){
                    vider_cache();
                    if (reponse == 'N' ) {
                        printf("Operation de recherche annule.\n");
                        return;
                    }
                }
        }
    }while (!valide);
    for (int i=0;i<4;i++){
        if (strlen(chaine[i]) != 0)
            tab[i] = chaine[i];
    }
    indice = rechercher_indice_client(liste_client,taille_actuelle,tab[2],tab[3],tab[0],tab[1]);
    if (indice <0)
        printf("client non trouver \n");
    else {
        afficher_client(liste_client[indice]);
    }
}

void option_6(int taille_actuelle,CLIENT *liste_client){
    char chaine[4][50];
    char *tab[] = {NULL,NULL,NULL,NULL};
    int nb_trouver;
    char reponse;
    printf("Attention cette recherche na aucun champs obligatoires, si vous ne rentrez pas de champs unique(telephone ou adresse mail) dans l'annuaire il peut avoir plusieur resultats.\n");
    saisir_chaine(chaine[0],MSG_PRENOM); // prenom
    saisir_chaine(chaine[1],MSG_NOM); // nom
    saisir_chaine(chaine[2],MSG_TELEPHONE_FACULTATIF); // telephone
    saisir_chaine(chaine[3],MSG_ADRESSE_MAIL); // mail
    for (int i=0;i<4;i++){        if (strlen(chaine[i]) != 0)
            tab[i] = chaine[i];
    }
    int* indice = rechercher_des_clients(liste_client,taille_actuelle,&nb_trouver,tab[2],tab[3],tab[0],tab[1]);
    if (nb_trouver <=0)
        printf("client non trouver \n");
    else {
        afficher_en_tete();
        for (int i=1;i-1<nb_trouver;i++){
            afficher_client_tab(liste_client[indice[i-1]]);
            if (i%50==0){
                int pages = (nb_trouver-i)/50+1;
                printf("appuyer sur une touche afficher la suite ( encore %d pages ) ou sur 'q' pour quitter : ",pages);
                reponse = getch(); // permet de apuyez sur une seul touche et enleve le defilement automatique
                if (reponse == 'q')
                    return;
            }
        }
    }
    free(indice);
}

void option_7(const CLIENT *liste_clients,int taille_actuelle){
    int nombre = 0,taille=500;
    int *indices = malloc(sizeof(int) * taille);
    int i=0;
    char reponse ;
    if (indices == NULL){
        perror("erreur d'allocation dynamique");
        exit(EXIT_FAILURE);
    }
    while (i<taille_actuelle){
        if (nombre == taille) {
                taille *= 2;
                int* temp = realloc(indices, taille * sizeof(int));
                if (temp == NULL) {
                    perror("erreur d'allocation dynamique");
                    free(indices);
                    exit(EXIT_FAILURE);
                }
                indices = temp;
            }
        if (donne_manquante(liste_clients[i])){
            indices[nombre] = i;
            nombre++;
        }
        i++;

    }
    printf("avant initilisation %d\n",nombre);
    CLIENT *client_donnees_manquante = malloc(sizeof(CLIENT) * nombre); //allocation  sur le tas
    if (client_donnees_manquante == NULL) {
        perror("erreur d'allocation dynamique");
        exit(EXIT_FAILURE);
    }
    for (i=0;i<nombre;i++){
        client_donnees_manquante[i] = liste_clients[indices[i]];
    }
    printf("il y a %d client avec des donnes manquante sur %d clients \n",nombre,taille_actuelle);
    printf("voulez vous voir la liste des clients (O/N) : ");
    scanf("%c",&reponse);
    if (reponse !='\n')
        vider_cache();
    if (reponse =='O'){
        tri_liste_clients(client_donnees_manquante,nombre);
        afficher_en_tete();
        for (i=1;i-1<nombre;i++){
            afficher_client_tab(client_donnees_manquante[i-1]);
            if (i%50==0){
                int pages = (nombre-i)/50+1;
                printf("appuyer sur une touche afficher la suite ( encore %d pages ) ou 'q' pour quitter : ",pages);
                reponse = getch(); // permet de apuyez sur une seul touche et enleve le defilement automatique
                if (reponse == 'q')
                    return;
            }
        }
    }
    free(client_donnees_manquante);
    free(indices);
}




