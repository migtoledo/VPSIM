#pragma once


// Disc of radius RADIUS centered at r0
vector<istate> getistatesmdisc(par r0, par v0, double m, double q, bool selfcolor, ALLEGRO_COLOR scolor, double dl, double RADIUS, double R)
{
	vector<istate> matrix;
	
	matrix.clear();

	// GEOMETRICAL INITIAL CONFIGURATION
	
	double n = RADIUS / dl;
	double i = 0;
	double _RAD = 0;

	vector<istate> _tmp;
	vector<istate> sum;

	for (i = n; i > 0; i--)
	{
		_RAD = i * dl;
		_tmp = getistatesmcirc(r0, v0, m, q, selfcolor, scolor, dl, _RAD, R);
		sum = sumistatesm(matrix, _tmp);
		matrix = sum;
	}
	
	return matrix;

}

// n-Discs, first centered at r=r0, all of them are equal
vector<istate> getistatesmndiscs(par r0, par v0, double m, double q, bool selfcolor, ALLEGRO_COLOR scolor, double dl, double RADIUS, double R, int n, ...)
{
	// n extra parameters: r1, r2, r3, ....

	vector<istate> matrix;

	// Initial Disc : centered at r0

	// Note again, that all metric units are mathematical, except
	// the radius of the elemental-particles, defined in physical (screen) pixels: R
	matrix = getistatesmdisc(r0, v0, m, q, selfcolor, scolor, dl, RADIUS, R);

	// Reading centers for n discs: r1, r2, r3, ...

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
		tmp_m = getistatesmdisc(*it, v0, m, q, selfcolor, scolor, dl, RADIUS, R);
		sum_m = sumistatesm(matrix, tmp_m);
		matrix = sum_m;
	}

	return matrix;
}
