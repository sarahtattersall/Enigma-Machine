#ifndef ROTOR_HPP
#define ROTOR_HPP
#include "Mapper.hpp"
#include "Notch.hpp"
#include "Transformer.hpp"
#include "EnigmaLetter.hpp"
#include <vector>


class Rotor {
    public:
        Rotor( Rotor* next_rotor = null );
        ~Rotor();
        
        Transformer& forward();
        Transformer& backward();
        static Transformer* load_rotor( const char* file_name );
        // Implements a turn of the rotor by increasing m_a_offset
        // Also turns next rotor if nessesary.
        void turn();
        
        // Resets rotor to starting position
        void reset();
        
        // Maps a given int x to it's shifted character. m_a_offset points to the
        // position in m_mappings that A represents. Shifts accoridng to m_a_offset
        // Calls mod function for cases when result could be negative, i.e. when applying
        // the wire mappings.
        // bool encode( int x );

        
    private:    
        class RotorTransformer : public Transformer {
            RotorTransformer(Rotor* rotor, bool forwards) : m_rotor(rotor), m_forwards(forwards) {}
            bool encode(EnigmaLetter value) { m_receptor.encode(m_rotor->encode(value, m_forwards)); }
        };
        
        // Changed from bool to EnigmaLetter. Is this right?
        EnigmaLetter encode(EnigmaLetter letter, bool forwards);
        Rotor();
        Rotor* m_next_rotor;
        RotorTransformer m_forward;
        RotorTransformer m_backward;
        std::vector<EnigmaLetter> m_mappings;
        std::vector<EnigmaLetter> m_rev_mappings;        
        EnigmaLetter m_a_offset;
        
        // Reads the specified rotor file into a vector m_mappings.
        // Displays error if fails to open.
        void read_file( const char* file_name );
        Notch m_notch;
};

#endif

