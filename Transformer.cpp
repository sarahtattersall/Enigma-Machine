#include "Transformer.hpp"
#include "Receptor.hpp"

bool Transformer::bind( Receptor* receptor ){
    m_receptor = receptor;
    return true;
};