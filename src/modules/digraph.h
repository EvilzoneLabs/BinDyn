/***************************************
 * digraph.h
 * Declares the Class to be define in digraph.cpp
 **************************************/
#include "Plotter.h"
#include <QSlider>
#include <QProgressBar>
#include <QObject>

class Digraph : public QWidget
{
	Q_OBJECT
	
	public:
		Digraph();
		
	public slots:
		void analysis( char *, size_t, bool, QProgressBar * );
		void clean();
	
	private:
        QSlider * brightness;
        Plotter * plot;
};
