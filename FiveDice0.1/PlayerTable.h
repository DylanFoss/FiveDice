#pragma once
#include "Player.h"
#include <Windows.h>
#include <vector>
class PlayerTable
{
private:

	std::vector<Player*>* scoresToDraw;

public:

	PlayerTable(std::vector<Player*>* player);

	void draw(wchar_t* screen, int x, int y);
};
