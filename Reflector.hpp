#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP
#include "Mapper.hpp"

class Reflector : public Mapper{
    public:
        // Maps an integer to another given integer represeting a character using
        // the provided formula.
        int map( int x );
};

#endif

