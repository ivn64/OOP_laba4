#include "Rhombus.h"

using namespace std;

Rhombus::Rhombus()
{
	vertDiagonal = 100;					//360
	horizDiagonal = 100;					//400
	frame�olor.rgbtRed = 0;				//0
	frame�olor.rgbtGreen = 255;			//255
	frame�olor.rgbtBlue = 0;			//0
}
Rhombus::Rhombus(int tVertDiagonal, int tHorizDiagonal, int x, int y, RGBTRIPLE tbackground�olor, RGBTRIPLE tFrame�olor)
{

	vertDiagonal = tVertDiagonal;								//360
	horizDiagonal = tHorizDiagonal;								//400
	frame�olor.rgbtRed = tFrame�olor.rgbtRed;					//0
	frame�olor.rgbtGreen = tFrame�olor.rgbtGreen;				//255
	frame�olor.rgbtBlue = tFrame�olor.rgbtBlue;					//0
}
int Rhombus::GetVertDiagonal() 
{ 
	return vertDiagonal;
}
int Rhombus::GetHorizDiagonal()
{
	return horizDiagonal;
}
RGBTRIPLE Rhombus::GetFrame�olor()
{ 
	return frame�olor;
}
void Rhombus::SetVertDiagonal(int newVertDiagonal)
{
	vertDiagonal = newVertDiagonal;
}
void Rhombus::SetHorizDiagonal(int newHorizDiagonal)
{
	horizDiagonal = newHorizDiagonal;
}
void Rhombus::SetFrame�olor(BYTE red, BYTE green, BYTE blue)
{
	frame�olor.rgbtRed = red;
	frame�olor.rgbtGreen = green;
	frame�olor.rgbtBlue = blue;
}
void Rhombus::SaveToFile()
{
	ofstream fileRomb;
	fileRomb.open("romb.txt");
	fileRomb.write((char*)&vertDiagonal, sizeof(vertDiagonal));
	fileRomb.write((char*)&horizDiagonal, sizeof(horizDiagonal));
	//fileRomb.write((char*)&background�olor, sizeof(background�olor));
	fileRomb.write((char*)&frame�olor, sizeof(frame�olor));
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
	//fileRomb.read((char*)&background�olor, sizeof(background�olor));
	fileRomb.read((char*)&frame�olor, sizeof(frame�olor));
	//fileRomb.read((char*)&xCenter, sizeof(xCenter));
	//fileRomb.read((char*)&yCenter, sizeof(yCenter));
	fileRomb.close();
}
void Rhombus::Draw(HDC hdc)
{
	// ������� ����
	HPEN hPen = CreatePen(PS_SOLID, 5, RGB(frame�olor.rgbtRed, frame�olor.rgbtGreen, frame�olor.rgbtBlue));
	// � �������� ��� � �������� �����������,
	// �������� ���������� ����
	HPEN hOldPen = SelectPen(hdc, hPen);
	// ������� �����
	HBRUSH hBrush = GetStockBrush(NULL_BRUSH);
	// � �������� �� � �������� �����������,
	// �������� ���������� �����
	HBRUSH hOldBrush = SelectBrush(hdc, hBrush);
	POINT ppt[4] = { { shapeXCenter - horizDiagonal / 2, shapeYCenter },{ shapeXCenter, shapeYCenter - vertDiagonal / 2 },{ shapeXCenter + horizDiagonal / 2, shapeYCenter },{ shapeXCenter, shapeYCenter + vertDiagonal / 2 } };
	Polygon(hdc, ppt, 4);
	// �������� � �������� ����������� ���������� ���� 
	SelectPen(hdc, hOldPen);
	// �������� � �������� ����������� ���������� ����� 
	SelectBrush(hdc, hOldBrush);
	// ������� ����
	DeletePen(hPen);
	// ������� �����
	DeleteBrush(hBrush);
};