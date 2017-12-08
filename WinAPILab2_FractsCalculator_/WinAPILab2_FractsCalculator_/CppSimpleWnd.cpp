#include "CppSimpleWnd.h"



CppSimpleWnd::CppSimpleWnd()
{
}

CppSimpleWnd::CppSimpleWnd( const HINSTANCE & hInstance, int cmdOpen)
{   

    _wndEx.lpszClassName = _wndClassName;
    _wndEx.cbSize = sizeof( WNDCLASSEX );
    _wndEx.lpfnWndProc = WNDPROC( CppSimpleWnd::wndProc );
    _wndEx.cbClsExtra = 0;
    _wndEx.cbWndExtra = 0;
    _wndEx.hbrBackground = HBRUSH( COLOR_WINDOW );
    _wndEx.hInstance = hInstance;
    _wndEx.hCursor = LoadCursor( 0, IDC_ARROW );
    _wndEx.style = CS_HREDRAW | CS_VREDRAW;
    _wndEx.hIcon = 0;
    _wndEx.hIconSm = 0;
    _wndEx.lpszMenuName = 0;

    if( !RegisterClassEx( &_wndEx ) )
        return;

    _hwnd = CreateWindow(
        _wndClassName, L"Fract Calculator (WinAPI version)",
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
        0, 0, 230, 180, HWND_DESKTOP, NULL, hInstance, NULL );

    ShowWindow( _hwnd, 1 );
    UpdateWindow( _hwnd );
   // create( wndClassName, className, hInstance, x, y, width, height );
}

bool CppSimpleWnd::create( const TCHAR & wndClassName, const TCHAR & windowName, const HINSTANCE & hInstance, const int & x, const int & y, const int & width, const int & height )
{
    if( !registerClassEx(hInstance) )
        return false;
    
    //_hwnd = CreateWindowW( _wndClassName, _windowName, WS_OVERLAPPEDWINDOW, x, y, width, height, 0, 0, hInstance, NULL );

    ShowWindow( _hwnd, 1 );
    UpdateWindow( _hwnd );

    return (bool)_hwnd;
}

LRESULT CALLBACK CppSimpleWnd::wndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam )
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

bool CppSimpleWnd::registerClassEx( HINSTANCE hInstance )
{
    _wndEx.lpszClassName = _wndClassName;
    _wndEx.cbSize = sizeof( WNDCLASSEX );
    _wndEx.lpfnWndProc = WNDPROC( CppSimpleWnd::wndProc );
    _wndEx.cbClsExtra = 0;
    _wndEx.cbWndExtra = 0;
    _wndEx.hbrBackground = HBRUSH( COLOR_WINDOW );
    _wndEx.hInstance = hInstance;
    _wndEx.hCursor = LoadCursor( 0, IDC_ARROW );
    _wndEx.style = CS_HREDRAW | CS_VREDRAW;
    _wndEx.hIcon = 0;
    _wndEx.hIconSm = 0;
    _wndEx.lpszMenuName = 0;

    return RegisterClassEx( &_wndEx );
}
