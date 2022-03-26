#pragma once
#include <array>
#include <numeric>
class Player
{
	private:
		std::array<int, 13> scores;
		std::array<bool, 13> checked;

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

		Player();

		std::array<int, 13>& getScores(){ return scores; };
		void setScore(int score, int arrayElement) 
		{ 
			scores[arrayElement] = score; 
			setChecked(arrayElement); 
		};

		std::array<bool, 13>& getChecked() { return checked; };
		void setChecked(int arrayElement) { checked[arrayElement] = true; };

		int getUpperTotal() { return std::accumulate(scores.begin(), scores.end()-6, 0); };
		int getLowerTotal() { return std::accumulate(scores.begin()+5, scores.end(), 0); };
		int getScoreTotal() { return std::accumulate(scores.begin(), scores.end(), 0); };

		
};

