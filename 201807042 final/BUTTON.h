#pragma once

#include "OBJECT.h"


using namespace std;
 
class BUTTON : public OBJECT{
private:

	// �Լ� ������
	int (*action)(
		HWND		hWnd,
		UINT		message,
		WPARAM		wParam,
		LPARAM		lParam
	) = NULL;
	// �Լ� ������

protected:
	WCHAR	name[21];	// ��ư�� ������ �� ���
	DWORD	code;
	//ACTION	action;
	void init_name(
		const WCHAR*	name
	);
	void init_code(
		const DWORD		& code
	);

public:
	BUTTON(
		const WCHAR*	name,
		const DWORD		& code,
		const int		& x,
		const int		& y,
		const int		& width,
		const int		& height
	);

	BUTTON(
		const WCHAR*	name,
		const DWORD		& code,
		const int		& x,
		const int		& y,
		const int		& width
	);

	void paint( const HWND		& hWnd);
	void paint( HDC		& hdc);

	// ��ư ���� �����ΰ�
	bool is_area(
		const LPARAM& lParam
	);

	bool press(
		const LPARAM		& lParam
	);

	void setAction(
		int (*action)(
			HWND		hWnd,
			UINT		message,
			WPARAM		wParam,
			LPARAM		lParam
		)
	);

	//�׼� ȣ��
	int Action(
		const	HWND&		hWnd,
		const	UINT&		message,
		const	WPARAM&		wParam,
		const	LPARAM&		lParam
	);

	// ���� ���¶�� �׼� ȣ��
	int press_Action(
		const	HWND& hWnd,
		const	UINT& message,
		const	WPARAM& wParam,
		const	LPARAM& lParam
	);
};
       
