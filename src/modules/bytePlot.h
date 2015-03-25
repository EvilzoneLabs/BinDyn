/***************************************
 * bytePlot.h
 * Declares the Class to be define in bytePlot.cpp
 **************************************/

#include "Plotter.h"
#include <QProgressBar>
#include <QObject>
#include <QScrollArea>
#include <QSlider>
#include <QLabel>

class BytePlot : public QWidget
{
	Q_OBJECT
	
	public:
		BytePlot( );
		
	public slots:
		void analysis( char *, size_t, QProgressBar *);
		void clean();
		void updateWidth(int);
		
	private:
		QScrollArea * scroll;
		Plotter * plot;
		QSlider * widthSlider;
		QLabel *userSetWidth;
};
