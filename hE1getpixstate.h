#pragma once

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
