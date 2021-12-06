#pragma once
#include<Windows.h>

#define DEFAULT_BRUSH RGB(200,200,200)
#define DEFAULT_PEN RGB(40,40,40)

class OBJECT
{
protected:
	RECT			rect	= { 0, };
	int				x		= 0;
	int				y		= 0;
	int				width	= 0;
	int				height	= 0;
	COLORREF		brush	= DEFAULT_BRUSH;
	COLORREF		pen		= DEFAULT_PEN;
	bool			visible	= true;
	bool			enabled = true;
public:
	void init(
		const int&		x,
		const int&		y,
		const int&		width,
		const int&		height
	);

	OBJECT(
		const int&		x,
		const int&		y,
		const int&		width,
		const int&		height
	);
	OBJECT(
		const RECT&		rect
	);

	void SetPen(const COLORREF& col);

	void SetBrush(const COLORREF& col);

	void setVisible(const bool& visible);

	void setEnabled(const bool& enabled);

	void setLocation(
		const int x,
		const int y
	);
	void moveHorizontal(const int n);

	void moveVertical(const int n);


	int get_left();
	int get_top();
	int get_right();
	int get_bottom();
	RECT get_rect();


};

