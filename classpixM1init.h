#pragma once

// Implementations

void pixM::setnull()
{
	this->istatesm.clear();
	this->pixm.clear();
	this->ptrpixm.clear();
	this->procm.clear();
	this->ptrprocm.clear();
	this->loaded = false;
}

pixM pixM::init(vector<istate> istatesm)
{
	this->loaded = false;
	this->setup(istatesm);
	return *this;
}

void pixM::setup(vector<istate> istatesm)
{
	this->setdefaults(istatesm);
}

void pixM::setdefaults(vector<istate> istatesm)
{
	this->loadistatesm(istatesm);
	this->buildpixm();		
	this->loaded = true;	
}

void pixM::buildptrpixm()
{
	this->ptrpixm.clear();
	this->ptrpixm.reserve(1024);
	vector<Pix>::iterator i;
	for (i = this->pixm.begin(); i < this->pixm.end(); i++)
	{
		this->ptrpixm.push_back(&(*i));
	}
	this->getid();
	this->getnpix();
	// Loading the interactions matrix:
	if (!this->ptrpixm.empty()) this->buildprocm();
}

void pixM::buildptrprocm()
{
	this->ptrprocm.clear();
	this->ptrprocm.reserve(1024);
	vector<procPix>::iterator i;
	for (i = this->procm.begin(); i < this->procm.end(); i++)
	{
		this->ptrprocm.push_back(&(*i));
	}
	this->getnproc();
}


