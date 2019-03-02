#pragma once



void pixM::setmessagecolor(ALLEGRO_COLOR messagecolor)
{
	this->messagecolor = messagecolor;
}


void pixM::drawloadingmessage()
{
	if (!this->loaded)
	{
		al_draw_textf(font, this->messagecolor, scrw/2, wah/3, ALLEGRO_ALIGN_CENTER, "LOADING INITIAL CONFIGURATION");
	}
}



void pixM::draw()
{
	this->drawloadingmessage();

	std::vector<Pix*> ::iterator i;

	for (i = this->ptrpixm.begin(); i < this->ptrpixm.end(); i++)
	{
		(*i)->draw();
	}
}


