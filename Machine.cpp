#include "Machine.hpp"
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "CharacterException.hpp"
using namespace::std;

static Transformer* Machine::load_machine(){
    Machine* machine = new Machine();
    Plugboard* f_plugboard = new Plugboard();
    Plugboard* b_plugboard = new Plugboard();
    Rotor* rotor1 = new Rotor();
    Reflector* reflector = new Reflector();
    //create rotors here pass in file names? etc.
    
    Transformer* backwards_rotor = rotor1.get_backwards();
    Transformer* forwards_rotor = rotor1.get_forwards();
    backwards_rotor->bind(b_plugboard);
    reflector->bind(backwards_rotor);
    forwards_rotor.bind(reflector);
    f_plugboard.bind(forwards_rotor);
    m_receptor = f_plugboard;
    return machine;
}

Machine::Machine(){
    
}

void Machine::load_rotor_file( const char* file_name )
{
    m_rotors.push_back( Rotor(file_name) );
}

void Machine::load_plug_file( const char* file_name )
{
    m_plugboard.read_file( file_name );
}

// TODO: Work out what to do with encode.
bool Machine::encode( EnigmaLetter value )
{
  // This is broken, isupper does not perform the same test that you rely on in
  // convert_to_int, it understands non english upper case letters.
  // In general, don't separate tests from operations when they are fundamentaly
  // tied together, write a single operation and test it succeeds instead.
    m_receptor.encode(mapping);
        // m_plugboard.map( mapping );
        // forward_rotor_pass( mapping );
        // m_reflector.map( mapping );
        // inverse_rotor_pass( mapping );
        // m_plugboard.map( mapping );
        // turn_rotors();
	// just return the result of the function.
	// storing it in a variable for no purpose makes it look like you meant
	// to put some more code in there but forgot.
        // return value.to_char();
    return true;
}
