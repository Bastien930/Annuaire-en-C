#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "validation.h"
#include "tri.h"
#define taille_mini 64


// tri insertion basique. avec un tableau de pointeur vers des chaines de caractere pour avoir une complexite optimal.
void insertionsort(CLIENT tab[], int gauche, int droite,CRITERE critere,int *compl) { // modifier avec des pointeur vers la structure ?
    CLIENT temp;
    (*compl) += 3; // itilialisation de i (affactation et lecture et operation).
    for (int i = gauche + 1; i <= droite; i++) {
        temp= tab[i];
        int j = i - 1;
        (*compl) += 4;
        while (j >= gauche && comparer_client(tab[j],temp,critere,compl) > 0) {
            tab[j+1]=tab[j];
            j--;
            (*compl) += 10; // pour le while
        }
        (*compl) += 4; // le test qui echoue
        tab[j+1]=temp;
        (*compl) += 3; // 1 acces , 1 ope et 1 affectation
        (*compl) += 3; // 1 comp , 1 ope et 1 affectation // tour de boucle
    }
    (*compl) += 1; // test de boucle qui echou
}

void fusion(CLIENT tab[], int gauche, int milieu, int droite,CRITERE critere,int * compl) {
    int len1 = milieu - gauche + 1, len2 = droite - milieu;
    (*compl) += 5;
    CLIENT *tab_gauche = malloc(len1 * sizeof(CLIENT));
    CLIENT *tab_droite = malloc(len2 * sizeof(CLIENT));
    (*compl) += 2*3; // 1 appel , 1 ope , 1 affect

    if (tab_gauche ==NULL || tab_droite == NULL) {
        printf("Erreur d'allocation de memoire\n");
        exit(EXIT_FAILURE);
    }
    (*compl) += 1; // 1 comp
    (*compl) += 1; // init
    for (int i = 0; i < len1; i++) {
        tab_gauche[i] = tab[gauche + i];
        (*compl) += 7;
    }
    (*compl) += 1; // echou
    (*compl) += 1; // init
    for (int i = 0; i < len2; i++) {
        tab_droite[i] = tab[milieu + 1 + i];
        (*compl) += 8;
    }
    // initialiser deux tableau et les à remplis
    int i = 0, j = 0, k = gauche;
    (*compl) += 3; // init
    while (i < len1 && j < len2) { // simple fusion des sous liste.
        (*compl) += 4; // if
        if (comparer_client(tab_gauche[i],tab_droite[j],critere,compl) <=0 ) {
            tab[k] = tab_gauche[i];
            i++;
            (*compl) += 5;
        }

        else {
            tab[k] = tab_droite[j];
            j++;
            (*compl) += 4;
        }
        k++;
        (*compl) += 2;
        (*compl) += 2; // test du while
    }
    (*compl) += 2;// test qui echou

    while (i < len1) {
        tab[k] = tab_gauche[i];
        k++;
        i++;
        (*compl) += 7;
        (*compl) += 1; // test while
    }
    (*compl) += 1;
    while (j < len2) {
        tab[k] = tab_droite[j];
        j++;
        k++;
        (*compl) += 7;
        (*compl) += 1; // test while
    }
    (*compl) += 1;
    free(tab_gauche);
    free(tab_droite);//libere la memoire des sous tableaux
    (*compl) += 2;
}

int tri_avec_deplacement_vide(CLIENT *liste_client,int taille_actuelle,CRITERE critere){
    int gauche = 0;
    int droite = taille_actuelle-1;
    int complexite=3;
    int *ptr = &complexite;
    while (gauche < droite){
        complexite++;
        while (gauche < droite && !champ_vide(liste_client[gauche],critere,ptr)){
            gauche++;
            complexite +=7;
        }
        while (gauche < droite && champ_vide(liste_client[droite],critere,ptr)){
            droite--;
            complexite +=7;
        }
        if (gauche < droite){
            CLIENT temp = liste_client[gauche];
            liste_client[gauche] = liste_client[droite];
            liste_client[droite] = temp;
            complexite +=7;
        }
        complexite++;
    }
    timsort(liste_client,gauche,critere,ptr);
    complexite++;
    return complexite;
}
void timsort(CLIENT tab[], int n,CRITERE critere, int * compl) {
    int droite;
    int milieu;
    (*compl) += 1;
    for (int i = 0; i < n; i += taille_mini) {
        (*compl) += 4; // if
        if (i + taille_mini - 1 < n - 1) { // verifie si pas sortie du tableau
            droite = i + taille_mini - 1;
            (*compl) += 3;
        }

        else {
            droite = n - 1;
            (*compl) += 2;
        }
        insertionsort(tab, i, droite,critere,compl);
        (*compl) += 1;
        (*compl) += 3; // le for
    }
    (*compl) += 1; // test qui echou
    (*compl) += 1;
    for (int taille = taille_mini; taille < n; taille = 2 * taille) { //fusion de tab de taille 32 puis 64 puis 128 ...
        (*compl) += 1;
        for (int gauche = 0; gauche < n; gauche += 2 * taille) {
                (*compl) += 5; // if
            milieu = gauche + taille - 1;
            (*compl) += 3;
            if (gauche + 2 * taille - 1 < n - 1) {
                droite = gauche + 2 * taille - 1;
                (*compl) += 4;
            }

            else {
                droite = n - 1;
                (*compl) += 2;
            }

            if (milieu < droite) {
                fusion(tab, gauche, milieu, droite,critere,compl);
                (*compl) += 1;
            }
            (*compl) += 1;
            (*compl) += 4; // for
        }
        (*compl) += 1; // test qui echou
        (*compl) += 3;// for
    }
    (*compl) += 1;//test qui echou
}

int comparer_client(CLIENT client_A,CLIENT client_B,CRITERE critere,int * compl){
    int res_comparaison = 0 ; // initialisation pour eviter les valeurs indefinis
    (*compl) += 1;
    if (critere == CRITERE_NOM){
        res_comparaison = _stricmp(client_A.nom,client_B.nom);
        (*compl) += 5;
    }
    else if(critere == CRITERE_PROFESSION){
        res_comparaison = _stricmp(client_A.profession,client_B.profession);
        (*compl) += 6;
    }
    else if (critere == CRITERE_CP){
        res_comparaison = _stricmp(client_A.cp,client_B.cp);
        (*compl) += 7;
    }
    else if (critere == CRITERE_DATE_NAISSANCE){
        (*compl) += 4;
        if (client_A.date_naissance.annee != client_B.date_naissance.annee){
            res_comparaison = client_B.date_naissance.annee - client_A.date_naissance.annee; // B-A pour etre comme la fonction _srticmp pour eviter de refaire une autre fonction insertion sort
            (*compl) += 11;
        }
        else if (client_A.date_naissance.mois !=client_B.date_naissance.mois){
            res_comparaison = client_B.date_naissance.mois - client_A.date_naissance.mois;
            (*compl) += 16;
        }
        else if (client_A.date_naissance.jour !=client_B.date_naissance.jour){
            res_comparaison = client_B.date_naissance.jour - client_A.date_naissance.jour;
            (*compl) += 21;
        }
        else{
            res_comparaison=0;
            (*compl) += 1;
        }
    }
    return res_comparaison;
}





bool champ_vide(CLIENT client, CRITERE critere,int *compl){
    bool est_vide=false;
    (*compl)++;
    switch (critere){
        case CRITERE_NOM:
            if (client.nom[0] == '\0'){
                est_vide = true;
                (*compl)++;
            }
            (*compl)+=4;
            break;
        case CRITERE_PROFESSION:
            if (client.profession[0] == '\0'){
                est_vide = true;
                (*compl)++;
            }
            (*compl)+=4;
            break;
        case CRITERE_CP:
            if (client.cp[0] == '\0'){
                est_vide = true;
                (*compl)++;
            }
            (*compl)+=4;
            break;
        case CRITERE_DATE_NAISSANCE:
            if (client.date_naissance.annee == 0){
               est_vide = true;
                (*compl)++;
            }
            (*compl)+=5;
            break;
        default:
            printf("erreur de critere\n");
            (*compl)++;
            break;
    }
    return est_vide;
}


int* rechercher_des_clients(CLIENT *liste_clients, int taille_actuelle,int *nb_trouver, char *profession, char *code_postal,
                       char *prenom,  char *nom,int age,int *compl) {
    int i=0;
    int capacite = taille_actuelle/2;
    int *indices = malloc(capacite * sizeof(int));
    int resultats = 0;
    *nb_trouver=0;
    bool flag=true;
    (*compl)+=8;
    if (!nom && !prenom && !profession && !code_postal && age == 0)
        flag=false;
    (*compl)+=1; // car on sarrete a nom
    while (flag && i<taille_actuelle){
        bool correspondance = true;
        (*compl)++;
        if (prenom ){
            resultats = _stricmp(liste_clients[i].prenom, prenom);
            (*compl)+=4;
            if (resultats!=0 && resultats<65 ){
                correspondance = false;
                (*compl)+=1;
            }
            (*compl)+=3;
        }
        (*compl)++;
        if (nom ){
            resultats = _stricmp(liste_clients[i].nom, nom);
            (*compl)+=4;
            if (resultats!=0 && resultats<65 ){
                correspondance = false;
                (*compl)++;
            }
            (*compl)+=3;
        }
        (*compl)++;
        if (profession ){
            resultats = _stricmp(liste_clients[i].profession, profession);
            (*compl)+=4;
            if (resultats!=0 && resultats<65 ){
                correspondance = false;
                (*compl)++;
            }
            (*compl)+=3;
        }
        if (code_postal ){
            resultats = _stricmp(liste_clients[i].cp, code_postal);
            (*compl)+=4;
            if (resultats!=0 && resultats<48 ){
                correspondance = false;
                (*compl)++;
            }
            (*compl)+=3;
        }
        (*compl)++;
        if (age!=0 ){
            int age_client[3] ;
            calculerage(liste_clients[i].date_naissance.annee,liste_clients[i].date_naissance.mois,liste_clients[i].date_naissance.jour,age_client);
            (*compl)+=10;
            if (age != age_client[2]){ // indice 2 pour lannee
                correspondance = false;
                (*compl)++;
            }
            (*compl)+=2;
        }
        (*compl)++;
        if (correspondance) {
            if (*nb_trouver >= capacite) {
                capacite *= 2; // Double la capacité
                int *temp = realloc(indices, capacite * sizeof(int));
                if (temp == NULL) {
                    perror("Erreur lors du realloc");
                    exit(EXIT_FAILURE);
                }
                indices = temp;
                (*compl)+=7;
            }
            indices[*nb_trouver]=i;  // Client trouvé
            (*nb_trouver)++;
            (*compl)+=8;
        }
        i++;
        (*compl)+=3;
    }
    if (*nb_trouver == 0) {
        free(indices);
        return NULL;
    }
    (*compl)+=2;
    return indices; // indice doit etrre liberer dans la fonction qui recupere ces resultats.
}


