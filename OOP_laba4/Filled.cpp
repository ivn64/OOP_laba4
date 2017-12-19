#include "Filled.h"

Filled::Filled()
{
	filled—olor.rgbtRed = 255;
	filled—olor.rgbtGreen = 0;
	filled—olor.rgbtBlue = 0;
}
RGBTRIPLE Filled::GetFilled—olor()
{
	return filled—olor;
}
void Filled::SetFilled—olor(BYTE red, BYTE green, BYTE blue)
{
	filled—olor.rgbtRed = red;
	filled—olor.rgbtGreen = green;
	filled—olor.rgbtBlue = blue;
}