/***************************************
 * conversions.cpp
 * Defines the Class declared in conversions.h
 * 
 * PreConditions: Program Started
 * Main Use: Simple COnversions and otehr tools
 *           useful in RE. Single byte Xor, rot 13
 *           number conversions. Etc.
 * 
 * PostCondtions: Conversons Shown
 * 
 * Gotchas: Not implemented yet
 **************************************/

#include "conversions.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

Conversions::Conversions( )
{
	//Create the Objects
	QLabel * dataInLabel = new QLabel("Data In");
	QLabel * conversionLabel = new QLabel("Conversion Type");
	QLabel * dataOutLabel = new QLabel("Data Out");
	dataIn = new QTextEdit();
	dataOut = new QTextEdit();
	
	conversionsOne = new QPushButton("Conversion One");
	conversionsTwo = new QPushButton("Conversion Two");
	conversionsThree = new QPushButton("Conversion Three");
	conversionsFour = new QPushButton("Conversion Four");
	conversionsFive = new QPushButton("Conversion Five");
	conversionsSix = new QPushButton("Conversion Six");
	
	//Connect Buttons to functions
	//Also too lazy to do this, just making the layout for now
	
	//Layout
	QVBoxLayout * mainLayout = new QVBoxLayout();
	
	QHBoxLayout * conversions = new QHBoxLayout();
	
	conversions -> addWidget(conversionsOne);
	conversions -> addWidget(conversionsTwo);
	conversions -> addWidget(conversionsThree);
	conversions -> addWidget(conversionsFour);
	conversions -> addWidget(conversionsFive);
	conversions -> addWidget(conversionsSix);
	
	mainLayout -> addWidget(dataInLabel);
	mainLayout -> addWidget(dataIn);
	mainLayout -> addWidget(conversionLabel);
	mainLayout -> addLayout(conversions);
	mainLayout -> addWidget(dataOutLabel);
	mainLayout -> addWidget(dataOut);
	
	setLayout(mainLayout);
}

void Conversions::analysis( char * fileString, size_t fileSize, QProgressBar * pb )
{
	//This is required so we don't throw an error but really this module exists seperate from the rest of the program :p
	return;
}

void Conversions::clean()
{
	dataIn -> clear();
	dataOut -> clear();
}
