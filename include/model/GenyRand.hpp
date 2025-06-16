#pragma once

#include <unordered_map>
#include <algorithm>
#include "RandomUtils.hpp" 
#include "WordBase.hpp"

class GenyRand : protected Random{
//Attributs
private: 
    WordBase wordbase;

public:
    /**
     * @brief Enumation of all generator
     */
    enum class generator{
        none,
        c_digit,
        c_u_alpha,
        c_l_alpha,
        c_s_char,
        c_p_char,
        w_db_char
    };
    
public:
    GenyRand();

//Methodes
public:
    WordBase &get_wordList(){return wordbase;}
    /**
     * @brief Genera with random generator
     * @details This methodes allows return random char generated with a random generator 😳
     * @param[in] gen_list Generator list who been used
     * @return The random char 
     */
    string const random_geny(vector<generator> &gen_list, size_t time = 1);

    //Bon, creation un suite de fonction specialise de generation pour pouvoir utiliser un map
    /**
     * @brief Generator of `c_digit`
     * @details This method allow to generate a `c_digit`
     * @return A `c_digit`
     */
    char gen_c_digit(){ return '0' + gen_rand_unit_number();}

    /**
     * @brief Generator of `c_u_alpha`
     * @details This method allow to generate a `c_u_alpha`
     * @return A `c_u_alpha`
     */
    char gen_c_u_alpha(){ return gen_rand_letter(true);}

    /**
     * @brief Generator of `c_l_alpha`
     * @details This method allow to generate a `c_l_alpha`
     * @return A `c_l_alpha`
     */
    char gen_c_l_alpha(){ return gen_rand_letter();}

    /**
     * @brief Generator of turn A `c_s_char`
     * @details This method allow to generate a `turn A `c_s_char`
     * @return A `turn A `c_s_char`
     */
    char gen_c_s_char(){ return gen_rand_spe_char();}

    /**
     * @brief Generator of `c_p_char`
     * @details This method allow to generate a `c_p_char`
     * @return A `c_p_char`
     */
    char gen_c_p_char(){ return gen_rand_spe_char(true);}

    /**
     * @brief Get random string in `wordbase`
     * @details This methode allows to get a random word of specific size in wordList
     * @param[in] lenght The lenght of the word you want to get
     * @return The word random Word in the wordList with this lenght or "" if not
     */
    const string get_rand_str(size_t const lenght);

public:
    /**
     * @brief Generate a secure password
     * @details This method allows to generate un strong password with multiple parameters
     *          The user can fully customise the the return of  the function
     * @param[in] lenght The lenght of the generated passw
     * @param[in] generators A reference of vector for all generator use.
     * @param[in] homogen If true, the generation of the passw will be completly random, if not, the char of the passw word will be group by type
     * @return A secure password with the preference of the user
     * @exception invalid_arguments If all th c_% are False. The minimum is 1
     * */
    string generate_secure_passw(
        const size_t lenght, 
        vector<generator> &generators, 
        const bool homogen = true
    );

    /**
     * @brief Generateur an unique user identifier
     * @details This method allows to generate a customised unique UID
     *          The user can fully customise the the return of  the function
     * 
     * @param[in] n_bloc The number of bloc in the generated uid
     * @param[in] l_bloc The lenght of one bloc in the uid
     * @param[in] s_bloc The separator of bloc
     * @param[in] homogen If true, the generation of the passw will be completly random, if not, the char of the passw word will be group by type 
     * @return A unique customised uid
     * @exception If all th c_% are False. The minimum is 1
     */
    string generate_unique_uid(
        const size_t n_bloc,
        const size_t l_bloc,
        const char s_bloc,
        vector<generator> generators,
        const bool homogen = true
    );
};