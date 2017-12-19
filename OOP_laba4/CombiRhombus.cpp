#include "CombiRhombus.h"

CombiRhombus::CombiRhombus()
{
	in.SetShapeXCenter(shapeXCenter);
	in.SetShapeYCenter(shapeYCenter);
	in.SetVertDiagonal(vertDiagonal / 2);
	in.SetHorizDiagonal(horizDiagonal / 2);
	in.SetFrameСolor(0, 150, 255);
	in.SetFilledСolor(0, 0, 0);
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
void CombiRhombus::SetInFrameСolor(BYTE r, BYTE g, BYTE b)
{
	this->in.SetFrameСolor(r, g, b);
}
void CombiRhombus::SetInFilledСolor(BYTE r, BYTE g, BYTE b)
{
	this->in.SetFilledСolor(r, g, b);
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
	// создаем перо
	HPEN hPen = CreatePen(PS_SOLID, 5, RGB(frameСolor.rgbtRed, frameСolor.rgbtGreen, frameСolor.rgbtBlue));
	// и выбираем его в контекст отображения,
	// сохраняя предыдущее перо
	HPEN hOldPen = SelectPen(hdc, hPen);
	// создаем кисть
	HBRUSH hBrush = CreateSolidBrush(RGB(filledСolor.rgbtRed, filledСolor.rgbtGreen, filledСolor.rgbtBlue));
	// и выбираем ее в контекст отображения,
	// сохраняя предыдущую кисть
	HBRUSH hOldBrush = SelectBrush(hdc, hBrush);
	POINT ppt[4] = { { shapeXCenter - horizDiagonal / 2, shapeYCenter },{ shapeXCenter, shapeYCenter - vertDiagonal / 2 },{ shapeXCenter + horizDiagonal / 2, shapeYCenter },{ shapeXCenter, shapeYCenter + vertDiagonal / 2 } };
	Polygon(hdc, ppt, 4);
	RGBTRIPLE tempColor = in.GetFrameСolor();
	hPen = CreatePen(PS_SOLID, 5, RGB(tempColor.rgbtRed, tempColor.rgbtGreen, tempColor.rgbtBlue));
	hOldPen = SelectPen(hdc, hPen);
	tempColor = in.GetFilledСolor();
	hBrush = CreateSolidBrush(RGB(tempColor.rgbtRed, tempColor.rgbtGreen, tempColor.rgbtBlue));
	hOldBrush = SelectBrush(hdc, hBrush);
	POINT ppt1[4] = { { in.GetShapeXCenter() - in.GetHorizDiagonal() / 2, in.GetShapeYCenter() },{ in.GetShapeXCenter(), in.GetShapeYCenter() - in.GetVertDiagonal() / 2 },{ in.GetShapeXCenter() + in.GetHorizDiagonal() / 2, in.GetShapeYCenter() },{ in.GetShapeXCenter(), in.GetShapeYCenter() + in.GetVertDiagonal() / 2 } };
	Polygon(hdc, ppt1, 4);
	// выбираем в контекст отображения предыдущее перо 
	SelectPen(hdc, hOldPen);
	// выбираем в контекст отображения предыдущую кисть 
	SelectBrush(hdc, hOldBrush);
	// удаляем перо
	DeletePen(hPen);
	// удаляем кисть
	DeleteBrush(hBrush);
}