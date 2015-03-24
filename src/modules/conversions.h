/***************************************
 * conversions.h
 * Declares the Class to be define in conversions.cpp
 **************************************/
#include <QWidget>
#include <QObject>
#include <QProgressBar>

class Conversions : public QWidget
{
	Q_OBJECT
	
	public:
		Conversions( );
	
	public slots:
		void analysis( char *, size_t, QProgressBar * );
		void clean();
};
