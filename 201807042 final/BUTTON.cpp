#include "BUTTON.h"

void BUTTON::init_name(const	WCHAR		*name) 
{
	wcscpy_s(this->name, name);
}

void BUTTON::init_code(const	DWORD		& code)
{
	this->code = code;
}


BUTTON::BUTTON(
	const	WCHAR*		name,
	const	DWORD&		code,
	const	int&		x,
	const	int&		y,
	const	int&		width,
	const	int&		height
) : OBJECT(x, y, width, width) {
	init_name(name);
	init_code(code);
}

BUTTON::BUTTON(
	const	WCHAR*		name,
	const	DWORD&		code,
	const	int&		x,
	const	int&		y,
	const	int&		width
) : OBJECT(x, y, width, width) {
	init_name(name);
	init_code(code);
}

void BUTTON::paint(const HWND&		hWnd)
{
	HDC hdc = GetDC(hWnd);
	paint(hdc);
	ReleaseDC(hWnd, hdc);
}

void BUTTON::paint(HDC&			hdc)
{
	HPEN open, npen;
	HBRUSH obrush, nbrush;
	npen = CreatePen(PS_SOLID, 1, this->pen);
	nbrush = CreateSolidBrush(this->brush);
	open = (HPEN)SelectObject(hdc, npen);
	obrush = (HBRUSH)SelectObject(hdc, nbrush);
	Rectangle(hdc, this->x, this->y, this->x + this->width, this->y + this->height);
	SelectObject(hdc, open);
	SelectObject(hdc, obrush);

	DeleteObject(npen);
	DeleteObject(nbrush);
}

bool BUTTON::is_area(const LPARAM&		lParam)
{
	int		x = LOWORD(lParam);
	int		y = HIWORD(lParam);
	do {
		if (this->x <= x && x <= this->x + this->width)
			break;
		if (this->y <= y && y <= this->y + this->height)
			break;
		return false;
	} while (true);
	return true;
}

bool BUTTON::press(const LPARAM&		lParam)
{
	int		x = LOWORD(lParam);
	int		y = HIWORD(lParam);
	if (!this->enabled)
		return false;
	return this->is_area(lParam);
}

void BUTTON::setAction(
	int (*action)(
		HWND		hWnd,
		UINT		message,
		WPARAM		wParam,
		LPARAM		lParam)
)
{
	this->action = action;
}

int BUTTON::Action(
	const	HWND&		hWnd,
	const	UINT&		message,
	const	WPARAM&		wParam,
	const	LPARAM&		lParam
) {
	return action(hWnd, message, lParam, wParam);
}

int BUTTON::press_Action(
	const	HWND& hWnd,
	const	UINT& message,
	const	WPARAM& wParam,
	const	LPARAM& lParam
) {
	if(this->press(lParam))
		return action(hWnd, message, lParam, wParam);
}


//return action(HWND hWnd, UINT message, LPARAM lParam, WPARAM wParam)