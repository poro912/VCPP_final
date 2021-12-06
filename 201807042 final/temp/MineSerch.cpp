#include "MineSerch.h"
#define WM_GAME_CREATE WM_USER
#define WM_GAME_START WM_USER+1
#define WM_GAME_OVER WM_USER+2


MineSerch::MineSerch()
{
	this->TITLE = new LABEL(300, 30, L"지뢰찾기", 50);
	this->time_label = new LABEL(100, 50, L"0.00 초", 20);
	this->remain_label = new LABEL(450, 75, L"남은 개수 : 0", 20);
	this->find_label = new LABEL(450, 75, L"찾은 개수 : 0", 20);
}

MineSerch::~MineSerch()
{
	delete this->TITLE;
	delete this->time_label;
	delete this->remain_label;
	delete this->find_label;
	for (auto& i :map)
	{
		i.clear();
	}
	map.clear();
}


int MineSerch::proc(
	HWND		hWnd,
	UINT		message,
	WPARAM		wParam,
	LPARAM		lParam
)
{
	switch (message)
	{
	case WM_GAME_CREATE:
	case WM_GAME_OVER:
	case WM_GAME_START:
		break;

	default:
		break;
	}
}

void MineSerch::paint(
	HDC			hdc
)
{
	
	TITLE->paint(hdc);
	time_label->paint(hdc);
	remain_label->paint(hdc);
	find_label->paint(hdc);

	for (auto& i : map)
	{
		for (auto& j : i)
			j.paint(hdc);
	}

}

