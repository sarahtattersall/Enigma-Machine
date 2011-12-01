#ifndef ROTOR_HPP
#define ROTOR_HPP
#include "Programmable_Mapper.hpp"
#include "Notch.hpp"
#include <vector>

class Rotor : public Programmable_Mapper{
    private:
        std::vector<int> m_rev_mappings;        
        int m_a_offset;
        void read_file( const char* );
        int mod( int, int );
        Notch m_notch;
    public:
        Rotor( const char* );
        bool turn();
        void reset();
        void map( int& );
        void reverse_map( int& );
};

#endif

