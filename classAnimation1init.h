#pragma once


void Animation::setdefaultaxes()
{
	this->Axes = false;
}

void Animation::setdefaultgrid()
{
	this->Grid = false;
}

void Animation::setdefaultcolors()
{
	this->xAxisColor = ROJO_INDIANRED;
	this->yAxisColor = ROJO_INDIANRED;

	this->hLinesColor = MARRON_CHOCOLATE;
	this->vLinesColor = VERDE_CHARTREUSE;

	wacolor = BLANCO_ALICEBLUE;	
}

void Animation::setdefaultscales()
{
	this->ex = 40;
	this->ey = 40;
	this->getexy();
}

void Animation::setconsole()
{
	this->consoletitle = "INSTANT NUMERICAL INPUT";
	this->consolemessage = "";
}


void Animation::setwabgcolor()
{
	if (this->darkbg)
	{
		wacolor = _black;
	}

	if (this->whitebg)
	{
		wacolor = _white;
	}
}

void Animation::setmessagecolor()
{
	if (this->darkbg) this->_pixGlobal->setmessagecolor(_white);
	if (this->whitebg) this->_pixGlobal->setmessagecolor(_black);
}

void Animation::setdefaultsinterface()
{
	this->G = 0.1;
	this->K = 1;
	this->drawlabels = false;
	this->_drawxlabels = false;
	this->_drawylabels = false;
	this->Help = false;
	this->About = false;

	this->darkbg = true;
	this->whitebg = false;

	this->setmessagecolor();

	this->fontcolor = text_color;
	this->setwabgcolor();
	this->setconsole();
	this->setdefaultaxes();
	this->setdefaultgrid();
	this->setdefaultcolors();
	this->setdefaultscales();
	this->setxymax();
}

void Animation::setdefaultselements()
{
	// CONFIGURATIONS
			
	
	istatesm1 = getistatesmcirc(par(-7, 0), par(200, 0), 1, -1, true, ROJO_RED, 0.1, 0.1, 2);



	istatesm2 = getistatesmrectfill(par(7, -2), par(0, 0), 100, 0, true, VERDE_GREEN, par(8, 2), 0.2, 0.2, 2);



	istatesm3 = sumnistatesm(2, istatesm1, istatesm2);

	// Global Matrix - Container for interacting matrices - 
	
	// Initial conditions
	
	this->_pixGlobal->setdefaults(istatesm3);
	
	this->updatestateelements();

	this->getidforelements();
}

void Animation::getidforelements()
{
	this->_pixGlobal->getid();
}

void Animation::setupinterface()
{
	// Animation's Interface
	this->setdefaultsinterface();
}

void Animation::setnull()
{
	
}

Animation Animation::initinterface()
{
	this->setupinterface();
	return *this;
}

