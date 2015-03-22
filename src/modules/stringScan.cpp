/***************************************
 * stringScan.cpp
 * Defines the Class declared in stringScan.h
 * 
 * PreConditions: Program Started, file/user input passed in
 * Main Use: To scan fileString for strings over 3 chars in length and
 * 			 output them to the QTextEdit
 * PostCondtions: Done Scanning
 * 
 * Gotchas: last few lines are wonky, done that way to save some cpu cycles
 **************************************/

#include "stringScan.h"
#include <QVBoxLayout>
#include <QLayout>
#include <QString>

StringScan::StringScan()
{
    textOutput = new QTextEdit();
    QVBoxLayout * layout = new QVBoxLayout();
    layout -> addWidget( textOutput );
    setLayout( layout );
}

void StringScan::clean()
{
	textOutput->clear();
}

void StringScan::analysis( char * fileString, size_t fileSize, bool locality, QProgressBar * pb )
{
	QString tempString;
	size_t pbChunk = fileSize / 100; //Progress bar thing
	for (size_t counter = 0; counter < fileSize; counter++)
	{
		if (!(counter % pbChunk)) pb->setValue(pb->value() + 1); //Progress Bar
		if (fileString[counter] > 31 && fileString[counter] < 128)
		{	
			tempString.append(fileString[counter]);
		}	
		else if (fileString[counter] == '\n' && tempString.size() > 3)
		{
			textOutput -> append( tempString );
			tempString.clear();
		}
		else tempString.clear();
	}
}
