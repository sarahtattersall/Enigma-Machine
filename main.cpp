#include <QtGui/QApplication>
#include "MachineGUI.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Machine *machine = new Machine;
    MachineGUI *enigma = new MachineGUI(machine);
    enigma->show();
    return app.exec();
}
