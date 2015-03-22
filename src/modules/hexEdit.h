/***************************************
 * hexEdit.h
 * Declares the Class to be define in hexEdit.cpp
 **************************************/

#include <QWidget>
#include <QObject>
#include <QProgressBar>
#include <QTextEdit>

class HexEditor : public QWidget
{
	Q_OBJECT
	
	public:
		HexEditor();
	
	public slots:
		void analysis( char *,  size_t, bool, QProgressBar * );
		void clean();
		
	private:
		QTextEdit *hex;
		QTextEdit *ascii;
};
