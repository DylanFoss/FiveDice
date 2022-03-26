#include "ScoreTable.h"

ScoreTable::ScoreTable(Dice& dice) : diceToDraw(dice)
{
};

//TO-DO: use multi-dimensional ararys to initalise table, then loop
void ScoreTable::draw(wchar_t* screen, int x, int y)
{
	int screenWidth = 120;
	int screenHeight = 40;

	wsprintf(&screen[9 * screenWidth + screenWidth / 2 - 55], L"Upper Table:");
	wsprintf(&screen[10 * screenWidth + screenWidth / 2 - 55], L"------------");

	wsprintf(&screen[11 * screenWidth + screenWidth / 2 - 55], L"Total Aces");
	wsprintf(&screen[12 * screenWidth + screenWidth / 2 - 55], L"Total Twos");
	wsprintf(&screen[13 * screenWidth + screenWidth / 2 - 55], L"Total Threes");
	wsprintf(&screen[14 * screenWidth + screenWidth / 2 - 55], L"Total Fours");
	wsprintf(&screen[15 * screenWidth + screenWidth / 2 - 55], L"Total Fives");
	wsprintf(&screen[16 * screenWidth + screenWidth / 2 - 55], L"Total Sixes");

	wsprintf(&screen[18 * screenWidth + screenWidth / 2 - 55], L"Lower Table:");
	wsprintf(&screen[19 * screenWidth + screenWidth / 2 - 55], L"------------");

	wsprintf(&screen[20 * screenWidth + screenWidth / 2 - 55], L"Three of a Kind");
	wsprintf(&screen[21 * screenWidth + screenWidth / 2 - 55], L"Four of a Kind");
	wsprintf(&screen[22 * screenWidth + screenWidth / 2 - 55], L"Full House");
	wsprintf(&screen[23 * screenWidth + screenWidth / 2 - 55], L"Small Straight");
	wsprintf(&screen[24 * screenWidth + screenWidth / 2 - 55], L"Large Straight");
	wsprintf(&screen[25 * screenWidth + screenWidth / 2 - 55], L"Yatzhee");
	wsprintf(&screen[26 * screenWidth + screenWidth / 2 - 55], L"Chance");

	for (int i = 0; i < 6; i++)
	{
		int a = diceToDraw.getScore()[i];

		wsprintf(&screen[(11 + i) * screenWidth + screenWidth / 2 - 38], L": %d", a);
	}

	for (int i = 0; i < 7; i++)
	{
		int a = diceToDraw.getScore()[i+6];
		wsprintf(&screen[(20 + i) * screenWidth + screenWidth / 2 - 38], L": %d", a);
	}
};