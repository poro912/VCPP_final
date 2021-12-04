#include"TEXTBUTTON.h"


TEXTBUTTON::TEXTBUTTON(
	const	WCHAR* name,
	const	DWORD& code,
	const int		x,
	const int		y,
	const int		width,
	const int		height,
	const int		font_size
) : BUTTON(name, code, x, y, width, height), LABEL(x, y, name, font_size)
{
	TEXTBUTTON::LABEL::setLocation(x + (width / 2) - (lstrlenW(name) / 3 * font_size),
		y + (height / 4) - (font_size / 2));
}


void TEXTBUTTON::paint(HDC hdc)
{
	BUTTON::paint(hdc);
	LABEL::paint(hdc);
}


void TEXTBUTTON::setEnabled(bool enabled)
{
	BUTTON::setEnabled(enabled);
	LABEL::setEnabled(enabled);
}
void TEXTBUTTON::setVisible(bool visible)
{
	BUTTON::setVisible(visible);
	LABEL::setVisible(visible);
}