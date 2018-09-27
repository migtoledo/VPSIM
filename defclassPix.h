#pragma once

// Class definition: "Pix"

class Pix
{
	public:

		// Pure Internal Variables

		bool active=false;
		bool initialized=false;
		bool contacted=false;
		bool selfcolor=false;
		ALLEGRO_COLOR scolor;
		// Internal "radius" in pixels
		double R;
		// Mass
		double m;
		// Charge
		double q;
		// Univocally Identification's Number
		double id;
		// Color
		ALLEGRO_COLOR color;
		// Math coordinates
		par r;
		par r0;
		par dr;
		par v;
		par v0;
		par rmin, rmax;
		// Transformed coordinates -> Work Area
		par rr;
		// External parameters ( Animation )
		// XY Scales
		par exy;
		// Background color
		bool blackbg, whitebg;
				
	public:

		// Default constructor
		Pix();

		void setnull();

		~Pix() { this->setnull(); }
		
		Pix init(par r0, par v0, double m, double q, bool selfcolor, ALLEGRO_COLOR scolor, double R);

		Pix init(istate initialstate);

		void setdefaults(par r0, par v0, double m, double q, bool selfcolor, ALLEGRO_COLOR scolor, double R);

		void setdefaults(istate initialstate);

		void setup(par r0, par v0, double m, double q, bool selfcolor, ALLEGRO_COLOR scolor, double R);

		void setup(istate initialstate);

		void setR(double R);
		void getid();
		void setid(double id);
		void getdr();
		void getrmax();
		void setexy(par exy);
		void computeboundary();
		void compute_v();
		void setcolor(ALLEGRO_COLOR color);	
		void getbgcolor(bool blackbg, bool whitebg);
		void setforegroundcolor();	
		void compute_r();
		par grr(par r);
		void getrr();
		void getscale(par exy);
		void draw();
};
