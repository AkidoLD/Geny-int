#include "RandomUtils.hpp"

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