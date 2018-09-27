#pragma once


void setfont()
{
	font = fontdefault;

	if (gmode > 1)
	{
		font = fontb1;
	}

	if (gmode > 3)
	{
		font = fontb2;
	}

}

// Assings window icon for the display
void seticon()
{
	const char* filename = "iconvps.bmp";

	if (fileexist(filename))
	{
		icon = al_load_bitmap(filename);
		al_set_display_icon(display, icon);
	}
}

void drawwelcomeimage()
{
	
	ALLEGRO_BITMAP *bmp;
	const char* filename = "gplv3.bmp";
	double bmpwidth = 128; double bmpheight = 62;
	double y = (scrh - bmpheight) / 2;
	double k = vspace(1);

	if (fileexist(filename))
	{
		bmp = al_load_bitmap(filename);
		al_draw_bitmap(bmp, (scrw-bmpwidth) / 2, y+k, 0);
				
	}
	
}

void welcome()
{
	font = fontwelcome;

	scrw = al_get_display_width(display);
	scrh = al_get_display_height(display);
	
	ALLEGRO_COLOR scr_welcome_color = _white;
	ALLEGRO_COLOR scr_info_frame_color1 = VERDE_GREEN;
	ALLEGRO_COLOR scr_info_frame_color2 = AZUL_BLUE;
	
	al_clear_to_color(scr_welcome_color);
		
	// Assigns the display window title
	display_title = "VPS v1.0 - VIRTUAL PARTICLES SIMULATOR -";
	al_set_window_title(display, display_title);

	seticon();
	
	float x0 = scrw / 2;

	float Line1 = scrh / 8;
	const char* Line1Text = "V I R T U A L   P A R T I C L E S   S I M U L A T O R";
	
	float Line2 = Line1 + vspace(3);
	const char* Line2Text = "v 1.0"; 

	float Line3 = Line2 + vspace(3);
	const char* Line3Text = "C o p y r i g h t  (C)  2 0 1 8   M. T o l e d o  G o n z a l e z";


	drawwelcomeimage();
	
	
		
	float Line4 = scrh - vspace(6);
	const char* Line4Text = "License GPL v3 - Free Software Foundation - USA";

	float Line5 = Line4+vspace(2);
	const char* Line5Text = "P r e s s     a n y     k e y  ...";


	
	al_draw_text(font, _black, x0, Line1, ALLEGRO_ALIGN_CENTER, Line1Text);
	al_draw_text(font, _black, x0, Line2, ALLEGRO_ALIGN_CENTER, Line2Text);
	al_draw_text(font, _black, x0, Line3, ALLEGRO_ALIGN_CENTER, Line3Text);
	al_draw_text(font, _black, x0, Line4, ALLEGRO_ALIGN_CENTER, Line4Text);
	al_draw_text(font, _black, x0, Line5, ALLEGRO_ALIGN_CENTER, Line5Text);
		
	al_flip_display();
	
	// Fetch events

	bool _continue = false;

	while (_continue == false)
	{
		al_wait_for_event(KeyboardEventsQueue, &KeyboardEvent);

		switch (KeyboardEvent.type)
		{
			case ALLEGRO_EVENT_DISPLAY_CLOSE: 
				exit(1);

			case ALLEGRO_EVENT_DISPLAY_RESIZE:
				exit(1);

			case ALLEGRO_EVENT_KEY_DOWN:

				switch (KeyboardEvent.keyboard.keycode)
				{
					case ALLEGRO_KEY_ESCAPE:
						exit(1);

					default:
						_continue = true;
						al_clear_to_color(scrcolor);
						break;
				}
		}
	} // Continue?	

	setfont();

}

