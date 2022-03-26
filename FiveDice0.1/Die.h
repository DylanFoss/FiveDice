#pragma once
#include <random>
#include <time.h> 

class Die
{
	private:

		int m_value;
		int screenWidth;
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


};

bool operator< (const Die& a, const Die& b);
bool operator> (const Die& a, const Die& b);
bool operator== (const Die& a, const Die& b);
int operator+ (const Die& a, const Die& b);
