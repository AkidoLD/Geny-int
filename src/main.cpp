#include <iostream>
#include <unordered_map>
#include "WordBase.hpp"
#include "RandomUtils.hpp"
#include "model/GenyRand.hpp"

using namespace std;

int main(int argc, char* argv[]){
    (void) argc; (void) argv;
    // WordBase wordbase;
    // cout << boolalpha <<wordbase.load_database();
    // cout << wordbase;
    // wordbase.save_database();
    // cout << "Vous avez actuellement "<<wordbase.number_of_word() << " mots dans votre base";

    GenyRand geny;
    vector<GenyRand::generator> gen_list{
        GenyRand::generator::c_l_alpha,
        GenyRand::generator::c_p_char,
        GenyRand::generator::c_u_alpha,
    };
    cout << geny.random_geny(gen_list, 20) <<endl;
    // cout << geny.get_wordList() <<endl;
    cout << geny.get_rand_str(5);
    return 0;
}