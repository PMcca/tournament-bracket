/*
*   A round represents a single round of the tournament. Each round consists
*   of a pairing of each of the participating players.
*/
#pragma once
#include "Player.h"
#include <string>
class Round
{
private:
	Player p1, p2;

public:
	Round(Player pp1, Player pp2) { p1 = pp1; p2 = pp2; }

	Player getP1() { return this->p1; }
	Player getP2() { return this->p2; }

	std ::string printRound(); //Produces the result for that round
};