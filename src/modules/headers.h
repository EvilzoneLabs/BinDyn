#include <QWidget>
#include <QObject>
#include <QProgressBar>

class Headers : public QWidget
{
	Q_OBJECT
	
	public:
		Headers( );
	
	public slots:
		void analysis( char *, size_t, QProgressBar * );
		void clean();
};
