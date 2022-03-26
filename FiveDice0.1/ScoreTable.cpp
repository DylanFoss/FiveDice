#include "ScoreTable.h"

ScoreTable::ScoreTable(Dice& dice) : diceToDraw(dice)
{
};

//TO-DO: use multi-dimensional arrays to initalise table, then loop // take in x and y parameters
void ScoreTable::draw(wchar_t* screen, int x, int y)
{
	int screenWidth = 120;
	int screenHeight = 40;

	wsprintf(&screen[y * screenWidth + x], L"Upper Table:");
	wsprintf(&screen[(y + 1) * screenWidth + x], L"------------");

	wsprintf(&screen[(y + 2) * screenWidth + x], L"Total Aces");
	wsprintf(&screen[(y + 3) * screenWidth + x], L"Total Twos");
	wsprintf(&screen[(y + 4) * screenWidth + x], L"Total Threes");
	wsprintf(&screen[(y + 5) * screenWidth + x], L"Total Fours");
	wsprintf(&screen[(y + 6) * screenWidth + x], L"Total Fives");
	wsprintf(&screen[(y + 7) * screenWidth + x], L"Total Sixes");

	wsprintf(&screen[(y + 9) * screenWidth + x], L"Lower Table:");
	wsprintf(&screen[(y + 10) * screenWidth + x], L"------------");

	wsprintf(&screen[(y + 11) * screenWidth + x], L"Three of a Kind");
	wsprintf(&screen[(y + 12) * screenWidth + x], L"Four of a Kind");
	wsprintf(&screen[(y + 13) * screenWidth + x], L"Full House");
	wsprintf(&screen[(y + 14) * screenWidth + x], L"Small Straight");
	wsprintf(&screen[(y + 15) * screenWidth + x], L"Large Straight");
	wsprintf(&screen[(y + 16) * screenWidth + x], L"Yatzhee");
	wsprintf(&screen[(y + 17) * screenWidth + x], L"Chance");

	for (int i = 0; i < 6; i++)
	{
		int a = diceToDraw.getScore()[i];
		wsprintf(&screen[((y + 2) + i) * screenWidth + (x+17)], L": %d", a);
	}

	for (int i = 0; i < 7; i++)
	{
		int a = diceToDraw.getScore()[i+6];
		wsprintf(&screen[((y + 11) + i) * screenWidth + (x+17)], L": %d", a);
	}
};