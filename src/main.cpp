#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[]){
    (void) argc; (void) argv;
    cout << "Hello Geny" << endl;
    //
    char *a;
    {
        char c[] = "Bonjour";
        a = c;
    }
    cout << a; 
    return 0;
}