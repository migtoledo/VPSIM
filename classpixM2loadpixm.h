#pragma once

void pixM::loadistatesm(vector<istate> istatesm)
{
	this->istatesm = istatesm;
}

void pixM::buildpixm()
{
	// Reading initial states from matrix of states
	// and building corresponding matrix of particles

	this->pixm.clear();
	this->pixm.reserve(1024);
	vector<istate> :: iterator i;
	//Pix p;
	
	for (i = this->istatesm.begin(); i < this->istatesm.end(); i++)
	{
		Pix *p = new Pix;
		//p = p.init(*i);
		p->init(*i);
		this->pixm.push_back(*p);
		delete p;
	}
	this->buildptrpixm();
}

void pixM::getnpix()
{
	this->npix = this->ptrpixm.size();
}

void pixM::buildprocm()
{
	this->procm.clear();
	this->procm.reserve((1024));	
	vector<Pix*>::iterator i;
	vector<Pix*>::iterator j;
	//procPix tmp;
	//procPix* _tmp = &tmp;

	for (i = this->ptrpixm.begin(); i < this->ptrpixm.end(); i++)
	{
		for (j = this->ptrpixm.begin(); j < this->ptrpixm.end(); j++)
		{
			if (j > i)
			{
				procPix *tmp = new procPix;
				tmp->init(*i, *j);
				//_tmp->init(*i, *j);
				this->procm.push_back(*tmp);
				delete tmp;
			}
		}
	}		
	this->buildptrprocm();
}


