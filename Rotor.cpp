#include "Rotor.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

// mappings and rev_mappings are both not initialized, and read_file
// does not verify that it fills in all the values.
// also nothing verifies that read_file was ever even called.
/*
 * Again private constructor, public factory method. 
 */

using namespace::std;

void Rotor::load_rotor( const char* file_name )
{
    Rotor* rotor = new Rotor();
    string input;
    ifstream rotor_file ( file_name);
    if( rotor_file.is_open() )
    {
        int i = 0;
        while( rotor_file.good() )
        {
            getline( rotor_file, input, ' ' );
            if( input.compare( string ("N") ) == 0 )
            {
                m_notch.add(i);
            }
            else
            {
                int value = atoi( input.c_str() );
                rotor->m_mappings[i] = EnigmaLetter(value - i);
                rotor->m_rev_mappings[value] = EnigmaLetter(i - value);
                ++i;
            }
        }
        if( m_notch.is_empty() )
        {
            m_notch.add(EnigmaLetter(0));
        }
    }
    else
    {
        cerr << "Error opening " << file_name << endl;
        exit(1);
    }
    return rotor;
}

Rotor::Rotor() : m_mappings(26), m_rev_mappings(26)
{
    m_forward = create_forward_transformer();
    m_backward = create_backward_transformer()
}

Rotor::~Rotor(){
    delete m_forward;
    delete m_backward;
}

Transformer* Rotor::create_forward_transformer(){
    Transformer* forward = new Transformer();
    return forward;
}


Transformer* Rotor::create_backward_transformer(){
    Transformer* backward = new Transformer() ;
    return backward;
}

int Rotor::mod( int x, int m )
{
    x %= m;
    return x < 0 ? x + m : x;
}

void Rotor::reset(){
    m_a_offset = 0;
}

int Rotor::map( int x )
{
    return mod( m_mappings[( m_a_offset + x ) % 26] + x, 26 );
}

int Rotor::reverse_map( int x )
{
    return mod( m_rev_mappings[ ( m_a_offset + x ) % 26 ] + x, 26 );
}

bool Rotor::turn()
{
    m_a_offset = mod( m_a_offset + 1, 26 );
    return m_a_offset == 0;
}
