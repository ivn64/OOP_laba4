#pragma once
#include <iostream>
#include <windowsx.h>
#include <fstream>

#include "Shape.h"

class Rhombus: public Shape
{
protected:
	int vertDiagonal;
	int horizDiagonal;
	RGBTRIPLE frame—olor;

public:
	Rhombus();
	Rhombus(int, int, int, int, RGBTRIPLE, RGBTRIPLE);
	int GetVertDiagonal();
	int GetHorizDiagonal();
	RGBTRIPLE GetFrame—olor();
	void SetFrame—olor(BYTE, BYTE, BYTE);
	void SetVertDiagonal(int);
	void SetHorizDiagonal(int);
	void SaveToFile();
	void LoadFromFile();
	void Draw(HDC);
};