#include <iostream>
#include <unordered_map>
#include "WordBase.hpp"

using namespace std;

int main(int argc, char* argv[]){
    (void) argc; (void) argv;
    WordBase wordbase;
    cout << boolalpha <<wordbase.load_database();
    cout << wordbase;
    wordbase.save_database();

    cout << "Vous avez actuellement "<<wordbase.number_of_word() << " mots dans votre base";
    return 0;
}