#include "OBJECT.h"

void OBJECT::init(
	const int&		x,
	const int&		y,
	const int&		width,
	const int&		height
){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

OBJECT::OBJECT(
	const int&		x,
	const int&		y,
	const int&		width,
	const int&		height
) {
	this->init(x, y, width, height);
}


void OBJECT::SetPen(const COLORREF&		col) {
	this->pen = col;
}

void OBJECT::SetBrush(const COLORREF&		col) {
	this->brush = col;
}


void OBJECT::setVisible(const bool&			visible)
{
	this->visible = visible;
}

void OBJECT::setEnabled(const bool&			enabled)
{
	this->enabled = enabled;
}

