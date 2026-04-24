/**
 * @file client.h
 * @brief fichier d'en tete
 * @author bastien et raphael
 * @version 1
 * @date 27/12/2024
 *
 * fichier de declartion des fonction liées aux clients
 *
 */

#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#define TAILLE 25
#include "message.h"
#include <stdbool.h>

//verifier les type de certaine param[in]
//mettre les auteur
//ectt

/**
 * @brief Définition de la structure représentant une date.
 *
 * La structure `DATE` contient trois champs pour stocker une date : le jour, le mois et l'année.
 * Ces trois champs sont utilisés pour représenter une date sous forme de nombres entiers.
 * Par exemple : 25/12/2024.
 *
 * @struct DATE
 */
typedef struct {
    int jour;
    int mois;
    int annee;
} DATE;


/**
 * @brief Définition de la structure représentant un client.
 *
 * La structure `CLIENT` contient toutes les informations nécessaires pour décrire un client, y compris son nom, prénom, adresse, numéro de téléphone, et plus encore.
 * Elle inclut également un champ de type `DATE` pour stocker la date de naissance du client.
 *
 * @struct CLIENT
 */
typedef struct{
    char prenom[TAILLE],nom[TAILLE];
    char ville[TAILLE];
    char cp[6];
    char telephone[15];
    char adresse_mail[2*TAILLE];
    char profession[TAILLE];
    DATE date_naissance;

}CLIENT;



/**
 * @brief Tableau constant contenant les messages descriptifs pour les champs de saisie d'un client.
 *
 * Ce tableau est utilisé pour afficher des messages d'invite spécifiques à chaque champ
 * lors de la saisie des informations d'un client.
 *
 * @details
 * Les champs disponibles incluent :
 * - Prénom
 * - Nom
 * - Ville
 * - Code postal (format attendu : XXXXX)
 * - Numéro de téléphone (format attendu : XX.XX.XX.XX.XX)
 * - Profession
 * - Adresse email (format attendu : exemple@gmail.com)
 * - Date de naissance (format : jj mm aaaa)
 *
 * @note Les descriptions sont organisées selon des indices spécifiques à des constantes telles que `MSG_PRENOM`, `MSG_NOM`, etc.
 *
 */
const char *const TABLEAU_CHAINES[9];


/**
 * @brief Tableau constant contenant les messages d'erreur pour les champs de saisie d'un client.
 *
 * Ce tableau est utilisé pour afficher des messages d'erreur spécifiques lorsque l'utilisateur saisit des informations incorrectes,
 * ainsi que pour lui rappeler le format attendu.
 *
 * @details
 * Les champs disponibles incluent :
 * - Prénom : Le prénom est invalide. Veuillez entrer un prénom avec uniquement des lettres alphabétiques. Ce champ peut être vide.
 * - Nom : Le nom est invalide. Veuillez entrer un nom avec uniquement des lettres alphabétiques. Ce champ peut être vide.
 * - Ville : La ville est invalide. Veuillez entrer une ville avec uniquement des lettres et des espaces. Ce champ peut être vide.
 * - Code postal : Le code postal est invalide. Le format attendu est : XXXXX. Ce champ peut être vide.
 * - Numéro de téléphone : Le numéro de téléphone est invalide. Le format attendu est : XX.XX.XX.XX.XX. Ce champ peut être vide.
 * - Profession : La profession est invalide. Veuillez entrer une profession avec uniquement des lettres et des espaces. Ce champ peut être vide.
 * - Adresse email : L'adresse email est invalide. Le format attendu est : exemple@gmail.com. Ce champ peut être vide.
 * - Date de naissance : La date de naissance est invalide. Le format attendu est : JJ/MM/AAAA. Ce champ peut être vide.
 *
 * @note Les descriptions sont organisées selon des indices spécifiques à des constantes telles que `MSG_PRENOM`, `MSG_NOM`, etc.
 *
 */
 const char *const TABLEAU_ERREURS[9] ;


/**
 * @brief Permet de recueillir toutes les informations nécessaires pour créer ou modifier un client.
 *
 * Cette fonction guide l'utilisateur dans la saisie des informations d'un client,
 * en validant chaque champ avant de l'ajouter à la structure `CLIENT`.
 *
 * @param[in] client Structure `CLIENT` existante qui sera remplie avec les nouvelles données.
 *
 * @return
 * - Une structure `CLIENT` entièrement remplie et validée.
 *
 * @pre
 * - Les fonctions de saisie associées (`saisir_chaine`, `saisir_date`) doivent être correctement implémentées.
 *
 * @post
 * - Tous les champs de la structure `CLIENT` retournée sont validés selon les critères définis.
 *
 * @details
 * - Chaque champ est saisi via la fonction `saisir_chaine`, sauf la date de naissance qui est obtenue avec `saisir_date`.
 * - Les validations incluent :
 *   - Format des chaînes de caractères pour les champs texte.
 *   - Validité de la date de naissance.
 *
 * @see
 * - `saisir_chaine` pour la saisie et validation des chaînes.
 * - `saisir_date` pour la saisie de la date de naissance.
 */
CLIENT recuperer_donner(CLIENT client);

/**
 * @brief Permet à l'utilisateur de saisir une date valide au format "jj mm aaaa".
 *
 * Cette fonction demande la saisie d'une date de naissance, vérifie sa validité,
 * et retourne une structure `DATE` correctement remplie.
 *
 * @return
 * - Une structure `DATE` contenant les informations saisies.
 * - Si aucune date n'est saisie, les valeurs par défaut sont `0` pour le jour, le mois et l'année.
 *
 * @pre
 * - La fonction `valide_date_naissance` doit être correctement implémentée.
 *
 * @post
 * - La structure `DATE` retournée est soit vide (si aucune date n'a été saisie),
 *   soit valide selon les critères de `valide_date_naissance`.
 *
 * @details
 * - La saisie est effectuée en utilisant `fgets` pour capturer la ligne.
 * - En cas de dépassement de la taille du tampon ou de saisie incorrecte, un message d'erreur est affiché,
 *   et l'utilisateur est invité à recommencer.
 * - Les chaînes de caractères sont nettoyées pour supprimer les caractères de retour à la ligne.
 *
 * @warning
 * - La validation de la date repose sur la fonction `valide_date_naissance`.
 * - Les utilisateurs doivent respecter le format demandé ("jj mm aaaa").
 *
 * @see
 * - `valide_date_naissance` pour la validation de la structure `DATE`.
 * - `retour_chariot` pour le nettoyage des chaînes.
 */
DATE saisir_date();




/**
 * @brief Remplit une liste de structures `CLIENT` à partir des données d'un fichier texte.
 *
 * Cette fonction lit les lignes d'un fichier CSV contenant les informations des clients et
 * les convertit en structures `CLIENT` via la fonction `line_to_client`.
 *
 * @param[in] fichier : FILE* Pointeur vers un fichier texte ouvert contenant les données des clients.
 * @param[out] liste_clients : CLIENT* Tableau de structures `CLIENT` à remplir.
 * @param[in] taille_clients : int Nombre de clients maximum pouvant être stockés dans le tableau.
 *
 * @pre
 * - `fichier` doit être ouvert en mode lecture.
 * - `liste_clients` doit être un tableau alloué pouvant contenir au moins `taille_clients` éléments.
 * - La fonction `line_to_client` doit être correctement implémentée pour convertir une ligne en structure `CLIENT`.
 *
 * @post
 * - Le tableau `liste_clients` est rempli avec jusqu'à `taille_clients` clients extraits du fichier.
 * - Si le fichier contient moins de `taille_clients` lignes valides, seules les structures correspondantes sont remplies.
 *
 * @details
 * - La fonction utilise `fgets` pour lire les lignes du fichier.
 * - Chaque ligne lue est passée à la fonction `line_to_client` pour être convertie en structure `CLIENT`.
 * - Les lignes invalides ou les erreurs de lecture sont ignorées.
 *
 * @warning
 * - Si le fichier contient des données mal formatées, le comportement dépend de l'implémentation de `line_to_client`.
 * - La taille du tampon de lecture est limitée à 256 caractères par ligne.
 *
 * @see
 * - `line_to_client` pour la conversion des lignes en structures `CLIENT`.
 * - `fgets` pour la lecture des lignes du fichier.
 */
void remplir_liste_clients(FILE *fichier,CLIENT *liste_clients,int taille_clients);


/**
 * @brief Compte le nombre de lignes dans un fichier texte.
 *
 * Cette fonction lit un fichier texte ligne par ligne et retourne le nombre total de lignes.
 *
 * @param[in] fichier : FILE* Pointeur vers un fichier texte ouvert en mode lecture.
 *
 * @return
 * - Le nombre de lignes dans le fichier.
 * - Retourne 0 si le fichier est vide ou si une erreur survient.
 *
 * @pre
 * - `fichier` doit être un fichier ouvert en mode lecture.
 *
 * @post
 * - La position du pointeur dans le fichier est réinitialisée au début grâce à `rewind`.
 *
 * @details
 * - Chaque ligne est lue dans un tampon de taille fixe (`buffer[256]`).
 * - Les lignes vides sont également comptées.
 *
 * @warning
 * - Cette fonction ne gère pas les fichiers dont la taille dépasse les limites du tampon (256 caractères par ligne).
 *
 * @see
 * - `fgets` pour la lecture des lignes.
 */
 int compte_ligne(FILE * fichier);


/**
 * @brief Demande à l'utilisateur de saisir une chaîne de caractères et valide la saisie en fonction du type de données attendu.
 *
 * Cette fonction affiche un message personnalisé, lit la saisie utilisateur et vérifie sa validité
 * selon le type de données spécifié dans `msg`.
 *
 * @param[out] ch : char* Pointeur vers le tableau de caractères où sera stockée la chaîne saisie.
 * @param[in] msg : MESSAGE Type de message et de validation à effectuer (index correspondant à `TABLEAU_CHAINES`).
 *
 * @pre
 * - `ch` doit être un tableau alloué capable de contenir au moins `TAILLE` caractères.
 * - `TABLEAU_CHAINES` doit contenir des messages associés à chaque type de validation.
 * - Les fonctions de validation associées (par exemple `valide_prenom_nom_profession`) doivent être correctement implémentées.
 *
 * @post
 * - La chaîne `ch` contient une saisie valide sans retour chariot (`\n`).
 *
 * @details
 * - En cas de dépassement de taille de la saisie, le cache est vidé automatiquement.
 * - Les validations disponibles incluent :
 *   - Prénom, nom, profession (`valide_prenom_nom_profession`).
 *   - Ville (`valide_ville`).
 *   - Code postal (`valide_code_postal`).
 *   - Téléphone (`valide_telephone`).
 *   - Adresse mail (`valide_mail`).
 * - Si la saisie est invalide, l'utilisateur est invité à réessayer jusqu'à obtenir une entrée valide.
 *
 * @warning
 * - La validation dépend du type de données (`msg`) passé en paramètre.
 * - Les erreurs liées à des chaînes mal formatées ou non prises en charge doivent être gérées dans les fonctions de validation.
 *
 * @see
 * - `valide_prenom_nom_profession`, `valide_ville`, `valide_code_postal`, `valide_telephon
*/
void saisir_chaine(char *ch,MESSAGE msg);


/**
 * @brief Convertit une ligne de texte CSV en une structure CLIENT.
 *
 * Cette fonction analyse une chaîne de caractères représentant une ligne d'un fichier CSV
 * et extrait les informations pour remplir une structure `CLIENT`.
 *
 * @param[in] str : char* Chaîne de caractères (maximum 200) contenant les données du client, formatées comme suit :
 *                `prenom,nom,ville cp,telephone,adresse_mail,profession,jour/mois/annee`.
 *
 * @return
 * - Une structure `CLIENT` contenant les données extraites.
 * - Si certains champs ne peuvent pas être extraits, ils seront initialisés à des chaînes vides ou à des valeurs par défaut.
 *
 * @pre
 * - La chaîne `str` doit être non NULL et suivre le format attendu.
 * - Les champs doivent être séparés par des virgules, et la date doit suivre le format `jour/mois/annee`.
 *
 * @post
 * - Tous les champs de la structure `CLIENT` sont initialisés.
 *
 * @details
 * - La ville et le code postal sont extraits d'un seul champ et scindés en deux champs distincts :
 *   - La partie contenant des chiffres est considérée comme le code postal.
 *   - La partie avant le code postal est considérée comme la ville.
 * - Si la date n'est pas valide ou absente, les champs de la date de naissance (`jour`, `mois`, `annee`) sont initialisés à 0.
 *
 * @warning
 * - La fonction ne gère pas les erreurs de format complexes (par exemple, des virgules manquantes ou des champs mal alignés).
 * - Les champs dépassant leurs tailles maximales définies dans la structure `CLIENT` peuvent être tronqués sans avertissement.
 *
 * @see
 * - La structure `CLIENT` pour les détails sur les champs remplis.
 * - `sscanf` pour le parsing de la date.
 */
CLIENT line_to_client(char str[200]);



/**
 * @brief Recherche tous les indices des clients correspondant aux critères spécifiés.
 *
 * Cette fonction parcourt la liste des clients et retourne un tableau dynamique
 * contenant les indices des clients qui correspondent à tous les critères donnés.
 *
 * @param[in] liste_clients : CLIENT* Pointeur vers le tableau des clients à examiner.
 * @param[in] taille_actuelle : int Nombre total de clients dans la liste.
 * @param[out] nb_trouver : int* Pointeur vers un entier où sera stocké le nombre de clients trouvés.
 * @param[in] numero_telephone :char* Chaîne représentant le numéro de téléphone à rechercher (peut être NULL).
 * @param[in] adresse_mail : char* Chaîne représentant l'adresse mail à rechercher (peut être NULL).
 * @param[in] prenom Chaîne : char* représentant le prénom à rechercher (peut être NULL).
 * @param[in] nom :char* Chaîne représentant le nom à rechercher (peut être NULL).
 *
 * @return
 * - Un pointeur vers un tableau dynamique contenant les indices des clients trouvés.
 * - Si aucun client n'est trouvé, retourne un tableau vide et `*nb_trouver` est mis à 0.
 *
 * @pre
 * - `taille_actuelle` doit être supérieur ou égal à 0.
 * - `liste_clients` doit être un tableau valide contenant `taille_actuelle` clients.
 * - `nb_trouver` doit être un pointeur valide.
 *
 * @post
 * - Si des clients sont trouvés, `*nb_trouver` contient leur nombre et le tableau retourné contient leurs indices.
 * - Si aucun client n'est trouvé, `*nb_trouver` est mis à 0.
 * - La mémoire allouée pour le tableau des indices doit être libérée par l'appelant.
 *
 * @details
 * - Les critères non spécifiés (NULL) sont ignorés lors de la recherche.
 * - La recherche est insensible à la casse grâce à `_stricmp`.
 * - La capacité du tableau est ajustée dynamiquement via `realloc` si nécessaire.
 *
 * @warning
 * - Si une erreur survient lors de l'allocation de mémoire, le programme affiche un message d'erreur et termine avec `exit`.
 * - L'appelant est responsable de libérer la mémoire du tableau retourné.
 */
int* rechercher_des_clients(CLIENT *liste_clients, int taille_actuelle,int *nb_trouver, char *profession, char *code_postal,
                       char *prenom,  char *nom,int age,int *compl) ;



 /**
 * @brief Recherche le premier indice d'un client correspondant aux critères spécifiés.
 *
 * Cette fonction parcourt la liste des clients et retourne l'indice du premier client
 * qui correspond à tous les critères donnés (numéro de téléphone, adresse mail, prénom, nom).
 *
 * @param[in] liste_clients : CLIENT* Pointeur vers le tableau des clients à examiner.
 * @param[in] taille_actuelle : int Nombre total de clients dans la liste.
 * @param[out] nb_trouver : int* Pointeur vers un entier où sera stocké le nombre de clients trouvés.
 * @param[in] numero_telephone :char* Chaîne représentant le numéro de téléphone à rechercher (peut être NULL).
 * @param[in] adresse_mail : char* Chaîne représentant l'adresse mail à rechercher (peut être NULL).
 * @param[in] prenom Chaîne : char* représentant le prénom à rechercher (peut être NULL).
 * @param[in] nom :char* Chaîne représentant le nom à rechercher (peut être NULL).
 *
 * @return
 * - L'indice du premier client correspondant aux critères donnés.
 * - `-1` si aucun client ne correspond.
 *
 * @pre
 * - `taille_actuelle` doit être supérieur ou égal à 0.
 * - `liste_clients` doit être un tableau valide contenant `taille_actuelle` clients.
 *
 * @post
 * - Aucun changement n'est apporté à la liste des clients.
 *
 * @details
 * - Les critères non spécifiés (NULL) sont ignorés lors de la recherche.
 * - La recherche est insensible à la casse grâce à `_stricmp`.
 * - La recherche s'arrête dès qu'un client correspondant est trouvé.
 *
 * @warning
 * - La fonction suppose que les chaînes de critères sont valides si elles ne sont pas NULL.
 * - En cas de données incorrectes, le comportement est indéfini.
 */
int rechercher_indice_client(CLIENT *liste_clients, int taille_actuelle, char *numero_telephone, char *adresse_mail,
                              char *prenom, char *nom);


/**
 * @brief Trie la liste des clients en fonction d'un critère choisi par l'utilisateur.
 *
 * Cette fonction permet à l'utilisateur de sélectionner un critère pour trier
 * la liste des clients et effectue le tri en conséquence.
 *
 * @param[in,out] liste_client : CLIENT* Pointeur vers le tableau des clients à trier.
 * @param[in] taille_actuelle : int Nombre total de clients dans la liste.
 *
 * @pre
 * - `liste_client` doit être un tableau valide contenant `taille_actuelle` éléments.
 * - `taille_actuelle` doit être supérieur ou égal à 0.
 *
 * @post
 * - Si un critère de tri est choisi, la liste est triée selon ce critère.
 * - Si aucun critère valide n'est choisi, la liste reste inchangée.
 *
 * @details
 * - Les options de tri disponibles sont :
 *   - Nom : Trie les clients par ordre alphabétique de leur nom.
 *   - Profession : Trie les clients par profession.
 *   - Code postal : Trie les clients par code postal.
 *   - Date de naissance : Trie les clients par date de naissance.
 * - Le tri est effectué à l'aide de la fonction `timsort` et d'un critère correspondant.
 *
 * @warning
 * - Si l'utilisateur ne sélectionne pas une option valide, aucune modification n'est effectuée.
 * - L'entrée utilisateur doit être gérée pour éviter les comportements inattendus.
 *
 * @see
 * - `timsort` pour effectuer le tri selon un critère spécifique.
 * - `vider_cache` pour gérer les entrées utilisateur.
 */
void tri_liste_clients(CLIENT *liste_client, int taille_actuelle);



/**
 * @brief Supprime un client de la liste en décalant les éléments suivants.
 *
 * Cette fonction supprime un client spécifié par son indice dans la liste,
 * en décalant tous les éléments suivants pour combler l'espace laissé.
 *
 * @param[in,out] taille_actuel : int* Pointeur vers le nombre actuel de clients dans la liste.
 * @param[in,out] liste_clients : CLIENT* Pointeur vers le tableau des clients existants.
 * @param[in] indice : int Indice du client à supprimer (doit être valide).
 *
 * @pre
 * - `taille_actuel` doit être supérieur à 0.
 * - `liste_clients` doit être un tableau valide contenant au moins `*taille_actuel` éléments.
 * - `indice` doit être compris entre 0 et `*taille_actuel - 1`.
 *
 * @post
 * - Le client à l'indice spécifié est supprimé.
 * - Les éléments suivants sont décalés d'une position vers le début.
 * - Le nombre total de clients est décrémenté.
 *
 * @details
 * - La fonction identifie le client à supprimer par son indice.
 * - Les données suivantes sont décalées d'une position pour combler l'espace.
 *
 * @warning
 * - Si `indice` est invalide, le comportement est indéfini.
 * - Aucun message d'erreur n'est affiché si l'indice dépasse la plage valide.
 */
void suprimer_client(int *taille_actuel, CLIENT *liste_clients, int indice);



/**
 * @brief Ajoute un client à la liste si la capacité maximale n'est pas atteinte.
 *
 * Cette fonction insère un nouveau client à la fin de la liste des clients,
 * si la liste n'a pas atteint sa taille maximale.
 *
 * @param[in,out] liste_clients : CLIENT* Pointeur vers le tableau des clients existants.
 * @param[in,out] taille_max : int* Pointeur vers la capacité maximale de la liste.
 * @param[in] taille_actuel : int Nombre actuel de clients dans la liste.
 * @param[in] client : CLIENT Données du nouveau client à ajouter.
 *
 * @return
 * - Le nouveau nombre de clients dans la liste après l'ajout.
 * - La valeur initiale de `taille_actuel` si l'ajout échoue (taille maximale atteinte).
 *
 * @pre
 * - `taille_actuel` doit être supérieur ou égal à 0 et inférieur ou égal à `*taille_max`.
 * - `liste_clients` doit être un tableau valide contenant au moins `taille_actuel` éléments.
 *
 * @post
 * - Si l'ajout est réussi, `taille_actuel` est incrémenté et la liste contient le nouveau client.
 * - Si l'ajout échoue, un message d'erreur est affiché et aucun changement n'est apporté à la liste.
 *
 * @details
 * - La fonction vérifie si la taille actuelle est inférieure ou égale à la capacité maximale.
 * - Si la capacité est suffisante, le client est ajouté à la fin de la liste.
 *
 * @warning
 * - Si la taille maximale est atteinte, aucun ajout n'est effectué.
 */
void ajouter_client(CLIENT *liste_clients, int taille_max, int *taille_actuel, CLIENT client);


void option_0(int *taille_actuelle, int taille_max, CLIENT *liste_client);

/**
 * @brief Supprime un client de la liste à partir de son numéro de téléphone.
 *
 * Cette fonction permet à l'utilisateur de rechercher un client via son numéro de téléphone
 * et de le supprimer après confirmation.
 *
 * @param[in,out] taille_actuelle : int* Pointeur vers la taille actuelle de la liste des clients.
 * @param[in,out] liste_client : CLIENT* Pointeur vers le tableau des clients existants.
 *
 * @pre
 * - `taille_actuelle` doit pointer sur une valeur supérieure ou égale à 0.
 * - `liste_client` doit être un tableau valide contenant `taille_actuelle` clients.
 *
 * @post
 * - Si aucun client n'est trouvé, un message d'erreur est affiché.
 * - Si un client est trouvé et confirmé pour suppression :
 *   - Le client est supprimé de la liste.
 *   - La taille actuelle de la liste est décrémentée.
 *
 * @details
 * - L'utilisateur est invité à saisir un numéro de téléphone.
 * - La recherche est effectuée via la fonction `rechercher_indice_client`.
 * - Si un client correspondant est trouvé, une confirmation de suppression est demandée.
 * - Si confirmée, la suppression est effectuée via la fonction `suprimer_client`.
 *
 * @warning
 * - Un client est identifié uniquement par son numéro de téléphone.
 * - La confirmation est obligatoire pour supprimer un client.
 *
 * @see
 * - `saisir_chaine` pour la saisie du numéro de téléphone.
 * - `rechercher_indice_client` pour rechercher le client dans la liste.
 * - `suprimer_client` pour supprimer le client.
 * - `vider_cache` pour gérer les saisies utilisateur.
 */
void option_2(int *taille_actuelle, CLIENT *liste_client);

/**
 * @brief Trie et affiche tous les clients dans la liste.
 *
 * Cette fonction trie la liste des clients en fonction d'un critère donné
 * avant d'afficher tous les clients sous forme de tableau.
 *
 * @param[in] taille_actuelle : int* Nombre total de clients dans la liste.
 * @param[in] liste_client : CLIENT* Pointeur vers le tableau des clients existants.
 *
 * @pre
 * - `taille_actuelle` doit être supérieur ou égal à 0.
 * - `liste_client` doit être un tableau valide contenant `taille_actuelle` clients.
 *
 * @post
 * - La liste des clients est triée selon un critère prédéfini.
 * - Tous les clients sont affichés sous forme de tableau.
 *
 * @details
 * - La fonction commence par trier la liste des clients via `tri_liste_clients`.
 * - Tous les clients triés sont ensuite affichés via `afficher_tous_clients`.
 *
 * @warning
 * - La fonction suppose que la liste contient des données valides.
 * - Le tri est effectué sur la liste entière.
 *
 * @see
 * - `tri_liste_clients` pour trier la liste selon un critère.
 * - `afficher_tous_clients` pour afficher les détails des clients.
 */
void option_4(int taille_actuelle, CLIENT *liste_client);


/**
 * @brief Recherche un client dans la liste en fonction de plusieurs critères et affiche le résultat.
 *
 * La fonction permet à l'utilisateur de rechercher des clients dans une liste
 * en spécifiant un prénom, un nom, et soit un numéro de téléphone, soit une adresse mail.
 *
 * @param[in] taille_actuelle : int Nombre total de clients dans la liste.
 * @param[in] liste_client : CLIENT* Tableau contenant la liste complète des clients.
 *
 * @pre
 * - `taille_actuelle` doit être supérieur ou égal à 0.
 * - `liste_client` doit pointer vers un tableau valide contenant `taille_actuelle` clients.
 * - La fonction `rechercher_indice_client` doit être correctement implémentée pour renvoyer
 *   un indice d'un client correspondant aux critères de recherche.
 *
 * @post
 * - Si aucun client correspondant n'est trouvé, un message approprié est affiché.
 * - Si un client est trouvé :
 *    - le client est afficher
 *
 * @details
 * - L'utilisateur doit saisir un prénom, un nom, et au moins un numéro de téléphone ou une adresse mail.
 * - Les saisies sont validées pour s'assurer que tous les champs requis sont remplis.
 * - Une fois les données saisies, la fonction recherche dans la liste des clients et affiche le résultat trouvé.
 *
 * @warning
 * - L'utilisateur doit fournir des entrées valides et respecter les critères de saisie.
 * - Un telephone ou une adresse mail sont obligatoire pour la recherche affin de garantir un unique resultat.
 * - Les erreurs d'entrée utilisateur (comme des chaînes vides pour les champs obligatoire) sont gérées par une boucle jusqu'à validation correcte.
 *
 * @see
 * - `saisir_chaine` pour les saisies sécurisées.
 * - `rechercher_indice_client` pour la logique de recherche dans la liste des clients.
 * - `afficher_client` pour afficher les détails d'un client .
 */
void option_5(int taille_actuelle,CLIENT *liste_client);

/**
 * @brief Recherche un ou plusieurs clients dans la liste en fonction de plusieurs critères et affiche les résultats.
 *
 * La fonction permet à l'utilisateur de rechercher des clients dans une liste
 * en spécifiant un prénom, un nom, et soit un numéro de téléphone, soit une adresse mail.
 * Les résultats trouvés sont affichés sous forme de tableau.
 *
 * @param[in] taille_actuelle : int Nombre total de clients dans la liste.
 * @param[in] liste_client : CLIENT* Tableau contenant la liste complète des clients.
 *
 * @pre
 * - `taille_actuelle` doit être supérieur ou égal à 0.
 * - `liste_client` doit pointer vers un tableau valide contenant `taille_actuelle` clients.
 * - La fonction `rechercher_des_clients` doit être correctement implémentée pour renvoyer
 *   les indices des clients correspondant aux critères de recherche.
 *
 * @post
 * - Si aucun client correspondant n'est trouvé, un message approprié est affiché.
 * - Si des clients sont trouvés :
 *   - Une table d'en-tête est affichée.
 *   - Les clients trouvés sont affichés avec une pagination (50 clients par page).
 *
 * @details
 * - L'utilisateur peut saisir un prénom, un nom, un numéro de téléphone, et une adresse mail.
 * - Les saisies sont validées pour s'assurer que les saisies sont valides.
 * - Une fois les données saisies, la fonction recherche dans la liste des clients et affiche les résultats trouvés.
 * - Si le nombre de clients trouvés dépasse 50, une pause interactive est introduite pour afficher les résultats par blocs.
 *
 * @warning
 * - L'utilisateur doit fournir des entrées valides et respecter les critères de saisie.
 * - Les erreurs d'entrée utilisateur (comme des chaînes vides) sont gérées par une boucle jusqu'à validation correcte.
 *
 * @see
 * - `saisir_chaine` pour les saisies sécurisées.
 * - `rechercher_des_clients` pour la logique de recherche dans la liste des clients.
 * - `afficher_client_tab` pour afficher les détails d'un client sous forme de tableau.
 * - `afficher_en_tete` pour afficher l'en-tête de la liste des clients.
 */
void option_6(int taille_actuelle, CLIENT *liste_client);

/**
 * @brief Identifie et affiche les clients avec des données manquantes.
 *
 * La fonction recherche dans la liste des clients ceux qui ont des données manquantes.
 * Elle offre à l'utilisateur l'option d'afficher la liste des clients concernés après tri.
 * Si le nombre de clients dépasse 50, l'affichage est paginé.
 *
 * @param[in] liste_clients : CLIENT* Tableau contenant la liste complète des clients.
 * @param[in] taille_actuelle : int Nombre total de clients dans la liste.
 *
 * @pre
 * - `liste_clients` doit pointer vers un tableau valide contenant `taille_actuelle` clients.
 * - La structure `CLIENT` et la fonction `donne_manquante` doivent être correctement définies.
 *
 * @post
 * - Identifie et affiche les clients avec des données manquantes.
 * - Trie et affiche ces clients si l'utilisateur choisit cette option.
 * - Libère la mémoire allouée dynamiquement.
 *
 * @details
 * - La fonction utilise de l'allocation dynamique pour stocker les indices des clients
 *   avec des données manquantes ainsi que pour créer une nouvelle liste contenant ces clients.
 * - Si une erreur d'allocation mémoire survient, le programme affiche un message d'erreur et termine l'exécution.
 * - L'utilisateur peut choisir d'afficher ou non la liste des clients trouvés.
 * - Les clients affichés sont triés selon le critère choisi par l'utilisateur dans la fonction `tri_liste_clients`.
 * - L'affichage est paginé par blocs de 50 clients, avec une attente de validation utilisateur avant de continuer.
 *
 * @warning
 * - Cette fonction suppose que `donne_manquante` est correctement implémentée pour détecter les données absentes.
 * - Les erreurs d'entrée utilisateur ne sont pas entièrement gérées (par exemple, saisies invalides).
 */
void option_7(const CLIENT *liste_clients, int taille_actuelle);



/**
 * @brief Trie une liste de clients en fonction d'un critère choisi par l'utilisateur.
 *
 * L'utilisateur peut choisir de trier la liste selon :
 * - Le nom (option '0')
 * - La profession (option '1')
 * - Le code postal (option '2')
 * - La date de naissance (option '3')
 *
 * Si aucune option valide n'est sélectionnée, les données ne sont pas triées.
 *
 * @param[in,out] liste_client : CLIENT* Tableau contenant la liste des clients.
 * @param[in] taille_actuelle : int Nombre actuel de clients dans la liste.
 * @pre :
 *   - La liste des clients doit être valide.
 *   - La taille actuelle doit correspondre au nombre d'éléments du tableau.
 * @post :
 *   - La liste est triée selon le critère choisi par l'utilisateur si une option valide est sélectionnée.
 *   - La liste reste inchangée si aucune option valide n'est sélectionnée.
 * @note
 *   - Utilise la fonction `timsort` pour effectuer le tri.
 *   - Les options disponibles sont affichées dans le terminal avant que l'utilisateur fasse son choix.
 */
void tri_liste_clients(CLIENT *liste_client, int taille_actuelle);

#endif // CLIENT_H_INCLUDED
