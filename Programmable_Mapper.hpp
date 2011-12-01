#ifndef PROGRAMMABLE_MAPPER_HPP
#define PROGRAMMABLE_MAPPER_HPP
#include "Mapper.hpp"
#include <vector>

// I don't think this class adds anything useful to the class heirarchy.
// If you really want this stuff abstracted, it can be in a class used by the
// other concrete implementations, rather than descended from.
/*
 * This is only for code reuse - tut tut!
 * Better to have a read_file class? or a static method that returns a reflector.
 * Make private constuctor. Public factory method.
 */
class Programmable_Mapper : public Mapper {
    protected:
        Programmable_Mapper();
        std::vector<int> m_mappings;
        virtual void read_file( const char* ) = 0;
};

#endif
