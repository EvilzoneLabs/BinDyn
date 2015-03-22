/***************************************
 * Plotter.h
 * Declares the Class to be define in Plotter.cpp
 * Leave the header guards.
 **************************************/

#ifndef PLOT_H
#define PLOT_H
#include <QWidget>
//This one be for plotting things, eh

struct point 
{
	unsigned short int x;
	unsigned int y;
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

class Plotter : public QWidget 
{
	
	public:
		Plotter(); 
		void plot(point *, unsigned int, size_t, unsigned short int, unsigned int );
		void clean();
		unsigned int * getSize( );
		void d2xy( int, int, int *, int * );
		int xy2d ( int, int, int );
		
	protected:
		void paintEvent( QPaintEvent *event );
	
	private:
		point * points = NULL;
		unsigned int penSize;	
		size_t fileSize;
		void rot( int, int * , int * , int, int );
};
#endif
