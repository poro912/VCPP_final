#pragma once
#include "BUTTON.h"
class PLAYER : BUTTON
{
private:
	int		speed = 10;
public:
	PLAYER(
		const int& x,
		const int& y,
		const int& speed
	);

	PLAYER(
		const int& x,
		const int& y,
		const int& width,
		const int& height,
		const int& speed
	);

	PLAYER(
		const RECT& rect,
		const int& speed
	);

	void move_left();
	void move_right();
	void move_up();
	void move_down();

	void paint(HDC hdc);

	void setSpeed(const int& speed);
	int	getSpeed();

};