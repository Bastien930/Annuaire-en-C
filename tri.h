/**
 * @file tri.h
 * @brief fichier d'en tete
 * @author bastien et raphael
 * @version 1
 * @date 27/12/2024
 *
 * fichier de declartion des fonction de tri
 *
 */



#ifndef TRI_H_INCLUDED
#define TRI_H_INCLUDED


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
bool champ_vide(CLIENT client, CRITERE critere,int *compl);

#endif // TRI_H_INCLUDED
