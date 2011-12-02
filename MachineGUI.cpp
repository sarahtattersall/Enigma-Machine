#include "MachineGUI.hpp"
#include <QtGui/QtGui>

MachineGUI::MachineGUI( Machine *machine, QWidget *parent ): QMainWindow(parent)
{
    m_machine = machine;
    ui.setupUi( this );
    connect(  ui.rotorsButton, SIGNAL( clicked()), this, SLOT( load_rotor_files() ) );
    connect( ui.plugboardButton, SIGNAL( clicked()), this, SLOT( load_plug_file() ) );
    connect( ui.encodeButton, SIGNAL( clicked()), this, SLOT( encrypt_text() ) );
}

void MachineGUI::load_rotor_files()
{
    QStringList files = QFileDialog::getOpenFileNames(
        this,
        "Select files to open",
        QString::null,
        "Rotor files (*.rot)");

        int i;
        for (i = 0; i < files.size(); i++){
            m_machine->load_rotor_file(files.at(i).toAscii().constData());
        }
}

void MachineGUI::load_plug_file()
{
    QString file = QFileDialog::getOpenFileName(
        this,
        "Choose a file to open",
        QString::null,
        "Plugboard files (*.pb)");
    m_machine->load_plug_file( file.toAscii().constData() );
}

void MachineGUI::encrypt_text()
{
    QString input = ui.inputText->toPlainText();
    ui.outputText->clear();
    m_machine->reset_rotors();
    QString output;
    try
    {
        for( QString::iterator itr = input.begin(); itr != input.end(); itr++ )
        {
            output.append(m_machine->encrypt((*itr).toAscii()));
        }
        ui.outputText->setPlainText(output);
    }
    catch( const CharacterException& e )
    {
        QErrorMessage error;
        error.showMessage(e.what());
        error.exec();
    }
}