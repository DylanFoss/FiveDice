#pragma once
#include "Dice.h"
#include <Windows.h>
class ScoreTable
{
	private:

		Dice& diceToDraw;

	public:

		ScoreTable(Dice& dice);

		void draw(wchar_t* screen, int x, int y);
};

