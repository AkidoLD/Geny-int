#include <iostream>
#include <unordered_map>
#include <cmath>
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

    GenyRand geny{};
    vector<generator> gen_list{
        generator::c_u_alpha,
        generator::c_digit,
        // generator::c_s_char,
    };
    //
    auto generators = GenyRand::make_generator_list(1, 0, 0, 0, 0);
    cout << geny.generate_secure_passw(20, generators, true, false) << endl;
    cout << geny.generate_personal_pseudo("Akido", 10, 10, generators, true, false, false);
    //cout << geny.get_wordList() << endl;

    return 0;
}