#ifndef PROGRAMMABLE_MAPPER_HPP
#define PROGRAMMABLE_MAPPER_HPP
#include "Mapper.hpp"
#include <vector>


class Programmable_Mapper : public Mapper {
    protected:
        Programmable_Mapper();
        std::vector<int> m_mappings;
        virtual void read_file( const char* ) = 0;
};

#endif
