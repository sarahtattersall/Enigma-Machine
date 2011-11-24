#ifndef NOTCH_HPP
#define NOTCH_HPP
#include <vector>

class Notch{
    private:
        std::vector<int> m_positions;
    public:
        bool correct_position( int );
        bool is_empty();
        void add( int );
        
};

#endif
