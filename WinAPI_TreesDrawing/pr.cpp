#include <windows.h>
#include <iostream>
#define WIN32_LEAN_AND_MEAN


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

class TreePicture
{
  void line(const HDC& dc, const int x1, const int y1, const int x2, const int y2)
  {
    MoveToEx(dc, x1, y1, 0);
    LineTo(dc, x2, y2);
  }
public:
  void show(const HWND& hwnd, const HDC& dc, const int X, const int Y);
};

class House
{
public:
  void show(const HWND& hwnd, const HDC& dc, const int X, const int Y);
};

int APIENTRY  WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  HWND hMainWnd;

  WNDCLASSEX wc;
  // заполняем структуру класса окна
  wc.cbSize = sizeof(wc);
  wc.style = CS_HREDRAW | CS_VREDRAW;
  wc.lpfnWndProc = WndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = hInstance;
  wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH) COLOR_WINDOW;
  wc.lpszMenuName = NULL;
  wc.lpszClassName = L"MyClass";
  wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

  // регистрируем класс окна
  if (!RegisterClassEx(&wc))
  {
    MessageBox(NULL, L"Cannot register class", L"Error", MB_OK);
    return 1;
  }
  // создаем основное окно приложения
  hMainWnd = CreateWindow(L"MyClass", L"Hello Application", WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL,
                          hInstance, NULL);
  if (!hMainWnd)
  {
    MessageBox(NULL, L"Cannot create main window", L"Error", MB_OK);
    return 2;
  }
  // Показываем наше окно
  ShowWindow(hMainWnd, nCmdShow);
  MSG msg;
  // Выполняем цикл обработки сообщений до закрытия приложения
  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  HDC hDC;
  PAINTSTRUCT ps;
  RECT rect;

  TreePicture *tPic;

  switch(uMsg)
  {
  case WM_PAINT:
    hDC = BeginPaint(hWnd, &ps);
    GetClientRect(hWnd, &rect);

    tPic = new TreePicture();

    tPic->show(hWnd, hDC, rect.left+15, rect.top-15);

    EndPaint(hWnd, &ps);
    break;
  case WM_CLOSE:
    DestroyWindow(hWnd);
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  default:
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
  }

  return 0;
}



void House::show(const HWND& hwnd, const HDC& dc, const int X, const int Y)
{
  /*ФАСАД ДОМА*/
  HBRUSH  brush = CreateSolidBrush(RGB(254, 255, 220));
  SelectObject(dc,brush);
  Rectangle(dc, X, Y+260, X + 130, Y + 400);
  DeleteObject(brush);

  /*ТРЕУГОЛЬНАЯ КРЫША*/
  POINT poly[3] = { {X,Y+260 },{ X+130 , Y+260 },{X+130/2, Y+200} };
  brush = CreateHatchBrush(HS_DIAGCROSS, RGB(254, 255, 220));
  SelectObject(dc, brush);
  Polygon(dc, poly, 3);
  DeleteObject(brush);

  //////////////////////////
  /*ДВЕРЬ*/
  brush = CreateSolidBrush(RGB(175, 75, 0));
  SelectObject(dc, brush);
  Rectangle(dc, X + 70, Y + 320, X + 110, Y + 400);
  DeleteObject(brush);

  /*ОКНА*/


  brush = CreateSolidBrush(RGB(200, 200, 200));
  SelectObject(dc, brush);
  Rectangle(dc, X + 290, Y + 300, X + 330, Y + 340);
  DeleteObject(brush);

}

void TreePicture::show(const HWND& hwnd, const HDC& dc, const int X, const int Y)
{
  HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));
  SelectObject(dc, brush);
  line(dc, X, Y, X, Y - 150); //Здесь 150 - это высота ствола, рисование идёт снизу к верху.

  /*Рисуем ветки*/
  line(dc, X, Y - 75, X - 50, Y - 75 - 15);
  //circle == (X,Y, X+R, Y+R)
  Ellipse(dc, X-70, Y - 105, X - 40, Y-105 + 30); //Подгоняем листья

  line(dc, X, Y - 95, X - 50, Y - 95 - 15);
  Ellipse(dc, X - 75, Y - 120, X - 50, Y - 120 + 15); //Подгоняем листья
  Ellipse(dc, X - 50, Y - 130, X - 35, Y - 120 + 15); //Подгоняем листья

  Ellipse(dc, X - 10, Y - 150, X + 10, Y - 150 + 15); //Подгоняем листья

  line(dc, X, Y - 60, X+80, Y - 165);  //Ветви
  line(dc, X, Y - 90, X + 30, Y - 135);
  line(dc, X + 25, Y - 95, X + 85, Y - 100);
  line(dc, X + 50, Y - 130, X + 55, Y - 170);

  Ellipse(dc, 15 + X + 55, 15 + Y - 170, 15 + X + 75, 15 + Y - 190); //листва
  Ellipse(dc, 15 + X + 34, 15 + Y - 180, 15 + X + 46, 15 + Y - 200);
  Ellipse(dc, 25 + X + (-5), 25 + Y - 120, 25 + X + 7, 25 + Y - 144);
  Ellipse(dc, 15 + X + 55, 15 + Y - 103, 15 + X + 75, 15 + Y - 127);
  Ellipse(dc, 15 + X + 10, 15 + Y - 140, 15 + X + 28, 15 + Y - 158);

  DeleteObject(brush);
}


