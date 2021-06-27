// FiveDice0.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include "Dice.h"
#include <conio.h>
#include "ScoreTable.h"

int screenWidth = 120;
int screenHeight = 40;

wchar_t* screen;
HANDLE console;
DWORD dwBytersWritten;


Dice dice;
Die die;
ScoreTable scoreTable = ScoreTable(dice);

char key;
int asciiValue;

void initialise()
{

}

void update()
{

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
		for (int i = 0; i < screenWidth; i++)
		{
			screen[i] = L'=';
			screen[2 * screenWidth + i] = L'=';
		}
		wsprintf(&screen[screenWidth + screenWidth / 2 - 4], L"Five Dice");

		key = _getch();
		asciiValue = key;

		if (asciiValue == 27)
			break;

		if (asciiValue == 32)
		{
			dice.Roll();
		}

		dice.draw(screen, 35, 4, 5);
		scoreTable.draw(screen, 0, 9);

		WriteConsoleOutputCharacter(console, screen, screenWidth * screenHeight, { 0,0 }, &dwBytersWritten);
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
