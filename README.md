# Tournament Bracket
Given a set of n players, this program will produce two sets of matchups, whereby each player will play every other player exactly once per wave.
- Created in **C++ C14**
- Deployed through **CMake 3.0**

## Features
- Implements round-robin algorithm to determine each unique matchup per wave
- Algorithm ensures the "starting player" (player on left) is never the starting player again in the second wave
- Program allows for writing of each round's matchup to disk in .txt format

## Building & Using
This program is deployed using CMake 3.0. A simple call to:

`cmake .`

should suffice to build the application. Depending on your environment, this will produce a variety of files. 
- **Linux**- A makefile will be generated. Simply run `make` in the directory to build an executable of the program.
- **Windows**- Depending on what is installed (VS for example) this will generate corresponding project files, allowing you to open them in the respective IDE.

When the program starts, you will be asked to input the number of players. If you input an odd number of players, you will be notified that one player will have the ID "-1" which represents a bye. Should any player be matched up with P-1, that player should sit that round out.

Each round wave's rounds can be written to disk in a .txt format by using the command "write" in the program. This will:
- Create a folder in the root of the program folder called "out"
- Create (n-1)*2 .txt files, each one representing an individual round of matchups (where n = number of players)
- A "meta.txt" file, used by the program to manage file output

Should the meta.txt file be left in-tact, the program will automatically wipe the directory when a new instance is run.

---

### Future Features
- Allow user to choose number of waves
- Create more efficient and relatable way of identifying users
- Allow program to keep track of individual scores and produce list of final placements based on wins
- Improve deployment method
