#include "stdafx.h"
#include "House.h"

void House::show(const HDC& dc, const int X, const int Y,int r)
{

	HBRUSH  brush = CreateSolidBrush(RGB(254, 255, 220));
	SelectObject(dc, brush);
	Rectangle(dc, X - r, (Y)-r, (X)+r, (Y)+r);
	DeleteObject(brush);


	POINT poly[3] = {
		{ X - r,Y - r },
		{ X  , Y - 2 * r },
		{ X + r, Y - r } ,
	};
	brush = CreateSolidBrush(RGB(254, 255, 220));
	SelectObject(dc, brush);
	Polygon(dc, poly, 3);
	DeleteObject(brush);


	brush = CreateSolidBrush(RGB(175, 75, 0));
	SelectObject(dc, brush);
	Rectangle(dc, (X + 70) - 0.5*r, (Y + 320) - r / 2, (X + 110) + 0.5*r, (Y + 400) + r / 2);
	DeleteObject(brush);


	brush = CreateSolidBrush(RGB(200, 200, 200));
	SelectObject(dc, brush);
	Rectangle(dc, X - 0.5*r, (Y)-0.5*r, (X)+0.5*r, (Y)+0.5*r);
	DeleteObject(brush);

}