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
#include <QHBoxLayout>
#include <cmath>

BytePlot::BytePlot( )
{
        plot = new Plotter( );
        scroll = new QScrollArea;
        scroll->setWidget( plot );
        QVBoxLayout *layout = new QVBoxLayout;
        QHBoxLayout * bar = new QHBoxLayout;
        widthSlider = new QSlider( Qt::Horizontal, this );
        widthSlider -> setRange(0,width() * 2); //Works well on my box, fack off if you dont like it
		userSetWidth = new QLabel("0");
		QLabel * widthLabel = new QLabel("Width -Leave On 0 For Auto Sizing");
		bar -> addWidget(widthLabel);
		bar -> addWidget(widthSlider);
		bar -> addWidget(userSetWidth);
		layout -> addLayout(bar);
        layout->addWidget( scroll );
        setLayout( layout );
        QObject::connect(widthSlider,SIGNAL(valueChanged(int)),this,SLOT(updateWidth(int)));
}

void BytePlot::clean()
{
	plot -> clean();
}

void BytePlot::analysis( char * fileString, size_t fileSize, QProgressBar * pb )
{
	//Allocate the point array
		point * localPoints = new point[ fileSize ];
	size_t pbChunk = fileSize / 100; //Progress bar thing
	if (!pbChunk) pbChunk = 1;
	unsigned char temp = 0;
	unsigned int w, height, penSize;
	
	//Get Sizes
		if (userSetWidth->text().toInt())
		{
			w = scroll-> width() - 10; 
			height = scroll -> height() - 10;
			penSize = width() / userSetWidth->text().toInt();
		}
		else
		{
			w = scroll-> width() - 10;
			height = scroll -> height() - 10;
			penSize = sqrt( (w * height) / fileSize);
		}
		if ( !penSize ) penSize = 1;
	//Gen Points
		for ( size_t counter = 0; counter < fileSize; counter++ )
		{	
			if (!(counter % pbChunk)) pb->setValue(pb->value() + 1); //Progress bar.
			temp = static_cast<unsigned char>(fileString[ counter ]);
			localPoints[ counter ].x = counter % (w/penSize) * penSize;
			localPoints[ counter ].y = counter / (w/penSize) * penSize;
			localPoints[ counter ].r = localPoints[ counter ].g = localPoints[ counter ].b = temp;
		}
	plot->plot(localPoints, penSize, fileSize, w, fileSize * penSize / w );
}



void BytePlot::updateWidth(int value)
{
	userSetWidth->setText(QString("%1").arg(value));
}
