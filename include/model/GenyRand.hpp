#pragma once

#include "RandomUtils.hpp" 
#include "WordBase.hpp"

class GenyRand : protected Random{
//Attributs
private: 
    WordBase wordbase;
public:
    string generate_secure_passw();
};