#include "Dodge.h"
#define WM_KEYBOARD WM_USER+2
#define WM_GAME_START WM_USER+1
#define KEY_SENSE 2

#ifndef NOW_FPS
#define NOW_FPS 30/1000
#endif

Dodge::Dodge()
{
	this->player = new PLAYER(200,100,5);
}

Dodge::~Dodge()
{

}

int Dodge::proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_GAME_START:
		SetTimer(hWnd, KEY_SENSE, NOW_FPS, NULL);
		break;
	case WM_KEYBOARD:
		if (GetKeyState(VK_LEFT) & 0x8000)
			player->move_left();
		else if (GetKeyState('A') & 0x8000)
			player->move_left();

		if (GetKeyState(VK_RIGHT) & 0x8000)
			player->move_right();
		else if (GetKeyState('D') & 0x8000)
			player->move_right();

		if (GetKeyState(VK_UP) & 0x8000)
			player->move_up();
		else if (GetKeyState('W') & 0x8000)
			player->move_up();

		if (GetKeyState(VK_DOWN) & 0x8000)
			player->move_down();
		else if (GetKeyState('S') & 0x8000)
			player->move_down();
		break;
	case WM_USER + 10:
		break;
		// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡTimerㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	case WM_TIMER:
		switch (wParam)
		{
		case 0: //frame
			PostMessage(hWnd, WM_KEYBOARD, 0, 0);
		default:
			break;
		}
		break;
		// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡPAINT, COMMAND, DESTROYㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	break;
	case WM_CHAR:
	case WM_KEYDOWN:
	{
		
	}
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
		this->player->paint(hdc);
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_DESTROY:
		break;
	default:
		return 0;
	}
	return 1;// 하나라도 실행되면 1 반환
}


void Dodge::paint(HDC hdc)
{


}


