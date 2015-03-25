/***************************************
 * hexEdit.cpp
 * Defines the Class declared in hexEdit.h
 * 
 * PreConditions: Program Started, User/File loaded
 * Main Use: Print entire file in sync in both ascii
 *           and hex.
 * PostCondtions: Done printing.
 * 
 * Gotchas: Loads entire thing to memory and builds
 *          in memory, takes a while, can bork on
 *          large files.
 **************************************/

#include "hexEdit.h"
#include <QLabel>
#include <QObject>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollBar>
#include <QString>

HexEditor::HexEditor()
{
	//Make the Layout
		hex = new QTextEdit();
		ascii = new QTextEdit();
		QLabel * warning = new QLabel( "Caution, this Hex Editor currently loads it all at once, you break it, don't bitch. " );
		QVBoxLayout * mainLayout = new QVBoxLayout();
		mainLayout -> addWidget( warning );
		QHBoxLayout * bottom = new QHBoxLayout();
		bottom -> addWidget( ascii );
		bottom -> addWidget( hex );
		mainLayout -> addLayout( bottom );
		setLayout( mainLayout );
	//Connect the Scrollbars
		QObject::connect(hex -> verticalScrollBar(), SIGNAL(valueChanged(int)), ascii -> verticalScrollBar(), SLOT(setValue(int)));
		QObject::connect(ascii -> verticalScrollBar(), SIGNAL(valueChanged(int)), hex -> verticalScrollBar(), SLOT(setValue(int)));
}

void HexEditor::clean()
{
	hex->clear();
	ascii->clear();
}

void HexEditor::analysis(char * fileString, size_t fileSize, QProgressBar * pb)
{
	hex->clear();
	ascii->clear();
	//Look at this alpha stage hack of a hex editor xD
	QString asciiText;
	QString hexText;
	size_t pbChunk = fileSize / 100; //Progress bar thing
	if (!pbChunk) pbChunk = 1;
	const int lineLength = 35;
	QChar controlChar = ' ';
	unsigned int temp = 0;	
	//Here be the ugliness
	for (size_t counter = 0; counter < fileSize; counter++)
	{
		if (!(counter % pbChunk)) pb->setValue(pb->value() + 1);
		temp = static_cast <unsigned char>(fileString[counter]);
		if (!(counter % lineLength) && counter != 0) controlChar = '\n';
		if (temp < 16)
			hexText.append(QChar('0') + QString::number(temp,16).toUpper() + controlChar);
		else
			hexText.append(QString::number(temp,16).toUpper() + controlChar);
		if (temp > 32 && temp < 127)
			asciiText.append(fileString[counter] + QChar(' ') + controlChar);
		else
			asciiText.append(QString(".. ") + controlChar);
		controlChar = ' ';	
	}
	hex->insertPlainText(hexText);
	ascii->insertPlainText(asciiText);
	pb->setValue(100);
}
