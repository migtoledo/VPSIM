#pragma once

// Class definition: procPix

class procPix
{
	public:

		Pix *_pix1;

		Pix *_pix2;

		// Gravity Constant
		double G;

		// Electric Constant
		double K;
		
		bool contact;

		bool closer;
		
		// Distances between Pixs for consecutive cycles
		double d1, d2, dmin;
		
	public:

		procPix init(Pix *_pix1, Pix *_pix2);

		void setgravity(double G);

		void setelectric(double K);

		void setconstants(double G, double K);
			
		void start();

		void computedistances();

		void determineapproach();

		void determinecontact();

		void modifypixvelocitiescontact();

		void modifypixvelocitiesgravity();

		void modifypixvelocitieselectric();
		
		void getdmin();

		void reset();

		void run();
};

// Implementations


procPix procPix::init(Pix *_pix1, Pix *_pix2)
{
	this->_pix1 = _pix1;
	this->_pix2 = _pix2;

	this->start();

	return *this;
}

void procPix::setgravity(double G)
{
	this->G = G;
}

void procPix::setelectric(double K)
{
	this->K = K;
}

void procPix::setconstants(double G, double K)
{
	this->setgravity(G);
	this->setelectric(K);
}

void procPix::computedistances()
{
	this->getdmin();

	double s1, s2;

	// Distance between particles "NOW"

	s1 = abs(this->_pix2->r - this->_pix1->r);

	// Distance between particles "next-cycle = NOW+0.02 s"

	s2 = abs(( this->_pix2->r + this->_pix2->dr) - ( this->_pix1->r+this->_pix1->dr));

	this->d1 = s1;

	this->d2 = s2;

}

void procPix::determineapproach()
{
	this->computedistances();

	(this->d2 < this->d1) ? 
		this->closer = true : this->closer = false;
}

void procPix::getdmin()
{
	double ex = this->_pix1->exy.real();
	double ey = this->_pix1->exy.imag();

	double iex = 1 / ex;
	double iey = 1 / ey;

	par iexy = par(iex, iey);

	this->dmin = abs(iexy);
}

void procPix::determinecontact()
{
		
	(this->closer && (this->d2 < this->dmin)) ?
		this->contact = true : this->contact = false;
}

void procPix::modifypixvelocitiescontact()
{
	// Initial velocities (before contact)
	double v1xi, v1yi, v2xi, v2yi;

	// Mass of particle 1
	double m1;

	// Mass of particle 2
	double m2;

	// Final velocities (after contact)
	double v1xf, v1yf, v2xf, v2yf;

	m1 = this->_pix1->m;
	m2 = this->_pix2->m;

	v1xi = this->_pix1->v.real();
	v1yi = this->_pix1->v.imag();

	v2xi = this->_pix2->v.real();
	v2yi = this->_pix2->v.imag();

	v1xf = (1 / (m1 + m2))*((m1 - m2)*v1xi + 2 * m2*v2xi);
	v1yf = (1 / (m1 + m2))*((m1 - m2)*v1yi + 2 * m2*v2yi);

	v2xf = (1 / (m1 + m2))*((m2 - m1)*v2xi + 2 * m1*v1xi);
	v2yf = (1 / (m1 + m2))*((m2 - m1)*v2yi + 2 * m1*v1yi);

	par v1 = par(v1xf, v1yf);
	par v2 = par(v2xf, v2yf);
		
	this->_pix1->v = v1;
	this->_pix2->v = v2;
}

void procPix::modifypixvelocitiesgravity()
{
	this->getdmin();

	// Gravitiy constant
	double G = this->G;

	// Differential-time
	double dt = _dt;

	// Relative distance
	double d;
	double d2;

	// Masses of Particles
	double m1, m2;

	// Accelerations
	par a1, a2;

	// Differential-velocities
	par dv1, dv2;

	// Relative Positions

	par r1, r2, r12, r21, r12u, r21u;

	// Gravitational Forces

	// Force of Particle "1" over Particle "2"
	par F12;

	// Force of Particle "2" over Particle "1"
	par F21;

	// r12: From "1" to "2" = r2-r1 : r1 + r12 = r2

	// r21: From "2" to "1" = r1-r2 : r2 + r21 = r1

	// r12 = -r21

	// Calculating unitary-vectors:

	r1 = this->_pix1->r;
	r2 = this->_pix2->r;

	r12 = r2 - r1;
	r21 = -r12;

	r12u = r12 / abs(r12);
	r21u = -r12u;

	// Applying Gravity Law of Newton: 
	// F12=-G[(m1m2)/(r12^2)]r12u : Force of "1" over "2"
	// F21=-G[(m1m2)/(r21^2)]r21u : Force of "2" over "1"
	
	m1 = this->_pix1->m;
	m2 = this->_pix2->m;
	
	// Gravity Force of Particle "2" over Particle "1"

	d = abs(r12);
	d2 = pow(d, 2);

	(d2 > 2*this->dmin) ?
		F21 = ((-G)*(m1*m2) / d2)* r21u : F21 = 0.0 * r21u;

	// Applying 2nd. Law of Newton for particle "1" : F21=m1a1

	a1 = F21 / m1;

	// Calculating force and acceleration for particle 2:

	F12 = -F21;

	a2 = F12 / m2;

	// Calculating differential velocities:

	dv1 = a1 * dt;
	dv2 = a2 * dt;

	// Updating velocities:
		
	this->_pix1->v = this->_pix1->v + dv1;
	this->_pix2->v = this->_pix2->v + dv2;
	
}


void procPix::modifypixvelocitieselectric()
{
	this->getdmin();

	// Coulomb's constant
	double K = this->K;

	// Differential-time
	double dt = _dt;

	// Relative distance
	double d;
	double d2;

	// Masses of Particles

	double m1, m2;

	// Charges of Particles 
	// Supposed to be electrons (-1), protons (+1) or neutrons (0)
	double q1, q2;

	// Accelerations
	par a1, a2;

	// Differential-velocities
	par dv1, dv2;

	// Relative Positions

	par r1, r2, r12, r21, r12u, r21u;

	// Electrical Forces

	// Force of Particle "1" over Particle "2"
	par F12;

	// Force of Particle "2" over Particle "1"
	par F21;

	// r12: From "1" to "2" = r2-r1 : r1 + r12 = r2

	// r21: From "2" to "1" = r1-r2 : r2 + r21 = r1

	// r12 = -r21

	// Calculating unitary-vectors:

	r1 = this->_pix1->r;
	r2 = this->_pix2->r;

	r12 = r2 - r1;
	r21 = -r12;

	r12u = r12 / abs(r12);
	r21u = -r12u;

	// Applying Coulomb's law: 
	// F12=K[(q1q2)/(r12^2)]r12u : Force of "1" over "2"
	
	q1 = this->_pix1->q;
	q2 = this->_pix2->q;

	m1 = this->_pix1->m;
	m2 = this->_pix2->m;

	// Electrical Force of Particle "2" over Particle "1"

	d = abs(r12);
	d2 = pow(d, 2);

	(d2 > 2 * this->dmin) ?
		F21 = ((K)*(q1*q2) / d2)* r21u : F21 = 0.0 * r21u;

	// Applying 2nd. Law of Newton for particle "1" : F21=m1a1

	a1 = F21 / m1;

	// Calculating force and acceleration for particle 2:

	F12 = -F21;

	a2 = F12 / m2;

	// Calculating differential velocities:

	dv1 = a1 * dt;
	dv2 = a2 * dt;

	// Updating velocities:

	this->_pix1->v = this->_pix1->v + dv1;
	this->_pix2->v = this->_pix2->v + dv2;

}

void procPix::start()
{
	this->contact = false;	
	this->closer = false;	
}

void procPix::run()
{
	this->determineapproach();

	this->determinecontact();
	
	if (this->contact) this->modifypixvelocitiescontact();

	this->modifypixvelocitiesgravity();

	this->modifypixvelocitieselectric();
	
}

void procPix::reset()
{
	this->start();
}


