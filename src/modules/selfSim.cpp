/***************************************
 * selfSim.cpp
 * Defines the Class declared in selfSim.h
 * 
 * PreConditions: Program Started, User/File loaded
 * Main Use: Generate a plot of the files values on 
 * 			  the x and y axis, anywhere they overlap
 *            place a point, useful for ID'ing small 
 *            data structures.
 * PostCondtions: Done scanning / reporting.
 * 
 * Gotchas: the image generated contains filesize^2
 *          points and at the time of writing that is 
 *          9 bytes per point.
 *          SMALL FILES ONLY
 **************************************/

#include "selfSim.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>

SelfSim::SelfSim()
{
	plot = new Plotter( );
	QScrollArea * scroll = new QScrollArea;
	scroll -> setWidget( plot );
	QVBoxLayout * layout = new QVBoxLayout;
	QLabel * warning = new QLabel( "Will bork itself on large files, 10 kb = 900 mb of image." );
	layout -> addWidget( warning );
    layout -> addWidget( scroll );
    setLayout( layout );
}

void SelfSim::clean()
{
	plot->clean();
}

void SelfSim::analysis( char * fileString, size_t fileSize, QProgressBar * pb )
{
	//I can't let you do that to yourself.
	if (fileSize > 20000) return;
	//Progress bar thing
	size_t pbChunk = fileSize / 100;	
	if (!pbChunk) pbChunk = 1;
	point * localPoints = new point[ fileSize * fileSize ];
	unsigned int offset = 0;
	for (size_t x = 0; x < fileSize; x++)
	{
		for (size_t y = 0; y < fileSize; y++)
		{
			offset = ( x * fileSize ) + y;			
			if (!(offset % pbChunk)) pb->setValue(pb->value() + 1); //Progress bar.
			localPoints[ offset ].x = x;
			localPoints[ offset ].y = y;
			localPoints[ offset ].g = 0;
			localPoints[ offset ].b = 0;
			if (fileString[ x ] == fileString[ y ])
				localPoints[ offset ].r = 255;
			else
				localPoints[ offset ].r = 0;
		}
	}
	plot->plot(localPoints, 1, fileSize*fileSize, fileSize+1, fileSize+1 );
}
