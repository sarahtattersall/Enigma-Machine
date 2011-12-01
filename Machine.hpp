#ifndef MACHINE_HPP
#define MACHINE_HPP
#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "EnigmaMachine.hpp"
#include "CharacterException.hpp"

class Machine : public QMainWindow{
        Q_OBJECT
    
    private:
        std::vector<Rotor> m_rotors;
        Plugboard m_plugboard;
        Reflector m_reflector;
        Ui::EnigmaMachine ui;
        char convert_to_char( int );
        int convert_to_int( char );
        void forward_rotor_pass( int& );
        void inverse_rotor_pass( int& );
        void turn_rotors();
        void reset_rotors();
    public:
        Machine(QWidget *parent = 0);
        char encrypt( char );
    
    public slots:
        void load_rotor_files();
        void load_plug_file();
        void encrypt_text();
};

#endif
