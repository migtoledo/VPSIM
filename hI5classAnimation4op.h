#pragma once

// Drawing to Output Panel
void Animation::opdraw()
{
	this->getxymouse();

	// Linex XY

	float dline = vspace(2);
	float x0 = vspace(1);
	float y0 = vspace(1);
	float xc = scrw / 2;
	float xm = scrw - vspace(1);

	float Line1 = y0;
	float Line2 = Line1 + dline;
	float Line3 = Line2 + dline;
	float Line4 = Line3 + dline;
	float Line5 = Line4 + dline;
	float Line6 = Line5 + dline/1.3;

	const char* textline1 = NULL;
	const char* textline2a = NULL;
	const char* textline2b = NULL;
	const char* textline3a = NULL;
	const char* textline3b = NULL;
	const char* textline4a = NULL;
	const char* textline4b = NULL;
	const char* textline5 = NULL;
	const char* textline6 = NULL;

	switch (gmode)
	{
		// 640 x 480 (Full)
		case 1:

			textline1 = "V I R T U A L    P A R T I C L E S    S I M U L A T O R";
			textline2a = "[%.0fx%.0f] [FPS:%.0f] [T:%.2fs] [R.time:%.2fs]";
			textline2b = "[ %s ]";
			textline3a = "[dt:%.2fs] [XY-Scale (%.0fpx,%.0fpx)] [(x,y)=(%.2f,%.2f)]";
			textline3b = "[V.time:%.2f v.u.]";
			textline4a = "[Gravity Constant: %.4e v.u.]  [Electric Constant: %.4e v.u.]";
			textline4b = "";
			textline5 = "[Particles:%.0f][Processors:%.0f] [C.M.=(%.2f,%.2f)] [Temperature: %.1f t.u.]";
			textline6 = "[Planck-Length: %.2em][Planck-Time: %.2es][Bohr-Radius=%.2e Pl.U.]";

			// Line 1
			al_draw_textf(font, text_color, xc, Line1, ALLEGRO_ALIGN_CENTER, textline1);
			// Line 2a
			al_draw_textf(font, text_color, x0, Line2, ALLEGRO_ALIGN_LEFT, textline2a, scrw, scrh, FPS, dt, rt);
			// Line 2b
			al_draw_textf(font, text_color, xm, Line2, ALLEGRO_ALIGN_RIGHT, textline2b, _timeinfo);
			// Line 3a
			al_draw_textf(font, text_color, x0, Line3, ALLEGRO_ALIGN_LEFT, textline3a, _dt, this->ex, this->ey, this->xmouse, this->ymouse, vt);
			// Line 3b
			al_draw_textf(font, text_color, xm, Line3, ALLEGRO_ALIGN_RIGHT, textline3b, vt);
			// Line 4a
			al_draw_textf(font, text_color, x0, Line4, ALLEGRO_ALIGN_LEFT, textline4a, this->G, this->K);
			// Line 4b
			al_draw_textf(font, text_color, xm, Line4, ALLEGRO_ALIGN_RIGHT, textline4b, this->_pixGlobal->energy);
			// Line 5
			al_draw_textf(font, text_color, x0, Line5, ALLEGRO_ALIGN_LEFT, textline5, this->_pixGlobal->npix, this->_pixGlobal->nproc, this->_pixGlobal->cm.real(), this->_pixGlobal->cm.imag(), this->_pixGlobal->energy);
			// Line 6
			al_draw_textf(font, text_color, x0, Line6, ALLEGRO_ALIGN_LEFT, textline6, SI_PlanckLength,tPlanck, getplancklengthfromatomic(1));

			break;
			

		// 800 x 600 (Full)
		case 2:

			textline1 = "V I R T U A L     P A R T I C L E S     S I M U L A T O R";
			textline2a = "[ %.0f x %.0f ]          [ FPS: %.0f ]          [ Refresh-rate: %.3fs ]          [ Real-time: %.3fs ]";
			textline2b = "[ %s ]";
			textline3a = "[ dt: %.3fs ]  [ XY-Scale (%.0fpx, %.0fpx) ]  [ (x, y) = (%.3f, %.3f) ]  [ Virtual-time: %.3f v.u. ]  [ Gravity C. : %.2e v.u. ]  [ Electric C. : %.2e v.u. ]";
			textline3b = "";
			textline4a = "[ Particles: %.0f ]  [ Processors: %.0f ]  [ CenterMass = (%.2f, %.2f) ]  [ Temperature: %.2f t.u. ]";
			textline4b = "";
			textline5 = "[Planck-Length: %.2e m][Planck-Time: %.2e s][Bohr-Radius=%.2e Planck-Units]";
			
			// Line 1
			al_draw_textf(font, text_color, xc, Line1, ALLEGRO_ALIGN_CENTER, textline1);
			// Line 2a
			al_draw_textf(font, text_color, x0, Line2, ALLEGRO_ALIGN_LEFT, textline2a, scrw, scrh, FPS, dt, rt);
			// Line 2b
			al_draw_textf(font, text_color, xm, Line2, ALLEGRO_ALIGN_RIGHT, textline2b, _timeinfo);
			// Line 3a
			al_draw_textf(font, text_color, x0, Line3, ALLEGRO_ALIGN_LEFT, textline3a, _dt, this->ex, this->ey, this->xmouse, this->ymouse, vt, this->G, this->K);
			// Line 3b
			al_draw_textf(font, text_color, xm, Line3, ALLEGRO_ALIGN_RIGHT, textline3b);
			// Line 4a
			al_draw_textf(font, text_color, x0, Line4, ALLEGRO_ALIGN_LEFT, textline4a, this->_pixGlobal->npix, this->_pixGlobal->nproc, this->_pixGlobal->cm.real(), this->_pixGlobal->cm.imag(), this->_pixGlobal->energy);
			// Line 4b
			al_draw_textf(font, text_color, xm, Line4, ALLEGRO_ALIGN_RIGHT, textline4b);
			// Line 5
			al_draw_textf(font, text_color, x0, Line5, ALLEGRO_ALIGN_LEFT, textline5, SI_PlanckLength, tPlanck, getplancklengthfromatomic(1));

			break;

		// 800 x 600
		case 3:

			textline1 = "V I R T U A L     P A R T I C L E S     S I M U L A T O R";
			textline2a = "[ %.0f x %.0f ]          [ FPS: %.0f ]          [ Refresh-rate: %.3fs ]          [ Real-time: %.3fs ]";
			textline2b = "[ %s ]";
			textline3a = "[ dt: %.3fs ]  [ XY-Scale (%.0fpx, %.0fpx) ]  [ (x, y) = (%.3f, %.3f) ]  [ Virtual-time: %.3fs ]  [ Gravity C. : %.2e v.u. ]  [ Electric C. : %.2e v.u. ]";
			textline3b = "";
			textline4a = "[ Particles: %.0f ]  [ Processors: %.0f ]  [ CenterMass = (%.2f, %.2f) ]  [ Temperature: %.2f t.u. ]";
			textline4b = "";
			textline5 = "[Planck-Length: %.2e m][Planck-Time: %.2e s][Bohr-Radius=%.2e Planck-Units]";

			// Line 1
			al_draw_textf(font, text_color, xc, Line1, ALLEGRO_ALIGN_CENTER, textline1);
			// Line 2a
			al_draw_textf(font, text_color, x0, Line2, ALLEGRO_ALIGN_LEFT, textline2a, scrw, scrh, FPS, dt, rt);
			// Line 2b
			al_draw_textf(font, text_color, xm, Line2, ALLEGRO_ALIGN_RIGHT, textline2b, _timeinfo);
			// Line 3a
			al_draw_textf(font, text_color, x0, Line3, ALLEGRO_ALIGN_LEFT, textline3a, _dt, this->ex, this->ey, this->xmouse, this->ymouse, vt, this->G, this->K);
			// Line 3b
			al_draw_textf(font, text_color, xm, Line3, ALLEGRO_ALIGN_RIGHT, textline3b);
			// Line 4a
			al_draw_textf(font, text_color, x0, Line4, ALLEGRO_ALIGN_LEFT, textline4a, this->_pixGlobal->npix, this->_pixGlobal->nproc, this->_pixGlobal->cm.real(), this->_pixGlobal->cm.imag(), this->_pixGlobal->energy);
			// Line 4b
			al_draw_textf(font, text_color, xm, Line4, ALLEGRO_ALIGN_RIGHT, textline4b);
			// Line 5
			al_draw_textf(font, text_color, x0, Line5, ALLEGRO_ALIGN_LEFT, textline5, SI_PlanckLength, tPlanck, getplancklengthfromatomic(1));


			break;

		// 1200 x 600 
		case 4:

			textline1 = "V I R T U A L     P A R T I C L E S     S I M U L A T O R";
			textline2a = "[ %.0f x %.0f ]          [ FPS: %.0f ]          [ Refresh-rate: %.3fs ]          [ Real-time: %.3fs ]";
			textline2b = "[ %s ]";
			textline3a = "[ dt: %.3fs ] [ XY-Scale (%.0fpx, %.0fpx) ] [ (x, y) = (%.2f, %.2f) ] [ Virtual-time: %.3fs ] [ Gravity C. : %.2e v.u. ] [ Electric C. : %.2e v.u. ]";
			textline3b = "";
			textline4a = "[ Particles: %.0f ]  [ Processors: %.0f ]  [ CenterMass = (%.2f, %.2f) ]  [ Temperature: %.2f t.u. ]  [ Velocity CenterMass =  (%.2f, %.2f) ]";
			textline4b = "";
			textline5 = "[Planck-Length: %.2e m][Planck-Time: %.2e s][Bohr-Radius=%.2e Planck-Units]";

			// Line 1
			al_draw_textf(font, text_color, xc, Line1, ALLEGRO_ALIGN_CENTER, textline1);
			// Line 2a
			al_draw_textf(font, text_color, x0, Line2, ALLEGRO_ALIGN_LEFT, textline2a, scrw, scrh, FPS, dt, rt);
			// Line 2b
			al_draw_textf(font, text_color, xm, Line2, ALLEGRO_ALIGN_RIGHT, textline2b, _timeinfo);
			// Line 3a
			al_draw_textf(font, text_color, x0, Line3, ALLEGRO_ALIGN_LEFT, textline3a, _dt, this->ex, this->ey, this->xmouse, this->ymouse, vt, this->G, this->K);
			// Line 3b
			al_draw_textf(font, text_color, xm, Line3, ALLEGRO_ALIGN_RIGHT, textline3b);
			// Line 4a
			al_draw_textf(font, text_color, x0, Line4, ALLEGRO_ALIGN_LEFT, textline4a, this->_pixGlobal->npix, this->_pixGlobal->nproc, this->_pixGlobal->cm.real(), this->_pixGlobal->cm.imag(), this->_pixGlobal->energy, this->_pixGlobal->vcm.real(), this->_pixGlobal->vcm.imag());
			// Line 4b
			al_draw_textf(font, text_color, xm, Line4, ALLEGRO_ALIGN_RIGHT, textline4b);
			// Line 5
			al_draw_textf(font, text_color, x0, Line5-dline/3, ALLEGRO_ALIGN_LEFT, textline5, SI_PlanckLength, tPlanck, getplancklengthfromatomic(1));

			break;

		// 1300 x 600 
		case 5:

			textline1 = "V I R T U A L     P A R T I C L E S     S I M U L A T O R";
			textline2a = "[ %.0f x %.0f ]          [ FPS: %.0f ]          [ Refresh-rate: %.3fs ]          [ Real-time: %.3fs ]";
			textline2b = "[ %s ]";
			textline3a = "[ dt: %.3fs ] [ XY-Scale (%.0fpx, %.0fpx) ] [ (x, y) = (%.2f, %.2f) ] [ Virtual-time: %.3fs ] [ Gravity Constant: %.2e v.u. ] [ Electric Constant: %.2e v.u. ]";
			textline3b = "";
			textline4a = "[ Particles: %.0f ]  [ Processors: %.0f ]  [ CenterMass = (%.2f, %.2f) ]  [ Temperature: %.2f t.u. ]  [ Velocity CenterMass =  (%.2f, %.2f) ]";
			textline4b = "";
			textline5 = "[Planck-Length: %.2e m][Planck-Time: %.2e s][Bohr-Radius=%.2e Planck-Units]";

			// Line 1
			al_draw_textf(font, text_color, xc, Line1, ALLEGRO_ALIGN_CENTER, textline1);
			// Line 2a
			al_draw_textf(font, text_color, x0, Line2, ALLEGRO_ALIGN_LEFT, textline2a, scrw, scrh, FPS, dt, rt);
			// Line 2b
			al_draw_textf(font, text_color, xm, Line2, ALLEGRO_ALIGN_RIGHT, textline2b, _timeinfo);
			// Line 3a
			al_draw_textf(font, text_color, x0, Line3, ALLEGRO_ALIGN_LEFT, textline3a, _dt, this->ex, this->ey, this->xmouse, this->ymouse, vt, this->G, this->K);
			// Line 3b
			al_draw_textf(font, text_color, xm, Line3, ALLEGRO_ALIGN_RIGHT, textline3b);
			// Line 4a
			al_draw_textf(font, text_color, x0, Line4, ALLEGRO_ALIGN_LEFT, textline4a, this->_pixGlobal->npix, this->_pixGlobal->nproc, this->_pixGlobal->cm.real(), this->_pixGlobal->cm.imag(), this->_pixGlobal->energy, this->_pixGlobal->vcm.real(), this->_pixGlobal->vcm.imag());
			// Line 4b
			al_draw_textf(font, text_color, xm, Line4, ALLEGRO_ALIGN_RIGHT, textline4b);
			// Line 5
			al_draw_textf(font, text_color, x0, Line5-dline/3, ALLEGRO_ALIGN_LEFT, textline5, SI_PlanckLength, tPlanck, getplancklengthfromatomic(1));
			
			break;

		// Full screen 
		case 6:

			textline1 = "V I R T U A L     P A R T I C L E S     S I M U L A T O R";
			textline2a = "[ %.0f x %.0f ]          [ FPS: %.0f ]          [ Refresh-rate: %.3fs ]          [ Real-time: %.3fs ]";
			textline2b = "[ %s ]";
			textline3a = "[ dt: %.3fs ] [ XY-Scale (%.0fpx, %.0fpx) ] [ (x, y) = (%.2f, %.2f) ] [ Virtual-time: %.3fs ] [ Gravity Constant: %.2e v.u. ] [ Electric Constant: %.2e v.u. ]";
			textline3b = "";
			textline4a = "[ Particles: %.0f ]  [ Processors: %.0f ]  [ CenterMass = (%.2f, %.2f) ]  [ Temperature: %.2f t.u. ]  [ Velocity CenterMass =  (%.2f, %.2f) ]";
			textline4b = "";
			textline5 = "[Planck-Length: %.2e m][Planck-Time: %.2e s][Bohr-Radius=%.2e Planck-Units]";

			// Line 1
			al_draw_textf(font, text_color, xc, Line1, ALLEGRO_ALIGN_CENTER, textline1);
			// Line 2a
			al_draw_textf(font, text_color, x0, Line2, ALLEGRO_ALIGN_LEFT, textline2a, scrw, scrh, FPS, dt, rt);
			// Line 2b
			al_draw_textf(font, text_color, xm, Line2, ALLEGRO_ALIGN_RIGHT, textline2b, _timeinfo);
			// Line 3a
			al_draw_textf(font, text_color, x0, Line3, ALLEGRO_ALIGN_LEFT, textline3a, _dt, this->ex, this->ey, this->xmouse, this->ymouse, vt, this->G, this->K);
			// Line 3b
			al_draw_textf(font, text_color, xm, Line3, ALLEGRO_ALIGN_RIGHT, textline3b);
			// Line 4a
			al_draw_textf(font, text_color, x0, Line4, ALLEGRO_ALIGN_LEFT, textline4a, this->_pixGlobal->npix, this->_pixGlobal->nproc, this->_pixGlobal->cm.real(), this->_pixGlobal->cm.imag(), this->_pixGlobal->energy, this->_pixGlobal->vcm.real(), this->_pixGlobal->vcm.imag()) ;
			// Line 4b
			al_draw_textf(font, text_color, xm, Line4, ALLEGRO_ALIGN_RIGHT, textline4b);
			// Line 5
			al_draw_textf(font, text_color, x0, Line5-dline/3, ALLEGRO_ALIGN_LEFT, textline5, SI_PlanckLength, tPlanck, getplancklengthfromatomic(1));
			
			break;
			
		default:

			textline1 = "V I R T U A L    P A R T I C L E S    S I M U L A T O R";
			textline2a = "[%.0fx%.0f] [FPS:%.0f] [T:%.2fs] [R.time:%.2fs]";
			textline2b = "[ %s ]";
			textline3a = "[dt:%.2fs] [XY-Scale (%.0fpx,%.0fpx)] [(x,y)=(%.2f,%.2f)]";
			textline3b = "[V.time:%.2fs]";
			textline4a = "[Gravity Constant: %.2f v.u.]  [Electric Constant: %.2f v.u.]";
			textline4b = "";
			textline5 = "[Particles: %.0f] [Processors: %.0f] [CenterMass=(%.2f,%.2f)] [Temperature: %.4f t.u.]";
			textline6 = "[Planck-Length: %.2em][Planck-Time: %.2es][Bohr-Radius=%.2e Pl.U.]";

			// Line 1
			al_draw_textf(font, text_color, xc, Line1, ALLEGRO_ALIGN_CENTER, textline1);
			// Line 2a
			al_draw_textf(font, text_color, x0, Line2, ALLEGRO_ALIGN_LEFT, textline2a, scrw, scrh, FPS, dt, rt);
			// Line 2b
			al_draw_textf(font, text_color, xm, Line2, ALLEGRO_ALIGN_RIGHT, textline2b, _timeinfo);
			// Line 3a
			al_draw_textf(font, text_color, x0, Line3, ALLEGRO_ALIGN_LEFT, textline3a, _dt, this->ex, this->ey, this->xmouse, this->ymouse, vt);
			// Line 3b
			al_draw_textf(font, text_color, xm, Line3, ALLEGRO_ALIGN_RIGHT, textline3b, vt);
			// Line 4a
			al_draw_textf(font, text_color, x0, Line4, ALLEGRO_ALIGN_LEFT, textline4a, this->G, this->K);
			// Line 4b
			al_draw_textf(font, text_color, xm, Line4, ALLEGRO_ALIGN_RIGHT, textline4b, this->_pixGlobal->energy);
			// Line 5
			al_draw_textf(font, text_color, x0, Line5, ALLEGRO_ALIGN_LEFT, textline5, this->_pixGlobal->npix, this->_pixGlobal->nproc, this->_pixGlobal->cm.real(), this->_pixGlobal->cm.imag(), this->_pixGlobal->energy);
			// Line 6
			al_draw_textf(font, text_color, x0, Line6, ALLEGRO_ALIGN_LEFT, textline6, SI_PlanckLength, tPlanck, getplancklengthfromatomic(1));
			
			break;
	}
	
	
	// Calculates correctly the number of processors:
	// For matrix = 8 x 8 = 64 particles, loads C(64,2)=2016 processors [Binomial coefficient]
}

