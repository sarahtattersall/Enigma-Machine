#ifndef ROTOR_HPP
#define ROTOR_HPP
#include "Programmable_Mapper.hpp"
#include "Notch.hpp"
#include <vector>

class Rotor : public Programmable_Mapper{
    public:
        Rotor( const char* rotor_file );
        
        // Implements a turn of the rotor by increasing m_a_offset
        bool turn();
        
        // Resets rotor to starting position
        void reset();
        
        // Maps a given int x to it's shifted character. m_a_offset points to the
        // position in m_mappings that A represents. Shifts accoridng to m_a_offset
        // Calls mod function for cases when result could be negative, i.e. when applying
        // the wire mappings.
        void map( int& x );
        
        // Inversley maps a character to it's original character.
        // Calls mod function for cases when result could be negative, i.e. when applying
        // the wire mappings.
        void reverse_map( int& x );
    private:
        std::vector<int> m_rev_mappings;        
        int m_a_offset;
        
        // Reads the specified rotor file into a vector m_mappings.
        // Displays error if fails to open.
        void read_file( const char* file_name );
        int mod( int x, int m );
        Notch m_notch;
};

#endif

