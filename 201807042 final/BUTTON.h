#pragma once

#include "OBJECT.h"


using namespace std;
 
class BUTTON : public OBJECT{
private:

	// 함수 포인터
	int (*action)(
		HWND		hWnd,
		UINT		message,
		WPARAM		wParam,
		LPARAM		lParam
	) = NULL;
	// 함수 포인터

protected:
	WCHAR	name[21];	// 버튼의 내용이 들어갈 장소
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

	// 버튼 범위 안쪽인가
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

	//액션 호출
	int Action(
		const	HWND&		hWnd,
		const	UINT&		message,
		const	WPARAM&		wParam,
		const	LPARAM&		lParam
	);

	// 눌린 상태라면 액션 호출
	int press_Action(
		const	HWND& hWnd,
		const	UINT& message,
		const	WPARAM& wParam,
		const	LPARAM& lParam
	);
};
       
