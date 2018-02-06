/*
*   Tournament is the control infastructure used to handle all general tournament-related
*   activities, such as determining storing player and round data, calculating round matchups
*   and handling the writing of rounds to disk.
*/
#pragma once
#include <vector>
#include <iostream>
#include "Player.h"
#include "Round.h"
using namespace std;

class Tournament {
private:
	int MAX_ROUNDS;
	bool oddPlayerCount;

	vector<Player> players;//Collection of participating players
	vector<vector<Round>> rounds;//All player pairings for next round

public:
	Tournament(int playerCount);	
	void calcRounds(); //Determine pairings for next wave of rounds
	void printRounds(); //Print all rounds to console
	void writeRounds(); //Write rounds to "/out/" as .txt files
	int getMaxRounds() { return this->MAX_ROUNDS; }
};