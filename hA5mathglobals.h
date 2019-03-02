#pragma once


#define PI (4.0*atan(1.0))

// From radians to grads
double radtograd(double rad)
{
	double grad = rad * (180.0 / PI);

	return grad;
}

// From grads to radians
double gradtorad(double grad)
{
	double rad = grad * (PI / 180.0);

	return rad;
}


double getrandom()
{
	double retval = 0;
	random_device rd;

	retval = rd();

	return retval;
		
}


typedef complex<double> par;

// Structure for r=(x, y) and v=(vx, vy)
struct bipar
{
	// Position r
	par r;

	// Velocity v
	par v;
};

typedef bipar bipar;


// A bit of Euclidian-Geometry ...

// C-Macros are sublime

#define _max(x1, x2) ((x1>x2) ? x1: x2)

#define _min(x1, x2) ((x1<x2) ? x1: x2)

#define xInx1x2(x, x1, x2) ((x>_min(x1,x2) && x<_max(x1,x2)) ? true: false)

// Determining if a point (x, y) is inside a rectangle of borders [ (x1, y1), (x2, y2) ]
#define xyInx1y1x2y2(x, y, x1, y1, x2, y2) ((xInx1x2(x, x1, x2) && xInx1x2(y, y1, y2)) ? true: false)


// Determining if r In rectangle (r1, r2)
bool rInr1r2(par r, par r1, par r2)
{
	bool retval = false;

	retval = xyInx1y1x2y2(r.real(), r.imag(), r1.real(), r1.imag(), r2.real(), r2.imag());

	return retval;
	
}





