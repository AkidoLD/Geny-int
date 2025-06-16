#include "model/GenyRand.hpp"

GenyRand::GenyRand(){
    if(wordbase.load_database() == false){
        cerr << "Erreur lors du chargement des donnees de l'app" << endl;
    }   
        
    wordbase.save_database();
}

string const GenyRand::random_geny(vector<generator> &gen_list, size_t gchar_l){
    if(gen_list.empty())
        throw invalid_argument("La generator list ne peut etre vide");
    //
    if(gchar_l <= 0)
        throw invalid_argument("Le nombre de char genere ne peut etre null");
    //Choisir le generateur a utiliser
    auto _generator = gen_list[generate_rand_num(gen_list.size() - 1)];
    
    string gen_str = ""; //
    
    //Etape generation de la chaine
    while(gen_str.length() < gchar_l){
        switch (_generator)
        {
        case generator::c_digit:
            gen_str += gen_c_digit();
            break;
        case generator::c_l_alpha:
            gen_str += gen_c_l_alpha();
            break;
        case generator::c_u_alpha:
            gen_str += gen_c_u_alpha();
            break;
        case generator::c_s_char:
            gen_str += gen_c_s_char();
            break;
        case generator::c_p_char:
            gen_str += gen_c_p_char();
            break;
        case generator::w_db_char:
            gen_str += "";
            break;
        default:
            throw invalid_argument("Le un des generateur passe ne parametre est invalide");
            break;
        }
    }
    return gen_str;
}

string GenyRand::generate_secure_passw(
        const size_t lenght,
        const bool c_letter,
        const bool c_int,
        const bool c_schar,
        const bool p_char,
        const bool homogen,
        const bool w_base
)
{
    //Verification des parametre en entre
    if(lenght == 0) return "";
    if(!(c_letter || c_int || c_schar))
        throw invalid_argument("Tout les c_% ne peuvent pas etre a false");
    //
    /**
     * 
     */
    string gen_passw = "";
    //Liste des generateur utliser
    vector<u_short> generator_list;
    
    while(gen_passw.length() < lenght){

    }
}

const string GenyRand::get_rand_str(size_t const lenght){
    if(lenght == 0) return string("");
    unordered_set<string> word_set;
    try{
        word_set = wordbase.get_words_with_length(lenght);
    }catch(range_error &e){
        cerr << e.what() << endl;
        return string("");
    }
    //
    auto it = word_set.begin();
    advance(it, generate_rand_num(word_set.size() - 1));
    //
    return  *it;
}