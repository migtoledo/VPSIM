#pragma once

// Class definition: "Animation"

class Animation
{
	public:

		// Virtual Gravity Constant
		double G;

		// Virtual Electric Constant
		double K;

		bool darkbg, whitebg;
		
		// AXIS-GRID ELEMENTS

		// Work Area Background Color
		ALLEGRO_COLOR wabgcolor;

		ALLEGRO_COLOR xAxisColor;

		ALLEGRO_COLOR yAxisColor;

		ALLEGRO_COLOR hLinesColor;

		ALLEGRO_COLOR vLinesColor;

		double input;

		double tmp;

		const char* consoletitle;

		const char* consolemessage;

		double xmin, ymin, xmax, ymax;

		// Scale XY :  Pixels / Unit
		double ex, ey;
		par exy;

		// XY Grid-Lines distances
		double dx, dy;
		
		// Mouse coordinates
		double xmouse, ymouse;

		// Show / Hide Axes, Grid
		bool Axes, Grid;

		// Show Help, About
		bool Help, About;

		// Labels
		bool drawlabels, _drawxlabels, _drawylabels;

		ALLEGRO_COLOR fontcolor;

		// Elements
		
		vector<istate> istatesm1;
		vector<istate> istatesm2;
		vector<istate> istatesm3;
		vector<istate> istatesm1m2m3;

		pixM pixGlobal;
		pixM *_pixGlobal = &pixGlobal;
									
	public:

		void setnull();

		Animation() { this->setnull(); }
		~Animation() { this->setnull(); }

		Animation initinterface();
		void setupinterface();
		void setdefaultsinterface();
		void setdefaultselements();

		void setmessagecolor();
		
		void getidforelements();

		void setgravity(double G);

		void setelectrick(double K);
				
		void getexy();
		
		boolstr savegraphic();

		void drawxlabels();

		void drawylabels();

		void drawxylabels();

		void setwabgcolor();
		
		void showaux();

		void showhelp();

		void showabout();

		void setdefaultaxes();

		void setdefaultgrid();

		void setxymax();

		void getxymouse();

		// Draw Output Panel
		void opdraw();

		// Draw Work Area
		void wadraw();

		// Draw Input Panel
		void ipdraw();

		// Draw Grid Elements - Work Area -

		void drawAxis();

		void drawGrid();

		// Draw Buttons - Input Panel -

		void drawButtons();

		// Draw Console

		void drawConsole();

		// Coordinates

		// From Math Space (x,y) to Work Area Space (xx,yy)

		double xx(double x);

		double yy(double y);
		
		void setdefaultcolors();

		void setdefaultscales();

		void setconsole();

		// XY Scales
		
		// Update xy min-max, axes, grid
		void setXscale(double sx);

		void setYscale(double sy);

		// Functions for dynamical elements

		// Update state of dynamical elements
		void updatestateelements();

		void updatescaleforelements();

		void updatecolorsforelements();

		void updateelectrogravity();

		void runelements();

		void stopelements();

		void resetelements();

		void drawelements();
};

//Animation Anim;
//Animation* _Anim = &Anim;

Animation *_Anim = new Animation;

// Implementations

void Animation::getexy()
{
	this->exy = par(this->ex, this->ey);
}

void Animation::drawelements()
{
	this->_pixGlobal->draw();
}

void Animation::runelements()
{
	if (ticks > ticksforloading)
	{
		this->updatestateelements();
		this->_pixGlobal->run();	
	}	
}

void Animation::stopelements()
{
	this->setdefaultselements();
}

void Animation::resetelements()
{
	this->stopelements();
}

void Animation::updatescaleforelements()
{
	this->_pixGlobal->getscale(this->exy);
}

void Animation::updatecolorsforelements()
{
	this->_pixGlobal->getbgcolor(this->darkbg, this->whitebg);
}

void Animation::updateelectrogravity()
{
	
	this->_pixGlobal->setconstants(this->G, this->K);
	
}


void Animation::updatestateelements()
{
	this->updatecolorsforelements();
	this->updatescaleforelements();
	this->updateelectrogravity();
}


