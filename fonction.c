#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"
#include "message.h"
#define taille_mini 32
#include <stdbool.h> // true et false



/**
 * @brief Trie un tableau de clients selon un critère donné en utilisant l'algorithme de tri par insertion.
 *
 * Cette fonction trie une portion du tableau de clients (`tab`) dans l'ordre croissant ou décroissant
 * en fonction du critère spécifié, à l'aide de l'algorithme de tri par insertion.
 * Le tri est effectué dans la plage d'indices définie par `gauche` et `droite`.
 *
 *@author bastien
 *
 * @param[in,out] tab : CLIENT* Tableau contenant les clients à trier.
 * @param[in] gauche : int Indice de début de la portion à trier dans le tableau.
 * @param[in] droite : int Indice de fin de la portion à trier dans le tableau.
 * @param[in] critere : CRITERE Critère de comparaison des clients pour le tri (par exemple, nom, prénom, etc.).
 *
 * @pre :
 *   - Le tableau `tab` contient des clients valides.
 *   - Les indices `gauche` et `droite` définissent une portion valide du tableau.
 * @post :
 *   - La portion du tableau spécifiée est triée en fonction du critère donné.
 *
 * @note :
 *   - Utilise la fonction `comparer_client` pour comparer les éléments du tableau selon le critère choisi.
 */
void insertionsort(CLIENT tab[], int gauche, int droite, CRITERE critere,int * compl) ;

/**
 * @brief Fusionne deux sous-listes triées dans un tableau de clients selon un critère donné.
 *
 * Cette fonction fusionne deux sous-listes triées du tableau `tab` en un seul tableau trié. Les sous-listes
 * sont définies par les indices `gauche`, `milieu` et `droite`. Le critère de comparaison des éléments
 * est spécifié par le paramètre `critere`. La fusion est réalisée en utilisant la méthode du tri par fusion.
 *
 *@author bastien
 *
 * @param[in,out] tab : CLIENT* Tableau de clients contenant les sous-listes à fusionner.
 * @param[in] gauche : int Indice de début de la première sous-liste à fusionner.
 * @param[in] milieu : int Indice de fin de la première sous-liste et début de la seconde.
 * @param[in] droite : int Indice de fin de la seconde sous-liste à fusionner.
 * @param[in] critere : CRITERE Critère de comparaison des clients pour le tri (par exemple, nom, prénom, etc.).
 *
 * @pre :
 *   - Les sous-listes spécifiées par les indices `gauche`, `milieu`, et `droite` doivent être valides et triées.
 *   - Le tableau `tab` doit contenir des clients valides.
 * @post :
 *   - Les deux sous-listes sont fusionnées et triées dans le tableau `tab`.
 *
 * @note :
 *   - La fonction alloue de la mémoire dynamique pour les sous-listes temporaires `tab_gauche` et `tab_droite`.
 *   - Après l'utilisation des sous-listes temporaires, la mémoire est libérée pour éviter les fuites de mémoire.
 *   - Utilise la fonction `comparer_client` pour comparer les éléments selon le critère choisi.
 */
 void fusion(CLIENT tab[], int gauche, int milieu, int droite, CRITERE critere,int * compl) ;


/**
 * @brief Trie un tableau de clients en utilisant l'algorithme de tri Timsort.
 *
 * Timsort est un algorithme hybride combinant le tri par insertion et le tri fusion. Il divise d'abord le tableau en sous-listes
 * de taille minimale, puis trie chaque sous-liste à l'aide du tri par insertion. Ensuite, il fusionne les sous-listes triées
 * en utilisant le tri par fusion, doublant progressivement la taille des sous-listes fusionnées.
 *
 *@author bastien
 *
 * @param[in,out] tab : CLIENT* Tableau de clients à trier.
 * @param[in] n : int Nombre d'éléments dans le tableau `tab`.
 * @param[in] critere : CRITERE Critère de comparaison pour le tri (par exemple, nom, profession, date de naissance).
 *
 * @pre :
 *   - Le tableau `tab` doit contenir des clients valides.
 *   - Le paramètre `critere` doit être un critère valide de comparaison des clients.
 *
 * @post :
 *   - Le tableau `tab` est trié selon le critère de comparaison spécifié.
 *
 * @note :
 *   - Utilise un tri par insertion pour les petites sous-listes et un tri par fusion pour les grandes sous-listes.
 *   - La fonction `insertionsort` est utilisée pour trier les petites sous-listes.
 *   - La fonction `fusion` est utilisée pour fusionner les sous-listes triées.
 */
void timsort(CLIENT tab[], int n, CRITERE critere,int * compl) ;

/**
 * @brief Compare deux clients selon un critère spécifié.
 *
 * Cette fonction compare deux clients (`client_A` et `client_B`) selon un critère de comparaison donné par le paramètre `critere`.
 * Les critères possibles sont le nom, la profession, le code postal, et la date de naissance.
 *
 *@author bastien
 *
 * @param[in] client_A : CLIENT Premier client à comparer.
 * @param[in] client_B : CLIENT Deuxième client à comparer.
 * @param[in] critere : CRITERE Critère de comparaison (par exemple, nom, profession, code postal, ou date de naissance).
 *
 * @return :
 *   - Un entier négatif si `client_A` est inférieur à `client_B` selon le critère.
 *   - Zéro si `client_A` et `client_B` sont égaux selon le critère.
 *   - Un entier positif si `client_A` est supérieur à `client_B` selon le critère.
 *
 * @pre :
 *   - Les deux clients doivent être valides.
 *   - le critère un entier entre 0 et 3 inclus.
 *
 * @post :
 *   - La fonction retourne un résultat de comparaison en fonction du critère choisi.
 *
 * @note :
 *   - Utilise la fonction `_stricmp` pour la comparaison des chaînes de caractères (insensible à la casse).
 *   - Pour la comparaison des dates de naissance, la fonction compare d'abord l'année, puis le mois, et enfin le jour.
 */
int comparer_client(CLIENT client_A, CLIENT client_B, CRITERE critere,int * compl) ;

/**
 * @brief Trie une liste de clients en déplaçant ceux ayant un champ vide en fin de liste.
 *
 * Cette fonction place tous les éléments de la liste pour lesquels un champ spécifique est vide
 * à la fin de la liste, puis trie les éléments non vides en utilisant `timsort`.
 *
 * @param liste_client : CLIENT Tableau de clients à trier.
 * @param taille_actuelle : int Nombre d'éléments actuellement dans la liste.
 * @param critere : CRITERE Le champ à vérifier, défini par un type `CRITERE` (nom, profession, code postal, date de naissance).
 *
 * @pre la structure client doit exister et critere est un alias d'entier entre 0 et 3 inclus.
 *
 * @note Les éléments non vides sont triés avant les éléments vides dans le tableau résultant.
 */
 int tri_avec_deplacement_vide(CLIENT *liste_client,int taille_actuelle,CRITERE critere);


/**
 * @brief Vérifie si un champ spécifique d'un client est vide.
 *
 * Cette fonction permet de déterminer si un champ donné (nom, profession, code postal
 * ou date de naissance) est vide dans la structure `CLIENT`. Le critère à vérifier est
 * spécifié par le paramètre `critere`.
 *
 * @param[in] client : CLIENT La structure `CLIENT` à analyser.
 * @param[in] critere : CRITERE Le champ à vérifier, déterminé par un type `CRITERE` (nom, profession, code postal, date de naissance).
 *
 * @pre la structure client doit exister et critere est un alias d'entier entre 0 et 3 inclus.
 *
 * @return `true` si le champ est vide, `false` sinon.
 *
 * @note Pour le champ `date_naissance`, une date est considérée comme vide si l'année vaut 0.
 * la fonction a besoin de verifier seulement le premier caractere des champs.
 */
bool champ_vide(CLIENT client, CRITERE critere);

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



int tri_avec_deplacement_vide(CLIENT *liste_client,int taille_actuelle,CRITERE critere){
    int gauche = 0;
    int droite = taille_actuelle-1;
    int complexite=0;
    int *ptr = &complexite;
    while (gauche < droite){
        while (gauche < droite && !champ_vide(liste_client[gauche],critere)){
            gauche++;
        }
        while (gauche < droite && champ_vide(liste_client[droite],critere)){
            droite--;
        }
        if (gauche < droite){
            CLIENT temp = liste_client[gauche];
            liste_client[gauche] = liste_client[droite];
            liste_client[droite] = temp;
        }
    }
    timsort(liste_client,gauche,critere,ptr);
    return complexite;
}

bool champ_vide(CLIENT client, CRITERE critere){
    bool est_vide=false;
    switch (critere){
        case CRITERE_NOM:
            if (client.nom[0] == '\0')
                est_vide = true;
            break;
        case CRITERE_PROFESSION:
            if (client.profession[0] == '\0')
                est_vide = true;
            break;
        case CRITERE_CP:
            if (client.cp[0] == '\0')
                est_vide = true;
            break;
        case CRITERE_DATE_NAISSANCE:
            if (client.date_naissance.annee == 0)
               est_vide = true;
            break;
        default:
            printf("erreur de critere\n");
            break;
    }
    return est_vide;
}


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
