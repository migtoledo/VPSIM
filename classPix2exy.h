#pragma once


void Pix::getrmax()
{
	double xmin = (-ox + 1) / (this->exy.real());
	double xmax = -xmin;
	double ymax = (oy - 1) / (this->exy.imag());
	double ymin = -ymax;

	this->rmin = par(xmin, ymin);
	this->rmax = par(xmax, ymax);

}

void Pix::getscale(par exy)
{
	this->setexy(exy);
}

void Pix::setcolor(ALLEGRO_COLOR color)
{
	this->color = color;
}

void Pix::setexy(par exy)
{
	this->exy = exy;
	this->getrmax();
	this->getrr();
}

void Pix::getbgcolor(bool blackbg, bool whitebg)
{
	this->blackbg = blackbg;
	this->whitebg = whitebg;
	this->setforegroundcolor();
}

void Pix::setforegroundcolor()
{
	if (this->selfcolor)
	{
		this->setcolor(this->scolor);
	}
	else
	{
		if (this->blackbg) this->setcolor(_white);
		if (this->whitebg) this->setcolor(_black);
	}	
}
