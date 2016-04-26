#include <windows.h>
#include "WApplication.h"
#include "WWindow.h"

//---------------------------------------------------------------------------
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT Msg,
	WPARAM wParam, LPARAM lParam);
//---------------------------------------------------------------------------
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst,
	LPSTR lpCmdLine, int nCmdShow)
{
	MSG   Msg;
	LPCTSTR ClsName = L"Win32OOP";
	LPCTSTR WndName = L"Object-Oriented Win32 Programming";

	// Initialize the application class
	WApplication WinApp(hInstance, ClsName, MainWndProc);
	WinApp.Register();

	// Create the main window
	WWindow Wnd;
	Wnd.Create(hInstance, ClsName, WndName, nullptr, WS_OVERLAPPEDWINDOW, 0UL, 100, 200, 300, 400);
	Wnd.SetText(L"lallooooo");

	// Display the main winow
	Wnd.Show();

	/*WWindow wnd2;
	wnd2.Create(hInstance, ClsName, L"Another one bites the dust");
	wnd2.Show();*/

	// Process the main window's messages
	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return 0;
}
//---------------------------------------------------------------------------
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT Msg,
	WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		return 0;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}
//---------------------------------------------------------------------------