#include "Die.h"

Die::Die()
{
	m_value = (rand() % 6 + 1);
    screenWidth = 120;
};

Die::Die(int value)
{
	m_value = value;
};

void Die::Roll()
{
	m_value = (rand() % 6 + 1);
};

void Die::draw(wchar_t* screen, int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            screen[x + ((i + y) * screenWidth + j)] = die[i][j];
        }
    }

    drawFace(screen, x ,y);
};

void Die::drawFace(wchar_t* screen, int x, int y)
{
    switch (m_value)
    {
        case(1):
        {
            screen[(x + 4) + ((y + 2) * screenWidth)] = '*';
            break;
        }
        case(2):
        {
            screen[(x + 2) + ((y + 1) * screenWidth)] = '*';
            screen[(x + 6) + ((y + 3) * screenWidth)] = '*';
            break;
        }
        case(3):
        {
            screen[(x + 2) + ((y + 1) * screenWidth)] = '*';
            screen[(x + 4) + ((y + 2) * screenWidth)] = '*';
            screen[(x + 6) + ((y + 3) * screenWidth)] = '*';
            break;
        }
        case(4):
        {
            screen[(x + 2) + ((y + 1) * screenWidth)] = '*';
            screen[(x + 6) + ((y + 1) * screenWidth)] = '*';
            screen[(x + 2) + ((y + 3) * screenWidth)] = '*';
            screen[(x + 6) + ((y + 3) * screenWidth)] = '*';
            break;
        }
        case(5):
        {
            screen[(x + 2) + ((y + 1) * screenWidth)] = '*';
            screen[(x + 6) + ((y + 1) * screenWidth)] = '*';
            screen[(x + 4) + ((y + 2) * screenWidth)] = '*';
            screen[(x + 2) + ((y + 3) * screenWidth)] = '*';
            screen[(x + 6) + ((y + 3) * screenWidth)] = '*';
            break;
        }
        case(6):
        {
            screen[(x + 2) + ((y + 1) * screenWidth)] = '*';
            screen[(x + 6) + ((y + 1) * screenWidth)] = '*';
            screen[(x + 2) + ((y + 2) * screenWidth)] = '*';
            screen[(x + 6) + ((y + 2) * screenWidth)] = '*';
            screen[(x + 2) + ((y + 3) * screenWidth)] = '*';
            screen[(x + 6) + ((y + 3) * screenWidth)] = '*';
            break;
        }
    }
}

bool operator< (const Die& a, const Die& b) { return a.getValue() < b.getValue(); };
bool operator> (const Die& a, const Die& b) { return a.getValue() > b.getValue(); };
bool operator== (const Die& a, const Die& b) { return a.getValue() == b.getValue(); };
int operator+ (const Die& a, const Die& b) { return a.getValue() + b.getValue();}