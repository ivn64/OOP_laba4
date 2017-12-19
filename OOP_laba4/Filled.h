#pragma once
#include <Windows.h>

class Filled
{
protected:
	RGBTRIPLE filled—olor;
public:
	Filled();
	RGBTRIPLE GetFilled—olor();
	void SetFilled—olor(BYTE, BYTE, BYTE);
};