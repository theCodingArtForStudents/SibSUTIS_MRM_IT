#ifndef TREEPICTURE_H
#define TREEPICTURE_H

#pragma once
class TreePicture
{
private:
	void line(const HDC& dc, const int x1, const int y1, const int x2, const int y2);
	void drawingTree(const HDC& dc, const int X, const int Y);
	void drawSpruce(const HDC& dc, const int X, const int Y,int r);
public:
	TreePicture();
	void draw(const HDC & dc, const int x, const int y,int r, int type);
};

enum TreeType
{
	Tree = 0,
	SpruceT,
	FractalSpruceT, //Triangles
	FractalSpruceL	//Lines
};


#endif