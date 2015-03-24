/***************************************
 * signatureScan.h
 * Declares the Class to be define in signatureScan.cpp
 **************************************/
 
#include <QObject>
#include <QProgressBar>
#include <QTextEdit>

class SignatureScan : public QWidget 
{
	Q_OBJECT
	
	public slots:
		void analysis( char * , size_t, QProgressBar * );
		void clean();
		
	public:
		SignatureScan( );
		
	private:
		QTextEdit * textOutput ;
};
