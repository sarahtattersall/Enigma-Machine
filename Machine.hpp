#ifndef MACHINE_HPP
#define MACHINE_HPP
#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "EnigmaMachine.hpp"
#include "CharacterException.hpp"
#include "Transformer.hpp"
#include "EnigmaLetter.hpp"

class Machine : public Transformer {
    public:
        static Transformer* load_machine();
        // Encrpyts a char.
        // If the char is A-Z  converts it to integer
        // representation then passes through the plugboard, rotors, reflector,
        // inverse rotors and finally back through the plugboard before
        // displaying it on screen.
        // If the char is white space it ignores it.
        // Anything else and it produces an error.
        bool encode( EnigmaLetter value );
    
    private:
        Machine();
        std::vector<Rotor> m_rotors;
        Plugboard m_plugboard;
        Reflector m_reflector;
        Ui::EnigmaMachine ui;

};

#endif
