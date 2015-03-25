/***************************************
 * dissasemble.h
 * Declares the Class to be define in dissasemble.cpp
 **************************************/
#include <QWidget>
#include <QObject>
#include <QProgressBar>
#include <QTextEdit>
#include <QProcess>

class Dissasemble : public QWidget
{
	Q_OBJECT
	
	public:
		Dissasemble( );
	
	public slots:
		void analysis( char *, size_t, QProgressBar * );
		void clean();
	
	private:
		QTextEdit * dissasembly;
		QProcess * objdumpProcess;
};
