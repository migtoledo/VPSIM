#pragma once

// TOP-RIGHT , RIGHT-TOP

void Boundary::computeTopRight()
{
	// TOP -> RIGHT

	if (this->dx > 0)
	{

		if (this->x1 > this->xmax - this->dx)
		{
			// Change v to vy < 0

			this->vy = -fabs(this->vx);

			this->vx = 0;

			this->x = this->xmax - this->l;

		}

	} // For TOP -> RIGHT
}

void Boundary::computeRightTop()
{
	// RIGHT -> TOP

	if (this->dy > 0)
	{

		if (this->y1 > this->ymax - this->dy)
		{
			// Change v to vx < 0

			this->y = this->ymax - this->l;

			this->vx = (this->vy)*(this->tsig);

			this->vy = 0;
		}

	} // For RIGHT -> TOP
}

// RIGHT-BOTTOM , BOTTOM-RIGHT

void Boundary::computeRightBottom()
{
	// RIGHT -> BOTTOM

	if (this->dy < 0)
	{

		if (this->y < this->ymin - this->dy)
		{
			// Change v to vx < 0

			this->vx = -fabs(this->vy);

			this->vy = 0;

			this->y = this->ymin;

		}

	} // For RIGHT -> BOTTOM
}

void Boundary::computeBottomRight()
{
	// BOTTOM -> RIGHT

	if (this->dx > 0)
	{

		if (this->x1 > this->xmax - this->dx)
		{
			// Change v to vy > 0

			this->x = this->xmax - this->l;

			this->vy = (this->vx)*(-this->tsig);

			this->vx = 0;



		}

	} // For BOTTOM -> RIGHT
}

// BOTTOM-LEFT , LEFT-BOTTOM

void Boundary::computeBottomLeft()
{
	// BOTTOM -> LEFT

	if (this->dx < 0)
	{

		if (this->x < this->xmin - this->dx)
		{
			// Change v to vy > 0

			this->vy = fabs(this->vx);

			this->vx = 0;

			this->x = this->xmin;

		}

	} // For BOTTOM -> LEFT
}

void Boundary::computeLeftBottom()
{
	// LEFT -> BOTTOM

	if (this->dy < 0)
	{

		if (this->y < this->ymin - this->dy)
		{
			//exit(0);
			this->y = this->ymin;

			// Change v to vx > 0

			this->vx = (this->vy)*(this->tsig);

			this->vy = 0;
		}

	} // For LEFT -> BOTTOM
}

// TOP-LEFT , LEFT-TOP

void Boundary::computeTopLeft()
{
	// TOP -> LEFT

	if (this->dx < 0)
	{

		if (this->x < this->xmin - this->dx)
		{
			//exit(0);

			this->x = this->xmin;

			// Change v to vy < 0

			this->vy = (this->vx)*(-this->tsig);

			this->vx = 0;
		}

	} // For TOP -> LEFT
}

void Boundary::computeLeftTop()
{
	// LEFT -> TOP

	if (this->dy > 0)
	{

		if (this->y1 > this->ymax - this->dy)
		{
			// Change v to vx > 0

			this->y = this->ymax - this->l;

			this->vx = (this->vy);

			this->vy = 0;
		}

	} // For RIGHT -> TOP
}


// BOUNDARY: TOP, RIGHT, BOTTOM, LEFT

void Boundary::computeTop()
{
	// TOP --------------------------------------------------

	if (this->y == this->y0)
	{
		this->computeTopLeft();

		this->computeTopRight();
	}

	// Armadillo moves on TOP-side. -----------------------------------------
}

void Boundary::computeRight()
{
	// RIGHT --------------------------------------------------

	if (this->x == this->xmax - this->l)
	{
		this->computeRightBottom();

		this->computeRightTop();

	} // Armadillo moves on RIGHT-side. -----------------------------------------

}

void Boundary::computeBottom()
{

	// BOTTOM --------------------------------------------------

	if (this->y == this->ymin)
	{

		this->computeBottomLeft();

		this->computeBottomRight();


	} // Armadillo moves on BOTTOM-side. -----------------------------------------

}

void Boundary::computeLeft()
{

	// LEFT --------------------------------------------------

	if (this->x == this->xmin)
	{

		this->computeLeftBottom();

		this->computeLeftTop();


	} // Armadillo moves on LEFT-side. -----------------------------------------

}
