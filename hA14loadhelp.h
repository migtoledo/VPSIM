#pragma once

ALLEGRO_BITMAP *bmphelp;
ALLEGRO_BITMAP *bmpabout;

void loadhelp()
{
	const char* filename = "help.bmp";
	
	if (fileexist(filename))
	{
		bmphelp = al_load_bitmap(filename);
	}

}

void loadabout()
{
	const char* filename = "about.bmp";

	if (fileexist(filename))
	{
		bmpabout = al_load_bitmap(filename);
	}

}

void loadauxbmps()
{
	loadhelp();
	loadabout();
}
