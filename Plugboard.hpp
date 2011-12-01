#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP
#include "Programmable_Mapper.hpp"

class Plugboard : public Programmable_Mapper{
    public:
        Plugboard();
        
        // Reads the plugboard file, representing the pairings in m_mappings.
        // Displays error if fails to open.
        void read_file( const char* file_name );
        
        // Maps an int to it's representing integer representation of a character
        void map( int& );
};

#endif

