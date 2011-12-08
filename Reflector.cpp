#include "Reflector.hpp"

// TODO: FIGURE OUT WHAT TO DO WITH ENCODE
bool Reflector::encode( EnigmaLetter letter )
{
    return m_receptor->encode(letter + EnigmaLetter('N'));
}
