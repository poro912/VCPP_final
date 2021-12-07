#pragma once
#include "Mine.h"

#define WM_GAME_CREATE WM_USER
#define WM_GAME_START WM_USER+1
#define WM_GAME_OVER WM_USER+2


#ifndef NOW_FPS
#define NOW_FPS 30/1000
#endif

#ifndef START_BUTTON
#define START_BUTTON 100
#endif

Mine::Mine()
{
	this->TITLE = new LABEL(250, 30, L"지뢰찾기", 50);
	this->time_label = new LABEL(530, 100, L"0.00 초", 20);
	this->remain_label = new LABEL(100, 75, L"남은 개수 : 0", 20);
	this->find_label = new LABEL(100, 100, L"찾은 개수 : 0", 20);

	this->area.left = 150;
	this->area.top = 125;
	this->area.right = area.left + 400;
	this->area.bottom = area.top + 400;

	this->btn_start = new TEXTBUTTON(L"START", START_BUTTON, 300, 250, 100, 50, 20);
	this->btn_start->setAction(start);

	this->x = 25;
	this->y = 25;
	return;
}

Mine::~Mine()
{
	delete this->TITLE;
	delete this->time_label;
	delete this->remain_label;
	delete this->find_label;
	for (auto& i : result_map)
	{
		i.clear();
	}
	result_map.clear();
	
	for (auto& i : hide_map)
	{
		i.clear();
	}
	hide_map.clear();

	return;
}

int Mine::proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int i;
	switch (message)
	{
	case WM_GAME_CREATE:

		break;

	case WM_GAME_START:
	{
		btn_start->setEnabled(false);
		btn_start->setVisible(false);

		int left = this->area.left;
		int top = this->area.top;
		int width = (this->area.right - left) / x;
		int height = (this->area.bottom - top) / y;
		for (int i = 0; i < x; i++)
		{
			vector<BUTTON>	temp_hide;
			vector<TEXTBUTTON> temp_result;
			for (int j = 0; j < y; j++)
			{
				BUTTON hide(L"", 20, left + width * j, top + height * i, width, height);
				TEXTBUTTON result(L"0", 20, left + width * j, top + height * i, width, height, 5);
				temp_hide.push_back(hide);
				temp_result.push_back(result);
			}
			hide_map.push_back(temp_hide);
			result_map.push_back(temp_result);
		}
	}
		break;
		
	case WM_GAME_OVER:
	{
		break;
	}
	case WM_KEYDOWN:
		
		break;
	case WM_LBUTTONUP:
		btn_start->press_Action(hWnd, message, wParam, lParam);
		break;
	case WM_KEYUP:
		break;
		// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡTimerㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	case WM_TIMER:
		// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡPAINT, COMMAND, DESTROYㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
		break;

	case WM_COMMAND:    // 버튼과 메뉴에 관한 설정
	{
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case 'a':
		default:
			return 0;
		}
	}
	break;

	case WM_DESTROY:
		SendMessage(hWnd, WM_GAME_OVER, 0, 0);

		break;
	default:
		return 0;
	}
	return 1;// 하나라도 실행되면 1 반환
}


void Mine::paint(HDC hdc)
{
	TITLE->paint(hdc);
	time_label->paint(hdc);
	remain_label->paint(hdc);
	find_label->paint(hdc);

	Rectangle(hdc, this->area.left, this->area.top, this->area.right, this->area.bottom);

	this->btn_start->paint(hdc);

	for (auto& i : result_map)
	{
		for (auto& j : i)
			j.paint(hdc);
	}
	for (auto& i : hide_map)
	{
		for (auto& j : i)
			j.paint(hdc);
	}
}

int start(
	HWND hWnd,
	UINT message,
	WPARAM wParam,
	LPARAM lParam
) {
	PostMessage(hWnd, WM_GAME_START, 0, 0);
	return 0;
}
