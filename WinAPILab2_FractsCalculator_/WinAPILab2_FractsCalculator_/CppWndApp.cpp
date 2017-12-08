#include "CppWndApp.h"

int CppWndApp::Run()
{
	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}
