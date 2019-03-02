#pragma once

// Init system
void initsystem()
{

	cout << endl;

	cout << "|---------------------------------------|" << endl;

	cout << "|.......................................|" << endl;

	cout << "|.......................................|" << endl;

	cout << "| VIRTUAL PARTICLES SIMULATOR           |" << endl;

	cout << "| v1.0                                  |" << endl;

	cout << "| Copyright (c) 2018 M. Toledo Gonzalez |" << endl;

	cout << "|.......................................|" << endl;

	cout << "|.......................................|" << endl;

	cout << "|---------------------------------------|" << endl;
		
	cout << endl;

	cout << endl;
	
	cout << "Starting system ..." << endl;

	cout << endl;

	cout << endl;
}

// Init Allegro
void initallegro()
{
	// Initialize Allegro 5
	al_init();
	// Install keyboard
	al_install_keyboard();
	// Initialize Font addons
	al_init_font_addon();
	al_init_ttf_addon();
	// Built-in font
	// font = al_create_builtin_font();
	// Initialize Primitives addon
	al_init_primitives_addon();
	// Images addon
	al_init_image_addon();
	// Initialize the timer
	timer = al_create_timer(ALLEGRO_BPS_TO_SECS(FPS));
	// Installing the mouse
	al_install_mouse();
	// Get display data
	al_get_display_mode(al_get_num_display_modes() - 1, &display_data);
	// Create the event queue
	KeyboardEventsQueue = al_create_event_queue();
	MouseEventsQueue = al_create_event_queue();
	TimerEventsQueue = al_create_event_queue();
	ScrEventsQueue = al_create_event_queue();
	// Register event sources
	// Register Display events
	//al_register_event_source(event_queue, al_get_display_event_source(display));
	// * Display is initialized later, on function "graphicsmode()"
	// Register Timer events
	al_register_event_source(TimerEventsQueue, al_get_timer_event_source(timer));
	// Register Keyboard events
	al_register_event_source(KeyboardEventsQueue, al_get_keyboard_event_source());
	// Register Mouse Events
	al_register_event_source(MouseEventsQueue, al_get_mouse_event_source());
	setscrcolors();

}

// Initialize the timer
void init_timer()
{
	// Start the timer
	al_start_timer(timer);
	// Initialize timeout
	al_init_timeout(&timeout, __timeout);
	// Differential-real-time
	dt = al_get_timer_speed(timer);
	// Differential-virtual-time
	_dt = 0;
	t0 = al_get_time();
	rt = 0;
	vt = 0;
}

