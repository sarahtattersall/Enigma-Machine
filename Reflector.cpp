#include "Reflector.hpp"

/*
 * Maps an integer to another given integer represeting a character using
 * the provided formula.
 */
void Reflector::map( int &x )
{
    x = ( x + 13 ) % 26;
}
