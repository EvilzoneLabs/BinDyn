/***************************************
 * digraph.cpp
 * Defines the Class declared in digraph.h
 * 
 * PreConditions: Program Started, User/File loaded
 * Main Use: Scan file generate plot of neighbouring
 *           bytes. THis relationship shows very distinct 
 *           patterns.
 * PostCondtions: Done scanning / reporting.
 * 
 * Gotchas: any larger file will need to be scanned
 *          with a low brightness
 **************************************/

#include "digraph.h"
#include <QHBoxLayout>
#include <iostream>

Digraph::Digraph()
{
        plot = new Plotter( );
        brightness = new QSlider( Qt::Vertical );
        brightness->setRange( 1, 100 );
        brightness->setValue( 20 );
        QHBoxLayout * layout = new QHBoxLayout;
        layout->addWidget( brightness );
        layout->addWidget( plot );
        setLayout( layout );
}

void Digraph::clean()
{
	plot -> clean();
}

void Digraph::analysis( char * fileString, size_t fileSize, QProgressBar * pb )
{
	//Get The Data
		int digraphArray[257][257] = {0};
		int x = static_cast<unsigned char>(fileString[ 0 ] );
		int y = 0;
		for ( int i = 1; i < fileSize; x = y, i++ )
		{
			y = static_cast<unsigned char>(fileString[ i ] );
			digraphArray[ x ][ y ]++;
		}
	pb->setValue(25); //Progress Bar
	//Get Sizes -- currently borked
		unsigned int * dim = plot->getSize();
		unsigned int width = 1000;
		unsigned int height = 600;
	//Generate offsets and pensize
		unsigned int penSize = height / 255;
		unsigned int xOffset = (width - (255 * penSize)) / 2;
		unsigned int yOffset = (height - (255 * penSize)) / 2;
	pb->setValue(50); //Progress Bar
	//Generate the array
		point * localPoints = new point[65536];
		unsigned int pointBrightness = 0;
		unsigned int brightnessValue = brightness->value();
		unsigned int pointsOffset = 0;
		for (size_t x = 0; x < 256; x++ )
		{
			for (size_t y = 0; y < 256; y++ )
			{
				pointBrightness = digraphArray[ x ][ y ] * brightnessValue;
				if ( pointBrightness > 255 ) pointBrightness = 255; 
				//Here be the fucked up lines which places the point in the array in the right spot.
					pointsOffset = ( ( x * 255 ) + y );
					localPoints[ pointsOffset ].x = (x * penSize) + xOffset;
					localPoints[ pointsOffset ].y = (y * penSize) + yOffset;
					localPoints[ pointsOffset ].r = static_cast <unsigned char>(pointBrightness);
					localPoints[ pointsOffset ].g = 0;
					localPoints[ pointsOffset ].b = 0;
			}
		}
	pb->setValue(75);
	plot->plot(localPoints, penSize, 65535, 1000, 1000 ); //Do not question the magic number
	pb->setValue(100);
}
