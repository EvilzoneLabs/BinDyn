/***************************************
 * dissasemble.h
 * Declares the Class to be define in dissasemble.cpp
 **************************************/
#include <QWidget>
#include <QObject>
#include <QProgressBar>
#include <QTextEdit>
#include <QString>
#include <QSlider>


class Dissasemble : public QWidget
{
	Q_OBJECT
	
	public:
		Dissasemble( );
	
	public slots:
		void analysis( char *, size_t, bool, QProgressBar * );
		void clean();
	
	private:
		QTextEdit * addresses;
		QTextEdit * dissasembly;
		QTextEdit * notes;
		QSlider * archSlider;
		//Arch Related
		int numArchs = 1;
		void dis_x86(char*, size_t);
};
