#pragma once

// Drawing to Input Panel

void Animation::drawConsole()
{
	// Text Lines
	
	float k0 = 0;
	float k1 = 1; 
	float k2 = 1;
	float k3 = 1;
	float k4 = 1;
	
	float x0;
	float xc;
	float Line1_TitleConsole;
	float Line2_MessageConsole;
	float Line3_Inputs;
	
	if (gmode == 1) { k0 = 5; k1 = 0.5; k2 = 0.6; k3 = 1; k4 = 1; }
	if (gmode == 2) { k0 = 9; k1 = 0; k2 = 1.4; k3 = 2; k4 = 2; }
	if (gmode == 3) { k0 = 9; k1 = 0; k2 = 1.4; k3 = 2; k4 = 2; }
	if (gmode == 4) { k0 = 5; k1 = 0; k2 = 1.4; k3 = 1; k4 = 1; }
	if (gmode == 5) { k0 = 5; k1 = 0; k2 = 1.4; k3 = 1; k4 = 1; }
	if (gmode == 6) { k0 = 5; k1 = 0; k2 = 1.4; k3 = 1; k4 = 1; }

	x0 = vspace(1);
	xc = scrw / 2;

	Line1_TitleConsole = iph - vspace(k0);

	Line2_MessageConsole = Line1_TitleConsole + vspace(k3);

	Line3_Inputs = Line2_MessageConsole + vspace(k4);
		
	al_draw_filled_rectangle(vspace(1), Line1_TitleConsole-vspace(k1), scrw-vspace(1), Line1_TitleConsole + vspace(k2), AZUL_BLUE);
	
	al_draw_textf(font, text_color, xc, Line1_TitleConsole, ALLEGRO_ALIGN_CENTER, this->consoletitle);
	
	al_draw_textf(font, text_color, x0, Line2_MessageConsole, ALLEGRO_ALIGN_LEFT, this->consolemessage, this->tmp);

	al_draw_textf(font, text_color, x0, Line3_Inputs, ALLEGRO_ALIGN_LEFT, "Input=%.8f", this->input);

	al_draw_textf(font, text_color, scrw-vspace(1), Line3_Inputs, ALLEGRO_ALIGN_RIGHT, "Float decimals: . = , ");

}

void Animation::drawButtons()
{
	// Lines XY

	float k = 1;

	switch (gmode)
	{
		case 1: // 640 x 480 (Full)
			k = 2;
			break;

		case 2: // 800 x 600 (Full)
			k = 2;
			break;

		case 3: // 800 x 600 
			k = 2;
			break;

		case 4: // 1200 x 600
			k = 1.3;
			break;

		case 5: // 1300 x 600
			k = 1.3;
			break;

		case 6: // Full screen
			k = 1.4;
			break;

		default:
			k = 1;
			break;
	}

	float dline = vspace(1);
	float x0 = dline; float y0 = dline;
	float xc = scrw / 2;
	
	float Line1 = 0.5*dline;
	float Line2 = Line1 + k * dline;
	float Line3 = Line2 + k * dline;
	
	// Text Lines
		
	const char* txtline1=NULL;
	const char* txtline2=NULL;
	const char* txtline3=NULL;

	switch (gmode)
	{
		case 1: // 640 x 480 (Full)
			txtline1 = "[RUN=R] [BACKWARDS=B] [PAUSE=P] [STOP=S] [HELP=H] [ABOUT=O] [CLEAR=C] [QUIT=ESC]";
			txtline2 = "[RESET=E] [SET ELECTRIC CONSTANT=K] [AXES=A] [GRID=G]  [X-SCALE=X] [Y-SCALE=Y]";
			txtline3 = "[DARK BG=D] [WHITE BG=W] [SET GRAVITY=F] [SHOW/HIDE LABELS=L] [SAVE GRAPHIC=V]";
			break;

		case 2: // 800 x 600 (Full)
			txtline1 = "[ RUN = R ]        [ BACKWARDS = B ]        [ PAUSE = P ]        [ STOP = S ]        [ HELP = H ]        [ ABOUT = O ]        [ CLEAR = C ]      [ QUIT = ESC ]";
			txtline2 = "[ RESET = E ]   [ SET ELECTRIC CONSTANT = K ]   [ SHOW/H. AXES = A ]    [ SHOW/H. GRID = G ]   [ NEW X-SCALE = X ]    [ NEW Y-SCALE = Y ]";
			txtline3 = "[ DARK BACKGROUND = D ]    [ WHITE BACKGROUND = W ]   [ SET GRAVITY = F ]    [ SHOW/HIDE LABELS = L ]      [ SAVE GRAPHIC = V ]";
			break;

		case 3: // 800 x 600 (Full)
			txtline1 = "[ RUN = R ]        [ BACKWARDS = B ]        [ PAUSE = P ]        [ STOP = S ]        [ HELP = H ]        [ ABOUT = O ]        [ CLEAR = C ]      [ QUIT = ESC ]";
			txtline2 = "[ RESET = E ]  [SET ELECTRIC CONSTANT=K]    [ SHOW/HIDE AXES = A ]    [ SHOW/HIDE GRID = G ]     [ NEW X-SCALE = X ]      [ NEW Y-SCALE = Y ]";
			txtline3 = "[ DARK BACKGROUND = D ]      [ WHITE BACKGROUND = W ]     [ SET GRAVITY=F ]    [ SHOW/HIDE LABELS = L ]      [ SAVE GRAPHIC = V ]";
			break;

		case 4: // 1200 x 600
			txtline1 = "[ RUN = R ]       [ BACKWARDS = B ]       [ PAUSE = P ]       [ STOP = S ]       [ HELP = H ]       [ ABOUT = O ]       [ CLEAR = C ]     [ QUIT = ESC ]";
			txtline2 = "[ RESET = E ]   [ SET ELECTRIC CONSTANT = K ]   [ SHOW/H. AXES = A ]   [ SHOW/H. GRID = G ]   [ X-SCALE = X ]   [ Y-SCALE = Y ]";
			txtline3 = "[ DARK BACKGROUND = D ]    [ WHITE BACKGROUND = W ]    [ SET GRAVITY = F ]    [ SHOW/HIDE LABELS = L ]    [ SAVE GRAPHIC = V ]";
			break;

		case 5: // 1300 x 600
			txtline1 = "[ RUN = R ]       [ BACKWARDS = B ]       [ PAUSE = P ]       [ STOP = S ]       [ HELP = H ]       [ ABOUT = O ]       [ CLEAR = C ]     [ QUIT = ESC ]";
			txtline2 = "[ RESET = E ]   [ SET ELECTRIC CONSTANT = K ]   [ SHOW/H. AXES = A ]   [ SHOW/H. GRID = G ]   [ X-SCALE = X ]   [ Y-SCALE = Y ]";
			txtline3 = "[ DARK BACKGROUND = D ]    [ WHITE BACKGROUND = W ]    [ SET GRAVITY = F ]    [ SHOW/HIDE LABELS = L ]    [ SAVE GRAPHIC = V ]";
			break;

		case 6: // Full screen
			txtline1 = "[ RUN = R ]       [ BACKWARDS = B ]       [ PAUSE = P ]       [ STOP = S ]       [ HELP = H ]       [ ABOUT = O ]       [ CLEAR = C ]     [ QUIT = ESC ]";
			txtline2 = "[ RESET = E ]   [ SET ELECTRIC CONSTANT = K ]   [ SHOW/HIDE AXES = A ]   [ SHOW/HIDE GRID = G ]   [ X-SCALE = X ]   [ Y-SCALE = Y ]";
			txtline3 = "[ DARK BACKGROUND = D ]    [ WHITE BACKGROUND = W ]    [ SET GRAVITY = F ]    [ SHOW/HIDE LABELS = L ]    [ SAVE GRAPHIC = V ]";
			break;

		default:
			txtline1 = "[RUN=R] [BACKWARDS=B] [PAUSE=P] [STOP=S] [HELP=H] [ABOUT=O] [CLEAR=C] [QUIT=ESC]";
			txtline2 = "[RESET=E][SET ELECT.C.=K][SHOW/H. AXES=A][SHOW/H. GRID=G][X-SCALE=X][Y-SCALE=Y]";
			txtline3 = "[DARK BG=D] [WHITE BG=W] [SET GRAVITY=F] [SHOW/HIDE LABELS=L] [SAVE GRAPHIC=V]";
			break;
	}
	
	// Line 1

	al_draw_textf(font, text_color, xc, Line1, ALLEGRO_ALIGN_CENTER, txtline1);

	// Line 2

	al_draw_textf(font, text_color, xc, Line2, ALLEGRO_ALIGN_CENTER, txtline2);

	// Line 3

	al_draw_textf(font, text_color, xc, Line3, ALLEGRO_ALIGN_CENTER, txtline3);

}

void Animation::ipdraw()
{
	this->drawButtons();

	this->drawConsole();
}

