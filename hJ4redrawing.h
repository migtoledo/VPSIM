#pragma once


void opredraw()
{
	opclean();
	al_set_target_bitmap(opbmp);

	opdraw();

	al_set_target_bitmap(al_get_backbuffer(display));
	al_draw_bitmap(opbmp, 0, 0, 0);
}


void waredraw()
{
	waclean();
	al_set_target_bitmap(wabmp);

	wadraw();

	al_set_target_bitmap(al_get_backbuffer(display));
	al_draw_bitmap(wabmp, 0, way0, 0);
}

void ipredraw()
{
	ipclean();
	al_set_target_bitmap(ipbmp);

	ipdraw();

	al_set_target_bitmap(al_get_backbuffer(display));
	al_draw_bitmap(ipbmp, 0, ipy0, 0);

}

void redrawbuffers()
{
	opredraw();
	ipredraw();
	waredraw();
}
