#include "PlayerTable.h"
PlayerTable::PlayerTable(std::vector<Player*>* players)
{
	scoresToDraw = players;
};

//TO-DO: use multi-dimensional ararys to initalise table, then loop // take in x and y parameters
void PlayerTable::draw(wchar_t* screen, int x, int y)
{
	int screenWidth = 120;
	int screenHeight = 40;

	for (int i = 0; i < scoresToDraw->size(); i++)
	{
		wsprintf(&screen[(y) * screenWidth + x + (i * 5)], L"P%d:", i+1);
		wsprintf(&screen[(y+1) * screenWidth + x + (i * 5)], L"---");

		for (int j = 0; j < 6; j++)
		{
			int a = (*scoresToDraw)[i]->getScores()[j];
			wsprintf(&screen[(y+2 + j) * screenWidth + x + (i*5)], L": %d", a);
		}

		for (int j = 0; j < 7; j++)
		{
			int a = (*scoresToDraw)[i]->getScores()[j+6];
			wsprintf(&screen[(y+11 + j) * screenWidth + x + (i * 5)], L": %d", a);
		}

		int a = (*scoresToDraw)[i]->getUpperTotal();
		wsprintf(&screen[(y+8) * screenWidth + x + (i*5)], L": %d", a);
		a = (*scoresToDraw)[i]->getLowerTotal();
		wsprintf(&screen[(y+18) * screenWidth + x + (i * 5)], L": %d", a);
		a = (*scoresToDraw)[i]->getScoreTotal();
		wsprintf(&screen[(y+20) * screenWidth + x + (i * 5)], L": %d", a);
	}
};