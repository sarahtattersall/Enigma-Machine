#include <QtGui/QApplication>
#include "MachineGUI.hpp"
#include "EnigmaLetter.hpp"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    EnigmaLetter letter('a');
    cout << letter.to_char(); << endl;
    // QApplication app(argc, argv);
    // Machine *machine = new Machine;
    // MachineGUI *enigma = new MachineGUI(machine);
    // enigma->show();
    // return app.exec();
}
