/**
 * @file message.h
 * @brief fichier d'en tete
 * @author bastien et raphael
 * @version 1
 * @date 27/12/2024
 *
 * fichier de declartion de type d'enumeration.
 *
 */


#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

/**
 * @brief Définition des messages pour la saisie de données utilisateur.
 *
 * L'énumération `MESSAGE` définit les différents types de messages utilisés pour guider l'utilisateur lors de la saisie de données. Chaque valeur correspond à un type de champ de saisie spécifique, comme le prénom, le nom, la ville, etc.
 *
 *@author bastien
 *
 * @enum MESSAGE
 * @see saisir_chaine, qui utilise cette énumération pour afficher des messages spécifiques.
 */
typedef enum {
    MSG_PRENOM,
    MSG_NOM,
    MSG_VILLE,
    MSG_CP,
    MSG_TELEPHONE,
    MSG_PROFESSION,
    MSG_ADRESSE_MAIL,
    MSG_DATE_NAISSANCE,
    MSG_TELEPHONE_FACULTATIF
} MESSAGE;


/**
 * @brief Définition des critères de tri pour la liste des clients.
 *
 * L'énumération `CRITERE` définit les critères de tri disponibles pour organiser la liste des clients en fonction de différents attributs.
 *
 *@author bastien
 *
 * @enum CRITERE
 * @see tri_liste_clients, qui utilise cette énumération pour spécifier les critères de tri.
 */
typedef enum {
    CRITERE_NOM,
    CRITERE_PROFESSION,
    CRITERE_CP,
    CRITERE_DATE_NAISSANCE
} CRITERE;


#endif // MESSAGE_H_INCLUDED
