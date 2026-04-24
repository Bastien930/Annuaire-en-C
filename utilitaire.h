/**
 * @file utilitaire.h
 * @brief fichier d'en tete
 * @author bastien et raphael
 * @version 1
 * @date 27/12/2024
 *
 * fichier de declartion des fonction utiliser dans un large groupe de fonction.
 *
 */



#ifndef UTILITAIRE_H_INCLUDED
#define UTILITAIRE_H_INCLUDED

/**
 * @brief Structure représentant la date et l'heure actuelle.
 *
 * Cette variable externe est utilisée pour stocker la date et l'heure actuelles, telles que récupérées à partir de l'horloge système.
 * Elle est définie comme une structure `tm` de la bibliothèque standard C, qui contient des informations sur le jour, le mois, l'année,
 * ainsi que d'autres informations temporelles comme les heures, minutes et secondes.
 *
 *@author bastien
 *
 * @note Cette variable est utilisée dans diverses fonctions pour effectuer des calculs relatifs à la date et à l'heure actuelle.
 */
extern struct tm date_act;

/**
 * @brief Remplace le caractère de nouvelle ligne par un caractère nul ('\0') dans une chaîne de caractères.
 *
 * Cette fonction permet de supprimer le retour chariot ('\n') qui peut être présent à la fin d'une chaîne de caractères,
 * typiquement après une entrée de l'utilisateur avec `scanf` ou `fgets`.
 *
 *@author bastien
 *
 * @param[in,out] ch  : char* La chaîne de caractères à traiter. Si un retour chariot ('\n') est trouvé, il sera remplacé par un caractère nul.
 *
 * @note Cette fonction modifie directement la chaîne de caractères fournie en argument.
 */
 void retour_chariot(char *ch) ;

 /**
 * @brief Vide le cache d'entrée (flush du buffer d'entrée).
 *
 * Cette fonction est utilisée pour vider le buffer d'entrée après un appel à `scanf`, afin de s'assurer qu'aucune donnée résiduelle
 * (comme un retour chariot) ne perturbe les appels suivants de saisie.
 *
 *@author bastien
 *
 * @note Cette fonction ne prend aucun paramètre et vide uniquement le cache de saisie.
 */
void vider_cache(void) ;

/**
 * @brief Calcule l'âge en années, mois et jours à partir d'une date de naissance.
 *
 * Cette fonction calcule l'âge en fonction de la date de naissance fournie et de la date actuelle.
 * Elle prend en compte les années bissextiles et ajuste les mois et jours si nécessaire.
 *
 *@author bastien
 *
 * @param[in] annee : int L'année de naissance.
 * @param[in] mois  : int Le mois de naissance.
 * @param[in] jour  : int Le jour de naissance.
 * @param[out] tab : int  Un tableau de 3 entiers où l'âge sera stocké sous forme de [jours, mois, années].
 *                   - tab[0] : jours
 *                   - tab[1] : mois
 *                   - tab[2] : années
 *
 * @note La fonction utilise la date actuelle obtenue via la variable globale `date_act`.
 *  Cette fonction prend en compte les mois et jours, ajustant les calculs si le jour ou le mois actuel est inférieur à celui de la date de naissance.
 */
void calculerage(int annee, int mois, int jour, int tab[3]) ;

/**
 * @brief Initialise la date actuelle en remplissant la variable globale `date_act`.
 *
 * Cette fonction récupère la date et l'heure actuelles du système et initialise la structure globale `date_act`
 * avec ces informations, pour être utilisées dans d'autres fonctions comme `calculerage`.
 *
 *@author bastien
 *
 * @note La variable globale `date_act` est de type `struct tm` et contient la date actuelle sous forme de jour, mois, année, etc.
 */
void init_date() ;

/**
 * @brief Compte le nombre de lignes dans un fichier.
 *
 *@author bastien
 *
 * @param[in] fichier : FILE* Fichier dont le nombre de lignes doit être compté.
 *
 * @return int Le nombre de lignes dans le fichier.
 *
 * @pre : Le fichier doit être ouvert en mode lecture.
 * @post : Retourne le nombre de lignes dans le fichier.
 */
int compte_ligne(FILE *fichier);
#endif // UTILITAIRE_H_INCLUDED
