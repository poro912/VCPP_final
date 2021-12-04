
#include"BUTTON.h"
#include"LABEL.h"

class TEXTBUTTON : public BUTTON, public LABEL
{
public:
	TEXTBUTTON(
		const	WCHAR*		name,
		const	DWORD&		code,
		const	int			x,
		const	int			y,
		const	int			width,
		const	int			height,
		const	int			font_size
	);

	void paint(HDC hdc);
	void setEnabled(bool enabled);
	void setVisible(bool visible);

};