#include "stdafx.h"
#include "TreePicture.h"


void TreePicture::line(const HDC & dc, const int x1, const int y1, const int x2, const int y2)
{
	MoveToEx(dc, x1, y1, 0);
	LineTo(dc, x2, y2);
}

TreePicture::TreePicture()
{
}

void TreePicture::draw(const HDC &dc, const int x, const int y, int type = 0)
{
	switch (type)
	{
	case TreeType::Tree:
		drawingTree(dc, x, y);
		break;
	case TreeType::SpruceT:
		drawSpruce(dc, x, y);
		break;
	case TreeType::FractalSpruceL:
		break;
	default:
		break;
	}
}

void TreePicture::drawingTree(const HDC& dc, const int x, const int y)
{
	HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));
	SelectObject(dc, brush);
	line(dc, x, y, x, y - 150); //Çäåñü 150 - ıòî âûñîòà ñòâîëà, ğèñîâàíèå èä¸ò ñíèçó ê âåğõó.

								/*Ğèñóåì âåòêè*/
	line(dc, x, y - 75, x - 50, y - 75 - 15);
	//circle == (X,Y, X+R, Y+R)
	Ellipse(dc, x - 70, y - 105, x - 40, y - 105 + 30); //Ïîäãîíÿåì ëèñòüÿ

	line(dc, x, y - 95, x - 50, y - 95 - 15);
	Ellipse(dc, x - 75, y - 120, x - 50, y - 120 + 15); //Ïîäãîíÿåì ëèñòüÿ
	Ellipse(dc, x - 50, y - 130, x - 35, y - 120 + 15); //Ïîäãîíÿåì ëèñòüÿ

	Ellipse(dc, x - 10, y - 150, x + 10, y - 150 + 15); //Ïîäãîíÿåì ëèñòüÿ

	line(dc, x, y - 60, x + 80, y - 165);  //Âåòâè
	line(dc, x, y - 90, x + 30, y - 135);
	line(dc, x + 25, y - 95, x + 85, y - 100);
	line(dc, x + 50, y - 130, x + 55, y - 170);

	Ellipse(dc, 15 + x + 55, 15 + y - 170, 15 + x + 75, 15 + y - 190); //ëèñòâà
	Ellipse(dc, 15 + x + 34, 15 + y - 180, 15 + x + 46, 15 + y - 200);
	Ellipse(dc, 25 + x + (-5), 25 + y - 120, 25 + x + 7, 25 + y - 144);
	Ellipse(dc, 15 + x + 55, 15 + y - 103, 15 + x + 75, 15 + y - 127);
	Ellipse(dc, 15 + x + 10, 15 + y - 140, 15 + x + 28, 15 + y - 158);

	DeleteObject(brush);
}

void TreePicture::drawSpruce(const HDC & dc, const int x, const int y)
{
	HBRUSH brush = CreateSolidBrush( RGB(128, 0 , 0) );	

	int deltaY = 250;
	int deltaX = 20;

	POINT poly[3] = {
		{x, y-deltaY},
		{x-deltaX, y},
		{x+deltaX, y}
	};
	SelectObject(dc, brush);
	Polygon(dc, poly, 3);
	DeleteObject(brush);

	deltaX += 5;


	for(int i = 5; i >= 0; i--) /*(int i = 0; i < 6; i++)*/ 
	{
		brush = CreateSolidBrush(RGB(25, 128, 0));
		poly[0] = {x, y - (deltaY - 30 * i)};
		poly[1] = {x-(deltaX+5*i), y- (deltaY - 40 * (i+1))};
		poly[2] = {x + (deltaX+5*i), y - (deltaY - 40 * (i+1))};
		SelectObject(dc, brush);
		Polygon(dc, poly, 3);		
	}
	DeleteObject(brush);
}
