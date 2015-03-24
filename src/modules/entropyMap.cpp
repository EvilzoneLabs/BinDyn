/***************************************
 * entropyMap.cpp
 * Defines the Class declared in entropyMap.h
 * 
 * PreConditions: Program Started, User/File loaded
 * Main Use: Scan file generate plot based on entropy
 *           of windows at specified jump distances. 
 *           jumpsize and windowsize can be played with
 *           for best effect.
 * PostCondtions: Done scanning / reporting.
 * 
 * Gotchas: currently a floating point error on files
 *          less than 1 kb, have not found time to 
 *          find it yet.
 *          Yes there are lot's of casts, it sucks,
 *          I know.
 **************************************/

#include "entropyMap.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>
#include <cmath>

EntropyMap::EntropyMap()
{
	//Dat Layout Objects
		locality = new QCheckBox(" Preserve Locality?");
		output = new QTextEdit;
		threshold = new QLineEdit( );
		threshold -> setText( "150" );
		jump = new QSlider( Qt::Horizontal );
		jump -> setRange( 1, 20 );
		jump -> setValue( 10 );
		range = new QSlider( Qt::Horizontal );
		range -> setRange( 50, 500 );
		range -> setValue( 150 );
		plot = new Plotter( );
		scroll = new QScrollArea( );
		scroll -> setWidget( plot );
		QLabel * rangeLabel = new QLabel( "Window Size" );
		QLabel * jumpLabel = new QLabel( "Jump Size" );
		QLabel * thresholdLabel = new QLabel( "Entropy Threshold" );
		listThreshold = new QCheckBox( "List Positions Over Entropy Threshold?" );
    //Dat Layout.
		QVBoxLayout * layout = new QVBoxLayout( );
		QHBoxLayout * bottom = new QHBoxLayout( );
		QHBoxLayout * buttons = new QHBoxLayout( );
		buttons -> addWidget(locality);
		buttons -> addWidget( listThreshold );
		buttons -> addWidget( thresholdLabel );
		buttons -> addWidget( threshold );
		buttons -> addWidget( jumpLabel );
		buttons -> addWidget( jump );
		buttons -> addWidget( rangeLabel );
		buttons -> addWidget( range );
		bottom -> addWidget( scroll );
		bottom -> addWidget( output );
		output -> setMaximumWidth( 250 );
		layout -> addLayout( buttons );
		layout -> addLayout( bottom );
		setLayout( layout );
}

void EntropyMap::clean()
{
	output -> clear();
	plot -> clean();
}

void EntropyMap::analysis( char * fileString, size_t fileSize, QProgressBar * pb )
{
	//Set up some variables
		unsigned int jumpSize = jump -> value();
		unsigned int windowRange = range -> value();
		double entropyThreshold = threshold -> text().toDouble();
		unsigned char tempEntropy = 0;
	//Set up the Point array
		point * localPoints = new point[ fileSize / jumpSize ];
	//Progress bar thing
		size_t pbChunk = (fileSize / jumpSize)  / 100;	
		if (!pbChunk) pbChunk = 1;	
	if (!locality->isChecked())
	{
		//Get Sizes 
			unsigned int width = scroll->width() - 10;
			unsigned int height = scroll->height();
		//Get Pensize
			unsigned int penSize = sqrt((width * height) / ( fileSize / jumpSize ));
			if ( penSize == 0 ) { penSize = 1; }
		for ( size_t counter = 0; counter < (fileSize - windowRange) / jumpSize; counter++ )
		{
			if (!(counter % pbChunk)) pb->setValue(pb->value() + 1); //Progress bar.
			tempEntropy = entropy(reinterpret_cast<unsigned char*>(fileString + counter * jumpSize) , windowRange);
			if ( tempEntropy < entropyThreshold )
			{
				localPoints[ counter ].r = tempEntropy;
				localPoints[ counter ].b = 0;
				localPoints[ counter ].g = 0;
			}
			else
			{
				if (listThreshold -> isChecked())
				{
					output -> append("testtest");
				}
				localPoints[ counter ].b = tempEntropy;
				localPoints[ counter ].r = 0;
				localPoints[ counter ].g = 0;
			}
			localPoints[ counter ].x = (counter % (width / penSize)) * penSize;
			localPoints[ counter ].y = (counter / (width / penSize)) * penSize ;
		}
		plot -> plot(localPoints, penSize, fileSize / jumpSize, width, (fileSize / jumpSize / width)*penSize);
	}
	else
	{
		//Get penSize
			unsigned int penSize = sqrt( (scroll->width() * scroll->height()) / fileSize);
			if ( penSize == 0 ) { penSize = 1; }
		//Generate N, N must be a value that is a power of 2, IE 128,256,512,1024,etc.
		// Will limit these to 1024, sorry folks with high res, use the other monitor for porn
			unsigned int dimension;
			unsigned int testSize= scroll->width() / penSize;
			for (dimension = 2; dimension * 2 < testSize && dimension != 1024; dimension *= 2);
			unsigned int blockSize = dimension * dimension;
		//Will need these later
			int tempX;
			int tempY;
		//Do the same thing as above but with awful awful things at the end
			unsigned int blockCount = 0;
			for ( size_t counter = 0; counter < (fileSize - windowRange) / jumpSize; counter++ )
			{
				//Progress bar.
					if (!(counter % pbChunk)) pb->setValue(pb->value() + 1);
				//Increase if we're in a new block
					if (!(counter % blockSize) && counter != 0) blockCount += 1;	
				//Get moar entropy
					tempEntropy  = entropy(reinterpret_cast<unsigned char*>( fileString + counter * jumpSize ), windowRange);
				if ( tempEntropy < entropyThreshold )
				{
					localPoints[ counter ].r = tempEntropy;
					localPoints[ counter ].b = localPoints[ counter ].g = 0;
				}
				else
				{
					if (listThreshold -> isChecked())
					{
						output -> append("testtest");
					}
					localPoints[ counter ].b = tempEntropy;
					localPoints[ counter ].r = localPoints[ counter ].g = 0;
				}
				plot->d2xy(dimension, counter % blockSize, &tempX, &tempY);
				localPoints[ counter ].x = penSize * tempX;
				localPoints[ counter ].y = penSize * (tempY + (blockCount * dimension ));
			}
		plot->plot(localPoints, penSize, fileSize / jumpSize, penSize*dimension, penSize*fileSize/dimension);
	}
}

unsigned char EntropyMap::entropy(unsigned char *passed, unsigned int size) 
{ 
	//Generate a buffer, find the entropy via histrogram, return.
	double entropy = 0.0; 
	unsigned int i; 
 	int temp[256] = {0};
 	for (i = 0; i < size; ++i) ++temp[passed[i]]; 
 	for (i = 0; i < 256; ++i) 
 		if (temp[i]) 
			entropy -= static_cast<double>(temp[i]) / size * log2(static_cast<double>(temp[i])/size); 
	return static_cast<unsigned char>(entropy * 30);
}
