/***************************************
 * printableMap.h
 * Declares the Class to be define in printableMap.cpp
 **************************************/

#include "Plotter.h"
#include <QObject>
#include <QProgressBar>
#include <QColor>
#include <QScrollArea>

class PrintableMap : public QWidget
{
	Q_OBJECT
	
	public:
		PrintableMap();
		
	public slots:
		void nullColorDialog( );
		void belowColorDialog( );
		void printableColorDialog( );
		void aboveColorDialog( );
		void ffColorDialog( );
		void analysis(char * , size_t, QProgressBar * );
		void clean();
	
	private:
		Plotter * plot;
		QColor nullCol;
		QColor ffCol;
		QColor aboveCol;
		QColor belowCol;
		QColor printableCol;
		QScrollArea * scroll;
		void getPointRgb(unsigned char, point *, size_t);
};
