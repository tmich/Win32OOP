#include "WControl.h"
//---------------------------------------------------------------------------
WControl::WControl()
	: hwnd(0)
{
}
//---------------------------------------------------------------------------
WControl::~WControl()
{
}
//---------------------------------------------------------------------------
WControl::operator HWND()
{
	return hwnd;
}
//---------------------------------------------------------------------------
HWND WControl::Create(HINSTANCE hinst, LPCTSTR clsname,
	LPCTSTR wndname, HWND parent,
	DWORD dStyle,
	int x, int y,
	int width, int height)
{
	hwnd = CreateWindow(clsname, wndname, dStyle,
		x, y, width, height, parent, NULL, hinst, NULL);

	return hwnd;
}

void WControl::SetText(LPCTSTR text)
{
	//return ::SetWindowText(hwnd, text) == TRUE;
	SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)text);
}
//---------------------------------------------------------------------------
//bool WControl::Show(int dCmdShow)
//{
//	bool CanShow = ::ShowWindow(hwnd, dCmdShow) == TRUE;
//
//	if (CanShow)
//		return true;
//	return false;
//}
//---------------------------------------------------------------------------
HINSTANCE WControl::GetInstance()
{
	return mhInst;
}
//---------------------------------------------------------------------------