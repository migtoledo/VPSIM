#pragma once

// Geometries of matrices of initial states

// A Pix initial state
istate getpixstate(par r0, par v0, double m, double q, bool selfcolor, ALLEGRO_COLOR scolor, double R)
{
	istate pixstate;
	pixstate.r0 = r0;
	pixstate.v0 = v0;
	pixstate.m = m;
	pixstate.q = q;
	pixstate.selfcolor = selfcolor;
	pixstate.scolor = scolor;
	pixstate.R = R;
	return pixstate;	   	
}


// Segment geometry : Segment from r0 -> r1 : 
// spaces between consecutive particles = dl
vector<istate> getistatesmsegment(par r0, par v0, double m, double q, bool selfcolor, ALLEGRO_COLOR scolor, double dl, double R, par r1)
{
	vector<istate> matrix;

	// Temporary state for initialization
	istate tmp;

	matrix.clear();

	// GEOMETRICAL INITIAL CONFIGURATION

	// Unitary direction vector for segment [r0, r1]
	par ru = (r1 - r0) / abs(r1 - r0);
		
	// We divide the segment in pieces
	// of length dl, also the number of pieces:

	double n = abs(r1 - r0) / dl;

	// Building the segment adding consecutive pieces
	// of length dl:

	// For casting reasons, i needs to be float
	double i = 0;

	// Initial point for r:
	par r = r0;
	
	for (i = 0; i < n; i++)
	{
		r = r + dl*ru;
		tmp.r0 = r;
		tmp.v0 = v0;
		tmp.m = m;
		tmp.q = q;
		tmp.scolor = scolor;
		tmp.selfcolor = selfcolor;
		tmp.R = R;
		matrix.push_back(tmp);
	}

	return matrix;

}


// Circular geometry
// Circumference: centered at r0, radius RADIUS in units, particles-radius=R in px.
// Arc-distance between particles = dl
vector<istate> getistatesmcirc(par r0, par v0, double m, double q, bool selfcolor, ALLEGRO_COLOR scolor, double dl, double RADIUS, double R)
{
	vector<istate> matrix;

	// Temporary state for initialization
	istate tmp;

	matrix.clear();

	// GEOMETRICAL INITIAL CONFIGURATION

	// Angle in radians
	double fita = 0;

	// Number of pieces
	double n = (2 * PI*RADIUS)/dl;

	double i = 0;

	// Points of the circunference
	par ri;

	for (i = 0; i < n; i++)
	{
		fita = (i)*(dl / RADIUS);

		ri = r0+polar(RADIUS, fita);

		tmp.r0 = ri;
		tmp.v0 = v0;
		tmp.m = m;
		tmp.q = q;
		tmp.scolor = scolor;
		tmp.selfcolor = selfcolor;
		tmp.R = R;

		matrix.push_back(tmp);
		
	}
	   
	return matrix;

}




// Rectangular geometry
// Fill rectangle
vector<istate> getistatesmrectfill(par r0, par v0, double m, double q, bool selfcolor, ALLEGRO_COLOR scolor, par r1, double dx, double dy, double R)
{
	vector<istate> matrix;

	// Temporary state for initialization
	istate tmp;
	
	matrix.clear();

	// GEOMETRICAL INITIAL CONFIGURATION

	// r0, r1: Borders of the rectangle

	// Dimensions XY of the rectangle
	double x0, y0, x1, y1;
	double xi, yi, xf, yf;

	x0 = r0.real();
	y0 = r0.imag();
	x1 = r1.real();
	y1 = r1.imag();

	// Borde inferior
	xi = _min(x0, x1);
	yi = _min(y0, y1);

	// Borde superior
	xf = _max(x0, x1);
	yf = _max(y0, y1);

	// Anchura del rectángulo
	double lx = xf - xi;

	// Altura del rectángulo
	double ly = yf - yi;

	// i-row, j-column for particle(i, j)
	int i, j;
	i = 0; j = 0;

	int imax, jmax;

	// Número de columnas
	jmax = (int)lx / dx;

	// Número de filas
	imax = (int)ly / dy;

	// Geometry 2D -> Memory-matrix 1D

	// Posición inicial r0 de la partícula (i, j)
	par r0tmp;
	double x, y;

	// Filas i (líneas horizontales)
	for (i = 0; i < imax; i++)
	{
		// Columnas j (líneas verticales)
		for (j = 0; j < jmax; j++)
		{
			x = xi + j * dx;
			y = yi + i * dy;
			r0tmp.real(x);
			r0tmp.imag(y);
			tmp = getpixstate(r0tmp, v0, m, q, selfcolor, scolor, R);
			matrix.push_back(tmp);
		}
	}

	return matrix;
}
