#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>

#include "OpenStack.h"
#include "Rhombus.h"
#include "Shape.h"
#include "Filled.h"
#include "FilledRhombus.h"
#include "CombiRhombus.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	// получаем идентификатор окна
	HWND hwnd = GetConsoleWindow();
	// получаем контекст отображения
	HDC hdc = GetDC(hwnd);
	Rhombus romb;
	FilledRhombus fr;
	CombiRhombus cr;
	Shape *figura;
	
	/*OpenStack <Rhombus> RhombusStack(10);
	romb.MoveShapeXCenter(60);
	RhombusStack.Push(romb);
	romb.MoveShapeXCenter(60);
	RhombusStack.Push(romb);
	romb.MoveShapeXCenter(60);
	RhombusStack.Push(romb);
	RhombusStack.Print(hdc);
	cin.get();
	RhombusStack.Pop();
	RhombusStack.Print(hdc);*/

	/*OpenStack <FilledRhombus> FilledRhombusStack(10);
	fr.MoveShapeXCenter(60);
	FilledRhombusStack.Push(fr);
	fr.MoveShapeXCenter(60);
	FilledRhombusStack.Push(fr);
	fr.MoveShapeXCenter(60);
	FilledRhombusStack.Push(fr);
	FilledRhombusStack.Print(hdc);
	cin.get();
	FilledRhombusStack.Pop();
	FilledRhombusStack.Print(hdc);*/

	OpenStack <CombiRhombus> CombiRhombusStack(10);
	cr.MoveXCombiRhombus(110);
	CombiRhombusStack.Push(cr);
	cr.MoveXCombiRhombus(110);
	CombiRhombusStack.Push(cr);
	cr.MoveXCombiRhombus(110);
	CombiRhombusStack.Push(cr);
	CombiRhombusStack.Print(hdc);
	cin.get();
	CombiRhombusStack.Pop();
	CombiRhombusStack.Print(hdc);

	/*OpenStack <int> s(10);
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Print();*/
	
	cin.get();
	// освобождаем контекст отображения
	ReleaseDC (hwnd, hdc);
}