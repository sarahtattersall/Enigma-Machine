#include <QtGui/QApplication>
#include "Machine.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Machine *enigma = new Machine;
    enigma->show();
    return app.exec();
}
