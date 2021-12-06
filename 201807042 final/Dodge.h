#pragma once
#include"PAGE.h"

class Dodge : PAGE
{
private:
	PLAYER * player;
	RECT area;
	ULONGLONG start_time;
	ULONGLONG enduring_time;
	ULONGLONG best_enduring_time;
	ULONGLONG temp_time;
	ULONGLONG end_time;
	TEXTBUTTON * btn_start;
	
	LABEL* TITLE;
	LABEL* time_label;
	LABEL* bullet_label;
	LABEL* best_time;
	
	bool running;
	vector<BULLET> bullets;

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


