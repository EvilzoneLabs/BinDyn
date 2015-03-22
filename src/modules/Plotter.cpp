/***************************************
 * Plotter.cpp
 * Defines the Class declared in Plotter.h
 * 
 * PreConditions: Program Started, User/File loaded
 * Main Use: Accept a module generated list of points 
 *           of the type point (defined in Plotter.h)
 *           Generate a 2d image from this set.
 *           Also includes helper functions for size/
 *           spacing filling curves.
 * PostCondtions: Done plotting.
 * 
 * Gotchas: 1 point = 9 bytes, MEMORY USAGE.
 *          array of points can NOT be deleted
 *          after rendering due to the way QT
 *          handles paint events, currently I
 *         delete and force the user to re-analyze
 * 			using MainWindow::clearWidgets()
 **************************************/

#include "Plotter.h"
#include <QPainter>


void Plotter::paintEvent( QPaintEvent *event )
{
	Q_UNUSED( event );
	QPainter * qp = new QPainter(this);
	QPen pen;
	QColor penColor;
	pen.setWidth( penSize );
	//I also do the checks here to TRY and avoid the annoying "rgb parameters out of range" hasnt worked all the time so far..
	//It has been lessened though.
	if (points)
	{
		for (size_t counter = 0; counter < fileSize; counter++)
		{
			//Verify rgb parameters
			if (points[ counter ].r > 255 || points[ counter ].r < 0) 
				points[ counter ].r = 255;
			if (points[ counter ].g > 255 || points[ counter ].g < 0) 
				points[ counter ].g = 255;
			if (points[ counter ].b > 255 || points[ counter ].b < 0) 
				points[ counter ].b = 255;		
			penColor.setRgb( points[ counter ].r, points[ counter ].g, points[ counter ].b ); //ew
			pen.setColor( penColor );
			qp -> setPen( pen );
			qp -> drawPoint( points[ counter ].x, points[ counter ].y );
		}
	}
}	
			
void Plotter::plot(point * pts, unsigned int ps,  size_t fs, unsigned short int w, unsigned int h)
{
	//Lets outside objects reload this QPainted Canvas with data
	points = pts;
	penSize = ps;
	fileSize = fs;
	resize( w, h );
	update();
}

void Plotter::clean()
{
	if (points)
	{
		delete [] points;
		points = NULL;
	}
}
Plotter::Plotter()
{
}
	
unsigned int * Plotter::getSize()
{
	unsigned int coords[2];
	coords[0] = width();
	coords[1] = height();
	return coords;
}

//Props to Wikipedia for the following

//convert (x,y) to d
int Plotter::xy2d (int n, int x, int y) {
    int rx, ry, s, d=0;
    for (s=n/2; s>0; s/=2) {
        rx = (x & s) > 0;
        ry = (y & s) > 0;
        d += s * s * ((3 * rx) ^ ry);
        rot(s, &x, &y, rx, ry);
    }
    return d;
}
 
//convert d to (x,y)
void Plotter::d2xy(int n, int d, int *x, int *y) {
    int rx, ry, s, t=d;
    *x = *y = 0;
    for (s=1; s<n; s*=2) {
        rx = 1 & (t/2);
        ry = 1 & (t ^ rx);
        rot(s, x, y, rx, ry);
        *x += s * rx;
        *y += s * ry;
        t /= 4;
    }
}
 
//rotate/flip a quadrant appropriately
void Plotter::rot(int n, int *x, int *y, int rx, int ry) {
    if (ry == 0) {
        if (rx == 1) {
            *x = n-1 - *x;
            *y = n-1 - *y;
        }
        //Swap x and y
        int t  = *x;
        *x = *y;
        *y = t;
    }
}
