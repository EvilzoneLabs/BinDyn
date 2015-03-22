/***************************************
 * statistics.h
 * Declares the Class to be define in statistics.cpp
 **************************************/

#include "Plotter.h"
#include <QTextEdit>
#include <QObject>
#include <QProgressBar>

class Statistics : public QWidget
{
	Q_OBJECT
	
	public:
		Statistics( );
	
	public slots:
		void analysis( char * , size_t , bool, QProgressBar * );
		void clean();
		
	private:
		QTextEdit * stats;
		Plotter * plot;
};
