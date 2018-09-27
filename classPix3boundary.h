#pragma once


void Pix::getdr()
{
	if (vt != 0)
	{
		this->dr =par(this->v.real()*_dt, this->v.imag()*_dt);
	}
	else
	{
		this->dr = par(0, 0);
	}
}

void Pix::computeboundary()
{
	// Using INSTANT-CONTACT-technic
	// to avoid tunnel-effects and/or 
	// cyclic-surface contact-oscillations.
	
	// MOVING TO RIGHT

	if (this->dr.real() > 0)
	{
		// Next-cycle impacting to RIGHT-WALL: (1-real-cycle = 0.02 s approx.)
		if (this->r.real() + this->dr.real() > this->rmax.real())
		{
			// Well, now come the good thing, this particle will
			// be just NOW, impacting (saving 0.02 s of time, and many headaches...)
			// and adjusting its new velocity accordingly, just perfect-elastic collision.

			this->r.real(this->rmax.real());
			// To avoid xy-distortion of trajectory, we need to "move" instantaneously
				// the y-coordinate too. We make linear-interpolation.
				// y = y0 + (dy/dx)(x-x0) // For y, our incognite, x=xmax.
			// We're supposing for intervals of 0.02 s the movement is approximately linear.

			this->r.imag(this->r.imag() + (this->dr.imag() / this->dr.real())*(this->rmax.real() - this->r.real()));

			// Perfect-elastic = Total energy conservation
			// Just reversing sign of vx, vy stays constant.

			this->v.real(-real(this->v));

			// ready.

		}
	}

	// MOVING TO LEFT

	if (this->dr.real() < 0)
	{
		// Next-cycle impacting to LEFT-WALL: (1-real-cycle = 0.02 s approx.)
		if (this->r.real() + this->dr.real() < this->rmin.real())
		{
			this->r.real(this->rmin.real());
			
			this->r.imag(this->r.imag() + (this->dr.imag() / this->dr.real())*(this->rmin.real() - this->r.real()));

			this->v.real(-real(this->v));

		}
	}

	// MOVING TO TOP

	if (this->dr.imag() > 0)
	{
		// Next-cycle impacting to TOP-WALL: (1-real-cycle = 0.02 s approx.)
		if (this->r.imag() + this->dr.imag() > this->rmax.imag())
		{
			this->r.imag(this->rmax.imag());

			// Now adjusting x-linear, for y=ymax

			this->r.real(this->r.real() + (this->dr.real() / this->dr.imag())*(this->rmax.imag() - this->r.imag()));

			this->v.imag(-imag(this->v));

		}
	}

	// MOVING TO BOTTOM

	if (this->dr.imag() < 0)
	{
		// Next-cycle impacting to BOTTOM-WALL: (1-real-cycle = 0.02 s approx.)
		if (this->r.imag() + this->dr.imag() < this->rmin.imag())
		{
			this->r.imag(this->rmin.imag());

			// Now adjusting x-linear, for y=ymax

			this->r.real(this->r.real() + (this->dr.real() / this->dr.imag())*(this->rmin.imag() - this->r.imag()));

			this->v.imag(-imag(this->v));

		}
	}

	// Diagonals or curves are differential combinations of these 4-possibilities.

	// Tested with Allegro 5.2.4 (Asus Intel Core i3)
	// THIS ALGORITHM WORKS OK WITH PIXEL-2D-VELOCITIES OF  UNTIL 4000 pixels/s !
	// in normal laptop-screen. That means the pixel-movement gets-touching the
	// screen-area borders, rebounding perfect-elastically, not escaping, despite of the
	// particle looks more like a beam of light!
	
	// This algorithm took me more than 5 years of deep-thinking, despite of looks simple.
}

void Pix::compute_v()
{	
	if (vt == 0)
	{
		this->v = this->v0;
	}
	else
	{
		this->computeboundary();
	}
	
	this->getdr();
}

void Pix::compute_r()
{
	// At t=0 : r=r0, v=v0

	if (vt != 0)
	{
		this->compute_v();
		this->r += this->dr;
	}
	else
	{
		this->v = this->v0;
		this->dr = par(0, 0);
		// getting r0
		this->r = this->r0;
	}

	this->getrr();
}

void Pix::getrr()
{
	this->rr = this->grr(this->r);
}


void Pix::draw()
{
	//al_draw_pixel(this->rr.real(), this->rr.imag(), this->color);
	al_draw_filled_circle(this->rr.real(), this->rr.imag(), this->R, this->color);
}

par Pix::grr(par r)
{
	par retval = par(XXS(r.real(), this->exy.real()), YYS(r.imag(), this->exy.imag()));
	return retval;
}

