#include "Notch.hpp"
#include <algorithm>

using namespace::std;
void Notch::add( int x )
{
    m_positions.push_back(x);
}

bool Notch::correct_position( int x )
{
    return find(m_positions.begin(), m_positions.end(), x) != m_positions.end();
}

bool Notch::is_empty()
{
    return m_positions.empty();
}
