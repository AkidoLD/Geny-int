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
#include <vector>

using namespace std; 

class Random{
    public : 
    /**
     * @brief Vector of special char
     */
    static const vector<char>s_char;

    /**
     * @brief Vector of ponctuation char
     */
    static const vector<char> p_char;
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

    /**
     * @brief Generate a random letter
     * @details This function allow to generate a random letter beetween a and z or A and Z
     * @param[in] upper Say if the generate characte is to `UPPERPCASE`
     * @return A charactere beetween [A-Z || a-z]
     */
    static char gen_rand_letter(bool upper = false);

    /**
     * @brief Generate a unit number
     * @details This function allow to generate au number beetween 0 and 9
     * @return A number beetweeb 0 and 9 
     */
    static u_short gen_rand_unit_number();

    /**
     * @brief Generate a random special char
     * @details This function allow to generate a random special char
     *          inignore invisible char like space( ) and tabulation(\t)
     * @param[in] ponct Say if it can generate pointuation char
     * @return A special char
     */
    static char gen_rand_spe_char(bool ponct = false);

    /**
     * @brief Return a random value in an array
     * @details This function take a vector of any type and return a random value
     * @param[inout] values the vector of values
     * @return  Random value of this const reference vector
     */
    template<class T>
    static const T &make_rand_choice(const vector<T> &values);
};

#endif /* B5E463AA_72D7_4614_91C8_344F26D70A37 */

