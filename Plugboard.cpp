#include "Plugboard.hpp"
#include <iostream>
#include <fstream>
#include <string> 
#include <stdlib.h>

using namespace::std;
// TODO: CHECK IF M_RECEPTOR SET
bool Plugboard::encode( EnigmaLetter letter )
{
    return m_receptor->encode(m_mappings[letter.to_int()]);
}

// TODO: COMMENTED THIS OUT BUT I WANT TO DECLARE SIZE?
Plugboard::Plugboard() //: /m_mappings(26), 
{
    int i;
    for( i = 0; i < m_mappings.size(); i++ ){
        m_mappings[i] = EnigmaLetter(i);
    }
}

Transformer* Plugboard::load_plugboard( const char* file_name )
{
    Plugboard* plugboard = new Plugboard();
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
            plugboard->m_mappings[first_value] = EnigmaLetter(second_value);
            plugboard->m_mappings[second_value] = EnigmaLetter(first_value);
        }
    }
    else
    {
        cerr << "Error opening " << file_name << endl;
        exit(1);
    }
    return plugboard;
}
