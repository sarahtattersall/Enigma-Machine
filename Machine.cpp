#include "Machine.hpp"
#include <QtGui/QtGui>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <algorithm>
#include "CharacterException.hpp"
using namespace::std;

Machine::Machine( QWidget *parent ): QMainWindow(parent)
{
    ui.setupUi( this );
    connect(  ui.rotorsButton, SIGNAL( clicked()), this, SLOT( load_rotor_files() ) );
    connect( ui.plugboardButton, SIGNAL( clicked()), this, SLOT( load_plug_file() ) );
    connect( ui.encodeButton, SIGNAL( clicked()), this, SLOT( encrypt_text() ) );
}

void Machine::load_rotor_files()
{
    QStringList files = QFileDialog::getOpenFileNames(
        this,
        "Select files to open",
        QString::null,
        "Rotor files (*.rot)");

        int i;
        for (i = 0; i < files.size(); i++){
            m_rotors.push_back( Rotor (files.at(i).toAscii().constData()) );
        }
}


void Machine::load_plug_file()
{
    QString file = QFileDialog::getOpenFileName(
        this,
        "Choose a file to open",
        QString::null,
        "Plugboard files (*.pb)");
    m_plugboard.read_file( file.toAscii().constData() );
}



/*
 * Converts an integer, x, to it's character representation.
 */
char Machine::convert_to_char( int x )
{
  // The operation does not match the comment, the mod is much more.
  // Should the mod even be here, I think I would rather the other operations
  // ensured they only returned things in bounds, and this considered an out
  // of bounds value to be a fatal error.
    return ( x % 26 ) + 'A';
}

/*
 * Converts a char, x, to it's integer representation.
 */
int Machine::convert_to_int( char x )
{
    return x - 'A';
}

void Machine::forward_rotor_pass( int& mapping )
{
  // for this an all other for loops, try to declare the iterating variable
  // within the for statement, it's much safer and cleaner, and helps out the
  // optimizer
    std::vector<Rotor>::iterator it;
    for( it = m_rotors.begin(); it != m_rotors.end(); it++ )
    {
        (*it).map( mapping );
    }
}

void Machine::inverse_rotor_pass( int& mapping )
{
    std::vector<Rotor>::reverse_iterator rit;
    for( rit = m_rotors.rbegin(); rit != m_rotors.rend(); rit++ )
    {
        (*rit).reverse_map( mapping );
    }
}

void Machine::turn_rotors()
{
    std::vector<Rotor>::iterator it;
    for( it = m_rotors.begin(); it != m_rotors.end(); it++ )
    {
        if( !(*it).turn() )
        {
            break;
        }
    }
}

/*
 * Encrypts one character at a time from the input text box
 */
void Machine::encrypt_text()
{
    QString input = ui.inputText->toPlainText();
    QString::iterator itr;
    ui.outputText->clear();
    reset_rotors();
    QString output;
    try
    {
        for( itr = input.begin(); itr != input.end(); itr++ )
        {
            output.append(encrypt((*itr).toAscii()));
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


void Machine::reset_rotors(){
    std::vector<Rotor>::iterator it;
    for( it = m_rotors.begin(); it != m_rotors.end(); it++ )
    {
        (*it).reset();
    }
}

/*
 * Encrpyts a char.
 * If the char is A-Z  converts it to integer
 * representation then passes through the plugboard, rotors, reflector,
 * inverse rotors and finally back through the plugboard before
 * displaying it on screen.
 * If the char is white space it ignores it.
 * Anything else and it produces an error.
 */
char Machine::encrypt( char x )
{
  // This is broken, isupper does not perform the same test that you rely on in
  // convert_to_int, it understands non english upper case letters.
  // In general, don't separate tests from operations when they are fundamentaly
  // tied together, write a single operation and test it succeeds instead.
    if( isupper(x) )
    {
        int mapping = convert_to_int( x );
        m_plugboard.map( mapping );
        forward_rotor_pass( mapping );
        m_reflector.map( mapping );
        inverse_rotor_pass( mapping );
        m_plugboard.map( mapping );
        turn_rotors();
	// just return the result of the function.
	// storing it in a variable for no purpose makes it look like you meant
	// to put some more code in there but forgot.
        char letter = convert_to_char( mapping );
        return letter;
    }
    else if( isspace(x) )
    {
        return x;
    }
    else
    {
      // why is this an error anyway? I would think you would rather support
      // either pass through or stripping as options. Stripping is probably
      // safer given that this ought to be a secure function. That would make
      // it the same as space handling, which means you might as well not have
      // the space test either.
        string message = "error ";
        message += x;
        message.append(" is not a valid character!");
        throw CharacterException(message);
    }
}
