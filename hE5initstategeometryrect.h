#pragma once



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

