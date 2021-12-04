#pragma once
#include"PAGE.h"

class Dodge : PAGE
{
private:
	PLAYER * player;
	RECT area;
	ULONGLONG start_time;
	ULONGLONG enduring_time;
	BUTTON * btn_start;
	LABEL* time_label;
	LABEL* bullet_label;

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


int start_button(
	HWND hWnd, 
	UINT message, 
	WPARAM wParam, 
	LPARAM lParam
);


