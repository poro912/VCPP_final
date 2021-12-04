#include "LABEL.h"



LABEL::LABEL(
	const int		x,
	const int		y,
	const WCHAR *	text,
	const int		font_size
) : OBJECT(x, y, 0, 0 ) {
	setText(text);
	this->font_size = font_size;
}

LABEL::LABEL(
	const int		x,
	const int		y,
	const WCHAR* text
) : OBJECT(x, y, 0, 0) {
	setText(text);
	this->font_size = 12;
}


void LABEL::paint(const HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	paint(hdc);
	ReleaseDC(hWnd, hdc);
}

void LABEL::paint(HDC hdc)
{
	if (!this->visible)
		return;
	HFONT ofont, nfont;
	HPEN open, npen;
	HBRUSH obrush, nbrush;
	npen = CreatePen(PS_SOLID, 2, this->pen);
	nbrush = CreateSolidBrush(this->brush);
	nfont = CreateFont(this->font_size, 0, 0, 0, FW_BOLD, 0, 0, 0, HANGEUL_CHARSET,
		0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("D2Coding"));

	open = (HPEN)SelectObject(hdc, npen);
	obrush = (HBRUSH)SelectObject(hdc, nbrush);
	ofont = (HFONT)SelectObject(hdc, nfont);
	
	if(this->back)
		SetBkMode(hdc, OPAQUE);			// 배경색 출력
	else
		SetBkMode(hdc, TRANSPARENT);	// 배경색 미출력

	// TextOut
	TextOut(hdc, this->x, this->y, this->text, lstrlen(this->text));

	SelectObject(hdc, open);
	SelectObject(hdc, obrush);


	DeleteObject(npen);
	DeleteObject(nbrush);
	DeleteObject(nfont);
}


void LABEL::setLocation(
	const int x,
	const int y
) {
	this->x = x;
	this->y = y;
}

void LABEL::setText(
	const WCHAR * text
) {
	wcscpy_s(this->text, text);
}

void LABEL::setFontSize(
	const int		font_size
) {
	this->font_size = font_size;
}

void LABEL::setBack(
	const bool			set
){
	this->back = set;
}

void LABEL::toogleBack() {
	this->back = !this->back;
}