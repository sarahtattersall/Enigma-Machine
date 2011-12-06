#include "EnigmaLetter.hpp"

EnigmaLetter::EnigmaLetter(char value){
    if( value >= 'A' && value < 'Z'){
        m_representation = value - 'A';
    }else{
        // Error?
        m_representation = 0;
    }
}

EnigmaLetter::EnigmaLetter(int value){
    if( value >= 0  && value < 26){
        m_representation = value;
    }
}

int EnigmaLetter::mod( int value, int mod_value )
{
    value %= mod_value;
    return value < 0 ? value + mod_value : value;
}

EnigmaLetter EnigmaLetter::operator+(const EnigmaLetter& letter){
    cout << "Plus" << mod(m_representation + letter.m_representation, 26) << endl;
    return EnigmaLetter(mod(m_representation + letter.m_representation, 26));
}

EnigmaLetter EnigmaLetter::operator-(const EnigmaLetter& letter){
    return EnigmaLetter(mod(m_representation - letter.m_representation, 26));
}

EnigmaLetter EnigmaLetter::operator=(const EnigmaLetter& letter){
    cout << "Equals " << letter.m_representation << endl;
    m_representation = letter.m_representation;
    return *this;
}

char EnigmaLetter::to_char(){
    return 'A' + m_representation;
}

int EnigmaLetter::to_int(){
    return m_representation;
}