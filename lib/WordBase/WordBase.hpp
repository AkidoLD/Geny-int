#pragma once

#include <map>
#include <unordered_set>
#include <string>
#include <stdexcept>
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;

const string DEFAUT_DATABASE = "word_database.dat";
/**
 * @brief Storage and manage Word List
 * @details This class contains methode and attribut who allows to manages a database of word
 */
class WordBase{
//Attributs
private:
    /**
     * @brief Word Map
     */
    map<size_t, unordered_set<string>> wordList;
    const string database; 

public:
    //Constructeur
    WordBase(const string database = DEFAUT_DATABASE);

    //Methodes
private:
    bool create_file_if(const string file);
    
public:
    /**
     * @brief Load file database word
     * @details This methode allows to load the word database from the `database` or specifie `database` to the `wordList`
     * @return True if the loading is success or false if not
     */
    bool load_database(string database = "");

    /**
     * @brief Save database in file
     * @details This methode allows to save the database in a specific file
     * @return True if the saving is success or false if not
     */
    bool save_database(string database = "");

    /**
     * @brief Get a set of word
     * @details This method allows to get a reference of unordered_set of word of specific `lenght`
     * @param[in] lenght the len of the word
     * @return The unorded_set reference of word a `lenght` word in database
     * @exception `range_error` if no have unorded_set of word with this`lenght` 
     */
    const unordered_set<string> &get_words_with_length(size_t lenght);

    /**
     * @brief Say if a word exit in the wordList
     * @details This method allow to find a specific word in the wordList and say if this word exit in the database
     * @param[in] s_word the word to search
     * @return `True` if the word is find or `False` if not
     */
    bool word_exist(const string s_word);

    /**
     * @brief Get the number of word in wordList
     * @details This method allow to get the number of word in the wordList
     * @return The number of word in wordList
     */
    size_t number_of_word();

    /**
     * @brief The surcharge of the output flux operator
     * @details This surcharge allows to display all the `wordList`
     * @param[inout] os The ouput stream
     * @param[in] wordBase The wordBase to display
     * @return  the output stream
     */
    friend ostream &operator<<(ostream &os, WordBase &wordBase);

    /**
     * @brief Say if the WordBase is empty
     * @details This methods allows to know if a WordBase is empty
     * @return `True` if the wordList is empty, `false` if not
     */
    bool empty();

    /**
     * @brief Get the wordList of a WordBase
     * @details This methods is used to get a constante ref on the `wordList`
     * @return The const ref of `wordList` of `WordBase`
     */
    const map<size_t, unordered_set<string>> & get_wordList() const {return wordList;}
};