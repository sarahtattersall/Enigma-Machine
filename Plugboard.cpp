#include "Plugboard.hpp"
#include <iostream>
#include <fstream>
#include <string> 
#include <stdlib.h>

using namespace::std;
Plugboard::Plugboard() : m_mappings(26)
{
    int i;
    for( i = 0; i < m_mappings.size(); i++ ){
        m_mappings[i] = i;
    }
}

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

int Plugboard::map( int x )
{
    return m_mappings[x];
}
