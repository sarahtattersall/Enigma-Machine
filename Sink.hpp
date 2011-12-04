#ifndef "SINK_HPP"
#define "SINK_HPP"
#include "Receptor.hpp"

class Sink : public Receptor {
    int m_result;
    bool push(int value);
    int value();
};

#endif