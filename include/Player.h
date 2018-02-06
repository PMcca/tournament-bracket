/*
*   Player represents a single participant in the tournament. Players each
*	have a unique ID, ranging from 0-n, where n is # of participants.
*/
#pragma once
class Player
{
private:
	int id;	
	bool isBye;//For odd # of players

public:
	Player() {}
	Player(int pid) { this->id = pid; }
	Player(bool byeFlag) { isBye = true; id = -1; }	

	int getID() { return this->id; }	
	bool isDummy() { return this->isBye; }
};