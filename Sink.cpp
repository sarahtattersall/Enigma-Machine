#include "Sink.hpp"

bool Sink::encode(EnigmaLetter value){
  m_result = value;
  return true;
}

EnigmaLetter Sink::value(){
    return m_result;
}