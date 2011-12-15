#include "Machine.hpp"
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "CharacterException.hpp"
using namespace::std;


class MachineImpl : public Machine {
    public:
        static Transformer* load_machine(  char* plugboard_file, std::vector<std::string> rotor_files );
        // Encrpyts a char.
        // If the char is A-Z  converts it to integer
        // representation then passes through the plugboard, rotors, reflector,
        // inverse rotors and finally back through the plugboard before
        // displaying it on screen.
        // If the char is white space it ignores it.
        // Anything else and it produces an error.
        bool encode( EnigmaLetter value );
        bool bind( Receptor* receptor );
    
    private:
        Machine();
        ~Machine();
        std::vector<Rotor> m_rotors;
        Transformer* m_last;
        Transformer* m_start;
        // Plugboard m_plugboard;
        // Reflector m_reflector;
        Ui::EnigmaMachine ui;

};
//  Move this to builder.
Transformer* Machine::load_machine( char* plugboard_file, vector<string> rotor_files ){
    Machine* machine = new Machine();
    // Make all these pointers owned by machine.
    // Use scoped pointer (auto_pointer in memory library).
    // Destory vs. Delete
    // Object a;
    // Object* b = new Object();
    // 
    // b->~Object();
    // free(b);
    Transformer* forwards_plugboard = Plugboard::load_plugboard(plugboard_file);
    Transformer* backwards_plugboard = Plugboard::load_plugboard(plugboard_file);
    Rotor* next_rotor = NULL;
    vector<Rotor*> rotors;
    for( vector<string>::reverse_iterator rev_itr = rotor_files.rbegin(); rev_itr != rotor_files.rend(); ++rev_itr ){
        Rotor* rotor = Rotor::load_rotor((*rev_itr).c_str(), next_rotor);
        rotors.push_back(rotor);
        next_rotor = rotor;
    }
    // **********************************
    // AHHH WHERE DO I DELETE ALL THESE POINTERS?, IN OTHERS DESTRUCTORS? WHAT ABOUT NEXT_ROTOR?
    // Shared pointers from boost, if you don't have cycles...
    // 
    // **********************************
    Transformer* reflector = new Reflector();
    Transformer* last_backwards_rotor = rotors.back()->get_backward();
    Transformer* last_forwards_rotor = rotors.back()->get_forward();
    Transformer* first_backwards_rotor = rotors.front()->get_backward();
    Transformer* first_forwards_rotor = rotors.front()->get_forward();
    
    machine->m_last = last_backwards_rotor;
    machine->m_start = forwards_plugboard;
    
    first_backwards_rotor->bind(backwards_plugboard);
    reflector->bind(last_backwards_rotor);
    last_forwards_rotor->bind(reflector);
    forwards_plugboard->bind(first_forwards_rotor);
    return machine;
}

Machine::Machine(){
}

Machine::~Machine(){
    delete m_last;
    delete m_start;
}

bool Machine::bind(Receptor* receptor){
    return m_last->bind(receptor);
}

// TODO: Work out what to do with encode.
bool Machine::encode( EnigmaLetter value )
{
  // This is broken, isupper does not perform the same test that you rely on in
  // convert_to_int, it understands non english upper case letters.
  // In general, don't separate tests from operations when they are fundamentaly
  // tied together, write a single operation and test it succeeds instead.
    return m_start->encode(value);
}
