//#include <iostream>

//#include "fract.h"
//#include "CppSimpleWnd.h"
//#include "CppWndApp.h"
//#include "labhelper.h"

#include <Windows.h>

//using namespace std;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name


LRESULT CALLBACK wndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam );

int WINAPI WinMain( HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPWSTR    lpCmdLine,
                    int       nCmdShow 
                   )
{
  //  CppSimpleWnd csWnd( hInst, nCommandShow );
 //   CppWndApp app;

    //csWnd.create();

    LoadStringW( hInstance, 103, szTitle, MAX_LOADSTRING );
    LoadStringW( hInstance, 102, szWindowClass, MAX_LOADSTRING );

    LPCTSTR		_wndClassName = TEXT("my wnd");
    LPCTSTR		_windowName = L"my first window";
    int 	    x;
    int 	    y;
    int 	    nWidth;
    int 	    nHeight;

    WNDCLASSEX	wndEx = {0};


    wndEx.lpszClassName = _wndClassName;
    wndEx.cbSize = sizeof( WNDCLASSEX );
    wndEx.lpfnWndProc = WNDPROC( wndProc );
    wndEx.cbClsExtra = 0;
    wndEx.cbWndExtra = 0;
    wndEx.hbrBackground = HBRUSH( COLOR_WINDOW );
    wndEx.hInstance = hInst;
    wndEx.hCursor = LoadCursor( 0, IDC_ARROW );
    wndEx.style = CS_HREDRAW | CS_VREDRAW;
    wndEx.hIcon = 0;
    wndEx.hIconSm = 0;
    wndEx.lpszMenuName = 0;

    if( !RegisterClassEx( &wndEx ) )
        return 1;

    HWND hWnd = CreateWindow(
        _wndClassName, L"Fract Calculator (WinAPI version)",
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
        0, 0, 230, 180, HWND_DESKTOP, NULL, hInst, NULL );

    ShowWindow( hWnd, 1 );
    UpdateWindow( hWnd );

    if( !hWnd )
        return 2;
    
    MSG msg;
    while( GetMessage( &msg, NULL, 0, 0 ) ){
        TranslateMessage( &msg );
        DispatchMessage( &msg );
    }

    return (int)msg.wParam;

    //return app.Run();
}
//
////
//int main(int argc, char *argv[])
//{
//	/*Fract f(3, 8),
//		  f1(2, 5);
//
//
//  cout << " f:: " << f.toString() << "\n f2:: " << f1.toString() << endl;
//
//  cout << "f * f1 = " << Fract::Mul(f, f1).toString() << endl;
//  cout << "f / f1 = " << Fract::Div(f, f1).toString() << endl;
//*/
//
//    CppSimpleWnd csWnd( ( TCHAR )"csWnd", ( TCHAR )"Urraaaa", GetModuleHandle(0), CW_USEDEFAULT, CW_USEDEFAULT, 500, 500 );
//
//  return 0;
//}
LRESULT CALLBACK wndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam )
{
    switch( message ){

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint( hwnd, &ps );
        // TODO: Add any drawing code that uses hdc here...
        EndPaint( hwnd, &ps );
    }
    break;
    case WM_DESTROY:
        PostQuitMessage( 0 );
        break;
    default:
        return DefWindowProc( hwnd, message, wParam, lParam );
    }
    return 0;
}