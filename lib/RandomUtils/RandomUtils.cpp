#include "RandomUtils.hpp"

const vector<char>Random::s_char = {
        '<', '=', '>','@', 
        '[', '\\', ']', '/',
        '^', '_', '{', '|',
        '}', '~', '(', ')', 
        '%', '&', '-', '+',
        '*', '#', '$',
    };

const vector<char> Random::p_char = {':', ';', '?', '.', '\'', '\"', };

size_t Random::generate_rand_num(size_t _max, size_t _min) {
    if (_min > _max)
        throw invalid_argument("Min must be less than or equal to Max");
    
    // Initialiser le générateur si besoin
    static bool initialized = false;
    if (!initialized) {
        srand(static_cast<unsigned int>(time(nullptr)));
        initialized = true;
    }

    return _min + rand() % (_max - _min + 1);
}

string Random::get_rand_id(size_t nbr_string, size_t nbr_char){
    if(nbr_string == 0 || nbr_char == 0)
        throw invalid_argument("Les parametres ne peuvent pas etre null");
    //
    ostringstream id_stream; 
    for(size_t i = 0 ; i < nbr_string; i++){
        for(size_t y = 0 ; y < nbr_char ; y ++){
            size_t char_type = generate_rand_num(1); 
            if(char_type) id_stream << (char)generate_rand_num((size_t)'9', (size_t)'0'); 
            else id_stream << (char)generate_rand_num((size_t)'Z', (size_t)'A'); 
        }
        if(i < nbr_string - 1) id_stream << '-'; 
    }  
    return id_stream.str(); 
}

char Random::gen_rand_letter(bool upper){
    char gletter =  generate_rand_num('z','a');
    return upper ? toupper(gletter) : gletter;
}

u_short Random::gen_rand_unit_number(){
    return static_cast<u_short>(generate_rand_num(9));
}

char Random::gen_rand_spe_char(bool ponct){
    //If the ponctuation option is true, generator s_char ou p_char
    if(ponct) return generate_rand_num(1) ? s_char[generate_rand_num(size(s_char) -1)] : p_char[generate_rand_num(size(p_char) -1)];
    return s_char[generate_rand_num(size(s_char) -1)];
}

template<class T>
const T &Random::make_rand_choice(const vector<T> &values){
    if(values.empty())
        throw invalid_argument("The vector in parametre can't be empty");
    //
    return values[generate_rand_num(values.size() - 1)];
}