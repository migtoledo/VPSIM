#pragma once


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
	double n = (2 * PI*RADIUS) / dl;

	double i = 0;

	// Points of the circunference
	par ri;

	for (i = 0; i < n; i++)
	{
		fita = (i)*(dl / RADIUS);

		ri = r0 + polar(RADIUS, fita);

		tmp = getpixstate(ri, v0, m, q, selfcolor, scolor, R);
		
		matrix.push_back(tmp);

	}

	return matrix;

}

// n Circumferences: First centered at r0, second: r1, third: r2, ...
vector<istate> getistatesmncirc(par r0, par v0, double m, double q, bool selfcolor, ALLEGRO_COLOR scolor, double dl, double RADIUS, double R, int n, ...)
{
	// n extra parameters: r1, r2, r3, ....

	vector<istate> matrix;

	// Initial circumference

	matrix = getistatesmcirc(r0, v0, m, q, selfcolor, scolor, dl, RADIUS, R);

	// Reading centers for n circumferences: r1, r2, r3, ...

	vector<par> centers;
	centers.clear();
	par _tmp;
	va_list valist;
	va_start(valist, n);
	int _i = 0;
	for (_i = 0; _i < n; _i++)
	{
		_tmp = va_arg(valist, par);
		centers.push_back(_tmp);
	}
	va_end(valist);

	vector<istate> tmp_m;
	vector<istate> sum_m;
	int k = 0;
	vector<par>::iterator it;
	for (it = centers.begin(); it < centers.end(); it++)
	{
		k++;
		tmp_m = getistatesmcirc(*it, v0, m, q, selfcolor, scolor, dl, RADIUS, R);
		sum_m = sumistatesm(matrix, tmp_m);
		matrix = sum_m;
	}

	return matrix;

}


