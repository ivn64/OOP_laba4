#include "CombiRhombus.h"

CombiRhombus::CombiRhombus()
{
	in.SetShapeXCenter(shapeXCenter);
	in.SetShapeYCenter(shapeYCenter);
	in.SetVertDiagonal(vertDiagonal / 2);
	in.SetHorizDiagonal(horizDiagonal / 2);
	in.SetFrame�olor(0, 150, 255);
	in.SetFilled�olor(0, 0, 0);
}
void CombiRhombus::SetInXCenter(int t)
{
	this->in.SetShapeXCenter(t);
}
void CombiRhombus::SetInYCenter(int t)
{
	this->in.SetShapeYCenter(t);
}
void CombiRhombus::SetInVertDiagonal(int t)
{
	this->in.SetVertDiagonal(t);
}
void CombiRhombus::SetInHorizDiagonal(int t)
{
	this->in.SetHorizDiagonal(t);
}
void CombiRhombus::SetInFrame�olor(BYTE r, BYTE g, BYTE b)
{
	this->in.SetFrame�olor(r, g, b);
}
void CombiRhombus::SetInFilled�olor(BYTE r, BYTE g, BYTE b)
{
	this->in.SetFilled�olor(r, g, b);
}
void CombiRhombus::MoveXCombiRhombus(int move)
{
	shapeXCenter += move;
	int t = in.GetShapeXCenter() + move;
	in.SetShapeXCenter(t);
}
void CombiRhombus::MoveYCombiRhombus(int move)
{
	shapeYCenter += move;
	int t = in.GetShapeYCenter() + move;
	in.SetShapeYCenter(t);
}
void CombiRhombus::Draw(HDC hdc)
{
	// ������� ����
	HPEN hPen = CreatePen(PS_SOLID, 5, RGB(frame�olor.rgbtRed, frame�olor.rgbtGreen, frame�olor.rgbtBlue));
	// � �������� ��� � �������� �����������,
	// �������� ���������� ����
	HPEN hOldPen = SelectPen(hdc, hPen);
	// ������� �����
	HBRUSH hBrush = CreateSolidBrush(RGB(filled�olor.rgbtRed, filled�olor.rgbtGreen, filled�olor.rgbtBlue));
	// � �������� �� � �������� �����������,
	// �������� ���������� �����
	HBRUSH hOldBrush = SelectBrush(hdc, hBrush);
	POINT ppt[4] = { { shapeXCenter - horizDiagonal / 2, shapeYCenter },{ shapeXCenter, shapeYCenter - vertDiagonal / 2 },{ shapeXCenter + horizDiagonal / 2, shapeYCenter },{ shapeXCenter, shapeYCenter + vertDiagonal / 2 } };
	Polygon(hdc, ppt, 4);
	RGBTRIPLE tempColor = in.GetFrame�olor();
	hPen = CreatePen(PS_SOLID, 5, RGB(tempColor.rgbtRed, tempColor.rgbtGreen, tempColor.rgbtBlue));
	hOldPen = SelectPen(hdc, hPen);
	tempColor = in.GetFilled�olor();
	hBrush = CreateSolidBrush(RGB(tempColor.rgbtRed, tempColor.rgbtGreen, tempColor.rgbtBlue));
	hOldBrush = SelectBrush(hdc, hBrush);
	POINT ppt1[4] = { { in.GetShapeXCenter() - in.GetHorizDiagonal() / 2, in.GetShapeYCenter() },{ in.GetShapeXCenter(), in.GetShapeYCenter() - in.GetVertDiagonal() / 2 },{ in.GetShapeXCenter() + in.GetHorizDiagonal() / 2, in.GetShapeYCenter() },{ in.GetShapeXCenter(), in.GetShapeYCenter() + in.GetVertDiagonal() / 2 } };
	Polygon(hdc, ppt1, 4);
	// �������� � �������� ����������� ���������� ���� 
	SelectPen(hdc, hOldPen);
	// �������� � �������� ����������� ���������� ����� 
	SelectBrush(hdc, hOldBrush);
	// ������� ����
	DeletePen(hPen);
	// ������� �����
	DeleteBrush(hBrush);
}