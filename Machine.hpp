#ifndef MACHINE_HPP
#define MACHINE_HPP
#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "EnigmaMachine.hpp"
#include "CharacterException.hpp"

class Machine : public QMainWindow{
        Q_OBJECT
    
    public:
        Machine(QWidget *parent = 0);
        
        // Encrpyts a char.
        // If the char is A-Z  converts it to integer
        // representation then passes through the plugboard, rotors, reflector,
        // inverse rotors and finally back through the plugboard before
        // displaying it on screen.
        // If the char is white space it ignores it.
        // Anything else and it produces an error.
        char encrypt( char x );

    public slots:
        void load_rotor_files();
        void load_plug_file();
        
        // Encrypts one character at a time from the input text box
        void encrypt_text();
    
    private:
        std::vector<Rotor> m_rotors;
        Plugboard m_plugboard;
        Reflector m_reflector;
        Ui::EnigmaMachine ui;
        // Converts an integer, x, to it's character representation.
        char convert_to_char( int x );
        
        // Converts a char, x, to it's integer representation.
        int convert_to_int( char x );
        int forward_rotor_pass( int mapping );
        int inverse_rotor_pass( int mapping );
        void turn_rotors();
        void reset_rotors();

};

#endif
