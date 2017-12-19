#pragma once
#include <windows.h>

class Shape
{
protected:
	int shapeXCenter;
	int shapeYCenter;
public:
	Shape();
	virtual void Draw(HDC) = 0;
	void SetShapeXCenter(int);
	void SetShapeYCenter(int);
	void MoveShapeXCenter(int);
	void MoveShapeYCenter(int);
	int GetShapeXCenter();
	int GetShapeYCenter();
};