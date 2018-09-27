#pragma once

void pixM::setcolor(ALLEGRO_COLOR color)
{
	std::vector<Pix*> ::iterator i;

	for (i = this->ptrpixm.begin(); i < this->ptrpixm.end(); i++)
	{
		(*i)->setcolor(color);
	}
}


void pixM::getscale(par exy)
{
	std::vector<Pix*> ::iterator i;

	for (i = this->ptrpixm.begin(); i < this->ptrpixm.end(); i++)
	{
		(*i)->getscale(exy);
	}
}

void pixM::getbgcolor(bool blackbg, bool whitebg)
{
	std::vector<Pix*> ::iterator i;

	for (i = this->ptrpixm.begin(); i < this->ptrpixm.end(); i++)
	{
		(*i)->getbgcolor(blackbg, whitebg);
	}
}

void pixM::setforegroundcolor()
{
	std::vector<Pix*> ::iterator i;

	for (i = this->ptrpixm.begin(); i < this->ptrpixm.end(); i++)
	{
		(*i)->setforegroundcolor();
	}
}

