#include "Machine.hpp"
#include <QtGui/QtGui>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include "CharacterException.hpp"
using namespace::std;

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

char Machine::convert_to_char( int x )
{
  // The operation does not match the comment, the mod is much more.
  // Should the mod even be here, I think I would rather the other operations
  // ensured they only returned things in bounds, and this considered an out
  // of bounds value to be a fatal error.
  /* Could make a class for letters. Wrong in here but right method. All these should
   *only take inbounds things and return inboudn things.
   */
    return ( x % 26 ) + 'A';
}

int Machine::convert_to_int( char x )
{
    return x - 'A';
}

int Machine::forward_rotor_pass( int mapping )
{
  // for this an all other for loops, try to declare the iterating variable
  // within the for statement, it's much safer and cleaner, and helps out the
  // optimizer
  /* Locality, it stays in scope til end of method.
  */
    std::vector<Rotor>::iterator it;
    for( it = m_rotors.begin(); it != m_rotors.end(); it++ )
    {
        mapping = (*it).map( mapping );
    }
    return mapping;
}

int Machine::inverse_rotor_pass( int mapping )
{
    std::vector<Rotor>::reverse_iterator rit;
    for( rit = m_rotors.rbegin(); rit != m_rotors.rend(); rit++ )
    {
        mapping = (*rit).reverse_map( mapping );
    }
    return mapping;
}

void Machine::turn_rotors()
{
    std::vector<Rotor>::iterator it;
    for( it = m_rotors.begin(); it != m_rotors.end(); it++ )
    {
        if( !(*it).turn() )
        {
            break;
        }
    }
}

void Machine::reset_rotors(){
    std::vector<Rotor>::iterator it;
    for( it = m_rotors.begin(); it != m_rotors.end(); it++ )
    {
        (*it).reset();
    }
}

char Machine::encrypt( char x )
{
  // This is broken, isupper does not perform the same test that you rely on in
  // convert_to_int, it understands non english upper case letters.
  // In general, don't separate tests from operations when they are fundamentaly
  // tied together, write a single operation and test it succeeds instead.
    if( isupper(x) )
    {
        /* Could have it return -1 if it isnt an upper. Negative return values is OK for C++. 
        */
        int mapping = convert_to_int( x );
        m_plugboard.map( mapping );
        forward_rotor_pass( mapping );
        m_reflector.map( mapping );
        inverse_rotor_pass( mapping );
        m_plugboard.map( mapping );
        turn_rotors();
	// just return the result of the function.
	// storing it in a variable for no purpose makes it look like you meant
	// to put some more code in there but forgot.
        return convert_to_char( mapping );
    }
    else if( isspace(x) )
    {
        return x;
    }
    else
    {
      // why is this an error anyway? I would think you would rather support
      // either pass through or stripping as options. Stripping is probably
      // safer given that this ought to be a secure function. That would make
      // it the same as space handling, which means you might as well not have
      // the space test either.
        string message = "error ";
        message += x;
        message.append(" is not a valid character!");
        throw CharacterException(message);
    }
}
