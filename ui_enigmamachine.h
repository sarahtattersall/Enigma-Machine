/********************************************************************************
** Form generated from reading UI file 'enigmamachine.ui'
**
** Created: Sat Dec 10 22:31:08 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENIGMAMACHINE_H
#define UI_ENIGMAMACHINE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnigmaMachine
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *inputLabel;
    QPlainTextEdit *inputText;
    QLabel *outputLabel;
    QPlainTextEdit *outputText;
    QHBoxLayout *buttonLayout;
    QPushButton *rotorsButton;
    QPushButton *plugboardButton;
    QPushButton *encodeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EnigmaMachine)
    {
        if (EnigmaMachine->objectName().isEmpty())
            EnigmaMachine->setObjectName(QString::fromUtf8("EnigmaMachine"));
        EnigmaMachine->resize(800, 600);
        centralwidget = new QWidget(EnigmaMachine);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 791, 541));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        inputLabel = new QLabel(verticalLayoutWidget);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));

        verticalLayout->addWidget(inputLabel);

        inputText = new QPlainTextEdit(verticalLayoutWidget);
        inputText->setObjectName(QString::fromUtf8("inputText"));

        verticalLayout->addWidget(inputText);

        outputLabel = new QLabel(verticalLayoutWidget);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));

        verticalLayout->addWidget(outputLabel);

        outputText = new QPlainTextEdit(verticalLayoutWidget);
        outputText->setObjectName(QString::fromUtf8("outputText"));
        outputText->setReadOnly(true);

        verticalLayout->addWidget(outputText);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        rotorsButton = new QPushButton(verticalLayoutWidget);
        rotorsButton->setObjectName(QString::fromUtf8("rotorsButton"));

        buttonLayout->addWidget(rotorsButton);

        plugboardButton = new QPushButton(verticalLayoutWidget);
        plugboardButton->setObjectName(QString::fromUtf8("plugboardButton"));

        buttonLayout->addWidget(plugboardButton);

        encodeButton = new QPushButton(verticalLayoutWidget);
        encodeButton->setObjectName(QString::fromUtf8("encodeButton"));

        buttonLayout->addWidget(encodeButton);


        verticalLayout->addLayout(buttonLayout);

        EnigmaMachine->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EnigmaMachine);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        EnigmaMachine->setMenuBar(menubar);
        statusbar = new QStatusBar(EnigmaMachine);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EnigmaMachine->setStatusBar(statusbar);

        retranslateUi(EnigmaMachine);

        QMetaObject::connectSlotsByName(EnigmaMachine);
    } // setupUi

    void retranslateUi(QMainWindow *EnigmaMachine)
    {
        EnigmaMachine->setWindowTitle(QApplication::translate("EnigmaMachine", "MainWindow", 0, QApplication::UnicodeUTF8));
        inputLabel->setText(QApplication::translate("EnigmaMachine", "INPUT:", 0, QApplication::UnicodeUTF8));
        outputLabel->setText(QApplication::translate("EnigmaMachine", "OUTPUT:", 0, QApplication::UnicodeUTF8));
        rotorsButton->setText(QApplication::translate("EnigmaMachine", "Load Rotors", 0, QApplication::UnicodeUTF8));
        plugboardButton->setText(QApplication::translate("EnigmaMachine", "Load Plugboard", 0, QApplication::UnicodeUTF8));
        encodeButton->setText(QApplication::translate("EnigmaMachine", "Encode/Decode!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EnigmaMachine: public Ui_EnigmaMachine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENIGMAMACHINE_H
