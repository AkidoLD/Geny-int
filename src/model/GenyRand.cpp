#include "model/GenyRand.hpp"

GenyRand::GenyRand(){
    if(wordbase.load_database() == false){
        cerr << "Erreur lors du chargement des donnees de l'app" << endl;
    }   
    wordbase.save_database();
}

GenyRand::GenyRand(const string load_database):
    wordbase(load_database)
{
    if(wordbase.load_database() == false){
        cerr << "Erreur lors du chargement des donnees de l'app" << endl;
    }   
    wordbase.save_database();
}

string const GenyRand::random_geny(const vector<generator> &gen_list, size_t gchar_l){
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
    gen_passw.resize(lenght);
    //
    return gen_passw;
}

string GenyRand::generate_unique_uid(
    const size_t n_bloc,
    const size_t l_bloc,
    const string s_bloc,
    vector<generator> &generators,
    const bool homogen
) {
    if (n_bloc == 0 || l_bloc == 0)
        return "";

    if (generators.empty())
        throw std::invalid_argument("La liste de générateurs ne peut être vide");

    const size_t homo_coef = homogen ? 1 : l_bloc;
    vector<string> gen_uid;
    string bloc;

    // Génération des blocs
    while (gen_uid.size() < n_bloc) {
        bloc += random_geny(generators, homo_coef);

        if (bloc.size() >= l_bloc) {
            bloc.resize(l_bloc); // Tronque au cas où on dépasse
            gen_uid.push_back(std::move(bloc));
            bloc.clear();
        }
    }

    return join_randomly(gen_uid, homogen,s_bloc);
}


const string GenyRand::get_rand_str(size_t const lenght){
    if(lenght == 0) return "";
    const unordered_set<string>  *word_set = wordbase.get_words_with_length(lenght);
    if(word_set == nullptr || word_set->empty()) return "";
    //
    auto it = word_set->begin();
    advance(it, generate_rand_num(word_set->size() - 1));
    //
    return  *it;
}

const string GenyRand::generate_personal_pseudo(
        const string &sample,
        const size_t max_l,
        const size_t min_l,
        vector<generator> generators,
        const bool homo_gen,
        const bool r_sample
){
    if(generators.empty())
        throw invalid_argument("La liste de generateur ne peux pas etre null");
    //
    if(!(min_l > 0 && min_l <= max_l))
        throw invalid_argument("La taille taille minimal ne peux etre null et doit toujours etre inferieur ou egale a la taille maximal");
    //
    if(r_sample and min_l < sample.size())
        throw range_error("Si l'echantillon est requis, la taille minimal ne peux etre inferieur a la taille de celui ci");
    //
    size_t g_pseudo_l = generate_rand_num(max_l, min_l);// Longueur final du pseudo genere
    string g_pseudo = ""; g_pseudo.reserve(g_pseudo_l); //Alloue la taille necessaire

    vector<string> g_tokens; //Tokens generes
    size_t g_tokens_l = 0; //La taille a jour de la somme des tokens deja genere

    if(r_sample or rand_predicat()) {
        g_tokens.push_back(sample);
        g_tokens_l += sample.length();
    }

    while(g_tokens_l < g_pseudo_l){
        size_t g_token_l = generate_rand_num((g_pseudo_l - g_tokens_l), 1);
        string g_token = random_geny(generators, g_token_l);
        if(g_token.empty()) continue;
        g_tokens.push_back(g_token);
        g_tokens_l += g_token.length();
    }
    g_pseudo = join_randomly(move(g_tokens), homo_gen);
    g_pseudo.resize(g_pseudo_l);
    //
    return g_pseudo;
}

vector<generator> GenyRand::make_generator_list(
        const bool c_digit,
        const bool c_u_alpha,
        const bool c_l_alpha,
        const bool c_s_char,
        const bool c_p_char,
        const bool w_db_char
){
    vector<generator> generator_list;
    if(c_digit) generator_list.push_back(generator::c_digit);
    if(c_l_alpha) generator_list.push_back(generator::c_l_alpha);
    if(c_u_alpha) generator_list.push_back(generator::c_u_alpha);
    if(c_s_char) generator_list.push_back(generator::c_s_char);
    if(c_p_char) generator_list.push_back(generator::c_p_char);
    if(w_db_char) generator_list.push_back(generator::w_db_char);
    //
    return generator_list;
}