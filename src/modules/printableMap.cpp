/***************************************
 * printableMap.cpp
 * Defines the Class declared in printableMap.h
 * 
 * PreConditions: Program Started, User/File loaded
 * Main Use: Scan file generate byte plot with color
 *           coding defined by user, or defaults.
 *           useful for locating strings 
 * PostCondtions: Done scanning / reporting.
 * 
 * Gotchas: the buttons dont currently show the colors
 *          hope you have a good memory bruh.
 **************************************/

#include "printableMap.h"
#include <QColorDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <cmath>
#include <iostream>

PrintableMap::PrintableMap()
{
	//Starting Colors
		nullCol.setRgb( 0, 0, 0 );
		belowCol.setRgb( 255, 0, 0 );
		printableCol.setRgb( 0, 255, 0 );
		aboveCol.setRgb( 0, 0, 255 );
		ffCol.setRgb( 255, 255, 255 );
	//Buttons
		QPushButton * nullBtn = new QPushButton( "Null Color" );
		QPushButton * belowBtn = new QPushButton( "<32 Color" );
		QPushButton * printableBtn = new QPushButton( "Printable Color" );
		QPushButton * aboveBtn = new QPushButton( ">127 Color" );
		QPushButton * ffBtn = new QPushButton( "FF Color" );
	//connect the buttons
		QObject::connect( nullBtn, SIGNAL( clicked() ),this, SLOT( nullColorDialog() ) );
		QObject::connect( belowBtn, SIGNAL( clicked() ),this, SLOT( belowColorDialog() ) );
		QObject::connect( printableBtn, SIGNAL( clicked() ),this, SLOT( printableColorDialog() ) );
		QObject::connect( aboveBtn, SIGNAL( clicked() ),this, SLOT( aboveColorDialog() ) );
		QObject::connect( ffBtn, SIGNAL( clicked() ),this, SLOT( ffColorDialog() ) );  
	//Button Bar
		QHBoxLayout * buttonBar = new QHBoxLayout();
		buttonBar -> addWidget( nullBtn );
		buttonBar -> addWidget( ffBtn );
		buttonBar -> addWidget( printableBtn );
		buttonBar -> addWidget( aboveBtn );
		buttonBar -> addWidget( belowBtn );    
	//THe Plotting/scrolling Section
		plot = new Plotter();
		scroll = new QScrollArea();
		scroll -> setWidget( plot );
	//Layout
		QVBoxLayout * layout = new QVBoxLayout();
		layout -> addLayout( buttonBar );
		layout -> addWidget( scroll );
		setLayout( layout );
}

void PrintableMap::clean()
{
	plot -> clean();
}

void PrintableMap::analysis(char * fileString, size_t fileSize, bool locality, QProgressBar * pb)
{
	//Generate the point array
	point * localPoints = new point[ fileSize ];
	//Progress bar thing
		size_t pbChunk = fileSize / 100;	
	//Get Sizes
		unsigned int width = scroll -> width() - 10;
		unsigned int height = scroll -> height();
	//Get penSize
		unsigned int penSize = sqrt( (width * height) / fileSize );
		if (penSize == 0) { penSize = 1; }
	if (!locality)
	{
		//Get Colors	
			for ( size_t counter = 0; counter < fileSize; counter++ )
			{
				if (!(counter % pbChunk)) pb->setValue(pb->value() + 1); //Progress bar.
				getPointRgb(static_cast<unsigned char>(fileString[ counter ]),localPoints,counter);
				localPoints[ counter ].x = counter % ( width / penSize ) * penSize;
				localPoints[ counter ].y = counter / ( width / penSize ) * penSize;
			}
		plot -> plot(localPoints, penSize, fileSize, width, (fileSize/width)*penSize );
	}
	else
	{
		//Generate N, N must be a value that is a power of 2, IE 128,256,512,1024,etc.
		// Will limit these to 1024, sorry folks with high res, use the other monitor for porn
			unsigned int dimension;
			unsigned int testSize = scroll->width() / penSize;
			for (dimension = 2; dimension * 2 < testSize && dimension != 1024; dimension *= 2);
			unsigned int blockSize = dimension * dimension;
		//Will need these later
				int tempX;
				int tempY;	
		//Get these points see
			unsigned int blockCount = 0;
			for (size_t counter = 0; counter < fileSize; counter++)
			{
				//Progress bar.
					if (!(counter % pbChunk)) pb->setValue(pb->value() + 1);
				//Increase if we're in a new block
					if (!(counter % blockSize) && counter != 0) blockCount += 1;
				//Grab dat data
					getPointRgb(static_cast<unsigned char>(fileString[ counter ]),localPoints,counter);
				//XY still gives people herpes to look at.
					plot->d2xy(dimension, counter % blockSize, &tempX, &tempY);
					localPoints[ counter ].x = penSize * tempX;
					localPoints[ counter ].y = penSize * (tempY + (blockCount * dimension ));
			}
		plot->plot(localPoints, penSize, fileSize, penSize * dimension, penSize * fileSize/dimension);
	}
}

//This bad boy is called a lot in both functions so hey, why not right?
void PrintableMap::getPointRgb(unsigned char temp, point * localPoints, size_t counter)
{
	QColor * refCol;
	if ( temp == 0 ) refCol = &nullCol;
	else if (temp == 255) refCol = &ffCol;
	else if (temp > 32 && temp < 127) refCol = &printableCol;
	else if (temp < 32) refCol = &belowCol;
	else if (temp > 127) refCol = &aboveCol;
	localPoints[counter].r = refCol->red();
	localPoints[counter].g = refCol->green();
	localPoints[counter].b = refCol->blue();
}

//I don't want to talk about these functions, don't even mention them.
void PrintableMap::nullColorDialog( ) { nullCol = QColorDialog::getColor( ); }
void PrintableMap::belowColorDialog()  { belowCol = QColorDialog::getColor( ); }
void PrintableMap::printableColorDialog( ) { printableCol = QColorDialog::getColor( ); }
void PrintableMap::aboveColorDialog( ) { aboveCol = QColorDialog::getColor( ); }
void PrintableMap::ffColorDialog( ) { ffCol = QColorDialog::getColor( ); }
