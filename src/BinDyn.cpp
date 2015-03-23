/*
* Visual Binary Profiler By HTH
* Credit to Schalla for the Idea
* Released under the MIT License
* 
* Todo:
* conversions
* dissassembler
* possibly width changer inside the plotters?
* deque suggestions?
* refactor. No code smell allowed.
*/

#include "MainWindow.h"

int main( int argc, char *argv[ ] )
{
	QApplication app(argc, argv);
	MainWindow window; 
	window.show( );
	return app.exec( );
}
