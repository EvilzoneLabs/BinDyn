#include "autoScroll.h"
#include <QScrollBar>
#include <QTime>
//ScrollJumps = lines per jump, this is memory (graphics buffer id assume) intensive
//If you set a retarded jumps and time combo (1 line jumps, 100000 lines, 1 second)
//Then chances are things will just freeze as they should.

//Currently incomplete, chances are I will hit some sort of a scope issue

void autoScroll(QScrollArea * scrollArea, int scrollJumps, int desiredTime)
{
	//Check for idiocy
	if (scrollJumps == 0 || desiredTime == 0 || scrollArea == NULL) return;
	
	//Calculate Basic info and check again for idiocy
	int scrollHeight = scrollarea -> height();
	int desiredStepCount = scrollHeight / scrollJumps;
	if (!desiredStepCount) return; 
	float desiredStepFrequency = desiredTime / desiredStepCount; //Could easily be less than a second but now gauranteed not to be 0
	
	//Grab the scrollbar reference and set the range
	QScrollBar * autoScrollBar = scrollArea.verticalScrollBar;
	autoScrollBar.setRange(0,desiredStepCount);
	
	//Loop calling wait and autoScrollBar.setValue();
	
	
	
}

void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
