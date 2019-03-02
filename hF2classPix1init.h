#pragma once


Pix Pix::init(par r0, par v0, double m, double q, bool selfcolor, ALLEGRO_COLOR scolor, double R)
{
	this->setup(r0, v0, m, q, selfcolor, scolor, R);
	return *this;
}

Pix Pix::init(istate initialstate)
{
	this->setup(initialstate);
	return *this;
}



void Pix::setR(double R)
{
	(R >= 0.0) ? this->R = R : this->R = 1;
}

void Pix::setup(par r0, par v0, double m, double q, bool selfcolor, ALLEGRO_COLOR scolor, double R)
{
	this->setdefaults(r0, v0, m, q, selfcolor, scolor, R);
}

void Pix::setup(istate initialstate)
{
	this->setdefaults(initialstate);
}

void Pix::getid()
{
	this->id = getrandom();
}

void Pix::setid(double id)
{
	this->id = id;
}

Pix::Pix()
{
	this->setnull();
}

void Pix::setnull()
{
	this->setid(0);
	this->initialized = false;
	this->active = false;
	this->contacted = false;
	this->setcolor(_white);
	this->setR(0);
	this->r = par(0, 0);
	this->r0 = par(0, 0);
	this->v = par(0, 0);
	this->v0 = par(0, 0);
	this->m = 0;
	this->q = 0;
	this->dr = par(0, 0);
}

void Pix::setdefaults(par r0, par v0, double m, double q, bool selfcolor, ALLEGRO_COLOR scolor, double R)
{
	// Getting id only first-time
	
	this->setR(R);
	this->initialized = true;
	this->active = true;
	this->contacted = false;
	this->m = m;
	this->q = q;
	this->selfcolor = selfcolor;
	this->scolor = scolor;
	this->r0 = r0;
	this->v0 = v0;
	this->compute_r();
}

void Pix::setdefaults(istate initialstate)
{
	this->setR(initialstate.R);
	this->initialized = true;
	this->active = true;
	this->contacted = false;
	this->m = initialstate.m;
	this->q = initialstate.q;
	this->selfcolor = initialstate.selfcolor;
	this->scolor = initialstate.scolor;
	this->r0 = initialstate.r0;
	this->v0 = initialstate.v0;
	this->compute_r();
}

