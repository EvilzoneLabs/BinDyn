/***************************************
 * dissasemble
 * Defines the Class declared in dissasemble.h
 * 
 * PreConditions: Program Started
 * Main Use: x86-64 dissasembler
 * 
 * PostCondtions: Dissasembly shown
 * 
 * Gotchas: Not mine :( Not enough hours in the day to write my own before summer
 *          Also it doesnt support any other architectures, this is purely for a
 *          quick look at interesting parts before exporting for use in a proper 
 *          dissasembler.
 **************************************/

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollBar>
#include "dissasemble.h"

Dissasemble::Dissasemble( )
{
	//Generate Layout
        QHBoxLayout * mainLayout = new QHBoxLayout();
		addresses = new QTextEdit();
		dissasembly = new QTextEdit();
		notes = new QTextEdit();
		mainLayout -> addWidget( addresses );
		mainLayout -> addWidget( dissasembly );
		mainLayout -> addWidget( notes );
		addresses -> setMaximumWidth(200);
		notes -> setMaximumWidth(300);
		setLayout( mainLayout );
	//Connect the Scrollbars
		QObject::connect(addresses -> verticalScrollBar(), SIGNAL(valueChanged(int)), dissasembly -> verticalScrollBar(), SLOT(setValue(int)));
		QObject::connect(addresses -> verticalScrollBar(), SIGNAL(valueChanged(int)), notes -> verticalScrollBar(), SLOT(setValue(int)));
		QObject::connect(dissasembly -> verticalScrollBar(), SIGNAL(valueChanged(int)), addresses -> verticalScrollBar(), SLOT(setValue(int)));
		QObject::connect(dissasembly -> verticalScrollBar(), SIGNAL(valueChanged(int)), notes -> verticalScrollBar(), SLOT(setValue(int)));
		QObject::connect(notes -> verticalScrollBar(), SIGNAL(valueChanged(int)), dissasembly -> verticalScrollBar(), SLOT(setValue(int)));
		QObject::connect(notes -> verticalScrollBar(), SIGNAL(valueChanged(int)), addresses -> verticalScrollBar(), SLOT(setValue(int)));
}

void Dissasemble::analysis( char * fileString, size_t fileSize, QProgressBar * pb )
{
}

void Dissasemble::clean()
{
	addresses -> clear();
	dissasembly -> clear();
	notes -> clear();
}
