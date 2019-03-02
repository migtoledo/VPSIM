#pragma once

void pixM::getmass()
{
	this->mass = 0;
	vector<Pix*>::iterator i;
	for (i = this->ptrpixm.begin(); i < this->ptrpixm.end(); i++)
	{
		this->mass += (*i)->m;
	}
}

void pixM::getcentermass()
{
	this->getmass();
	par mr = par(0, 0);
	vector<Pix*>::iterator i;
	for (i = this->ptrpixm.begin(); i < this->ptrpixm.end(); i++)
	{
		mr += ((*i)->m)*((*i)->r);
	}
	this->cm = (mr) / this->mass;
}

void pixM::getaveragevelocity()
{
	this->getnpix();
	par vs = par(0, 0);
	vector<Pix*>::iterator i;
	for (i = this->ptrpixm.begin(); i < this->ptrpixm.end(); i++)
	{
		vs += ((*i)->v);
	}
	this->av = (vs) / this->npix;
}

void pixM::getcentermassvelocity()
{
	this->getmass();
	par vs = par(0, 0);
	vector<Pix*>::iterator i;
	for (i = this->ptrpixm.begin(); i < this->ptrpixm.end(); i++)
	{
		vs += ((*i)->m)*((*i)->v);
	}
	this->vcm = (vs) / this->mass;
}

void pixM::getenergy()
{
	double mv2 = 0;
	vector<Pix*>::iterator i;
	for (i = this->ptrpixm.begin(); i < this->ptrpixm.end(); i++)
	{
		mv2 += ((*i)->m)*(std::norm((*i)->v));
	}
	this->energy = 0.5*mv2;
}



void pixM::getnproc()
{
	this->nproc = this->ptrprocm.size();
}


