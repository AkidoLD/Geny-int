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
    vector<generator> gen_list{
        generator::c_u_alpha,
        generator::c_digit,
        // generator::c_s_char,
        generator::w_db_char
    };
    //
    cout << geny.generate_secure_passw(10, gen_list) << endl;
    cout << geny.generate_unique_uid(5, 5, "-", gen_list, true) << endl;
    cout << geny.generate_personal_pseudo("AkidoLD", 10, 5, gen_list, false) << endl;

    return 0;
}