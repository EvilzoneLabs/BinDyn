#include "headers.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

Headers::Headers( )
{
	//Create Objects
	headerFields = new QTextEdit();
	headerData = new QTextEdit();
	headerFields->setMaximumWidth(400);
	headerTypeOne = new QCheckBox("Header Type One");
	headerTypeTwo = new QCheckBox("Header Type Two");
	headerTypeThree = new QCheckBox("Header Type Three");
	QLabel * buttonLabel = new QLabel("Select a Header Type: ");
	QLabel * fieldLabel = new QLabel("Header Fields ");
	fieldLabel -> setMaximumWidth(400);
	QLabel * dataLabel = new QLabel("Header Data");
	
	//Connect them in such a way that only one may be checked.
	//Need to find appropriate signal, too lazy right now, is 3 am, was planning to sleep, sleep didnt happen
	
	//Also center the QtextEdits labels
	//Do Layout
	QHBoxLayout * headerType = new QHBoxLayout();
	QHBoxLayout * labels = new QHBoxLayout();
	QHBoxLayout * output = new QHBoxLayout();
	QVBoxLayout * mainLayout = new QVBoxLayout();
	
	headerType-> addWidget(buttonLabel);
	headerType-> addWidget(headerTypeOne);
	headerType-> addWidget(headerTypeTwo);
	headerType-> addWidget(headerTypeThree);
	
	labels -> addWidget( fieldLabel);
	labels -> addWidget( dataLabel);
	
	output -> addWidget( headerFields );
	output -> addWidget( headerData );
	
	mainLayout -> addLayout( headerType );
	mainLayout -> addLayout( labels );
	mainLayout -> addLayout( output );
	
	setLayout(mainLayout);
}

void Headers::analysis( char * fileString, size_t fileSize, QProgressBar * pb )
{
	//Since thanks to connections above we can assume only one if any is checked
	if (headerTypeOne->isChecked())
		analyzeHeaderOne(fileString, fileSize,pb);
	else if (headerTypeTwo->isChecked())
		analyzeHeaderTwo(fileString, fileSize,pb);
	else if (headerTypeThree->isChecked())
		analyzeHeaderThree(fileString, fileSize,pb);
	return;
}

void Headers::clean()
{
	headerFields -> clear();
	headerData -> clear();
}

void Headers::analyzeHeaderOne( char * fileString, size_t fileSize, QProgressBar * pb )
{
}

void Headers::analyzeHeaderTwo( char * fileString, size_t fileSize, QProgressBar * pb )
{
}

void Headers::analyzeHeaderThree( char * fileString, size_t fileSize, QProgressBar * pb )
{
}
