#include "Plugboard.hpp"
#include <iostream>
#include <fstream>
#include <string> 
#include <stdlib.h>

using namespace::std;
Plugboard::Plugboard()
{
    int i;
    for( i = 0; i < m_mappings.size(); i++ ){
        m_mappings[i] = i;
    }
}

/*
 * Reads the plugboard file, representing the pairings in m_mappings.
 * Displays error if fails to open.
 */
void Plugboard::read_file( const char* file_name )
{
    string input;
    ifstream plug_file ( file_name );
    if( plug_file.is_open() )
    {
        while( plug_file.good() )
        {
            getline( plug_file, input, ' ' );
            int first_value = atoi( input.c_str() );
            getline( plug_file, input, ' ' );
            int second_value = atoi( input.c_str() );
            m_mappings[first_value] = second_value;
            m_mappings[second_value] = first_value;
        }
    }
    else
    {
        cerr << "Error opening " << file_name << endl;
        exit(1);
    }
}

/*
 * Maps an int to it's representing integer representation of a character
 */
void Plugboard::map( int &x )
{
    x = m_mappings[x];
}
