#ifndef B5E463AA_72D7_4614_91C8_344F26D70A37
#define B5E463AA_72D7_4614_91C8_344F26D70A37
/**
 * Cette bibliotheque permet de generer des objets aleatoire de facon dynamique et diverse
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <sstream>

using namespace std; 

class Random{
    public : 
    /**
     * @brief Génère un nombre aléatoire entre `_min` et `_max`.
     * @details Cette méthode permet de générer un nombre aléatoire dans l'intervalle fermé [`_min`, `_max`].
     *          Si `_min` n'est pas précisé, la borne inférieure est 0.
     *          Les paramètres doivent être positifs.
     * @param[in] _max La valeur maximale (incluse) du nombre généré.
     * @param[in] _min La valeur minimale (incluse) du nombre généré. Par défaut : 0.
     * @return Le nombre aléatoire généré dans l'intervalle [_min, _max].
    */
    static size_t generate_rand_num(size_t _max, size_t _min = 0);

    /**
     * @brief Genere un ID aleatoire
     * @details This function generate au ID with
     * @param[in] nbr_string Number of chaine in ID
     * @param[in] nbr_char Number of char in a String
     * @return `The ID generated`
     */
    static string get_rand_id(size_t nbr_string = 3, size_t nbr_char = 4); 
};

#endif /* B5E463AA_72D7_4614_91C8_344F26D70A37 */
