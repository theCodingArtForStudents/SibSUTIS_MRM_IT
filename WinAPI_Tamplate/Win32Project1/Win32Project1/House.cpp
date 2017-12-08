#include "stdafx.h"
#include "House.h"

void House::show(const HDC& dc, const int X, const int Y)
{
	/*‘¿—¿ƒ ƒŒÃ¿*/
	HBRUSH  brush = CreateSolidBrush(RGB(254, 255, 220));
	SelectObject(dc, brush);
	Rectangle(dc, X, Y + 260, X + 130, Y + 400);
	DeleteObject(brush);

	/*“–≈”√ŒÀ‹Õ¿ﬂ  –€ÿ¿*/
	POINT poly[3] = { 
		{ X,Y + 260 },
		{ X + 130 , Y + 260 },
		{ X + 130 / 2, Y + 200 } 
	};
	brush = CreateSolidBrush(RGB(254, 255, 220));
	SelectObject(dc, brush);
	Polygon(dc, poly, 3);
	DeleteObject(brush);

	//////////////////////////
	/*ƒ¬≈–‹*/
	brush = CreateSolidBrush(RGB(175, 75, 0));
	SelectObject(dc, brush);
	Rectangle(dc, X + 70, Y + 320, X + 110, Y + 400);
	DeleteObject(brush);

	/*Œ Õ¿*/
	brush = CreateSolidBrush(RGB(200, 200, 200));
	SelectObject(dc, brush);
	Rectangle(dc, X + 10, Y + 300, X + 40, Y + 340);
	DeleteObject(brush);

}