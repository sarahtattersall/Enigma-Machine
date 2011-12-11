#include <QtGui/QApplication>
#include "MachineGUI.hpp"
#include "EnigmaLetter.hpp"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Transformer *machine = new Machine;
    MachineGUI *enigma = new MachineGUI(machine);
    enigma->show();
    return app.exec();
}
