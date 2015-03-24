/***************************************
 * bytePlot.cpp
 * Defines the Class declared in bytePlot.h
 * 
 * PreConditions: Program Started, User/File loaded
 * Main Use: Scan file generate byte plot, black and white.
 *           Brightness basedon byte value. really only 
 *           useful for ID'ing interesting parts to scan 
 *           with otehr tools.
 * PostCondtions: Done scanning / reporting.
 * 
 * Gotchas: Limited use, may get merged with PrintableMap.
 **************************************/

#include "bytePlot.h"
#include <QVBoxLayout>
#include <cmath>
#include <iostream>

BytePlot::BytePlot( )
{
        plot = new Plotter( );
        scroll = new QScrollArea;
        scroll->setWidget( plot );
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget( scroll );
        setLayout( layout );
}

void BytePlot::clean()
{
	plot -> clean();
}

void BytePlot::analysis( char * fileString, size_t fileSize, QProgressBar * pb )
{
	bool locality = 0;
	//Allocate the point array
		point * localPoints = new point[ fileSize ];
	size_t pbChunk = fileSize / 100; //Progress bar thing
	unsigned char temp = 0;
	//Get Sizes
		unsigned int width = scroll->width() - 10;
		unsigned int height = scroll -> height() - 10;		
	//Get penSize
		unsigned int penSize = sqrt( (width * height) / fileSize);
		if ( penSize == 0 ) { penSize = 1; }
	if (!locality)
	{		
		//Gen Points
			for ( size_t counter = 0; counter < fileSize; counter++ )
			{	
				if (!(counter % pbChunk)) pb->setValue(pb->value() + 1); //Progress bar.
				temp = static_cast<unsigned char>(fileString[ counter ]);
				localPoints[ counter ].x = counter % (width/penSize) * penSize;
				localPoints[ counter ].y = counter / (width/penSize) * penSize;
				localPoints[ counter ].r = localPoints[ counter ].g = localPoints[ counter ].b = temp;
			}
		plot->plot(localPoints, penSize, fileSize, width, (fileSize/width)*penSize );
	}
	else // Locality is set
	{	
		//Generate N, N must be a value that is a power of 2, IE 128,256,512,1024,etc.
		// Will limit these to 1024, sorry folks with high res, use the other monitor for porn
			unsigned int dimension;
			unsigned int testSize= scroll->width() / penSize;
			for (dimension = 2; dimension * 2 < testSize && dimension != 1024; dimension *= 2);
			unsigned int blockSize = dimension * dimension;
		//Will need these later
			int tempX;
			int tempY;		
		//Get these points see
			unsigned int blockCount = 0;
			for (size_t counter = 0; counter < fileSize; counter++)
			{
				if (!(counter % pbChunk)) pb->setValue(pb->value() + 1); //Progress bar.
				if (!(counter % blockSize) && counter != 0)blockCount += 1; 	//Increase if we're in a new block
				temp = static_cast<unsigned int>(fileString[ counter ]); //Grab dat data
				//RGB is EZ-PZ
					localPoints[ counter ].r = localPoints[ counter ].g = localPoints[ counter ].b = temp;
				//XY gives people herpes to look at.
					plot->d2xy(dimension, counter % blockSize, &tempX, &tempY);
					localPoints[ counter ].x = penSize * tempX;
					localPoints[ counter ].y = penSize * (tempY + (blockCount * dimension ));
			}
		plot->plot(localPoints, penSize, fileSize, penSize * dimension, penSize * fileSize/dimension);
	}
}
