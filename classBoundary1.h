#pragma once

// IMPLEMENTATIONS

void Boundary::gettsig()
{
	(_dt == 0) ? this->tsig = 0 : ((_dt > 0) ? this->tsig = 1 : this->tsig = -1);
}

Boundary Boundary::init()
{
	this->setup();
	return *this;
}

void Boundary::setdefaults()
{
	this->col = MARRON_BROWN;

	this->xmin = -ox + 1;
	this->xmax = -this->xmin;

	this->ymax = oy - 1;
	this->ymin = -this->ymax;

	this->l = vspace(1);

	this->vx0 = 10;
	this->vy0 = 0;

	this->x0 = this->xmin;
	this->y0 = this->ymax - this->l;

	this->vx = this->vx0;
	this->vy = this->vy0;

	this->x = this->x0;
	this->y = this->y0;

	this->x1 = this->x + this->l;
	this->y1 = this->y + this->l;

	this->computexy();
}

void Boundary::setup()
{

	this->setdefaults();

}

