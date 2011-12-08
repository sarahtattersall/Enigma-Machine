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

// Is it bad to have made m_a_offset an Enigma Letter?
Rotor::Rotor( Rotor* next_rotor = null ) : m_forward(this, true), m_backward(this,false), m_a_offset('A'){
    m_next_rotor = next_rotor;
}

// TODO: Implement smart pointer
Rotor::~Rotor(){
     delete m_next_rotor;
}

Transformer& Rotor::backward(){
    return m_backward&;
}

Transformer& Rotor::forward(){
    return m_forward&;
}


// Rotor::Rotor() : m_mappings(26), m_rev_mappings(26)
// {
//     m_forward = create_forward_transformer();
//     m_backward = create_backward_transformer()
// }



// Transformer* Rotor::create_forward_transformer(){
//     RotorTransformer* forward = new RotorTransformer();
//     return forward;
// }
// 
// Transformer* Rotor::create_backward_transformer(){
//     Transformer* backward = new Transformer();
//     return backward;
// }

bool Rotor::encode(EnigmaLetter letter, bool forwards){
    if (forwards){
        return m_mappings[(m_a_offset + letter)] + letter;
    } else{
        return m_rev_mappings[(m_a_offset + letter)] + letter;
    }
}

void Rotor::reset(){
    m_a_offset = 0;
}

void Rotor::turn()
{
    m_a_offset++;
    if (m_a_offset.int_value() == 0 && m_next_rotor != null){
        m_next_rotor.turn();
    }
}
