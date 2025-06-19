#pragma once

#include <map>
#include <unordered_set>
#include <string>
#include <stdexcept>
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;

const string DEFAUT_DATABASE = "data/wordbase.dat";
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

    /**
     * @brief The database file directory
     */
    const string datafile; 

    /**
     * @brief The state of the database
     */
    bool is_valid ;

public:
    //Constructeur
    WordBase();
    WordBase(const string &datafile);

    //Destructeur
    ~WordBase();

    //Methodes
private:
    bool create_file_if(const string &file);
    
public:
    /**
     * @brief Say if the wordbase is available
     * @details Thus methods is use to check the status of a wordbase
     * @return True is the avaible and false if not
     */
    bool is_avaibable()const {return is_valid;}

    /**
     * @brief Load file database word
     * @details This methode allows to load the word database from the `database` or specifie `database` to the `wordList`
     * @return True if the loading is success or false if not
     */
    bool load_database();

    /**
     * @brief Save database in file
     * @details This methode allows to save the database in a specific file
     * @return True if the saving is success or false if not
     */
    bool save_database();

    /**
     * @brief Load database from other base
     * @details This method allow to load data from another datafile
     * @param[in] datafile The datafile path
     * @return True if the operation is successful or false if not
     */
    bool import_data_from(const string &datafile);

    /**
     * @brief Save data from other datafile
     * @details This method allow to save data in speficifique datafile
     * @param[in] datafile The data file where the data was save
     * @return True if the operation is successful or false if not
     */
    bool export_data_on(const string &datafile);

    /**
     * @brief Get a set of word
     * @details This method allows to get a reference of unordered_set of word of specific `lenght`
     * @param[in] lenght the len of the word
     * @return The unorded_set pointer of word a `lenght` word in database
     * @exception `range_error` if no have unorded_set of word with this`lenght` 
     */
    const unordered_set<string>* get_words_with_length(size_t length) const;

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

    /**
     * @brief Get the statement of a WordBase
     * @details This methode allows to get the state of the WordBase
     * @return the state of the WordBase
     */
    bool get_state() const{ return is_valid;}

    /**
     * @brief Append new word in the WordBase
     * @details This method allow to append a new word in the WordBase
     * @param[in] word The word to append
     * @return True if the operation pass and false if not
     * @exception invalid_arguments if the word in parameter is empty
     */
    bool append_word(const string &word);

    /**
     * @brief Create a directory if don't exist
     * @details This method allow to create a directory if it don't exist
     * @param[in] directory The directory to create
     * @exception runtime_error If the creation failed
     */
    void create_file_directory(string const &directoy);
};