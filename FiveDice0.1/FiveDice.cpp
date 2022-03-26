// FiveDice0.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include "Dice.h"
#include "ScoreTable.h"
#include "Player.h"
#include "PlayerTable.h"

//screen definitions

int screenWidth = 120;
int screenHeight = 40;
wchar_t* screen;
HANDLE console;
DWORD dwBytersWritten;

Dice dice;
Die die;
Player player;
Player* x = &player;

std::vector<Player*> players;

ScoreTable scoreTable = ScoreTable(dice);
PlayerTable playerTable = PlayerTable(&players);

int menuCounter = 0;
int playerCounter = 0;

int turn = 0;
int roundCounter = 0;
enum gameState { menu = 0, game = 1, scoreboard = 2 };
gameState state;

//inputs
bool bKeyDown = false, bKeyUp = false, bKeyEnter = false, bKeySpace = false, bKeyOne = false, bKeyTwo = false, bKeyThree = false, bKeyFour = false, bKeyFive = false;
bool bKeyDownOld = false, bKeyUpOld = false, bKeyEnterOld = false, bKeySpaceOld = false, bKeyOneOld = false, bKeyTwoOld = false, bKeyThreeOld = false, bKeyFourOld = false, bKeyFiveOld = false;

void initialise()
{
	state = menu;
}

int main()
{
	wchar_t* screen = new wchar_t[screenWidth * screenHeight];
	for (int i = 0; i < screenWidth * screenHeight; i++) screen[i] = L' ';
	HANDLE console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(console);
	DWORD dwBytersWritten = 0;

	initialise();

	while (1)
	{
		//timing

		//input

		bKeyUp = (0x8000 & GetAsyncKeyState((unsigned char)(VK_UP))) != 0;
		bKeyDown = (0x8000 & GetAsyncKeyState((unsigned char)(VK_DOWN))) != 0;
		bKeySpace = (0x8000 & GetAsyncKeyState((unsigned char)(VK_SPACE))) != 0;
		bKeyEnter = (0x8000 & GetAsyncKeyState((unsigned char)(VK_RETURN))) != 0;

		bKeyOne = (0x8000 & GetAsyncKeyState((unsigned char)(0x31))) != 0;
		bKeyTwo = (0x8000 & GetAsyncKeyState((unsigned char)(0x32))) != 0;
		bKeyThree = (0x8000 & GetAsyncKeyState((unsigned char)(0x33))) != 0;
		bKeyFour = (0x8000 & GetAsyncKeyState((unsigned char)(0x34))) != 0;
		bKeyFive = (0x8000 & GetAsyncKeyState((unsigned char)(0x35))) != 0;

		switch (state)
		{
		case(menu):

			if (bKeyEnter && !bKeyEnterOld)
			{
				for (int i = 0; i < menuCounter + 1; i++)
					players.push_back(new Player);

				state = game;
			}

			if (bKeyUp && !bKeyUpOld)
			{
				if (menuCounter == 0)
				{
					menuCounter = 3;
				}
				else
				{
					menuCounter--;
				}
			}

			if (bKeyDown && !bKeyDownOld)
			{
				if (menuCounter == 3)
				{
					menuCounter = 0;
				}
				else
				{
					menuCounter++;
				}
			}

			wsprintf(&screen[7 * screenWidth + screenWidth / 2 - 10], L"Select # of Players:");
			wsprintf(&screen[8 * screenWidth + screenWidth / 2 - 10], L"--------------------");

			wsprintf(&screen[11 * screenWidth + screenWidth / 2 - 5], L"1 Player");
			wsprintf(&screen[12 * screenWidth + screenWidth / 2 - 5], L"2 Players");
			wsprintf(&screen[13 * screenWidth + screenWidth / 2 - 5], L"3 Players");
			wsprintf(&screen[14 * screenWidth + screenWidth / 2 - 5], L"4 Players");

			wsprintf(&screen[(11 + menuCounter) * screenWidth + screenWidth / 2 + 7], L"<-");

			break;

		case(game):

			switch (turn)
			{
				// the turn after last turn, you have to roll.
			case(0):

				menuCounter = 0;

				if (bKeySpace && !bKeySpaceOld)
				{
					dice.Roll();
					turn++;
				}

				wsprintf(&screen[(11) * screenWidth + screenWidth / 2 - 3], L"ROLL!");

				break;

			case(1):
			case(2):

				if (bKeySpace && !bKeySpaceOld)
				{
					dice.Roll();
					turn++;
				}

				if (bKeyOne && !bKeyOneOld)
				{
					dice.getDice()[0].swap();
				}

				if (bKeyTwo && !bKeyTwoOld)
				{
					dice.getDice()[1].swap();
				}

				if (bKeyThree && !bKeyThreeOld)
				{
					dice.getDice()[2].swap();
				}

				if (bKeyFour && !bKeyFourOld)
				{
					dice.getDice()[3].swap();
				}

				if (bKeyFive & !bKeyFiveOld)
				{
					dice.getDice()[4].swap();
				}

			case(3):

				if (bKeyUp && !bKeyUpOld)
				{
					if (menuCounter == 0)
					{
						menuCounter = 12;
					}
					else
					{
						menuCounter--;
					}
				}

				if (bKeyDown && !bKeyDownOld)
				{
					if (menuCounter == 12)
					{
						menuCounter = 0;
					}
					else
					{
						menuCounter++;
					}
				}

				if (bKeyEnter && !bKeyEnterOld)
				{
					if (!players[playerCounter]->getChecked()[menuCounter])
					{
						players[playerCounter]->setScore(dice.getScore()[menuCounter], menuCounter);

						for (int i = 0; i < 5; i++)
						{
							dice.getDice()[i].setHeld(false);
						}
						turn = 0;

						if (playerCounter < players.size() - 1)
						{
							playerCounter++;
						}
						else
						{
							playerCounter = 0;
							roundCounter++;
						}
					}
				}
				break;

			}

			if (roundCounter == 13)
			{
				state = scoreboard;
			}

			//display

			dice.draw(screen, 35, 4, 5);
			scoreTable.draw(screen, 5, 8);
			playerTable.draw(screen, 95, 8);

			if (menuCounter < 6)
			{
				if (players[playerCounter]->getChecked()[menuCounter])
				{
					wsprintf(&screen[(10 + menuCounter) * screenWidth + screenWidth / 2 - 30], L"X");
				}
				else
				{
					wsprintf(&screen[(10 + menuCounter) * screenWidth + screenWidth / 2 - 30], L"<-");
				}
			}
			if (menuCounter >= 6)
			{
				if (players[playerCounter]->getChecked()[menuCounter])
				{
					wsprintf(&screen[(13 + menuCounter) * screenWidth + screenWidth / 2 - 30], L"X");
				}
				else
				{
					wsprintf(&screen[(13 + menuCounter) * screenWidth + screenWidth / 2 - 30], L"<-");
				}
			}

					break;

			case(scoreboard):

				if (bKeySpace && !bKeySpaceOld)
				{
					for (Player* player : players)
						delete player;

					players.clear();

					menuCounter = 0;
					roundCounter = 0;
					playerCounter = 0;

					state = menu;
				}

				for (int i = 0; i < players.size(); i++)
					wsprintf(&screen[(10 + i) * screenWidth + screenWidth / 2 - 7], L"P%d Score: %d", i+1,players[i]->getScoreTotal());
				wsprintf(&screen[15 * screenWidth + screenWidth / 2 - 16], L"Press 'Space' to return to menu!");
					break;
		}

		bKeyUpOld = bKeyUp;
		bKeyDownOld = bKeyDown;
		bKeySpaceOld = bKeySpace;
		bKeyEnterOld = bKeyEnter;

		bKeyOneOld = bKeyOne;
		bKeyTwoOld = bKeyTwo;
		bKeyThreeOld = bKeyThree;
		bKeyFourOld = bKeyFour;
		bKeyFiveOld = bKeyFive;

		// banner
		for (int i = 0; i < screenWidth; i++)
		{
			screen[i] = L'=';
			screen[2 * screenWidth + i] = L'=';
		}
		wsprintf(&screen[screenWidth + screenWidth / 2 - 4], L"Five Dice");

		if (state == game)
		{
			wsprintf(&screen[screenWidth + screenWidth / 2 + 10], L"Current Turn: %d", turn);
			wsprintf(&screen[screenWidth + screenWidth / 2 + 30], L"Current Player: P%d", playerCounter + 1);

			wsprintf(&screen[screenWidth + screenWidth / 2 - 30], L"Current Round: %d", roundCounter);
		}


		WriteConsoleOutputCharacter(console, screen, screenWidth * screenHeight, { 0,0 }, &dwBytersWritten);
		for (int i = 0; i < screenWidth * screenHeight; i++) screen[i] = L' ';
	}
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
