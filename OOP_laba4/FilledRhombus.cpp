#include "FilledRhombus.h"

void FilledRhombus::Draw(HDC hdc)
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
	// �������� � �������� ����������� ���������� ���� 
	SelectPen(hdc, hOldPen);
	// �������� � �������� ����������� ���������� ����� 
	SelectBrush(hdc, hOldBrush);
	// ������� ����
	DeletePen(hPen);
	// ������� �����
	DeleteBrush(hBrush);
}