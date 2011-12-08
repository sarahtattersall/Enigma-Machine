#ifndef TRANSFORMER_HPP
#define TRANSFORMER_HPP
#include "Receptor.hpp"
#include "Source.hpp"

class Transformer : public Receptor, public Source {
    public:
        bool bind( Receptor* receptor );
        
    protected:
        // Consumer
        Receptor* m_receptor;
};

#endif