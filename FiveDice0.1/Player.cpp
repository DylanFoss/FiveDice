#include "Player.h"

Player::Player()
{
	for (int i = 0; i < 13; i++)
		scores[i] = 0;

	for (int i = 0; i < 13; i++)
		checked[i] = false;
}