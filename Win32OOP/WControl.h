#pragma once
#include <windows.h>

//---------------------------------------------------------------------------
class WControl
{
public:
	WControl();
	virtual ~WControl();

	virtual HWND Create(HINSTANCE hinst, LPCTSTR clsname,
		LPCTSTR wndname, HWND parent = NULL,
		DWORD dStyle = WS_OVERLAPPEDWINDOW,
		int x = CW_USEDEFAULT, int y = CW_USEDEFAULT,
		int width = 450, int height = 380);
	
	virtual bool Show(int dCmdShow = SW_SHOWNORMAL) = 0;

	virtual void SetText(LPCTSTR text);

	// Because each window is of type HWND, we will need a way
	// to recognize the window handle when used in our application
	virtual operator HWND();

	virtual HINSTANCE GetInstance();
protected:
	HWND hwnd;
	HINSTANCE mhInst;
};
//---------------------------------------------------------------------------