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

