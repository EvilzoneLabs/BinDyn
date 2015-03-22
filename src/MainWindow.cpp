/***************************************
 * MainWindow.cpp
 * Defines the Class declared in MainWindow.h
 * 
 * PreConditions: Program Started
 * Main Use: To Setup the Layout and act upon user input.
 * PostCondtions: Program Over.
 * 
 * Gotchas: analysisChoice() uses a metaobject to call the
 * child method of any given tab, this will scare you in six months.
 * 
 * there is also a metaobject call for cleaning memory.
 **************************************/

#include "MainWindow.h"
#include "modules/bytePlot.h"
#include "modules/conversions.h"
#include "modules/digraph.h"
#include "modules/entropyMap.h"
#include "modules/hexEdit.h"
#include "modules/printableMap.h"
#include "modules/selfSim.h"
#include "modules/signatureScan.h"
#include "modules/statistics.h"
#include "modules/stringScan.h"

MainWindow::MainWindow( )
{
	setWindowTitle( QString::fromUtf8( "BinDyn - A Dynamic Visual Binary Analysis Engine" ) );
	//Center one monitor in a horizontal array and FullScreen the app
		QDesktopWidget * desktop = QApplication::desktop( );
		int screenWidth = desktop->width( ) / desktop->screenCount( ) ;
		int screenHeight = desktop->height( ); 
		resize( screenWidth, screenHeight - 24 );
		move( screenWidth / 2 , screenHeight / 2 );
	//Allocate the layout(s)
		QVBoxLayout *mainLayout = new QVBoxLayout( );
		QHBoxLayout *barLayout = new QHBoxLayout( );
		QHBoxLayout *topLeft = new QHBoxLayout( );
		QHBoxLayout *topRight =  new QHBoxLayout( );
		QHBoxLayout *bottomLeft = new QHBoxLayout( );
		QHBoxLayout *bottomRight = new QHBoxLayout( );
		QVBoxLayout *left = new QVBoxLayout( );
		QVBoxLayout *right = new QVBoxLayout( );
	//Allocate the Button Bars
		fileName = new QLabel( );
		QLabel *fileNameLabel = new QLabel( );
		QLabel *startSldLabel = new QLabel( );
		QLabel *endSldLabel = new QLabel( );
		QPushButton *fileBtn = new QPushButton( "Open File", this );
		QPushButton *analysisBtn = new QPushButton( "Run Analysis", this );
		QPushButton *saveBtn = new QPushButton( "Save File", this );
		localityBtn = new QCheckBox( "Preserve Locality?", this );
		startSld = new QSlider( Qt::Horizontal, this );
		endSld = new QSlider( Qt::Horizontal, this );
	//Config the Button Bars
		fileNameLabel->setText( "FileName:" );
		startSldLabel->setText( "Start Point" );
		endSldLabel->setText( "End Point" );
		startSld->setRange( 0,100 );
		startSld->setValue( 0 );  
		endSld->setRange( 0,100 );
		endSld->setValue( 100 );
	//Connect the buttons to slots
		QObject::connect( analysisBtn, SIGNAL( clicked( ) ),this, SLOT(analysisChoice( ) ) ); 
		QObject::connect( saveBtn, SIGNAL( clicked( ) ),this, SLOT(saveFile( ) ) ); 
		QObject::connect( fileBtn, SIGNAL( clicked( ) ),this, SLOT(fileDialog( ) ) ); 
	//Create the ButtonBar and Add it to the main Windows layout
		topLeft->addWidget( fileBtn );
		topLeft->addWidget( fileNameLabel );
		topLeft->addWidget( fileName );
		topRight->addWidget( startSldLabel );
		topRight->addWidget( startSld );
		left->addLayout( topLeft );
		right->addLayout( topRight );   
		bottomLeft->addWidget(  saveBtn  );
		bottomLeft->addWidget( analysisBtn );
		bottomLeft->addWidget( localityBtn );
		bottomRight->addWidget( endSldLabel );
		bottomRight->addWidget( endSld );  
		left->addLayout( bottomLeft );
		right->addLayout( bottomRight );
		barLayout->addLayout( left );
		barLayout->addLayout( right );    
		mainLayout->addLayout( barLayout );
	//Generate the tab bar and tabs
		tab_widget = new QTabWidget( this ); 
		tab_widget->addTab( new SignatureScan( ), "Signature Scan" );
		tab_widget->addTab( new StringScan( ), "String Dump" );
		tab_widget->addTab( new HexEditor( ), "Hex Editor" );
		tab_widget->addTab( new Digraph( ), "Digraph" );
		tab_widget->addTab( new Statistics( ), "Statistics" );
		tab_widget->addTab( new BytePlot( ), "Byte Plot" );
		tab_widget->addTab( new PrintableMap( ), "Printable Map" );
		tab_widget->addTab( new EntropyMap( ), "Entropy Map" );
		tab_widget->addTab( new SelfSim( ), "Self Similarity Plot" );
		tab_widget->addTab( new Conversions( ), "Conversion Aide" );
		mainLayout->addWidget( tab_widget );
	//Generate the progress bar and set the layout
		pb = new QProgressBar(  );
		mainLayout->addWidget( pb );
		setLayout( mainLayout );
}

	
//These two are pretty self explanatory yeah?
void MainWindow::fileDialog( )
{
	QString fname = QFileDialog::getOpenFileName( this, "Open file", "/home" );
    fileName->setText( fname );
	QFile readFile( fname );
	readFile.open( QIODevice::ReadOnly );
	fileSize = readFile.size( );
	if (fileString) delete [] fileString; //Because Memory Leaks are naughty.
	fileString = new char [fileSize];
	readFile.read( fileString,fileSize );
	readFile.close( );
}
    
void MainWindow::saveFile( )
{
	QString sname = QFileDialog::getSaveFileName( this, "Save file", "/home" );
	QFile writeFile( sname );
	writeFile.open( QIODevice::WriteOnly );
	size_t startpoint = fileSize * startSld->value( ) / 100;
	size_t endpoint = fileSize * endSld->value( ) / 100;
	writeFile.write( fileString + startpoint , endpoint - startpoint );
	writeFile.close( );
}
		
void MainWindow::analysisChoice( )
{
	clearWidgets();
	size_t startpoint = fileSize * startSld->value( ) / 100;
	size_t endpoint = fileSize * endSld->value( ) / 100;
	if( fileSize <= 0 || endpoint < startpoint) return; // No seg faults here man
	size_t tFileSize = endpoint - startpoint;
	pb->setValue(0);
	//calls a child method (analysis) of the current tab 
	QMetaObject::invokeMethod( tab_widget->currentWidget( ),"analysis",Qt::DirectConnection,
		Q_ARG( char *,fileString + startpoint ),Q_ARG ( size_t,tFileSize ),
		Q_ARG( bool,localityBtn->isChecked( ) ),Q_ARG( QProgressBar *, pb ) );
}

void MainWindow::clearWidgets()
{
	int tCount = tab_widget->count();
	int tActive = tab_widget->currentIndex();
	for (int i = 0; i < tCount; i++)
		if (i != tActive)
			QMetaObject::invokeMethod( tab_widget->widget(i),"clean",Qt::DirectConnection);
}
