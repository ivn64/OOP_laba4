#include "FilledRhombus.h"

void FilledRhombus::Draw(HDC hdc)
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
	// выбираем в контекст отображения предыдущее перо 
	SelectPen(hdc, hOldPen);
	// выбираем в контекст отображения предыдущую кисть 
	SelectBrush(hdc, hOldBrush);
	// удаляем перо
	DeletePen(hPen);
	// удаляем кисть
	DeleteBrush(hBrush);
}