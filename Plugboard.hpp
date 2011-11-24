#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP
#include "Programmable_Mapper.hpp"

class Plugboard : public Programmable_Mapper{
    public:
        Plugboard();
        void read_file( const char* );
        void map( int& );
};

#endif

