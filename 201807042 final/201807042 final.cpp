﻿#include "framework.h"
#include "201807042 final.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
					 _In_opt_ HINSTANCE hPrevInstance,
					 _In_ LPWSTR    lpCmdLine,
					 _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 여기에 코드를 입력합니다.
	srand(time(NULL));
	// 전역 문자열을 초기화합니다.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_MY201807042FINAL, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
	// 애플리케이션 초기화를 수행합니다:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY201807042FINAL));

	MSG msg;

	// 기본 메시지 루프입니다:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style          = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc    = WndProc;
	wcex.cbClsExtra     = 0;
	wcex.cbWndExtra     = 0;
	wcex.hInstance      = hInstance;
	wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY201807042FINAL));
	wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground  = CreateSolidBrush(WINDOW_COLOR);
	wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY201807042FINAL);
	wcex.lpszClassName  = szWindowClass;
	wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
	  return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

int create_button(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//MessageBox(hWnd, L"test 성공", L"test", NULL);
	SendMessage(hWnd, WM_GAME_CREATE, 0, 0);
	//PostMessage(hWnd, WM_GAME_START, 0, 0);
	return 1;
}
int quit_button(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//MessageBox(hWnd, L"test 성공", L"test", NULL);
	SendMessage(hWnd, WM_GAME_OVER, 0, 0);
	//PostMessage(hWnd, WM_GAME_START, 0, 0);
	return 1;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int page = 0;
	static LABEL* lbl1;
	static TEXTBUTTON* btn_dodge;
	static TEXTBUTTON* btn_mine;
	static TEXTBUTTON* btn_quit;
	static Dodge* dot;
	static Mine* mine;
	int ret = 0;

	switch (page)
	{
	case 0:
		break;
	case 1:
		ret = dot->proc(hWnd, message, wParam, lParam);
		break;
	case 2:
		ret = mine->proc(hWnd, message, wParam, lParam);
		break;
	default:
		break;
	}



	switch (message)
	{
	case WM_GAME_CREATE:
		if (dot == NULL) {
			dot = new Dodge();
		}
		if (mine == NULL) {
			mine = new Mine();
		}
		
		break; 
	case WM_LBUTTONDOWN:
		break;

	case WM_MOUSEMOVE:
		break;
	case WM_LBUTTONUP:
		if (btn_dodge->press_Action(hWnd, message, wParam, lParam))
		{
			btn_dodge->setEnabled(false);
			btn_dodge->setVisible(false);
			page = 1;
		}
		if (btn_mine->press_Action(hWnd, message, wParam, lParam))
		{
			btn_mine->setEnabled(false);
			btn_mine->setVisible(false);
			page = 2;
		}
		if (btn_quit->press_Action(hWnd, message, wParam, lParam))
		{
			//delete dot;
			//dot = NULL;
			PostMessage(hWnd, WM_GAME_OVER, wParam, 0);
			btn_dodge->setEnabled(true);
			btn_dodge->setVisible(true);
			btn_mine->setEnabled(true);
			btn_mine->setVisible(true);

			if (page == 0)
			{
				PostMessage(hWnd, WM_DESTROY, wParam, 0);
			}
			page = 0;
		}
		break;

// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡTimerㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	case WM_TIMER:
		switch (wParam)
		{
		case FRAME_TIMER:
			InvalidateRect(hWnd, NULL, true);
			break;
		default:
			break;
		}
		break;
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡPAINT, COMMAND, DESTROYㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
	case WM_CREATE:
	{
		//SetTimer(hWnd,FRAME_TIMER,NOW_FPS,NULL);   // 30 fps
		SetTimer(hWnd, FRAME_TIMER, NOW_FPS, NULL);
		lbl1 = new LABEL(250, 50, L"게임 선택",50);
		btn_dodge = new TEXTBUTTON(L"Dodge", 1, 250, 120, 200, 50, 30);
		btn_dodge->setAction(create_button);

		
		btn_mine = new TEXTBUTTON(L"MINE", 2, 250, 200, 200, 50, 30);
		btn_mine->setAction(create_button);

		btn_quit = new TEXTBUTTON(L"QUIT", 0, 250, 600, 200, 50, 30);
		//function<int(HWND,UINT,LPARAM,WPARAM)>
		btn_quit->setAction(quit_button);
	}
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;		// 페인트 객체
		static HDC hdc, mem_dc;
		static HBITMAP nBitmap, oBitmap;
		static RECT buffer;
		HBRUSH nBrush;
		//static HDC hdc = BeginPaint(hWnd, &ps);  

		mem_dc = BeginPaint(hWnd, &ps);			// 페인트 dc를 받는다
		GetClientRect(hWnd, &buffer);			
		hdc = CreateCompatibleDC(mem_dc);		// 새로운 화면 할당
		nBitmap = CreateCompatibleBitmap(mem_dc, buffer.right, buffer.bottom);
												// mem_dc와 호환 가능한 비트맵 생성
		oBitmap = (HBITMAP)SelectObject(hdc, nBitmap);
												// hdc 에 연결된 비트맵을 호환 가능한 비트맵으로 선택
		
		nBrush = CreateSolidBrush(WINDOW_COLOR);
		SelectObject(hdc, nBrush);
		PatBlt(hdc, 0, 0, buffer.right, buffer.bottom, PATCOPY);
												// hdc(비트맵)에 흰 화면으로 출력 해당 범위만큼 출력
		DeleteObject(nBrush);

		if (page == 0)
		{
			btn_dodge->paint(hdc);
			btn_mine->paint(hdc);
			lbl1->paint(hdc);
		}
		else if(page == 1)
			dot->paint(hdc);
		else if(page == 2)
			mine->paint(hdc);

		btn_quit->paint(hdc);

		
		GetClientRect(hWnd, &buffer);			// 현재 hWnd 크기 받기
		BitBlt(mem_dc, 0, 0, buffer.right, buffer.bottom, hdc, 0, 0, SRCCOPY);
												// 0,0 위치부터 
		SelectObject(hdc, oBitmap);
		DeleteObject(nBitmap);
		DeleteDC(hdc);
		EndPaint(hWnd, &ps);
	}
		break;

	case WM_COMMAND:    // 버튼과 메뉴에 관한 설정
	{
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			if(ret == 0)
				return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
		break;

	case WM_DESTROY:
		KillTimer(hWnd, 0);
		SendMessage(hWnd, WM_GAME_OVER, 0, 0);
		PostQuitMessage(0);
		break;
	default:
		if(ret == 0)
			return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}


