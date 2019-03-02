#pragma once

void gethr()
{
	hr = 0.5;

	if (scrh > 500) hr = 0.50;

	if (scrh > 600) hr = 0.60;

	if (scrh > 700) hr = 0.60;
}

void scr_info()
{
	font = fontscrinfo;

	double trest = 2;
	
	ALLEGRO_COLOR scr_info_color = _white;
	
	al_clear_to_color(scr_info_color);

	float x0 = scrw / 2;
	float y0 = scrh / 4;
	
	const char* message = "GRAPHICS RESOLUTION = %.0f x %.0f";
	
	al_draw_textf(font, _black, x0, y0, ALLEGRO_ALIGN_CENTER, message, scrw, scrh);

	gethr();

	al_set_window_position(display, 0, 0);

	al_flip_display();

	al_rest(trest);
}

void loadfonts()
{
	fontdefault = al_create_builtin_font();
	
	const char* fntscrinfo = "font2.ttf";

	const char* fntwelcome = "font1.ttf";

	const char* bfonts = "font2.ttf";

	const char* fntlabels = "font3.ttf";
	
	(fileexist(fntscrinfo)) ? 
		fontscrinfo = al_load_font(fntscrinfo, 24, 1) : fontscrinfo = fontdefault;

	(fileexist(fntwelcome)) ?
		fontwelcome = al_load_font(fntwelcome, 24, 1) : fontwelcome = fontdefault;

	(fileexist(bfonts)) ?
		fontb1 = al_load_font(bfonts, 12, 1) : fontb1= fontdefault;

	(fileexist(bfonts)) ?
		fontb2 = al_load_font(bfonts, 18, 1) : fontb2 = fontdefault;

	(fileexist(fntlabels)) ?
		fontlabels = al_load_font(fntlabels, 12, 1) : fontlabels = fontb1;
	
}

void graphicsmode(int option)
{
	switch (option)
	{
		case 1:
			scrw = 640; scrh = 480; break;

		case 2:
			scrw = 800; scrh = 600; break;

		case 3:
			scrw = 800; scrh = 600; break;

		case 4:
			scrw = 1200; scrh = 600; break;

		case 5:
			scrw = 1300; scrh = 600; break;

		case 6:
			scrw = display_data.width; 
			scrh = display_data.height;
			break;
		// If no graphics mode selected, end of program!
		default:
			exit(0);
	}
	
	// Makes a display
	al_set_new_display_option(ALLEGRO_COLOR_SIZE, COLORDEPTH, ALLEGRO_REQUIRE);
	if (option == 6) al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	if (option == 1 || option==2) al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	display = al_create_display(scrw, scrh);
	al_set_window_position(display, 0, 0);
	// font = al_create_builtin_font();
	loadfonts();
	// Register display events
	al_register_event_source(ScrEventsQueue, al_get_display_event_source(display));
	// Cleans the display
	al_clear_to_color(scrcolor);

	scr_info();
		
}
