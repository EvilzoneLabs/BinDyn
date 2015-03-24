#include <QWidget>
#include <QObject>
#include <QProgressBar>
#include <QTextEdit>
#include <QString>
#include <QProcess> 
#include <QLineEdit>
#include <QPushButton>

class GDBrun : public QWidget
{
	Q_OBJECT
	
	public:
		GDBrun( );
	
	public slots:
		void analysis( char *, size_t, QProgressBar * );
		void clean();
		void processOutput();
		void sendCommand();
		
	private:
		QProcess * gdbProcess;
		QTextEdit * gdbOutput;
		QPushButton * commandButton;
		QLineEdit * command;
};
