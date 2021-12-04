#include"PLAYER.h"

PLAYER::PLAYER(
	const int& x,
	const int& y,
	const int& speed
) : BUTTON(L"PLAYER", 0, x, y, 20, 20)
{
	this->speed = speed;
}

PLAYER::PLAYER(
	const int& x,
	const int& y,
	const int& width,
	const int& height,
	const int& speed
) : BUTTON(L"PLAYER", 0, x, y, width, height)
{
	this->speed = speed;
}

PLAYER::PLAYER(
	const RECT& rect,
	const int& speed
) : BUTTON(L"PLAYER", 0, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top)
{
	this->speed = speed;
}

void PLAYER::move_left()
{
	this->x -= speed;
	this->rect.left -= speed;
	this->rect.right -= speed;
}
void PLAYER::move_right()
{
	this->x += speed;
	this->rect.left += speed;
	this->rect.right += speed;
}
void PLAYER::move_up()
{
	this->y -= speed;
	this->rect.top -= speed;
	this->rect.bottom -= speed;
}
void PLAYER::move_down()
{
	this->y += speed;
	this->rect.top += speed;
	this->rect.bottom += speed;
}

void PLAYER::setSpeed(const int& speed)
{
	this->speed = speed;
}
int	PLAYER::getSpeed()
{
	return this->speed;
}

int PLAYER::if_move_left()
{
	return this->rect.left - this->speed;
}

int PLAYER::if_move_right()
{
	return this->rect.right + this->speed;
}

int PLAYER::if_move_up()
{
	return this->rect.top - this->speed;
}

int PLAYER::if_move_down()
{
	return this->rect.bottom + this->speed;
}