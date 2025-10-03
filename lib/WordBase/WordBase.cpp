#include "WordBase.hpp"

WordBase::WordBase(const string &datafile):
    datafile(datafile),
    is_valid(false)
{
    this->load_database();
}

WordBase::WordBase():
    WordBase(DEFAUT_DATABASE){}

WordBase::~WordBase(){
    if(!this->save_database())
        cerr << "Une erreur est survenu lors de la sauvegarde des donnees" << endl;
    //
}

bool WordBase::create_file_if(const string &filepath){
    if(filesystem::exists(filepath)) return true;
    filesystem::path path(filepath);
    //
    const string directoty = path.parent_path();
    const string file = path.filename(); 
    //
    if(!directoty.empty())
        if(!filesystem::create_directory(directoty)) return false;
    //
    if(file.empty()){
        filesystem::remove(directoty);
        return false;
    }
    //
    ofstream tmpfile(filepath, ios::ios_base::app);
    //
    return tmpfile.is_open();
}

bool WordBase::import_data_from(const string &datafile){
    //si la chaine est vide utiliser la base de donneees par defaut de l'objet
    if(datafile.empty() || !filesystem::exists(datafile)) return is_valid = false;

    ifstream file_istream(datafile);
    if(!file_istream.is_open()) return is_valid = false;
    
    //Recuperation des donnees de la base
    string word;
    while(file_istream >> word){
        wordList[word.length()].insert(word);
    }
    //
    return is_valid = true;
}

bool WordBase::export_data_on(const string &datafile){
    //si la chaine est vide utiliser la base de donneees par defaut de l'objetstring word;
    if(!filesystem::exists(datafile))
        if(!create_file_if(datafile))
            return is_valid = false;
    //
    ofstream file_ostream(datafile);
    if(!file_ostream.is_open()) return is_valid = false;

    for(auto set : wordList){
        for(auto word : set.second){
            file_ostream << word << '\n';
        }
        file_ostream << flush;
    }
    //
    return true;        
}

bool WordBase::load_database(){
    return import_data_from(datafile);
}

bool WordBase::save_database(){
    return export_data_on(datafile);
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
    return !(wordList[s_word.length()].find(s_word) == wordList[s_word.length()].end());
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

