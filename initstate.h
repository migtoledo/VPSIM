#pragma once

// Structure for initial state of the particles
struct istate
{
	// Position
	par r0;

	// Velocity
	par v0;

	// Mass
	double m;

	// Electrical charge
	double q;

	// Takes self-color
	bool selfcolor;

	// Self color
	ALLEGRO_COLOR scolor;

	// Radius of the particle
	double R;
};


// Sum of two matrices of initial states
vector<istate> sumistatesm(vector<istate> m1, vector<istate> m2)
{
	vector<istate> sum;
	m1.insert(m1.end(), m2.begin(), m2.end());
	sum = m1;
	return sum;	
}

// Sum of n matrices of initial states
vector<istate> sumnistatesm(int n, ...)
{
	vector<istate> tmp;
	vector<istate> sum;

	va_list valist;
	va_start(valist, n);
	int i = 0;

	for (i = 0; i < n; i++)
	{
		tmp = va_arg(valist, vector<istate>);
		sum = sumistatesm(sum, tmp);
	}

	va_end(valist);

	return sum;
}

