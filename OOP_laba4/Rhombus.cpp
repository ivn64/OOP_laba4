#include "Rhombus.h"

using namespace std;

Rhombus::Rhombus()
{
	vertDiagonal = 100;					//360
	horizDiagonal = 100;					//400
	frameСolor.rgbtRed = 0;				//0
	frameСolor.rgbtGreen = 255;			//255
	frameСolor.rgbtBlue = 0;			//0
}
Rhombus::Rhombus(int tVertDiagonal, int tHorizDiagonal, int x, int y, RGBTRIPLE tbackgroundСolor, RGBTRIPLE tFrameСolor)
{

	vertDiagonal = tVertDiagonal;								//360
	horizDiagonal = tHorizDiagonal;								//400
	frameСolor.rgbtRed = tFrameСolor.rgbtRed;					//0
	frameСolor.rgbtGreen = tFrameСolor.rgbtGreen;				//255
	frameСolor.rgbtBlue = tFrameСolor.rgbtBlue;					//0
}
int Rhombus::GetVertDiagonal() 
{ 
	return vertDiagonal;
}
int Rhombus::GetHorizDiagonal()
{
	return horizDiagonal;
}
RGBTRIPLE Rhombus::GetFrameСolor()
{ 
	return frameСolor;
}
void Rhombus::SetVertDiagonal(int newVertDiagonal)
{
	vertDiagonal = newVertDiagonal;
}
void Rhombus::SetHorizDiagonal(int newHorizDiagonal)
{
	horizDiagonal = newHorizDiagonal;
}
void Rhombus::SetFrameСolor(BYTE red, BYTE green, BYTE blue)
{
	frameСolor.rgbtRed = red;
	frameСolor.rgbtGreen = green;
	frameСolor.rgbtBlue = blue;
}
void Rhombus::SaveToFile()
{
	ofstream fileRomb;
	fileRomb.open("romb.txt");
	fileRomb.write((char*)&vertDiagonal, sizeof(vertDiagonal));
	fileRomb.write((char*)&horizDiagonal, sizeof(horizDiagonal));
	//fileRomb.write((char*)&backgroundСolor, sizeof(backgroundСolor));
	fileRomb.write((char*)&frameСolor, sizeof(frameСolor));
	//fileRomb.write((char*)&xCenter, sizeof(xCenter));
	//fileRomb.write((char*)&yCenter, sizeof(yCenter));
	fileRomb.close();
}
void Rhombus::LoadFromFile()
{
	ifstream fileRomb;
	fileRomb.open("romb.txt");
	fileRomb.read((char*)&vertDiagonal, sizeof(vertDiagonal));
	fileRomb.read((char*)&horizDiagonal, sizeof(horizDiagonal));
	//fileRomb.read((char*)&backgroundСolor, sizeof(backgroundСolor));
	fileRomb.read((char*)&frameСolor, sizeof(frameСolor));
	//fileRomb.read((char*)&xCenter, sizeof(xCenter));
	//fileRomb.read((char*)&yCenter, sizeof(yCenter));
	fileRomb.close();
}
void Rhombus::Draw(HDC hdc)
{
	// создаем перо
	HPEN hPen = CreatePen(PS_SOLID, 5, RGB(frameСolor.rgbtRed, frameСolor.rgbtGreen, frameСolor.rgbtBlue));
	// и выбираем его в контекст отображения,
	// сохраняя предыдущее перо
	HPEN hOldPen = SelectPen(hdc, hPen);
	// создаем кисть
	HBRUSH hBrush = GetStockBrush(NULL_BRUSH);
	// и выбираем ее в контекст отображения,
	// сохраняя предыдущую кисть
	HBRUSH hOldBrush = SelectBrush(hdc, hBrush);
	POINT ppt[4] = { { shapeXCenter - horizDiagonal / 2, shapeYCenter },{ shapeXCenter, shapeYCenter - vertDiagonal / 2 },{ shapeXCenter + horizDiagonal / 2, shapeYCenter },{ shapeXCenter, shapeYCenter + vertDiagonal / 2 } };
	Polygon(hdc, ppt, 4);
	// выбираем в контекст отображения предыдущее перо 
	SelectPen(hdc, hOldPen);
	// выбираем в контекст отображения предыдущую кисть 
	SelectBrush(hdc, hOldBrush);
	// удаляем перо
	DeletePen(hPen);
	// удаляем кисть
	DeleteBrush(hBrush);
};