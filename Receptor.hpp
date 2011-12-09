#ifndef RECEPTOR_HPP
#define RECEPTOR_HPP
#include "EnigmaLetter.hpp"

class Receptor {
    public:
        virtual bool encode(EnigmaLetter letter) = 0;
};

#endif