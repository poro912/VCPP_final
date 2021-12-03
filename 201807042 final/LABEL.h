#pragma once
#include <string>
#include "OBJECT.h"


#ifndef MAX_LENGTH
#define MAX_LENGTH 100
#endif // MAX_LENGTH


class LABEL :
    public OBJECT
{
private:

protected:
    WCHAR	text[MAX_LENGTH];
	int		font_size = 12;
	bool	back = false;

public:
	LABEL(
		const int			x,
		const int			y,
		const WCHAR *		text,
		const int			font_size
	);

	LABEL(
		const int			x,
		const int			y,
		const WCHAR* text
	);

	void paint(
		const HWND		hWnd
	);
	void paint(
		const HDC		hdc
	);

	void setLocation(
		const int		x,
		const int		y
	);

	void setText(
		const WCHAR *		text
	);
	
	void setFontSize(
		const int			font_size
	);

	void setBack(
		const bool			set
	);

	void toogleBack();
};

