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

    GenyRand geny("/home/akido-ld/Documents/Memo/Guide pour Github et Git.txt");
    vector<generator> gen_list{
        generator::c_u_alpha,
        generator::c_digit,
        // generator::c_s_char,
        generator::w_db_char
    };
    //
    for (size_t i = 0; i < 100; i++)
    {
        cout << geny.generate_secure_passw(10, gen_list, false) << endl;
        cout << geny.generate_unique_uid(5, 5, " |=| ", gen_list, false) << endl;
        cout << geny.generate_personal_pseudo("AkidoLD", 20, 20, gen_list, false, true) << endl;
        cout <<endl << endl;
        /* code */
    }

    return 0;
}