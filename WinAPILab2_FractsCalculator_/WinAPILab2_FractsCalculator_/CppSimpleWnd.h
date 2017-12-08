#ifndef CPPSIMPLEWND_H
#define CPPSIMPLEWND_H

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "LabHelper.h"
#include "Fract.h"

class CppSimpleWnd
{
protected:
    HWND		_hwnd;
    TCHAR		_wndClassName[32];
    TCHAR		_windowName[64];
    int 	    x;
    int 	    y;
    int 	    nWidth;
    int 	    nHeight;

    WNDCLASSEX	_wndEx;

public:
    CppSimpleWnd();
    CppSimpleWnd( const HINSTANCE & hInstance, int cmdOpen );
    /*CppSimpleWnd( const TCHAR&      wndClassName,
                  const TCHAR&      windowName,
                  const HINSTANCE&  hInstance,
                  const int&	    x,
                  const int&	    y,
                  const int&	    nWidth,
                  const int&	    nHeight
    );*/
   /* CppSimpleWnd( const HWND &      hwnd,
                  const TCHAR&      wndClassName,
                  const TCHAR&      className, 
                  const DWORD&	    dwStyle,   
                  const HWND&       hWndParent,
                  const HMENU&      hMenu,     
                  const HINSTANCE&  hInstance, 
                  const LPVOID&     lParam     
    );*/
    bool create( const TCHAR&      wndClassName,
                 const TCHAR&      windowName,
                 const HINSTANCE&  hInstance,
                 const int&	    x,
                 const int&	    y,
                 const int&	    hidth,
                 const int&	    height
    );
    static LRESULT CALLBACK wndProc( HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam );


private:
    bool registerClassEx( HINSTANCE hInstance );

};

#endif