#include "Reflector.hpp"

void Reflector::map( int &x )
{
    x = ( x + 13 ) % 26;
}
