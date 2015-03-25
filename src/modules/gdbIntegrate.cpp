#include "gdbIntegrate.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

GDBrun::GDBrun( )
{
	//Generate Objects
	QPushButton * comm1 = new QPushButton("Print Registers");
	QPushButton * comm2 = new QPushButton("Back Trace");
	QPushButton * comm3 = new QPushButton("Print Stack Frames");
	QPushButton * comm4 = new QPushButton("Help");
	QPushButton * comm5 = new QPushButton("Start");
	commandButton = new QPushButton("Send");
	command = new QLineEdit();
	gdbOutput = new QTextEdit();
	
	//COnfigure
	commandButton -> setMaximumWidth(200);
	
	//Layout
	QVBoxLayout * mainlayout = new QVBoxLayout;
	QHBoxLayout * buttons = new QHBoxLayout();
	QHBoxLayout * commands = new QHBoxLayout();
	buttons -> addWidget(comm1);
	buttons -> addWidget(comm2);
	buttons -> addWidget(comm3);
	buttons -> addWidget(comm4);
	buttons -> addWidget(comm5);
	commands -> addWidget(command);
	commands -> addWidget(commandButton);
	mainlayout -> addLayout(buttons);
	mainlayout -> addWidget(gdbOutput);
	mainlayout -> addLayout(commands);
	setLayout(mainlayout);
	
	gdbProcess = new QProcess;
	connect (gdbProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(processOutput())); 
	QObject::connect( commandButton, SIGNAL( clicked() ),this, SLOT( sendCommand() ) ); 
	
}

void GDBrun::analysis( char * fileString, size_t fileSize, QProgressBar * pb )
{
	gdbProcess->start(QString("gdb"), QIODevice::ReadWrite);
	
}

void GDBrun::clean()
{
	//delete gdbProcess;
	//gdbProcess = NULL;
}

void GDBrun::processOutput()
{
	gdbOutput->insertPlainText(gdbProcess->readAllStandardOutput());
	gdbOutput->insertPlainText(gdbProcess->readAllStandardError()); 
}

void GDBrun::sendCommand()
{
	gdbOutput->insertPlainText(command->text().toLocal8Bit() + '\n');
	gdbProcess->write((command->text()  + '\n' ).toLocal8Bit());
	gdbProcess -> waitForReadyRead();
	command -> clear();
	processOutput();
}
