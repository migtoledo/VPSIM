#pragma once

void Animation::setdefaultaxes()
{
	this->Axes = true;
}

void Animation::setdefaultgrid()
{
	this->Grid = true;
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
	this->ex = 30;
	this->ey = 30;
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
	this->G = 1;
	this->K = 1;
	this->drawlabels = true;
	this->_drawxlabels = true;
	this->_drawylabels = true;
	this->Help = false;
	this->About = false;

	this->darkbg = false;
	this->whitebg = true;

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
		
	istatesm1 = getistatesmndiscs(par(0, 0), par(0, 0), 10, 0, true, blue, 0.5, 1, 1, 3, par(-2,-2), par(2,2), par(4,1));
	
	// Global Matrix - Container for interacting matrices - 
	
	// Initial conditions
	
	this->_pixGlobal->setdefaults(istatesm1);
	
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

