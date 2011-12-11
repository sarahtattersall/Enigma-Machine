#include "EnigmaLetter.hpp"
const int EnigmaLetter::m_error_value = -1;

EnigmaLetter::EnigmaLetter(char value){
    if( value >= 'A' && value < 'Z'){
        m_representation = value - 'A';
    }else{
        // Error representation. Modify all the maths...
        m_representation = m_error_value;
    }
}

// Had to do this in order to be able to create empty result
EnigmaLetter::EnigmaLetter(){
    m_representation = m_error_value;
}

int EnigmaLetter::mod( int value, int mod_value ) const{
    value %= mod_value;
    return value < 0 ? value + mod_value : value;
}

EnigmaLetter EnigmaLetter::operator+(const EnigmaLetter& letter) const{
    EnigmaLetter result;
    if (m_representation != m_error_value){
        result.m_representation = mod(m_representation + letter.m_representation, 26);
    }
    // (m_representation == m_error_value) ? value = m_error_value : value = mod(m_representation + letter.m_representation, 26);
    // result.m_representation = value;
    return result;
}

EnigmaLetter EnigmaLetter::operator-(const EnigmaLetter& letter) const{
    EnigmaLetter result;
    if (m_representation != m_error_value){
        result.m_representation = mod(m_representation - letter.m_representation, 26);
    }
    return result;
}

EnigmaLetter EnigmaLetter::operator=(const EnigmaLetter& letter){
    if (m_representation != m_error_value){
        m_representation = letter.m_representation;
    }
    return *this;
}

void EnigmaLetter::operator++(int value){
    if (m_representation != m_error_value){
        m_representation = mod(m_representation + value, 26);
    }
}

char EnigmaLetter::to_char() const{
    return 'A' + m_representation;
}

int EnigmaLetter::to_int() const{
    return m_representation;
}