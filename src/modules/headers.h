#include <QWidget>
#include <QObject>
#include <QProgressBar>
#include <QCheckBox>
#include <QTextEdit>

class Headers : public QWidget
{
	Q_OBJECT
	
	public:
		Headers( );
	
	public slots:
		void analysis( char *, size_t, QProgressBar * );
		void clean();
		
	private:
		QCheckBox * headerTypeOne;
		void analyzeHeaderOne(char *, size_t, QProgressBar *);
		
		QCheckBox * headerTypeTwo;
		void analyzeHeaderTwo(char *, size_t, QProgressBar *);
		
		QCheckBox * headerTypeThree;
		void analyzeHeaderThree(char *, size_t, QProgressBar *);
		
		QTextEdit * headerFields;
		QTextEdit * headerData;
};
