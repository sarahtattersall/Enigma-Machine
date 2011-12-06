#include "Notch.hpp"
#include <algorithm>

using namespace::std;
void Notch::add( EnigmaLetter letter )
{
    m_positions.push_back(letter);
}

bool Notch::correct_position( int position )
{
    return find(m_positions.begin(), m_positions.end(), position) != m_positions.end();
}

bool Notch::is_empty()
{
    return m_positions.empty();
}
