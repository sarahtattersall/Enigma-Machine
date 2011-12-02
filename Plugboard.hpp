#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP
#include "Mapper.hpp"
#include <vector>
class Plugboard : public Mapper{
    public:
        Plugboard();
        
        // Reads the plugboard file, representing the pairings in m_mappings.
        // Displays error if fails to open.
        void read_file( const char* file_name );
        
        // Maps an int to it's representing integer representation of a character
        int map( int x );
        
    private:    
        std::vector<int> m_mappings;
};

#endif

