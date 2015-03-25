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
#include <QString>
#include <QFile>

Dissasemble::Dissasemble( )
{
	//Generate Layout
        QHBoxLayout * mainLayout = new QHBoxLayout();
		dissasembly = new QTextEdit();
		mainLayout -> addWidget( dissasembly );
		setLayout( mainLayout );
}

void Dissasemble::analysis( char * fileString, size_t fileSize, QProgressBar * pb )
{
	//Make Temp File
	dissasembly->clear();
	QFile writeFile("/tmp/bindyn");
	writeFile.open( QIODevice::WriteOnly );
	writeFile.write( fileString, fileSize);
	writeFile.close( );
	
	//Run objdump on temp file
	objdumpProcess = new QProcess();
	objdumpProcess->start(QString("objdump -b binary -mi386 -D /tmp/bindyn"));
	objdumpProcess->waitForFinished();
	dissasembly->insertPlainText(objdumpProcess->readAllStandardOutput());
	dissasembly->insertPlainText(objdumpProcess->readAllStandardError());
	//Delete temp file
	QFile::remove("/tmp/bindyn");
	
}

void Dissasemble::clean()
{
	dissasembly -> clear();
}

