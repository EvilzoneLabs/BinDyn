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

class MainWindow : public QWidget 
{	
	Q_OBJECT

	public slots:	
		void fileDialog( );
		void saveFile( );
		void analysisChoice( );
		void clearWidgets( );

	public:
		MainWindow( );
	
	private:
		QLabel * fileName;
		QTabWidget * tab_widget;
		size_t fileSize = 0;
		char * fileString = NULL;
		QSlider * startSld;
		QSlider * endSld;
		QCheckBox * localityBtn;
		QProgressBar * pb;
};
