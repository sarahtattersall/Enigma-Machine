#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP
#include "EnigmaLetter.hpp"

class Reflector : public Transformer{
    public:
        // Maps an integer to another given integer represeting a character using
        // the provided formula.
        bool encode( EnigmaLetter letter );
};

#endif

