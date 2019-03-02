#pragma once

void pixM::getid()
{
	std::vector<Pix*> ::iterator i;

	if (!this->ptrpixm.empty())
	{
		for (i = this->ptrpixm.begin(); i < this->ptrpixm.end(); i++)
		{
			(*i)->getid();
		}
	}
}

void pixM::computexy()
{
	std::vector<Pix*> ::iterator i;

	for (i = this->ptrpixm.begin(); i < this->ptrpixm.end(); i++)
	{
		(*i)->compute_r();
	}
}
