#pragma once
#include "201807042 final.h"
#include "framework.h"


class PAGE
{

public:
	virtual int proc(
		const HWND			hWnd,
		const UINT			message,
		const WPARAM		wParam,
		const LPARAM		lParam
	) = 0;
	void paint(HWND hWnd)
	{
		HDC hdc = GetDC(hWnd);
		paint(hdc);
		ReleaseDC(hWnd, hdc);
	};
	virtual void paint(
		HDC hdc
	) = 0;
};

