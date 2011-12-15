#ifndef MACHINE_HPP
#define MACHINE_HPP
#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "EnigmaMachine.hpp"
#include "CharacterException.hpp"
#include "Transformer.hpp"
#include "EnigmaLetter.hpp"
#include <vector>

using std::vector;

class Machine : public Transformer {
};

class TransformerBuilder {
public:
    virtual Transformer* create() = 0;
};
class PlugboardBuilder {
    PlugboardBuilder(const string& filename) { setFile(filename); }
};

class MachineBuilder : public TransformerBuilder {
public:
    MachineBuilder& setPlugboard(const PlugboardBuilder& builder);
    MachineBuilder& addRotor(const Rotor& builder)
    {
        // do something here... blah;
        return *this;
    }
    // if haven't set rotors and plugboard crete should refuse.
    Machine* create();
private:
    PlugboardBuilder m_plugbloard;
    vector<RotorBuilder> m_rotors;
};

// MachineBuilder myBuilder;
// myBuilder.setPlugboard("somefilename");

createMyThing("somestring");

MyThingBuilder("somestring")
    .setStyle("cheesy")
    .create();

// blah
//     auto_ptr<Transformer> myTransformer = myBuilder();
#endif
