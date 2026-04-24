/**
 * @file validation.h
 * @brief fichier d'en tete
 * @author bastien et raphael
 * @version 1.2
 * @date 27/12/2024
 *
 * fichier de declartion des fonction de validation de saisie
 *
 */


#ifndef VALIDATION_H_INCLUDED
#define VALIDATION_H_INCLUDED

#include <stdbool.h> // true et false
#include "client.h"

bool valide_compt_carac(const char* email);



/**
 * @brief Vérifie la validité du prénom, nom, ville ou profession.
 *
 * Le prénom, nom ou profession doit uniquement contenir des lettres, des espaces, des apostrophes ou des tirets.
 *
 *@author bastien
 *
 * @param[in] prenom : char* Chaîne de caractères représentant le prénom, le nom, la ville ou la profession à valider.
 * @return bool Retourne `true` si le prénom, nom, ville ou profession est valide, `false` sinon.
 * @pre :
 *   - Le prénom, nom, ville ou profession doit être une chaîne de caractères.
 * @post :
 *   - Retourne `true` si le prénom, nom ou profession contient uniquement des lettres, des espaces ou des tirets.
 *   - Retourne `false` si le prénom, nom ou profession contient des caractères non autorisés (par exemple, des chiffres ou des symboles).
 * @note
 *   - Les caractères spéciaux autres que les espaces, les tirets et les apostrophes(comme les chiffres et les symboles) ne sont pas autorisés.
 *   - La fonction considère également un prénom, nom, ville ou profession vide comme valide.
 */
bool valide_prenom_nom_profession_ville(const char* ch);


/**
 * @brief Vérifie la validité d'un code postal.
 *
 * Le code postal doit être une chaîne de 4 ou 5 caractères numériques.
 * Si la chaîne est vide, elle est également considérée comme valide.
 *
 *@author bastien
 *
 * @param[in] codePostal : char* Chaîne de caractères représentant le code postal à valider.
 * @return bool Retourne `true` si le code postal est valide, `false` sinon.
 * @pre :
 *   - Le code postal doit être une chaîne de caractères contenant des chiffres.
 *   - Le code postal doit avoir une longueur de 4 ou 5 caractères.
 * @post :
 *   - Retourne `true` si le code postal est composé uniquement de chiffres et a une longueur valide (4 ou 5).
 *   - Retourne `false` si la longueur est différente de 4 ou 5 caractères ou si le code postal contient des caractères non numériques.
 * @note
 *   - Seulement les chiffres sont considerer comme valide.
 *   - La fonction considère également un code postal vide comme valide.
 */
 bool valide_code_postal(const char *codePostal) ;


/**
 * @brief Vérifie la validité d'un numéro de téléphone.
 *
 * Le numéro de téléphone doit être sous la forme "0XX.XX.XX.XX.XX" où "X" représente un chiffre.
 * La longueur doit être de 14 caractères et chaque groupe de 2 chiffres doit être séparé par un point.
 * Si le numéro ne respecte pas ces critères, il est considéré comme invalide.
 *
 *@author bastien
 *
 * @param[in] telephone : char* Chaîne de caractères représentant le numéro de téléphone à valider.
 * @return bool Retourne `true` si le numéro de téléphone est valide, `false` sinon.
 * @pre :
 *   - Le numéro de téléphone doit être sous forme d'une chaîne de caractères.
 *   - Le numéro doit respecter le format spécifié.
 * @post :
 *   - Retourne `true` si la longueur du numéro est de 14 caractères et que le format est valide.
 *   - Retourne `false` si le numéro n'est pas valide selon les critères spécifiés.
 * @note
 *   - Les caracteres autres que des chiffres et des points ne sont pas autorisés.
 *   - La fonction considère un telephone vide comme non valide.
 */
bool valide_telephone(const char *telephone) ;


/**
 * @brief Vérifie la validité d'un numéro de téléphone facultatif au format spécifique.
 *
 * Cette fonction vérifie si le numéro de téléphone suit un format particulier :
 * - Un numéro vide est également considéré comme valide.
 * - Le numéro de téléphone doit avoir 14 caractères ou être vide.
 * - Le format attendu est de type "0X.XX.XX.XX.XX", où X est un chiffre de 0 à 9 et chaque groupe de chiffres est séparé par un point ('.').
 *
 *@author bastien
 *
 * @param[in] telephone : char* Chaîne de caractères représentant le numéro de téléphone à valider.
 * La chaîne doit être sous forme de texte représentant un numéro de téléphone.
 *
 * @return bool
 * - `true` si le numéro de téléphone est valide selon le format décrit.
 * - `false` si le numéro de téléphone ne respecte pas ce format.
 *
 * @pre La chaîne de caractères `telephone` doit être allouée et contenir le numéro à vérifier.
 * @post Retourne `true` si le numéro de téléphone respecte le format spécifique. Sinon, retourne `false`.
 * @note
 *   - Les caracteres autres que des chiffres et des points ne sont pas autorisés.
 *   - La fonction considère également un telephone vide comme valide.
 */
bool valide_telephone_facultatif(const char *telephone);

/**
 * @brief Vérifie si une adresse e-mail est valide.
 *
 * Une adresse e-mail est considérée valide si elle contient exactement un caractère '@'
 * et un caractère '.' après le '@', sans espaces dans l'adresse.
 *
 *@author bastien
 *
 * @param[in] email : char* Pointeur vers la chaîne de caractères représentant l'adresse e-mail.
 * La chaîne doit être une adresse e-mail valide (au moins un caractère avant '@', un '.' après '@').
 * @return bool
 * - `true` si l'adresse e-mail est valide.
 * - `false` si l'adresse e-mail est invalide.
 *
 * @pre L'adresse e-mail fournie doit être une chaîne de caractères non vide.
 * @post Retourne `true` si l'adresse e-mail est valide (contient un '@' et un '.', sans espaces).
 *       Sinon, retourne `false`.
 * @note
 *   - seuls le caractere espace n'est pas autoriser.
 *   - La fonction considère également un mail vide comme valide.
 */
bool valide_mail(const char* email);


/**
 * @brief Vérifie si une année est bissextile.
 *
 * Une année est considérée comme valide pour cette fonction si elle est un entier positif.
 * Une année est bissextile si elle est divisible par 4, mais pas par 100, sauf si elle est divisible par 400.
 * Exemple : 2020 est bissextile, mais 1900 ne l'est pas, alors que 2000 l'est.
 *
 *@author bastien
 *
 * @param[in] annee : int L'année à vérifier. L'année doit être un entier valide et positif.
 * @return bool
 * - `true` si l'année est bissextile (valide).
 * - `false` si l'année n'est pas bissextile (non valide).
 *
 * @pre L'année passée en paramètre doit être un entier valide et positif.
 * @post Retourne `true` si l'année est bissextile (valide), sinon retourne `false`.
 *
 * @note
 * - La règle du calendrier grégorien est utilisée pour déterminer si une année est bissextile.
 */
bool estbissextile(int annee);

/**
 * @brief Vérifie si une date de naissance est valide.
 *
 * La date est considérée valide si :
 * - L'année est un entier entre 1900 et 2025 inclus (valide).
 * - Le mois est un entier entre 1 et 12 inclus (valide).
 * - Le jour est un entier valide, c'est-à-dire compris entre 1 et le nombre de jours du mois spécifié,
 *   en tenant compte des années bissextiles.
 *
 *@author bastien
 *
 * @param[in] date : DATE La date à vérifier. La structure `DATE` doit contenir un jour, un mois, et une année.
 * @return bool
 * - `true` si la date est valide.
 * - `false` si la date est non valide (par exemple, année hors de portée, mois ou jour incorrect).
 *
 * @pre La structure `DATE` doit être correctement initialisée avec des valeurs d'année, mois et jour valides.
 * @post Retourne `true` si la date est valide, sinon retourne `false`.
 *
 * @note
 *   - La fonction considère également une date de naissance vide comme valide.
 */
bool valide_date_naissance(const DATE date);



/**
 * @brief Vérifie si un client possède des informations manquantes.
 *
 * Cette fonction détermine si l'une des informations essentielles d'un client est absente ou invalide.
 *
 *@author bastien
 *
 * @param[in] client : CLIENT Structure représentant un client, contenant ses informations.
 * @return bool Retourne `true` si l'une des informations essentielles est manquante, `false` sinon.
 *
 * Les informations vérifiées sont :
 * - `prenom` : Chaîne de caractères représentant le prénom du client.
 * - `nom` : Chaîne de caractères représentant le nom du client.
 * - `ville` : Chaîne de caractères représentant la ville du client.
 * - `cp` : Chaîne de caractères représentant le code postal du client.
 * - `telephone` : Chaîne de caractères représentant le numéro de téléphone du client.
 * - `adresse_mail` : Chaîne de caractères représentant l'adresse e-mail du client.
 * - `date_naissance.annee` : Année de naissance du client (doit être différente de 0).
 *
 * @pre La structure `client` doit être initialisée correctement et contenir des champs valides.
 * @post Aucun effet de bord : cette fonction ne modifie pas la structure passée en paramètre.
 * @note
 *   - Cette fonction verifie que le premier caractere et est donc tres economique.
 */
bool donne_manquante(const CLIENT client);

/**
 * @brief Vérifie si un numéro de téléphone existe dans la liste des clients.
 *
 * Cette fonction parcourt la liste des clients et compare chaque numéro de téléphone
 * avec celui donné en paramètre de manière insensible à la casse.
 * @author bastien
 * @param liste_client Tableau contenant les informations des clients.
 * @param telephone Chaîne représentant le numéro de téléphone à rechercher.
 * @param taille_actuelle Nombre actuel de clients dans la liste.
 * @return true si le numéro de téléphone existe dans la liste.
 * @return false si le numéro de téléphone n'existe pas.
 */
bool existe_telephone(const CLIENT *liste_client,const char * telephone,int taille_actuelle);




#endif // VALIDATION_H_INCLUDED
