#include "WordBase.hpp"

WordBase::WordBase(const string database):
    database(database)
{
    if(this->load_database()) is_valid = true;
}

WordBase::~WordBase(){
    if(!this->save_database()){
        cerr << "Une erreur est survenu lors de la sauvegarde des donnees" << endl;
    }
}

bool WordBase::create_file_if(const string file){
    if(filesystem::exists(file)) return true;
    try{
        ofstream(file, ios_base::trunc).close();
        return true;
    }catch(exception &e){
        cerr << e.what() << endl;
        return false;
    }
}

bool WordBase::load_database(string database){
    //si la chaine est vide utiliser la base de donneees par defaut de l'objet
    database = database.empty() ? this->database : database;
    if(!filesystem::exists(database)){
        if(!create_file_if(database)) return false;
    }
    ifstream datafile; 
    try{
        datafile = ifstream(database);
    }catch(exception &e){
        cerr << e.what() << ": Erreur lors du chargement des donnees" << endl;
        return false;
    }
    //Recuperation des donnees de la base
    string word;
    while(datafile >> word){
        wordList[word.length()].insert(word);
    }
    return true;
}

bool WordBase::save_database(string database){
    //si la chaine est vide utiliser la base de donneees par defaut de l'objet
    database = database.empty() ? this->database : database;
    if(!filesystem::exists(database)){
        if(!create_file_if(database)) return false;
    }
    ofstream datafile;
    try{
        datafile = ofstream(database, ios_base::trunc);
    }catch(exception &e){
        cerr << e.what() << ": Erreur lors de la sauvegarde de la base de donnee" << endl;
        return false;
    }
    //
    for(auto set : wordList){
        for(auto word : set.second){
            datafile << word << '\n';
        }
        datafile << flush;
    }
    return true;        
}

const unordered_set<string>* WordBase::get_words_with_length(size_t length) const {
    if(wordList.empty()) return nullptr;
    //
    auto it = wordList.find(length);
    if (it == wordList.end()) {
        return nullptr; 
    }
    return &(it->second);
}

bool WordBase::word_exist(const string s_word){
    if(s_word.empty()) return false;
    if(wordList.find(s_word.length()) == wordList.end()) return false;
    if(wordList[s_word.length()].find(s_word) == wordList[s_word.length()].end()) return false;
    return true;
}

size_t WordBase::number_of_word(){
    size_t num_word = 0;
    for(auto set : wordList){
        num_word += set.second.size();
    }
    return num_word;
}

bool WordBase::empty(){
    return wordList.empty();
}

ostream &operator<<(ostream &os, WordBase &wordBase){
    if(wordBase.empty()){
        os << "La WordBase est vide" << endl;
        return os;
    }
    os << "==== Liste des mots contenu dans la WordBase ====" << endl;
    for(auto set : wordBase.wordList){
        os << ">==== Taille = " << set.first << " ====> : " <<endl;
        for(auto word : set.second)
            os << "- " << word << endl;
        //
        os << endl;
    }
    return os << "==== Fin de la list ====" <<endl;
}

bool WordBase::append_word(const string &word){
    if(word.empty())
        throw invalid_argument("Le mot passe en parametre ne peut vide");
    //
    wordList[word.length()].insert(word);
    return true;
}

