#pragma once

#include <Windows.h>
#include <windowsx.h>

#include "FilledRhombus.h"

class CombiRhombus : public FilledRhombus
{
protected:
	FilledRhombus in;
public:
	CombiRhombus();
	void Draw(HDC);
	void SetInXCenter(int);
	void SetInYCenter(int);
	void SetInVertDiagonal(int);
	void SetInHorizDiagonal(int);
	void SetInFrame—olor(BYTE, BYTE, BYTE);
	void SetInFilled—olor(BYTE, BYTE, BYTE);
	void MoveXCombiRhombus(int);
	void MoveYCombiRhombus(int);
};