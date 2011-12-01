#include "Rotor.hpp"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

// mappings and rev_mappings are both not initialized, and read_file
// does not verify that it fills in all the values.
// also nothing verifies that read_file was ever even called.

using namespace::std;

Rotor::Rotor( const char* rotor_file ) : m_rev_mappings(26)
{
    read_file( rotor_file );
    reset();
}

int Rotor::mod( int x, int m )
{
    x %= m;
    return x < 0 ? x + m : x;
}

void Rotor::reset(){
    m_a_offset = 0;
}

void Rotor::read_file( const char* file_name )
{
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
                m_mappings[i] = value - i;
                m_rev_mappings[value] = i - value;
                ++i;
            }
        }
        if( m_notch.is_empty() )
        {
            m_notch.add(0);
        }
    }
    else
    {
        cerr << "Error opening " << file_name << endl;
        exit(1);
    }
}


void Rotor::map( int &x )
{
    x = mod( m_mappings[( m_a_offset + x ) % 26] + x, 26 );
}

void Rotor::reverse_map( int &x )
{
    x = mod( m_rev_mappings[ ( m_a_offset + x ) % 26 ] + x, 26 );
}

bool Rotor::turn()
{
    m_a_offset = mod( m_a_offset + 1, 26 );
    return m_a_offset == 0;
}
