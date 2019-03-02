#pragma once

// Segment from r0 -> r1: spaces between consecutive particles = dl
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
		r = r + dl * ru;
		tmp = getpixstate(r, v0, m, q, selfcolor, scolor, R);
		matrix.push_back(tmp);
	}

	return matrix;

}

// n-Segments from r0 -> r1 -> r2 -> ... : 
// spaces between consecutive particles = dl
vector<istate> getistatesmnsegment(par r0, par v0, double m, double q, bool selfcolor, ALLEGRO_COLOR scolor, double dl, double R, par r1, int n, ...)
{
	// n-Segments: r0 - r1 - r2 - r3 - r4 - r5 - r6 - r7 - ... - rn
	
	// Building the corresponding matrix of states
	// First segment: r0 - r1

	vector<istate> matrix = getistatesmsegment(r0, v0, m, q, selfcolor, scolor, dl, R, r1);
	
	// Reading and storing the vertices of
	// n connected segments

	vector<par> vertices;
	vertices.clear();
	par _tmp;

	va_list valist;
	va_start(valist, n);

	int _i = 0;

	for (_i = 0; _i < n; _i++)
	{
		_tmp = va_arg(valist, par);
		vertices.push_back(_tmp);
	}

	va_end(valist);
	 		
	vector<istate> tmp_m;
	vector<istate> sum_m;
	par  __last_r, __r1;
	int k = 0;

	vector<par>::iterator it;
	for (it = vertices.begin(); it < vertices.end(); it++)
	{
		k++;
		
		if (k == 1) __last_r = r1;
		
		__r1 = *it;

		tmp_m = getistatesmsegment(__last_r, v0, m, q, selfcolor, scolor, dl, R, __r1);
				
		__last_r = __r1;

		sum_m = sumistatesm(matrix, tmp_m);
		matrix = sum_m;
	}
	   	  
	return matrix;

}

