#pragma once

// Drawing to Work Area


void Animation::showhelp()
{
	double bmpheight = wah;
	double bmpwidth = (1.3)*bmpheight;

	double x = (scrw - bmpwidth) / 2;
	double y = 0;

	if (this->Help)
	{
		al_draw_scaled_bitmap(bmphelp, 0, 0, 800, 600, x, y, bmpwidth, bmpheight, 0);
	}
}



void Animation::showabout()
{
	double bmpheight = wah;
	double bmpwidth = (1.3)*bmpheight;

	double x = (scrw - bmpwidth) / 2;
	double y = 0;

	if (this->About)
	{
		al_draw_scaled_bitmap(bmpabout, 0, 0, 800, 600, x, y, bmpwidth, bmpheight, 0);
	}
}

void Animation::showaux()
{
	this->showhelp();
	this->showabout();
}


void Animation::drawAxis()
{
	if (this->Axes)
	{
	
		// X - Axis

		al_draw_line(xx(this->xmin), yy(0), xx(this->xmax), yy(0), this->xAxisColor, 2);

		// Y - Axis

		al_draw_line(xx(0), yy(this->ymin), xx(0), yy(this->ymax), this->yAxisColor, 2);

	}
}

void Animation::drawGrid()
{
	// We're using math-units by default,
	// also x=1 means a pixel-distance of "ex=x-scale" pixels.

	double x = 0, y = 0, x1 = 0, y1 = 0;

	double dx = 1;
	double dy = 1;
	
	if (this->Grid)
	{

		// Drawing vertical lines

		// Right-Quadrant
		for (x = 0; x < this->xmax; x += dx)
		{
			y = this->ymin; y1 = this->ymax;

			al_draw_line(xx(x), yy(y), xx(x), yy(y1), this->vLinesColor, 1);
		}

		// Left-Quadrant
		for (x = 0; x > this->xmin; x -= dx)
		{
			y = this->ymin; y1 = this->ymax;

			al_draw_line(xx(x), yy(y), xx(x), yy(y1), this->vLinesColor, 1);
		}

		// Drawing horizontal lines

		// Top-Quadrant
		for (y = 0; y < this->ymax; y += dy)
		{
			x = this->xmin; x1 = this->xmax;

			al_draw_line(xx(x), yy(y), xx(x1), yy(y), this->hLinesColor, 1);

		}

		// Bottom-Quadrant
		for (y = 0; y > this->ymin; y -= dy)
		{
			x = this->xmin; x1 = this->xmax;

			al_draw_line(xx(x), yy(y), xx(x1), yy(y), this->hLinesColor, 1);

		}

	}

}

void Animation::drawxlabels()
{
	//fontlabels = font;

	if (this->drawlabels && this->_drawxlabels)
	{

		double x = 0, y = 0, x1 = 0, y1 = 0;

		double dx = 1;
		double dy = 1;

		// Drawing vertical lines

		// Right-Quadrant
		for (x = 0; x < this->xmax; x += dx)
		{
			al_draw_textf(fontlabels, fontcolor, this->xx(x), this->yy(0), ALLEGRO_ALIGN_LEFT, "%.0f", x);
		}

		// Left-Quadrant
		for (x = 0; x > this->xmin; x -= dx)
		{
			al_draw_textf(fontlabels, fontcolor, this->xx(x), this->yy(0), ALLEGRO_ALIGN_LEFT, "%.0f", x);
		}

	}

}

void Animation::drawylabels()
{
	//fontlabels = font;

	double x = 0, y = 0, x1 = 0, y1 = 0;

	double dx = 1;
	double dy = 1;

	if (this->drawlabels && this->_drawylabels)
	{
		// Top-Quadrant
		for (y = 0; y < this->ymax; y += dy)
		{
			al_draw_textf(fontlabels, fontcolor, this->xx(0), this->yy(y), ALLEGRO_ALIGN_LEFT, "%.0f", y);
		}

		// Bottom-Quadrant
		for (y = 0; y > this->ymin; y -= dy)
		{
			al_draw_textf(fontlabels, fontcolor, this->xx(0), this->yy(y), ALLEGRO_ALIGN_LEFT, "%.0f", y);
		}
	}
}

void Animation::drawxylabels()
{
	this->drawxlabels();
	this->drawylabels();
}



void Animation::wadraw()
{
	this->setwabgcolor();

	this->drawGrid();

	this->drawAxis();

	this->drawxylabels();

	// Draw Elements

	this->drawelements();

	this->showaux();
}


