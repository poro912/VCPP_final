#pragma once
#include"PAGE.h"

class Dodge : PAGE
{
private:
	PLAYER * player;

public:
	Dodge();
	~Dodge();
	

	int proc(
		HWND		hWnd,
		UINT		message,
		WPARAM		wParam,
		LPARAM		lParam
	);
	
	
	void paint(
		HDC			hdc
	);
};





