#ifndef NOTCH_HPP
#define NOTCH_HPP
#include <vector>

class Notch{
    public:
        bool is_empty();
        void add( int );
        // Checks to see if position x on the rotor is in m_positions.
        bool correct_position( int );

    private:
        std::vector<int> m_positions;
    
};

#endif
