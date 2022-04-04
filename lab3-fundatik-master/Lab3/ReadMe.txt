Assignment: Lab 3
Author: Funda Atik
E-mail: fatik@wustl.edu

Files: 
Lab3.cpp
Util.h
Util.cpp
TicTacToeGame.h
TicTacToeGame.cpp
ReadMe.txt

=======================

# Design Decisions:
## Desing of TicTacToeGame class

- struct game_piece
- enum class piece_code
- index() function of TicTacToeGame 
- std::vector<game_piece> gameBoard_
- unsigned int DIM_X, DIM_Y
- string DELIM = " "

-- I define "game_piece" structure to represent pieces on a game board. 
-- The game board is initialized in the constructor of TicTacToeGame. 
-- TicTacToeGame class keeps the representation of a game board in a vector consisting of game_piece objects. 
-- An index of a game piece on a game board is computed by index() function. 
-- The index computation is x*DIM_X + y. 
-- DIM_X_ and DIM_Y_ keep 2D dimensions of the game board. 
-- These dimensions are defined 5x5 as default in the default constructor of TicTacToeGame. 
-- However, the program defines another constructor which takes dimensions as parameters. 
-- Both contructors populate the game_board vector with EMPTY game pieces according to given dimensions.

- std::vector<std::pair<int,int>> movesSoFar_
- bool get_coordinates(std::string line, unsigned int& x, unsigned int& y)

-- I also define another vector which keeps a pair of coordinates that are played so far by each user. 
-- Player X plays the first move, and player O plays the second move. 
-- Both players play the game in turns so odd number of moves correspond to the moves of Player X, whereas even number of moves correspond to the moves Player O. 
-- Therefore, I can decide which moves belongs to which player without defining extra structures. 
-- get_coordinates() function takes a string line as parameter checks whether it starts with a comma-seperated two unsigned decimal integers. If it is the case, it returnss true. Otherwise, it returns false.

- getMaxMoves() and getNumOfTurns():
-- I define them as private functions because I only use them when I print out the game statistics.

# Methods:

Method 1. std::ostream& operator<< (std::ostream& ost, const TicTacToeGame& game)
- Print the game board by starting upper left corner (DIM_Y,DIM_X), go right and bottom the game board's (0,0) coordinates are at the bottom left corner 
- Print also row and column indices, the dimension of game board is DIM_Y x DIM_X 
- The dimension of area that a user can put a game piece is (DIM_Y-2) x (DIM_X), only inner cells are valid .
- The game content are kept in stringstream 

Method 2. bool done()
- Check if there is a winner. It returns true 3-Xs or Os are a vertical, horizontal or diagonal line, otherwise returns false
- There are two diagonals which are orthogonal to each other. 
- One that starts from the bottom-left corner to the upper-right corner. 
- Other one that starts from the uppe-left corner to the bottom right corner
- First diagonal direction: check if 3-Xs exist in a diagonal line , start from bottom left, increment both x and y.
- Second diagonal direction: check if 3-Xs exist in a diagonal line,  start from upper left, decrement y, increment x.
	
Method 3. bool draw()
- Check if it is a draw. It return false if empty spaces exist or if done() returns true, otherwise it returns true.
- I don't check whether it remains any winning moves or not, users keep playing until all empty spaces are occupied with a valid piece or someone wins the game.

Method 4. int prompt(unsigned int &x, unsigned int &y) 
- Get a line from the user. If the line say "quit", the game ends and the player quits the game without making a valid move.
- A valid line should starts with comma-seperated coordinates of two unsigned decimal integers. 
- If the user neither types "quit" or valid coordinates, the program re-prompts again.
- If the user enter valid comma-seperated coordinates, the program needs to perform following verifications:
	-- check if coordinates is in valid bounds [1:DIM_X_-2, 1:DIM_Y_-2]
	-- check if the place is empty
- If it verifies that the move is valid, then it stops asking user to type new coordinates.

Helper method 4.1. bool TicTacToeGame::get_coordinates(std::string line, unsigned int& x, unsigned int& y)
- Find the index of the comma chracters in the user's input kept in C++ style string parameter (i.e. line)
- Replace the comma character with the space character
- Wrap the string in an istringstream
- Read signed integers
- Cast non-negative integers as unsigned intergers
- If everything goes okay, it returns true. Otherwise, it returns false.

Method 5. int turn()
- Remember whose turn it is: even moveSoFar indicates that the turn is X's, whereas odd evenSoFar Os.
- Update game piece and player name based on who has the current turn: either X or Y
- Calls prompt() to get coordinates of a valid move
- If the player quits the game without making a valid move, terminates the program and returns exit_code::EarlyQuit.
- However, if the move valid, update the game status by performing the following actions:
	-- Store valid move
	-- Place the piece on the game board
	-- Print game board
	-- Print username
	-- Print which moves are played so far by a player who has the current turn; even indices for player X, odd indices for player O

Method 6: int play()
- Users play the game in turns until someone wins or draws
// Print the game board
// Player X starts first
// Initially nobody has same pieces 3 times in a row, all valid locations are empty
// The program repeatedly calls turn(), done(), and if not done(), then draw() until someone wins or draws or quits the game.
- When the game stops, the programs perform following actions:
	-- Calculate the number of turns played
	-- Find out which player's turn
	-- If someone wins, the program announces the winner player, return exit_code::Success.
	-- If it is draw, the program says that it is draw; it prints out the number of turns has been played; it returns exit_code::DrawNoWinner.
	-- If someone quits, the program says which player wants to quit the game, and prints out the number of turns has been played; it returns exit_code::EarlyQuit.

# Other:
- Other details about the code are given as comments throughout the code.

=======================

Part 8. It builds without any error and warnings.

Rebuild started...
1>------ Rebuild All started: Project: Lab3, Configuration: Debug Win32 ------
1>Lab3.cpp
1>TicTacToeGame.cpp
1>Util.cpp
1>Generating Code...
1>Lab3.vcxproj -> C:\Users\funda\source\repos\cse332s-sp21-wustl\lab3-fundatik\Lab3\Debug\Lab3.exe
========== Rebuild All: 1 succeeded, 0 failed, 0 skipped ==========


# Test Cases

1. Missing command argument, wrong number of arguments

- Case 1: missing
Lab3.exe
- Case 2: wrong number of arguments
Lab3.exe one two
- Case 3: wrong string
Lab3.exe Tictactoegame


- Output:
Lab3.exe requires 1 argument.
usage: Lab3.exe TicTacToeGame

It exited with code 1  (exit_code::IncorrectArguments).

- Case 4: Proper command argument
Lab3.exe TicTacToeGame

- Output: as expected

4
3
2
1
0
  0 1 2 3 4

Player X's turn...
Please enter a comma-seperated coordinate in [1:3,1:3] or type 'quit'

2. Non-zero returns

- Case 1: When a user quits early, the program exited with code 3 (exit_code::EarlyQuit).
-- Quits without any making any move:

C:\Users\funda\source\repos\cse332s-sp21-wustl\lab3-fundatik\Lab3\Debug>Lab3.exe TicTacToeGame

4
3
2
1
0
  0 1 2 3 4

Player X's turn...
Please enter a comma-seperated coordinate in [1:3,1:3] or type 'quit'
quit
You entered: quit
someone wants to quit the game.
is it draw? # moves: 0, max: 9
Player O quits! 0 turns have been played.

-- Quits without after tthe first move:
C:\Users\funda\source\repos\cse332s-sp21-wustl\lab3-fundatik\Lab3\Debug>Lab3.exe TicTacToeGame

4
3
2
1
0
  0 1 2 3 4

Player X's turn...
Please enter a comma-seperated coordinate in [1:3,1:3] or type 'quit'
1,2
You entered: 1,2

4
3
2
1     X
0
  0 1 2 3 4


Player X : 1, 2;
is it draw? # moves: 1, max: 9
Player Y's turn...
Please enter a comma-seperated coordinate in [1:3,1:3] or type 'quit'
quit
You entered: quit
someone wants to quit the game.
is it draw? # moves: 1, max: 9
Player X quits! 1 turns have been played.

--- echo %errorlevel%
3


- Case 2: Draw

4
3   X X O
2   O O X
1   X O X
0
  0 1 2 3 4


Player X : 1, 1; 1, 3; 2, 3; 3, 1; 3, 2;
is it draw? # moves: 9, max: 9
Draw! 9 turns have been played. No winning moves remained.



C:\Users\funda\source\repos\cse332s-sp21-wustl\lab3-fundatik\Lab3\Debug\Lab3.exe (process 12096) exited with code 4 (exit_code::DrawNoWinner).

3. When the game is successful - when someone wins - the program returns zero.

Output: 
4
3   X
2   O X O
1   X O X
0
  0 1 2 3 4


Player X : 1, 1; 1, 3; 2, 2; 3, 1;
Won! Player X is the winner!

C:\Users\funda\source\repos\cse332s-sp21-wustl\lab3-fundatik\Lab3\Debug\Lab3.exe (process 13328) exited with code 0 (exit_code::Success). 


4. When the user enters wrong coordinate formats

Current Game Board:
4
3
2
1   X
0
  0 1 2 3 4

Player X : 1, 1;
is it draw? # moves: 1, max: 9
Player Y's turn...
Please enter a comma-seperated coordinate in [1:3,1:3] or type 'quit'
1,1
You entered: 1,1
Sorry, the place is not empty. Try again!
Please enter a comma-seperated coordinate in [1:3,1:3] or type 'quit'
1,4
You entered: 1,4
Careful, you entered out of bound. Try again!
Please enter a comma-seperated coordinate in [1:3,1:3] or type 'quit'
1,,2
You entered: 1,,2
Please enter a comma-seperated coordinate in [1:3,1:3] or type 'quit'
1,-2
You entered: 1,-2
Please enter a comma-seperated coordinate in [1:3,1:3] or type 'quit'
2,2
You entered: 2,2

4
3
2     O
1   X
0
  0 1 2 3 4


Player Y : 2, 2;