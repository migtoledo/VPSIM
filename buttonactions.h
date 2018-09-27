#pragma once


// Buttons

/*

LINE 1

R = RUN
B = BACKWARDS
P = PAUSE
S = STOP
H = HELP
O = ABOUT
C = CLEAR
ESC = QUIT *

LINE 2

E = RESET
A = SHOW / HIDE AXES
G = SHOW / HIDE GRID
X = CHANGE X-SCALE
Y = CHANGE Y-SCALE

LINE 3

D = DARK BACKGROUND
W = WHITE BACKGROUND
L = LABELS XY
V = SAVE GRAPHIC

*/

// BUTTONS LINE 1

// R = RUN
void button_run_R()
{
	double tmp = 0;

	if (buttons[R])
	{
		if (_Anim->Help == false && _Anim->About == false)
		{
			if (_dt == 0 && _last_dt != 0)
			{
				_dt = _last_dt;
			}
			else
			{				
				_dt = dt;
			}
			_Anim->consolemessage = "Animation running";
		}
	}

}

// B = BACKWARDS
void button_backwards_B()
{
	if (buttons[B])
	{
		if (_dt == 0 && _last_dt != 0)
		{
			_dt = -_last_dt;
		}
		else
		{
			_dt = -_dt;
		}
		_Anim->consolemessage = "Virtual time-signature reversed";
	}
}

// P = PAUSE
void button_pause_P()
{
	if (buttons[P])
	{
		if (_dt != 0)
		{
			_last_dt = _dt;
			_dt = 0;
			_t0 = vt;
			_Anim->consolemessage = "Animation paused";
		}
		else
		{
			_dt = _last_dt;
			_Anim->consolemessage = "Animation re-running";
		}
		
	}
}

// S = STOP
void button_stop_S()
{
	if (buttons[S])
	{
		_dt = 0;
		_last_dt = 0;
		vt = 0;
		_t0 = 0;
		
		_Armadillo->setup();
		_Anim->setdefaultselements();
		_Anim->consolemessage = "Animation stopped";
	}
}

// H = HELP
void button_help_H()
{
	if (buttons[H])
	{
		_Anim->Help = true;
		if (_dt != 0)
		{
			_last_dt = _dt;
			_dt = 0;
			_t0 = vt;
			_Anim->consolemessage = "Showing Help. Animation paused.";
		}	
	}
}

// O = ABOUT
void button_about_O()
{
	if (buttons[O])
	{
		_Anim->About = true;
		if (_dt != 0)
		{
			_last_dt = _dt;
			_dt = 0;
			_t0 = vt;
			_Anim->consolemessage = "Showing About. Animation paused.";
		}
	}
}

// C = CLEAR
void button_clear_C()
{
	if (buttons[C])
	{
		_Anim->Help = false;
		_Anim->About = false;

		txtinput.clear();
		_Anim->input = 0;
		_Anim->consolemessage = "Input cleared";

		if (_dt == 0 && _last_dt != 0)
		{
			_dt = _last_dt;
			_Anim->consolemessage = "Animation re-running";
		}
	}
}

// BUTTONS LINE 2

// E = RESET
void button_reset_E()
{
	if (buttons[E])
	{
		_dt = 0;
		_last_dt = 0;
		vt = 0;
		_t0 = 0;

		_Armadillo->setdefaults();
		_Anim->setdefaultsinterface();
		_Anim->setdefaultselements();
		_Anim->consolemessage = "Reset to defaults";
	}
}

// K = SET ELECTRIC CONSTANT
void button_set_elect_K()
{
	if (buttons[K])
	{
		_Anim->tmp = _Anim->input;
		_Anim->setelectrick(_Anim->input);
		_Anim->consolemessage = "Electric Constant Set To %.8f virtual units";
		txtinput.clear();
		_Anim->input = 0;
	}
}



// A = SHOW/HIDE AXES
void button_axes_A()
{
	if (buttons[A])
	{
		_Anim->Axes = !_Anim->Axes;
	}
}


// G = GRID
void button_grid_G()
{
	if (buttons[G])
	{
		_Anim->Grid = !_Anim->Grid;
	}
}


// X = X-SCALE
void button_xscale_X()
{
	if (buttons[X])
	{
		_Anim->drawlabels = false;
		_Anim->tmp=_Anim->input;
		_Anim->setXscale(_Anim->input);
		_Anim->consolemessage = "X-Scale Changed to %.0f px/unit";
		if(_Anim->input==0) _Anim->consolemessage = "X-Scale Cannot be %.0f px/unit";
		if (_Anim->input< 0) _Anim->consolemessage = "X-Scale Cannot be < 0";
		txtinput.clear();
		_Anim->input = 0;
	}
}

// Y = Y-SCALE
void button_yscale_Y()
{
	if (buttons[Y])
	{
		_Anim->drawlabels = false;
		_Anim->tmp = _Anim->input;
		_Anim->setYscale(_Anim->input);
		_Anim->consolemessage = "Y-Scale Changed to %.0f px/unit";
		if (_Anim->input == 0) _Anim->consolemessage = "Y-Scale Cannot be %.0f px/unit";
		if (_Anim->input< 0) _Anim->consolemessage = "Y-Scale Cannot be < 0";
		txtinput.clear();
		_Anim->input = 0;
	}
}

// BUTTONS LINE 3

// D = DARK

void button_darkbg()
{
	if (buttons[D])
	{
		_Anim->darkbg = true;
		_Anim->whitebg = false;
		_Anim->setwabgcolor();
		_Anim->fontcolor = AMARILLO_YELLOW;
		_Anim->consolemessage = "Set Black-Background";	
	}
}

// W = WHITE

void button_whitebg()
{
	if (buttons[W])
	{
		_Anim->darkbg = false;
		_Anim->whitebg = true;
		_Anim->setwabgcolor();
		_Anim->fontcolor = AZUL_BLUE;
		_Anim->consolemessage = "Set White-Background";
	}
}

// F = SET GRAVITY CONSTANT
void button_set_gravity_F()
{
	if (buttons[F])
	{
		_Anim->tmp = _Anim->input;
		_Anim->setgravity(_Anim->input);
		_Anim->consolemessage = "Gravity Constant Set To %.8f virtual units";
		txtinput.clear();
		_Anim->input = 0;
	}
}


// L = LABELS

void button_labels()
{
	if (buttons[L])
	{
		_Anim->drawlabels = !_Anim->drawlabels;

		if (_Anim->darkbg) _Anim->fontcolor = AMARILLO_YELLOW;
		if (_Anim->whitebg) _Anim->fontcolor = AZUL_BLUE;

		(_Anim->ex > vspace(2) ) ?
			_Anim->_drawxlabels = true : _Anim->_drawxlabels = false;

		(_Anim->ey > vspace(2)) ?
			_Anim->_drawylabels = true : _Anim->_drawylabels = false;

		if(!_Anim->_drawxlabels) _Anim->consolemessage = "Scale too small for labels";
		
		if (!_Anim->_drawylabels) _Anim->consolemessage = "Scale too small for labels";

		if (_Anim->drawlabels && _Anim->_drawxlabels)
			_Anim->consolemessage = "Showing X labels";

		if (_Anim->drawlabels && _Anim->_drawylabels)
			_Anim->consolemessage = "Showing Y labels";

		if (_Anim->drawlabels && _Anim->_drawxlabels && _Anim->_drawylabels) 
			_Anim->consolemessage = "Showing XY labels";

		if (_Anim->consolemessage == "Showing XY labels" && _Anim->drawlabels == false)
			_Anim->consolemessage = "";
	}
}

// V = SAVE

void button_save()
{
	boolstr tmp;
	tmp.noyes = false;
	tmp.txt = "";

	if (buttons[V])
	{
		tmp=_Anim->savegraphic();
			
		if (tmp.noyes)
		{
			_Anim->consolemessage = "Graphic saved as PNG file in local program's folder";			
		}
		else
		{
			_Anim->consolemessage = "Graphic couldn't be saved";
		}
	}
}

void buttonactions()
{
	// BUTTONS LINE 1

	button_run_R();

	button_backwards_B();

	button_pause_P();

	button_stop_S();

	button_help_H();

	button_about_O();

	button_clear_C();
	
	// BUTTONS LINE 2

	button_reset_E();

	button_set_elect_K();

	button_axes_A();

	button_grid_G();

	button_xscale_X();

	button_yscale_Y();

	// BUTTONS LINE 3

	button_darkbg();

	button_whitebg();

	button_set_gravity_F();

	button_labels();

	button_save();

	al_flush_event_queue(KeyboardEventsQueue);
}
