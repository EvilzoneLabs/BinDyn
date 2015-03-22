/***************************************
 * stringScan.h
 * Declares the Class to be define in stringScan.cpp
 **************************************/

#include <QObject>
#include <QTextEdit>
#include <QProgressBar>

class StringScan : public QWidget 
{
	Q_OBJECT
	
	public slots:
		void analysis( char*, size_t, bool, QProgressBar * );
		void clean();
		
	public:
		StringScan( );
	
	private:
		QTextEdit * textOutput;
};
