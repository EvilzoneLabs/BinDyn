/***************************************
 * MainWindow.h
 * Declares the Class defined in MainWindow.cpp
 **************************************/

#include <QObject>
#include <QApplication>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QCheckBox>
#include <QProgressBar>
#include <QString>
#include <QFileDialog>
#include <QLineEdit>

class MainWindow : public QWidget 
{	
	Q_OBJECT

	public slots:	
		void fileDialog( );
		void saveFile( );
		void analysisChoice( );
		void clearWidgets( );
		void updateStartOffset(int);
		void updateEndOffset(int);
	public:
		MainWindow( );
		QLabel * fileName;
	private:
		QTabWidget * tab_widget;
		size_t fileSize;
		char * fileString;
		QSlider * startSld;
		QSlider * endSld;
		QLineEdit * startOffset;
		QLineEdit * stopOffset;
		QProgressBar * pb;
		
};
