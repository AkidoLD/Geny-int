#include <iostream>
#include <unordered_map>
#include "WordBase.hpp"
#include "RandomUtils.hpp"
#include "model/GenyRand.hpp"
#include <filesystem>
#include <functional>

using namespace std;

function<string()> f1 = []()->string{
    return "Function 1";
};
function<string()> f2 = []()->string{
    return "Function 2";
};
function<string()> f3 = []()->string{
    return "Function 3";
};
function<string()> f4 = []()->string{
    return "Function 4";
};

map<size_t, function<string()>> map_funct{
    {1, f1},
    {2, f2},
    {3, f3},
    {4, f4}
};


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
        //generator::w_db_char
    };
    cout << map_funct[2]() << endl;
    //
    // cout << geny.get_wordList() << endl;
    return 0;
}