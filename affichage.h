/**
 * @file affichage.h
 * @brief fichier d'en tete
 * @author bastien et raphael
 * @version 1
 * @date 27/12/2024
 *
 * fichier de declartion des fonction qui permetent l'affichage de données.
 *
 */



#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#include "client.h"
/**
 * @brief Affiche les informations d'un client sous forme de tableau.
 *
 * Cette fonction affiche les informations du client sous forme de tableau,
 * chaque champ étant affiché dans une colonne spécifique (prénom, nom, ville, code postal,
 * téléphone, adresse mail, profession et date de naissance).
 *
 *@author bastien
 *
 * @param[in] client : CLIENT Structure contenant les informations du client à afficher dans le tableau.
 *
 * @pre : La structure `client` doit contenir des données valides.
 * @post : Affiche les informations du client dans un format de tableau avec des colonnes bien alignées.
 * @note Cette fonction utilise :
 * - afficher_champ
 * - afficher_date
  * @warning ce format d'affichage convient pour une certaine taille d'ecran, basé sur ceux de l'IUT.
 *
 */
void afficher_client_tab(const CLIENT client) ;

/**
 * @brief Affiche les informations détaillées d'un client sous forme de texte.
 *
 * Cette fonction affiche les informations du client de manière lisible, avec des libellés
 * pour chaque champ (prénom, nom, ville, code postal, téléphone, adresse mail, et date de naissance).
 *
 *@author bastien
 *
 * @param[in] client : CLIENT Structure contenant les informations du client à afficher.
 *
 * @pre : La structure `client` doit contenir des données valides.
 * @post : Affiche les informations du client avec un formatage textuel lisible.
 * @note Cette fonction utilise :
 * - afficher_champs_tab
 * - afficher_date_tableau
 * - afficher_adresse_mail_tableau
 *
 */
void afficher_client(const CLIENT client) ;

/**
 * @brief Affiche l'en-tête des colonnes pour la liste des clients.
 *
 * Cette fonction affiche un en-tête formaté, représentant les colonnes des informations principales des clients.
 *
 * Les colonnes affichées sont :
 * - `prenom` : Prénom du client.
 * - `nom` : Nom du client.
 * - `ville` : Ville du client.
 * - `cp` : Code postal du client.
 * - `tel` : Numéro de téléphone du client.
 * - `adresse_mel` : Adresse e-mail du client.
 * - `profession` : Profession du client.
 * - `date_naissance` : Date de naissance du client.
 *
 *@author bastien
 *
 * @pre Aucun prérequis spécifique. L'environnement d'exécution doit prendre en charge l'impression via `printf`.
 * @post Affiche l'en-tête formaté des colonnes dans la console.
 *
 *@warning ce format d'affichage convient pour une certaine taille d'ecran, basé sur ceux de l'IUT.
 */
void afficher_en_tete() ;

/**
 * @brief Affiche la liste des clients dans un format aligné avec des champs bien définis.
 *
 * Cette fonction affiche tous les clients présents dans la liste `liste_client`. Elle utilise un format aligné pour afficher les informations,
 * avec les champs bien alignés, en particulier le prénom. Si le nombre de clients dépasse 50, l'utilisateur peut appuyer sur une touche pour
 * afficher la suite des résultats.
 *
 *@author bastien
 *
 * @param[in] liste_client : CLIENT* Tableau contenant la liste des clients à afficher.
 * @param[in] n : int Nombre total de clients à afficher.
 *
 * @pre :
 *   - La liste `liste_client` doit être correctement initialisée et contenir les informations des clients.
 *   - Le nombre `n` doit correspondre au nombre d'éléments dans `liste_client`.
 *
 * @post :
 *   - Affiche tous les clients dans un format aligné avec les informations de chaque client.
 *   - Si le nombre de clients dépasse 50, l'utilisateur est invité à appuyer sur une touche pour continuer l'affichage.
 *
 * @note
 *   - Utilise la fonction `afficher_en_tete` pour afficher l'en-tête avant la liste des clients.
 *   - Utilise la fonction `afficher_client_tab` pour afficher chaque client dans le tableau `liste_client`.
 */
void afficher_tous_clients(const CLIENT *liste_client, int n) ;

/**
 * @brief Affiche un champ de données avec un label.
 *
 * Cette fonction affiche un champ de données précédé d'un label. Si les données sont vides (représentées par une chaîne vide),
 * elle affiche "Non renseignée" après le label. Sinon, elle affiche les données fournies à côté du label.
 *
 *@author bastien
 *
 * @param[in] label : char* Chaîne de caractères représentant le label à afficher.
 * @param[in] donnees : char* Chaîne de caractères représentant les données à afficher.
 *
 * @pre Les chaînes de caractères `label` et `donnees` doivent être correctement initialisées.
 *      - Si `donnees` est vide (c'est-à-dire commence par le caractère nul '\0'), cela indique que les données ne sont pas renseignées.
 *
 * @post Affiche le label suivi des données ou un message "Non renseignée" si les données sont vides.
 */
void afficher_champ(const char *label,const char *donnees) ;

/**
 * @brief Affiche un champ de données dans un format de tableau.
 *
 * Cette fonction affiche un champ de données dans un tableau. Si les données sont vides (représentées par une chaîne vide),
 * elle affiche "Non renseignée". Sinon, elle affiche les données fournies.
 *
 *@author bastien
 *
 * @param[in] donnees : char* Chaîne de caractères représentant les données à afficher.
 *
 * @pre La chaîne de caractères `donnees` doit être correctement initialisée.
 *      - Si `donnees` est vide (c'est-à-dire commence par le caractère nul '\0'), cela indique que les données ne sont pas renseignées.
 *
 * @post Affiche les données dans le tableau ou un message "Non renseignée" si les données sont vides.
 * @note cette fonction affiche 25 catacreres dans tous les cas (comble avec des caracteres vides).
 */
void afficher_champ_tableau(const char *donnees) ;

/**
 * @brief Affiche l'adresse email dans un format de tableau.
 *
 * Cette fonction affiche l'adresse email dans un tableau. Si l'adresse email est vide (représentée par une chaîne vide),
 * elle affiche "Non renseignée". Sinon, elle affiche l'adresse email fournie.
 *
 *@author bastien
 *
 * @param[in] donnees : char* Chaîne de caractères représentant l'adresse email à afficher.
 *
 * @pre La chaîne de caractères `donnees` doit être correctement initialisée.
 *      - Si `donnees` est vide (c'est-à-dire commence par le caractère nul '\0'), cela indique que l'email n'est pas renseigné.
 *
 * @post Affiche l'adresse email dans le tableau ou un message "Non renseignée" si l'email est vide.
 * @note cette fonction affiche 50 catacreres dans tous les cas (comble avec des caracteres vides).
 */
void afficher_adresse_mail_tableau(const char *donnees) ;

/**
 * @brief Affiche l'âge d'une personne en années, mois et jours à partir de sa date de naissance dans un tableau.
 *
 * Cette fonction calcule l'âge d'une personne en fonction de la date de naissance fournie et affiche le résultat
 * dans un format spécifique, adapté pour être intégré dans un tableau. Si la date de naissance est non renseignée
 * (tous les champs de la date sont égaux à zéro), elle affiche "Non renseignée".
 *
 *@author bastien
 *
 * @param[in] date : DATE Structure contenant la date de naissance de la personne à afficher.
 *
 * @pre La structure DATE doit être correctement initialisée.
 *      - Si tous les champs de la date (jour, mois, année) sont égaux à zéro, cela indique que la date n'est pas renseignée.
 *
 * @post Affiche l'âge de la personne en années, mois et jours dans un tableau, ou un message "Non renseignée" si la date est vide.
 *
 * @note Utilise la fonction `calculerage` pour calculer l'âge à partir de la date de naissance fournie.
 * cette fonction affiche 25 catacreres dans tous les cas (comble avec des caracteres vides).
 */
void afficher_date_tableau(const DATE date);

/**
 * @brief Affiche l'âge d'une personne en années, mois et jours à partir de sa date de naissance.
 *
 * Cette fonction calcule l'âge d'une personne en fonction de la date de naissance fournie et affiche le résultat.
 * Si la date est non renseignée (tous les champs sont à zéro), un message indiquant "Non renseignée" est affiché.
 *
 *@author bastien
 *
 * @param[in] label : char* Libellé à afficher avant la date (ex. "Date de naissance").
 * @param[in] date : DATE Structure contenant la date de naissance de la personne à afficher.
 *
 * @pre La structure DATE doit être correctement initialisée.
 *      - Si tous les champs de la date (jour, mois, année) sont égaux à zéro, cela indique que la date n'est pas renseignée.
 *
 * @post Affiche l'âge de la personne en années, mois et jours, ou un message indiquant que la date n'est pas renseignée.
 *
 * @note La fonction `calculerage` est utilisée pour calculer l'âge à partir de la date fournie.
 */
 void afficher_date(const char *label,const DATE date);

#endif // AFFICHAGE_H_INCLUDED
