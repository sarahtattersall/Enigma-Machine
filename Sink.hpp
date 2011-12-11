#ifndef SINK_HPP
#define SINK_HPP
#include "Receptor.hpp"
#include "EnigmaLetter.hpp"

class Sink : public Receptor {
    public:
        bool encode(EnigmaLetter value);
        EnigmaLetter value();
    
    private:
        EnigmaLetter m_result;
};

#endif