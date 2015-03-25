/***************************************
 * statistics.cpp
 * Defines the Class declared in statistics.h
 * 
 * PreConditions: Program Started/fileuser input loaded
 * Main Use: Generate stats and a histogram based on fileString
 * PostCondtions: Done displaying stats
 * 
 * Gotchas: remember that unsigned char is being used
 *          as unsigned int8
 **************************************/

#include "statistics.h"
#include <QHBoxLayout>
#include <QString>

Statistics::Statistics()
{
    stats = new QTextEdit( );
    plot = new Plotter( );
    QHBoxLayout *layout = new QHBoxLayout( );
    layout -> addWidget( stats );
    stats -> setMaximumWidth( 200 );
    layout -> addWidget( plot );
    setLayout( layout );
}

void Statistics::clean()
{
	stats -> clear();
	plot -> clean();
}

void Statistics::analysis(char * fileString, size_t fileSize, QProgressBar * pb)
{
	//Setup
		stats -> clear();
		size_t values [257] = {0};
	//sum variables, hah, punny right? It's 6 am, leave me alone.
		size_t sum = 0;
		int temp = 0;	
	//Point array
		point * localPoints = new point[ 256*256 ]; //Magic numbers do not touch
		for(int i = 0; i < 256 * 256; i++) 
		{
			localPoints[i].x = 0;
			localPoints[i].y = 0;
			localPoints[i].r = 0;
			localPoints[i].g = 0;
			localPoints[i].b = 0;
		} 
	//Iterate gathering data
		for (size_t counter = 0; counter < fileSize; counter++, sum += temp)
		{
			temp = static_cast <unsigned char>(fileString[ counter ]);
			values[ temp ]++;
		}
	pb->setValue(25); //PB
	//Calc most common
		unsigned int maxPos = 1;
		for ( unsigned int counter = 2; counter < 255; counter++)
			if ( values[ counter ] > values[ maxPos ])
				maxPos = counter;	
		pb->setValue(30);
		if (!values[maxPos]) values[maxPos]++;
	//Average
		if (!sum) sum++;
		int avgByte = sum / fileSize;
		pb->setValue(40); 
	//Say things
		stats->insertPlainText("Out of: " + QString::number(fileSize) + " bytes\n");
		stats->insertPlainText(QString::number(values[0]) + " 0x00 bytes\n");
		stats->insertPlainText(QString::number(values[255]) + " 0xff bytes\n");
		stats->insertPlainText("Average byte value : " + QString::number(avgByte,16));
		stats->insertPlainText("\nMost Common is : " + QString::number(maxPos,16));
	pb->setValue(50); //PB
	//Get Sizes -- borked
		unsigned int w = width();
		unsigned int h = height();
	//Generate offsets and pensize
		unsigned int penSize = h / 255;
		if (!penSize) penSize++;
		unsigned int xOffset = (w - (255 * penSize)) / 2;
		unsigned int yOffset = (h - (255 * penSize)) / 2;
	//Fill the Array
		int pOffset = 0;
		for (unsigned int x = 0; x < 255; x++)
		{
			for (unsigned int y = 0; y < values[x]*255/values[maxPos]; y++)
			{
				pOffset =  ( x * 255 ) + y;
				localPoints[ pOffset ].x = x * penSize + xOffset;
				localPoints[ pOffset ].y = (255-y) * penSize + yOffset;
				localPoints[ pOffset ].r = 255;
				localPoints[ pOffset ].g = 0;
				localPoints[ pOffset ].b = 0;
			}
		}
	pb->setValue(75); //PB
	plot -> plot(localPoints, penSize, 256 * 256, w, h );
	pb->setValue(100); //PB
}
