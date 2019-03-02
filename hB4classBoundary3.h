#pragma once


void Boundary::updatexy()
{
	this->computevxy();
	this->computexy();
}

void Boundary::computevxy()
{

	this->gettsig();

	this->computeTop();

	this->computeRight();

	this->computeBottom();

	this->computeLeft();

}

void Boundary::computexy()
{

	this->dx = (this->vx)*_dt;
	this->dy = (this->vy)*_dt;

	this->x = this->x + this->dx;
	this->y = this->y + this->dy;

	this->x1 = this->x + this->l;
	this->y1 = this->y + this->l;

	this->computexxyy();
}

void Boundary::computexxyy()
{
	this->xx = XX(this->x);
	this->yy = YY(this->y);

	this->xx1 = XX(this->x1);
	this->yy1 = YY(this->y1);
}


void Boundary::draw()
{
	al_draw_rectangle(this->xx, this->yy, this->xx1, this->yy1, this->col, 1);
}

