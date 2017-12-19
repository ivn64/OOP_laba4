#pragma once

#include "Filled.h"
#include "Rhombus.h"

class FilledRhombus : public Rhombus, public Filled
{
public:
	void Draw(HDC);
};