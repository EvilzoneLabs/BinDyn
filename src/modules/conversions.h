/***************************************
 * conversions.h
 * Declares the Class to be define in conversions.cpp
 **************************************/
#include <QWidget>
#include <QObject>
#include <QProgressBar>
#include <QPushButton>
#include <QTextEdit>

class Conversions : public QWidget
{
	Q_OBJECT
	
	public:
		Conversions( );
	
	public slots:
		void analysis( char *, size_t, QProgressBar * );
		void clean();
	
	private:
		QPushButton * conversionsOne;
		QPushButton * conversionsTwo;
		QPushButton * conversionsThree;
		QPushButton * conversionsFour;
		QPushButton * conversionsFive;
		QPushButton * conversionsSix;
		QTextEdit * dataIn;
		QTextEdit * dataOut;
};
