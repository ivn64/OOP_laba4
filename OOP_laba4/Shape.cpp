#include "Shape.h"

Shape::Shape()
{
	shapeXCenter = 50;
	shapeYCenter = 240;
}
void Shape::SetShapeXCenter(int x)
{
	shapeXCenter = x;
}
void Shape::SetShapeYCenter(int y)
{
	shapeYCenter = y;
}
void Shape::MoveShapeXCenter(int move)
{
	shapeXCenter += move;
}
void Shape::MoveShapeYCenter(int move)
{
	shapeYCenter += move;
}
int Shape::GetShapeXCenter()
{
	return shapeXCenter;
}
int Shape::GetShapeYCenter()
{
	return shapeYCenter;
}