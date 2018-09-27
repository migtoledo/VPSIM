#pragma once

class Boundary
{

	public:

		ALLEGRO_COLOR col;

		volatile double tsig;

		double l;

		double xmin, xmax, ymin, ymax;

		double vx0, vy0, vx, vy;

		double dx, dy;

		double x0, y0;

		// Math coordinates
		double x, y, x1, y1;

		// Work Area coordinates
		double xx, yy, xx1, yy1;
		
	public:

		Boundary init();

		// Get time-signature: (-,0,+)
		void gettsig();

		void setdefaults();

		void setup();
				
		void computevxy();

		void computeTop();
		void computeTopLeft();
		void computeTopRight();

		void computeRight();
		void computeRightTop();
		void computeRightBottom();

		void computeBottom();
		void computeBottomLeft();
		void computeBottomRight();

		void computeLeft();
		void computeLeftBottom();
		void computeLeftTop();

		void computexy();

		void updatexy();

		void computexxyy();

		void draw();

};



Boundary Armadillo;
Boundary* _Armadillo = &Armadillo;



