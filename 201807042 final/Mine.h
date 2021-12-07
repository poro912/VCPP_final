#pragma once

#include"framework.h"

class Mine
{
private:
	LABEL* TITLE;
	LABEL* time_label;
	LABEL* remain_label;
	LABEL* find_label;

	RECT area;

	TEXTBUTTON* btn_start;

	vector<vector<BUTTON>> hide_map;
	vector<vector<TEXTBUTTON>> result_map;

	int x;	// °¡·Î Ä­ ¼ö
	int y;	// ¼¼·Î Ä­ ¼ö

	int mine;	//remain = serch - mine
	int serch;

public:
	Mine();
	~Mine();
	int proc(
		const HWND			hWnd,
		const UINT			message,
		const WPARAM		wParam,
		const LPARAM		lParam
	);
	
	void paint(HWND hWnd)
	{
		HDC hdc = GetDC(hWnd);
		paint(hdc);
		ReleaseDC(hWnd, hdc);
	};
	
	void paint(
		HDC hdc
	);
	
};

int start(
	HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam
);