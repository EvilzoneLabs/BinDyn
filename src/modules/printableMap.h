/***************************************
 * printableMap.h
 * Declares the Class to be define in printableMap.cpp
 **************************************/

#include "Plotter.h"
#include <QObject>
#include <QProgressBar>
#include <QColor>
#include <QScrollArea>
#include <QPushButton>
#include <QCheckBox>

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
		QPushButton * nullBtn;
		QPushButton * belowBtn;
		QPushButton * printableBtn;
		QPushButton * aboveBtn;
		QPushButton * ffBtn;
		QScrollArea * scroll;
		QCheckBox * locality;
		void getPointRgb(unsigned char, point *, size_t);
		void setBorder(QPushButton *, QColor);
};
