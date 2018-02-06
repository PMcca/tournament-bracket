#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

#ifdef _WIN32
#include <direct.h>
#endif

#ifdef linux
#include <sys/stat.h>
#endif

#include <cstdio>
#include <stdio.h>
#include "../include/Tournament.h"
#include "../include/Round.h"
#include "../include/Player.h"

Tournament::Tournament(int playerCount)
{
	(playerCount % 2 == 0) ? oddPlayerCount = false : oddPlayerCount = true; //See if there are odd # of players		

	for (int i = 0; i < playerCount; i++) //Load list of players
	{
		players.push_back(*(new Player(i + 1)));
	}

	if (oddPlayerCount)//Add dummy player if odd # of players
	{
		players.push_back(*(new Player(true)));
	}
	this->MAX_ROUNDS = players.size() - 1;

	calcRounds(); //Calculate rounds for tournament
}

vector<Round>* genRound(vector<Player> playerList, bool isWave2) //Generate a round based on the list of players given 
{	
	vector<Round> *newRound = new vector<Round>;
	vector<Player> ::iterator itB = playerList.begin();
	vector<Player> ::iterator itE = playerList.end() - 1;
		

	for (int i = 0; i < playerList.size() / 2; i++)//# of Matches
	{
		Round *r = (isWave2 ? new Round(*itE, *itB) : new Round(*itB, *itE)); //Swap starting players if in wave 2		
		newRound->push_back(*r);
		itB++;
		itE--;
	}
	return newRound;
}

void Tournament::calcRounds()
{
	const int MAX_ROUNDS = players.size() -1;

	vector<Player> playersC(players); //Copy of players

	vector<Round> *currentRound;

	for (int w = 0; w < 2; w++) //Waves 1 & 2
	{
		for (int i = 0; i < MAX_ROUNDS; i++)//# of Rounds
		{
			if (w > 0 && i == 0) //Reset player list in wave 2
			{
				playersC.clear();
				playersC = players;				
			}

			if (i == 0) //Base-case for first iteration- does not rotate players
			{
				currentRound = genRound(playersC, (w>0));
				rounds.push_back(*currentRound); //Add new list of matches to rounds vector
				continue;
			}

			rotate(playersC.begin() + 1, playersC.end() - 1, playersC.end()); //With player 1 fixed, shift others one to the right
			currentRound = genRound(playersC, (w>0));

			rounds.push_back(*currentRound);
		}
	}
}


void flushDirectory() //Remove all previously generated output files
{
	ifstream meta("out/meta.txt");
	string fName;

	while (getline(meta, fName)) //Get all filenames 
	{					
		remove(fName.c_str()); //Delete corresponding files
	}
	meta.close();
	
	ofstream metaD("out/meta.txt", ios::trunc);//Clear meta file
	metaD.close();
}

void appendMetaFile(string fname) //Meta file used for flushing directory
{
	ofstream meta("out/meta.txt", ios::app);
	meta << fname << endl;
	meta.close();
}

string genFName(int w, int r) //Return a string for a filename of format "out/Wx-Ry.txt"
{
	const string EXT = ".txt";
	string fName = "out/W" + to_string(w) + "-R" + to_string(r) + EXT;
	appendMetaFile(fName);
	return fName;
}

void Tournament::printRounds() //Print list of rounds to console
{
	int waveCount = 1, roundCount = 1;
	for (vector<Round> vec : rounds)
	{
		cout << "Wave " << waveCount << ", Round " << roundCount << "{\n";
		for (Round r : vec)
		{
			cout << r.printRound() << endl;
		}
		cout << "}\n\n";
		roundCount++;

		if (roundCount > this->MAX_ROUNDS)
		{
			waveCount++;
			roundCount = 1;
		}

	}
}

void Tournament::writeRounds() //Write list of rounds to disk in .txt format
{
#ifdef _WIN32
	_mkdir("out"); //Create output directory
#endif

#ifdef linux
	mkdir("out", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

	flushDirectory(); //Clear all pre-existing files
	
	ofstream outFile;
	int waveCount = 1, roundCount = 1;

	for (vector<Round> vec : rounds) 
	{
		outFile.open(genFName(waveCount, roundCount)); //Open new file for given wave/round
		for (Round r : vec) //For all individual rounds in given vector
		{		
			outFile << r.printRound() << endl;
		}
		outFile.close();
		roundCount++;

		if (roundCount > this->MAX_ROUNDS)
		{
			roundCount = 1;
			waveCount++;
		}
	}
}
