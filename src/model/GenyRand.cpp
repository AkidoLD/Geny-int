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
            gen_str += get_rand_str(gchar_l);
            break;
        default:
            throw invalid_argument("Le un des generateur passe ne parametre est invalide");
            break;
        }
    }
    return gen_str;
}

string GenyRand::generate_secure_passw(const size_t lenght, vector<generator> &generators, const bool homogen){
    //Verification des parametre en entre
    if(lenght == 0) return "";
    if(generators.empty())
        throw invalid_argument("Le vector de generator ne peut etre vide");
    //
    size_t homo_coef = homogen ? 1 : (size_t) lenght/ generators.size(); //Coefficiant d'homogenehite
    //
    string gen_passw = "";

    while(gen_passw.length() < lenght){
        gen_passw += random_geny(generators, homo_coef);
    }
    //
    return gen_passw;
}

string GenyRand::generate_unique_uid(
    const size_t n_bloc,
    const size_t l_bloc,
    const char s_bloc,
    vector<generator> generators,
    const bool homogen
)
{
    if(!n_bloc || !l_bloc) return "";
    if(generators.empty())
        throw invalid_argument("La liste de generateur ne peut etre vide");
    //
    
}

const string GenyRand::get_rand_str(size_t const lenght){
    if(lenght == 0) return "";
    unordered_set<string> word_set;
    try{
        word_set = wordbase.get_words_with_length(lenght);
    }catch(range_error &e){
        cerr << e.what() << endl;
        return "";
    }
    //
    auto it = word_set.begin();
    advance(it, generate_rand_num(word_set.size() - 1));
    //
    return  *it;
}