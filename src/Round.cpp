#include <string>
#include "../include/Round.h"
using namespace std;

string Round::printRound()
{
	return "P" + to_string(this->getP1().getID()) + " VS P" + to_string(this->getP2().getID());
}