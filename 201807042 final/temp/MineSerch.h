#pragma once
#include "PAGE.h"

class MineSerch :PAGE
{
private:
	LABEL* TITLE;
	LABEL* time_label;
	LABEL* remain_label;
	LABEL* find_label;

	int x;	// °¡·Î Ä­ ¼ö
	int y;	// ¼¼·Î Ä­ ¼ö

	int mine;	//remain = serch - mine
	int serch;

	vector<vector<BUTTON>> map;

public :
	MineSerch();
	~MineSerch();

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




/*int start_button(
	HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam
);
*/

