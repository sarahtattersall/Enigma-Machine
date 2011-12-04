#include "Sink.hpp"

bool Sink::push(int value){
  m_result = value;
  return true;
}

int Sink::value(){
    return m_result;
}