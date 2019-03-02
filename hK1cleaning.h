#pragma once


// Clean up
void cleanup()
{
	scrclean();
	al_draw_text(font, VERDE_GREEN, ox, scrh / 2, 0, "Exiting ...");
	al_flip_display();
	al_rest(1);
	al_destroy_display(display);
	al_destroy_event_queue(KeyboardEventsQueue);
	al_destroy_event_queue(MouseEventsQueue);
	al_destroy_event_queue(TimerEventsQueue);
	al_destroy_event_queue(ScrEventsQueue);
	al_destroy_bitmap(opbmp);
	al_destroy_bitmap(wabmp);
	al_destroy_bitmap(ipbmp);
	al_destroy_bitmap(bmphelp);
	al_destroy_bitmap(bmpabout);
	al_destroy_bitmap(bmpsave);
	delete _Anim;
}