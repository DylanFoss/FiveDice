#include "Dice.h"
#include <iostream>
#include <numeric>

std::array<Die, 5> dice;
std::array<int, 13> scores;


Dice::Dice()
{
	// upper table
	score_Aces = 0;
	score_Twos = 0;
	score_Threes = 0;
	score_Fours = 0;
	score_Fives = 0;
	score_Sixes = 0;

	// lower table
	score_ThreeOfAKind = 0;
	score_FourOfAKind = 0;
	score_FullHouse = 0; // one pair one triple
	score_SmallStraight = 0; // 4 consecutively
	score_LargeStraight = 0; // 12345 or 23456
	score_Yahtzee = 0;	// five of a kind
	score_Chance = 0; // adds all dice values up

	srand(time(NULL));
	for (int i = 0; i < 5; i++)
		dice[i] = Die();

	for (int i = 0; i < 13; i++)
		scores[i] = 0;

	updateScores();
}

void Dice::updateScores()
{
	resetScores();

	scores[0] = std::count(dice.begin(), dice.end(), 1);
	scores[1] = std::count(dice.begin(), dice.end(), 2) * 2;
	scores[2] = std::count(dice.begin(), dice.end(), 3) * 3;
	scores[3] = std::count(dice.begin(), dice.end(), 4) * 4;
	scores[4] = std::count(dice.begin(), dice.end(), 5) * 5;
	scores[5] = std::count(dice.begin(), dice.end(), 6) * 6;
	match();
	scores[12] = std::accumulate(dice.begin(), dice.end(), 0);
}

void Dice::resetScores()
{
	for (int i = 0; i < 13; i++)
		scores[i] = 0;
}

void Dice::Roll()
{
	for (int i = 0; i < 5; i++)
		dice[i].Roll();

	std::sort(dice.begin(), dice.end()); //sort array for checking scores

	updateScores();
}

void Dice::match()
{
	// pattern matching function
	auto PatternMatch = [&](const std::array<Die, 5>& arr, const std::string pattern) -> bool
	{
		uint8_t n = 0;
		bool match = true;

		for (int i = 0; i < 5; i++)
		{
			if (pattern[i] == 'n') // pattern element is N (repeated value)
			{
				if (n == 0)
				{
					n = arr[i].getValue();
				}
				else
				{
					match &= (arr[i].getValue() == n);
				}
			}
			else if (pattern[i] == '?')// pattern element is ? (wildcard)
			{
				match &= true;
			}
			else // pattern element is numeric (consecutive)
			{
				// convers a numeric char to a matching integer.
				match &= ((pattern[i] - '0') == dice[i].getValue());
			}
		}
		return match;
	};

	// nnn??, ?nn?, ??nnn - Three of a kind
	if (PatternMatch(dice, "nnn??") || PatternMatch(dice, "??nnn") || PatternMatch(dice, "?nnn?"))
	{
		scores[6] = 3 * dice[2].getValue();
	}
	// nnnn?. ?nnnn - Four of a kind
	if (PatternMatch(dice, "nnnn?") || PatternMatch(dice, "?nnnn"))
	{
		scores[7] = 4 * dice[1].getValue();
	}
	// nn??? & ??nnn, ???nn & nnn?? - Full House
	if (PatternMatch(dice, "nn???") && PatternMatch(dice, "??nnn") || PatternMatch(dice, "nnn??") && PatternMatch(dice, "???nn") )
	{
		scores[8] = 25;
	}
	// ?1234, 1234?, ?2345, 2345?, ?3456, 3456? - Small Straight
	if (PatternMatch(dice, "1234?") || PatternMatch(dice, "?1234") || PatternMatch(dice, "12?34")
	|| PatternMatch(dice, "2345?") || PatternMatch(dice, "?2345") || PatternMatch(dice, "23?45")
	|| PatternMatch(dice, "?3456") || PatternMatch(dice, "?3456") || PatternMatch(dice, "34?56"))
	{
		scores[9] = 30;
	}
	// 12345, 23456 - Large Straight
	if (PatternMatch(dice, "12345") || PatternMatch(dice, "23456"))
	{
		scores[10] = 40;
	}
	// nnnnn - Yahtzee
	if (PatternMatch(dice, "nnnnn"))
	{
		scores[11] = 50;
	}

}

std::array<Die,5>& Dice::getDice()
{
	return dice;
}
std::array<int, 13>& Dice::getScore()
{
	return scores;
}
;

// DEBUG: print off current scores for the current dice.
void Dice::printScores()
{
	std::cout << std::endl;
	std::cout << "Upper Table:" << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Total Aces: " << score_Aces << std::endl;
	std::cout << "Total Twos: " << score_Twos << std::endl;
	std::cout << "Total Threes: " << score_Threes << std::endl;
	std::cout << "Total Fours: " << score_Fours << std::endl;
	std::cout << "Total Fives: " << score_Fives << std::endl;
	std::cout << "Total Sixes: " << score_Sixes << std::endl;

	std::cout << std::endl;
	std::cout << "Lower Table:" << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Three of a Kind: " << score_ThreeOfAKind << std::endl;
	std::cout << "Four of a Kind: " << score_FourOfAKind << std::endl;
	std::cout << "Full House: " << score_FullHouse << std::endl;
	std::cout << "Small Straight: " << score_SmallStraight << std::endl;
	std::cout << "Large Straight: " << score_LargeStraight << std::endl;
	std::cout << "Yahtzee: " << score_Yahtzee << std::endl;
	std::cout << "Chance: " << score_Chance << std::endl;

	std::cout << "---------------" << std::endl;
	std::cout << std::endl;
}

void Dice::draw(wchar_t* screen, int x, int y, int numDice)
{
	for (int i = 0; i < numDice; i++)
	{
		dice[i].draw(screen, x+i*10, y);
	}
}
