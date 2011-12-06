#ifndef NOTCH_HPP
#define NOTCH_HPP
#include "EnigmaLetter.hpp"
#include <vector>

class Notch{
    public:
        bool is_empty();
        void add( EnigmaLetter letter );
        // Checks to see if position x on the rotor is in m_positions.
        bool correct_position( EnigmaLetter position );

    private:
        std::vector<EnigmaLetter> m_positions;
    
};

#endif
