#include "Dodge.h"

#define WM_GAME_CREATE WM_USER
#define WM_GAME_START WM_USER+1
#define WM_GAME_OVER WM_USER+2
#define WM_KEYBOARD WM_USER+3

#define CHECK_TIME 1
#define KEY_SENSE 2

#ifndef NOW_FPS
#define NOW_FPS 30/1000
#endif

#define START_BUTTON 100

Dodge::Dodge()
{
	this->area = { 100,100,500,500 };
	this->player = new PLAYER(300,300,5);
	this->start_time = 0;
	this->enduring_time = 0;
	this->btn_start = new TEXTBUTTON(L"START", START_BUTTON, 250, 250, 100, 50, 20);
	this->btn_start->setAction(start_button);
	this->time_label = new LABEL(100, 50, L"0.00 초", 20);
	this->bullet_label = NULL;
	this->running = false;
}

Dodge::~Dodge()
{
	delete this->player;
	delete this->btn_start;
}

int Dodge::proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_GAME_CREATE:
		
		break;
	case WM_GAME_START:
		this->running = true;
		this->start_time = GetTickCount64();
		this->enduring_time = start_time - GetTickCount64();
		KillTimer(hWnd, KEY_SENSE);
		SetTimer(hWnd, KEY_SENSE, NOW_FPS, NULL);
		SetTimer(hWnd, CHECK_TIME, 50, NULL);
		btn_start->setEnabled(false);
		btn_start->setVisible(false);
		this->player->setLocation(300, 300);
		break;

	case WM_GAME_OVER:
		delete this->player;
		KillTimer(hWnd, KEY_SENSE);
		KillTimer(hWnd, CHECK_TIME);
		btn_start->setEnabled(true);
		btn_start->setVisible(true);
		break;

	case WM_KEYBOARD:
		if (!this->running)
			SendMessage(hWnd, WM_GAME_START, 0, 0);
		if (GetKeyState('A') & 0x8000 || GetKeyState(VK_LEFT) & 0x8000)
		{
			if(this->area.left <= player->if_move_left())
				player->move_left();
		}
		if (GetKeyState('D') & 0x8000 || GetKeyState(VK_RIGHT) & 0x8000)
		{
			if (player->if_move_right() <= this->area.right)
				player->move_right();
		}
		if (GetKeyState('W') & 0x8000 || GetKeyState(VK_UP) & 0x8000)
		{
			if (this->area.top <= player->if_move_up())
				player->move_up();
			else
				int i = 0;
		}
		if (GetKeyState('S') & 0x8000 || GetKeyState(VK_DOWN) & 0x8000)
		{
			if (player->if_move_down() <= this->area.bottom)
				player->move_down();
		}
		break;

	case WM_LBUTTONUP:
		btn_start->press_Action(hWnd, message, wParam, lParam);
		break;

	case WM_KEYDOWN:
		if(!this->running)
			PostMessage(hWnd, WM_GAME_START, 0, 0);

		// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡTimerㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	case WM_TIMER:
		switch (wParam)
		{
		case KEY_SENSE: //frameq
			PostMessage(hWnd, WM_KEYBOARD, 0, 0);
			break;
		case CHECK_TIME:
		{
			WCHAR temp[50];
			this->enduring_time = (GetTickCount64() - this->start_time) / 10;
			wsprintf(temp, L"%d.%d 초", (int)(this->enduring_time / 100), (int)(this->enduring_time % 100));
			this->time_label->setText(temp);
			break;
		}
		default:
			break;
		}
		break;
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
	
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);


		// 게임 영역 출력
		Rectangle(hdc, this->area.left, this->area.top, this->area.right, this->area.bottom);

		btn_start->paint(hdc);
		this->player->paint(hdc);
		this->time_label->paint(hdc);

		EndPaint(hWnd, &ps);
		break;
	}
	case WM_DESTROY:
		SendMessage(hWnd, WM_GAME_OVER, 0, 0);
		break;
	default:
		return 0;
	}
	return 1;// 하나라도 실행되면 1 반환
}


void Dodge::paint(HDC hdc)
{


}


int start_button(
	HWND hWnd,
	UINT message, 
	WPARAM wParam, 
	LPARAM lParam
) {
	PostMessage(hWnd, WM_GAME_START, 0, 0);
	return 0;
}