#pragma once

class pixM
{
	public:
		// Initial States matrix
		vector<istate> istatesm;
		// Pix matrix
		vector<Pix> pixm;
		// Pix-pointers matrix
		vector<Pix*> ptrpixm;
		// Pix-processors matrix
		vector<procPix> procm;
		// Pix-processors pointers matrix
		vector<procPix*> ptrprocm;
		bool loaded = false;
		ALLEGRO_COLOR messagecolor = _white;

		// Physical characteristics

		// Color
		ALLEGRO_COLOR scolor;
		// Flag for default color
		bool selfcolor;
		// Gravity constant (Newton's)
		double G;
		// Electric constant (Coulomb's)
		double K;
		// Mass of each one of the particle's matrix
		double m;
		// Electrical charge of each one of the particle's matrix
		double q;
		// Initial velocity for each one of the particles
		par v0;
		// Number of particles - as float for
		// better compatibility
		double npix;
		// Interactions processors
		double nproc;
		// Total mass of the system
		double mass;
		// Center of mass
		par cm;
		// Average velocity
		par av;
		// Velocity of center of mass
		par vcm;
		// Cinetic energy
		double energy;
							
	public:

		// LOADING INITIAL STATES MATRIX

		void loadistatesm(vector<istate> istatesm);
		// After loading the initial states matrix
		// can build the corresponding Pix matrix
		void buildpixm();
		// After Pix matrix is built, can build Pix pointers matrix
		void buildptrpixm();
		// Building the processors-matrix   
		void buildprocm();
		// Building the pointers processors-matrix   
		void buildptrprocm();

		// LOADING PIX-POINTERS MATRIX

		void setnull();
		pixM() { this->setnull(); }
		~pixM() { this->setnull(); }
		pixM init(vector<istate> istatesm);
		void setup(vector<istate> istatesm);
		void setdefaults(vector<istate> istatesm);
		void setmessagecolor(ALLEGRO_COLOR messagecolor);
		void drawloadingmessage();			
				
		// PHYSICAL PROPERTIES
				
		void getnpix();
		void getnproc();
		void getmass();
		void getcentermass();
		void getaveragevelocity();
		void getcentermassvelocity();
		void getenergy();
		
		// ANIMATION OPERATIONS
				
		void getid();		
		void computexy();		
		void draw();		
		void setcolor(ALLEGRO_COLOR color);	
		void getscale(par exy);	
		void getbgcolor(bool blackbg, bool whitebg);	
		void setforegroundcolor();
		void setconstants(double G, double K);
		void dointeractions();
		void run();
};

