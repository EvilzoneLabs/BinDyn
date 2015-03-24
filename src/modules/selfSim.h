/***************************************
 * selfSim.h
 * Declares the Class to be define in selfSim.cpp
 **************************************/
#include "Plotter.h"
#include <QProgressBar>
#include <QObject>

class SelfSim : public QWidget
{
	Q_OBJECT
	
	public:
		SelfSim();
		
		
	public slots:
		void analysis( char * , size_t, QProgressBar * );
		void clean();
		
	private:
		Plotter * plot;
};
