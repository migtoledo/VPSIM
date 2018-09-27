#pragma once


void Animation::setxymax()
{
	this->xmin = (-ox + 1) / (this->ex);
	this->xmax = -this->xmin;

	this->ymax = (oy - 1) / (this->ey);
	this->ymin = -this->ymax;
}

void Animation::setXscale(double sx)
{
	if(sx>0) this->ex = sx;
	this->setxymax();
	this->getexy();
}

void Animation::setYscale(double sy)
{
	if(sy>0) this->ey = sy;
	this->setxymax();
	this->getexy();
}

void Animation::setgravity(double G)
{
	this->G = G;
}


void Animation::setelectrick(double K)
{
	this->K = K;
}




void Animation::getxymouse()
{
	// Mouse - WA Coordinates:
	double xmwa = xxmouse;
	double ymwa = yymouse - way0;

	// Transforming from WA-Coordinates to Math-Coordinates:
	this->xmouse = XS(xmwa, this->ex);
	this->ymouse = YS(ymwa, this->ey);

	// Checking out mouse in Work Area:

	if (!xyInx1y1x2y2(xmwa, ymwa, 0, 0, scrw, wah)) { this->xmouse = 0; this->ymouse = 0; }

	/*
	Alternativily:

	if (!xyInx1y1x2y2(this->xmouse, this->ymouse , this->xmin, this->ymin, this->xmax, this->ymax)) 
	{ this->xmouse = 0; this->ymouse = 0; }
	*/
	

}


