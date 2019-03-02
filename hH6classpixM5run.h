#pragma once

void pixM::run()
{
	if (_dt != 0)
	{
		this->computexy();
		this->dointeractions();
		this->getmass();
		this->getaveragevelocity();
		this->getcentermass();
		this->getenergy();
		this->getcentermassvelocity();
	}
}

void pixM::dointeractions()
{	
	std::vector<procPix*> ::iterator i;

	if (_dt != 0)
	{
		if (!this->ptrprocm.empty() && this->ptrprocm.size() > 0)
		{
			for (i = this->ptrprocm.begin(); i < this->ptrprocm.end(); i++)
			{
				(*i)->run();
			}
		}
	}
}

void pixM::setconstants(double G, double K)
{
	std::vector<procPix> ::iterator it;

	if (!this->procm.empty())
	{
		for (it = this->procm.begin(); it < this->procm.end(); it++)
		{
			it->setconstants(G, K);
		}
	}
}


