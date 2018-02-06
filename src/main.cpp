#include <iostream>
#include <string>
#include "../include/Tournament.h"
#include "../include/Player.h"
#include "../include/Round.h"

int main()
{	
	int playerNum;
	cout << "Please enter the number of players that will be entering the tournament.\n";
	cin >> playerNum;

	Tournament t(playerNum);
	if (playerNum % 2 != 0) //Inform of bye if odd # of players
		cout << "*Note*: The number of players is odd. Any player playing against another with the ID \"-1\" gets\na bye and must wait for the next round.\n\n";

	cout << "Matchups successfully created.\n2 waves of " << t.getMaxRounds() << " rounds.\n\n";

	string in;
	cout << "==Controls== \n\"List\" - Print all matchups\n\"Write\" - Output all matchups as individual .txt files.\n\"Exit\" - Close the program.\n";	
	getline(cin, in);

	while (in != "EXIT")
	{
		getline(cin, in);
		for (auto &c : in) //Change to uppercase for parsing
			c = toupper(c);

		if (in == "LIST")
		{
			t.printRounds();
			continue;
		}

		if (in == "WRITE")
		{
			t.writeRounds();
			cout << "Rounds successfully written to the /out/ directory.\nYou should now find this folder in the program's directory.\n";
			continue;
		}
		if (in == "EXIT")
			break;

		cout << "Could not parse " << in << " as a command.\n";
	}

}
