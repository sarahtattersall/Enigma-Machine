#ifndef CHARACTER_EXCEPTION_HPP
#define CHARACTER_EXCEPTION_HPP
#include <exception>


class CharacterException: public std::exception
{
private:
    std::string msg;

public:
    CharacterException(std::string m ):msg(m){};
    ~CharacterException() throw(){};

    const char* what() const throw() { return msg.c_str(); };
};
#endif
