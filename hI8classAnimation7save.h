#pragma once

boolstr Animation::savegraphic()
{

	boolstr retval;

	bmpsave = al_get_backbuffer(display);
	
	string strdate = gettimestring();

	string _filename = "image_";

	_filename = _filename + strdate + ".png";

	const char* filename = _filename.c_str();
		
	if (al_save_bitmap(filename, bmpsave))
	{
		retval.noyes = true;
		retval.txt = "File " + _filename + " saved in program's local folder";
	}
	else
	{
		retval.noyes = false;
		retval.txt = "Graphic couldn't be saved";
	}
	
	bmpsave = NULL;
	
	al_rest(0.01);

	return retval;
		
}
