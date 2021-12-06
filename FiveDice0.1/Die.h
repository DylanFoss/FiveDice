#pragma once
#include <random>
#include <Windows.h>
#include <time.h> 

class Die
{
	private:

		int m_value;
		int screenWidth;
		bool held;

		wchar_t die[5][9] =
		{
			{' ', '-', '-', '-', '-', '-', '-', '-', ' '},
			{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
			{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
			{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
			{' ', '-', '-', '-', '-', '-', '-', '-', ' '}
		};

	public:

		void Roll();

		Die();

		Die(int value);

		void draw(wchar_t* screen, int x, int y);
		void drawFace(wchar_t* screen, int x, int y);

		void setValue(int value) { m_value = value;};
		int getValue() const { return m_value;};

		void setHeld(bool value) { held = value; };
		bool getHeld() { return held;};

		void swap() { held ? held = false : held = true;};


};

bool operator< (const Die& a, const Die& b);
bool operator> (const Die& a, const Die& b);
bool operator== (const Die& a, const Die& b);
int operator+ (const Die& a, const Die& b);
