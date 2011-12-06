#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP
#include "Transformer.hpp"
#include "EnigmaLetter.hpp"
#include <vector>
class Plugboard : public Transformer{
    public:
        // Reads the plugboard file, representing the pairings in m_mappings.
        // Displays error if fails to open.
        static Transformer* load_plugboard( const char* file_name );
        
        // Maps an int to it's representing integer representation of a character
        bool encode( EnigmaLetter letter );
        
    private:
        Plugboard();    
        std::vector<EnigmaLetter> m_mappings;
};

#endif

