#pragma once
#include "Die.h"
#include <vector>
#include <array>
#include <string>  
class Dice
{
	private:

		std::array<Die, 5> dice;
		std::array<int, 13> scores;

		//current scores if each rule is applied

		// upper table
		int score_Aces;
		int score_Twos;
		int score_Threes;
		int score_Fours;
		int score_Fives;
		int score_Sixes;

		// lower table
		int score_ThreeOfAKind;
		int score_FourOfAKind;
		int score_FullHouse;
		int score_SmallStraight;
		int score_LargeStraight;
		int score_Yahtzee;
		int score_Chance;

	public:

		Dice();

		void Roll();
		
		void updateScores();

		void resetScores();

		void match();
		
		void printScores();

		void draw(wchar_t* screen, int x, int y, int number);

		std::array<Die, 5>& getDice();

		std::array<int, 13>& getScore();

};