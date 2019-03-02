#pragma once

void doactionsMouseEvents(bool _EventosMouse)
{
	if (_EventosMouse)
	{
		switch (MouseEvent.type)
		{
			case ALLEGRO_EVENT_MOUSE_AXES:
				xxmouse = MouseEvent.mouse.x;
				yymouse = MouseEvent.mouse.y;
				break;
		}
	}
}

void doactionsTimerEvents(bool _EventosTimer)
{
	if (_EventosTimer)
	{
		switch (TimerEvent.type)
		{
			case ALLEGRO_EVENT_TIMER:
				redraw = true;
				ticks++;
				rt = al_get_time() - t0;
				vt = vt + _dt;
				_Armadillo->updatexy();
				if (ticks == ticksforloading) _Anim->setdefaultselements();
				_Anim->runelements();
				break;
		}
		
		// Check if we need to redraw

		if (redraw)
		{
			// Resetting draw:
			redraw = false;
			// Redrawing: Clean, Draw, and Copy to screen			
			redrawbuffers();
			al_flip_display();
		}
	}
}

void doactionsScrEvents(bool _EventosPantalla)
{
	// Handle events
	if (_EventosPantalla)
	{
		switch (ScrEvent.type)
		{
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				exit(0);
				running = false;
				break;
		}
	}
}


void doactionsKeyboardEvents(bool _EventosTeclado)
{
	// Handle events
	if (_EventosTeclado)
	{
		switch (KeyboardEvent.type)
		{
		

		//case ALLEGRO_EVENT_DISPLAY_CLOSE:
			//exit(0);
			//running = false;
			//al_flush_event_queue(event_queue);
			//break;

		

		case ALLEGRO_EVENT_KEY_DOWN:
			switch (KeyboardEvent.keyboard.keycode)
			{
				// Numerical User Input: Listener

			case ALLEGRO_KEY_0:
				c = '0';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_PAD_0:
				c = '0';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_1:
				c = '1';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_PAD_1:
				c = '1';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_2:
				c = '2';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_PAD_2:
				c = '2';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_3:
				c = '3';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);

				break;

			case ALLEGRO_KEY_PAD_3:
				c = '3';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_4:
				c = '4';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_PAD_4:
				c = '4';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_5:
				c = '5';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_PAD_5:
				c = '5';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_6:
				c = '6';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_PAD_6:
				c = '6';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_7:
				c = '7';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_PAD_7:
				c = '7';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_8:
				c = '8';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_PAD_8:
				c = '8';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_9:
				c = '9';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_PAD_9:
				c = '9';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_COMMA:
				c = '.';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_FULLSTOP:
				c = '.';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_MINUS:
				c = '-';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

			case ALLEGRO_KEY_PAD_MINUS:
				c = '-';
				txtinput.push_back(c);
				cstring = new char[txtinput.size()];
				std::copy(txtinput.begin(), txtinput.end(), cstring);
				_cstring = cstring;
				_Anim->input = atof(_cstring);
				break;

				/// General Control Inputs: Buttons ///

				// BUTTONS-LINE 1

				// RUN = R
			case ALLEGRO_KEY_R:
				buttons[R] = true;
				break;

				// BACKWARDS = B
			case ALLEGRO_KEY_B:
				buttons[B] = true;
				break;

				// PAUSE = P
			case ALLEGRO_KEY_P:
				buttons[P] = true;
				break;

				// STOP = S
			case ALLEGRO_KEY_S:
				buttons[S] = true;
				al_flush_event_queue(KeyboardEventsQueue);
				break;

				// HELP = H
			case ALLEGRO_KEY_H:
				buttons[H] = true;
				break;

				// ABOUT = O
			case ALLEGRO_KEY_O:
				buttons[O] = true;
				break;

				// CLEAR = C
			case ALLEGRO_KEY_C:
				buttons[C] = true;
				break;

				// QUIT = ESC
			case ALLEGRO_KEY_ESCAPE:
				running = false;
				break;

				// BUTTONS-LINE 2

				// RESET = E
			case ALLEGRO_KEY_E:
				buttons[E] = true;
				break;

				// SET ELECTRIC CONSTANT = K
			case ALLEGRO_KEY_K:
				buttons[K] = true;
				break;


				// SHOW/HIDE AXES = A
			case ALLEGRO_KEY_A:
				buttons[A] = true;
				break;

				// SHOW/HIDE GRID = G
			case ALLEGRO_KEY_G:
				buttons[G] = true;
				break;

				// X-SCALE = X
			case ALLEGRO_KEY_X:
				buttons[X] = true;
				break;

				// Y-SCALE = Y
			case ALLEGRO_KEY_Y:
				buttons[Y] = true;
				break;

				// BUTTONS-LINE 3

				// DARK = D
			case ALLEGRO_KEY_D:
				buttons[D] = true;
				break;

				// WHITE = W
			case ALLEGRO_KEY_W:
				buttons[W] = true;
				break;

				// SET GRAVITY = F
			case ALLEGRO_KEY_F:
				buttons[F] = true;
				break;


				// LABELS = L
			case ALLEGRO_KEY_L:
				buttons[L] = true;
				break;

				// SAVE = V
			case ALLEGRO_KEY_V:
				buttons[V] = true;
				break;

			}

			// SCOPE: EVENT KEY DOWN
			buttonactions();

			// KEY UP: RESTORING BUTTONS-STATE

		case ALLEGRO_EVENT_KEY_UP:

			switch (KeyboardEvent.keyboard.keycode)
			{

				// BUTTONS LINE 1

			case ALLEGRO_KEY_ESCAPE:
				running = false;
				break;

				// RUN = R
			case ALLEGRO_KEY_R:
				buttons[R] = false;
				break;

				// BACKWARDS = B
			case ALLEGRO_KEY_B:
				buttons[B] = false;
				break;

				// PAUSE = P
			case ALLEGRO_KEY_P:
				buttons[P] = false;
				break;

				// STOP = S
			case ALLEGRO_KEY_S:
				buttons[S] = false;
				break;

				// HELP = H
			case ALLEGRO_KEY_H:
				buttons[H] = false;
				break;

				// ABOUT = O
			case ALLEGRO_KEY_O:
				buttons[O] = false;
				break;

				// CLEAR = C
			case ALLEGRO_KEY_C:
				buttons[C] = false;
				break;

				// BUTTONS-LINE 2

				// RESET = E
			case ALLEGRO_KEY_E:
				buttons[E] = false;
				break;

				// SET ELECTRIC CONSTANT = K
			case ALLEGRO_KEY_K:
				buttons[K] = false;
				break;

				// SHOW/HIDE AXES = A
			case ALLEGRO_KEY_A:
				buttons[A] = false;
				break;

				// SHOW/HIDE GRID = G
			case ALLEGRO_KEY_G:
				buttons[G] = false;
				break;

				// X-SCALE = X
			case ALLEGRO_KEY_X:
				buttons[X] = false;
				break;

				// Y-SCALE = Y
			case ALLEGRO_KEY_Y:
				buttons[Y] = false;
				break;

				// BUTTONS-LINE 3

				// DARK = D
			case ALLEGRO_KEY_D:
				buttons[D] = false;
				break;

				// WHITE = W
			case ALLEGRO_KEY_W:
				buttons[W] = false;
				break;

				// SET GRAVITY = F
			case ALLEGRO_KEY_F:
				buttons[F] = false;
				break;

				// LABELS = L
			case ALLEGRO_KEY_L:
				buttons[L] = false;
				break;

				// SAVE = V
			case ALLEGRO_KEY_V:
				buttons[V] = false;
				break;
			}
		}
	}
}
