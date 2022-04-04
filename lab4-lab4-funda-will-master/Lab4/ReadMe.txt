Assignment: Lab 4
Group members: Funda Atik and Will Wu
E-mails: fatik@wustl.edu, willwu@wustl.edu

Files: 
Lab4.cpp
Util.h
Util.cpp
TicTacToeGame.h
TicTacToeGame.cpp
ReadMe.txt

=======================

## Part 2: We did not encounter any errors.


# For TicTacToeGame:

Command: $Lab4.exe TicTacToeGame

Test 1. Someone wins the game by placing 3 pieces in a row, vertical, diagonal, and opposite diagonal. The error code returns 0 (Success).
Test 2. Detect draw (1) before the game, (2) when the entire board is filled but there is no winner. The error code returns 4 (DrawNoWinner).
Test 3. The first player start the game but immediately quit the game. The error code returns 3 (EarlyQuit).
Test 4. The second player start the game but immediately quit the game. The error code returns 3 (EarlyQuit).
Test 5. A player wants to quit the game after playing some turns. The error code returns 3 (EarlyQuit).
Test 6. When a player enter coordinates in badly format, the program warns the user and repeatly asks for a new valid coordinates.
Warning message: You entered wrong format. Try again!
Test 7. When a player plays a piece to an unempty location, the program warns user and asks for a new valid coordinates.
Warning message: Sorry, the place is not empty. Try again!
Test 8. When a player enters coordinates which are not in the bounds of the game board, the program warns the user and repeatly asks for a new valid coordinates.
Warning message: Careful, you entered out of bound. Try again!

In all cases, the game board displays each player moves correctly and updates the number of moves played correctly.

# Check command arguments
# Design Decision #1: We return the same error code for any errors caused by wrong arguments. We think that the usage message is very clear.

Test 9.  Single arguments exits the program and shows the usage message.. The error code returns 1 (IncorrectArguments).

$ lab4.exe
usage: lab4.exe "TicTacToeGame"|"GomokuGame <nDims> <Pieces2Win>"

Test 10. 2 The second arguments should be TicTacToeGame or GomokuGame, otherwise the program exits and shows the usage message.
$ lab4.exe Tic
usage: lab4.exe "TicTacToeGame"|"GomokuGame <nDims> <Pieces2Win>"

Test 11. When the second argument is TicTacToeGame, the user should provide additional arguments.

$ lab4.exe TicTacToeGame 1
usage: lab4.exe "TicTacToeGame"|"GomokuGame <nDims> <Pieces2Win>"
$ lab4.exe TicTacToeGame 1 2
usage: lab4.exe "TicTacToeGame"|"GomokuGame <nDims> <Pieces2Win>"
$ lab4.exe TicTacToeGame 1 2 3
usage: lab4.exe "TicTacToeGame"|"GomokuGame <nDims> <Pieces2Win>"

Test 12. When the second argument is GomokuGame, the program starts with 19x19 game board.

$ lab4.exe GomokuGame
Output: 

19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
X  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19

$ Turn #  1, B's turn...
Enter a comma-seperated coordinates in [1:19,1:19] or type 'quit'. Column first, then row

Test 13. When the second argument is GomokuGame, if more than 4 arguments are given, the programs exits and shows the usage message.

$ lab4.exe GomokuGame 1 2 3
usage: lab4.exe "TicTacToeGame"|"GomokuGame <nDims> <Pieces2Win>"

Test 14. When we starts GomokuGame with different dimensions, it works as expected.

$ lab4.exe GomokuGame 10
$ lab4.exe GomokuGame 7
$ lab4.exe GomokuGame 20
$ lab4.exe GomokuGame 5


## Extra credit

Test 15. When we starts GomokuGame with different dimensions and the number of pieces to win, it works as expected. The pieces to win are updated to given argument.

$ lab4.exe GomokuGame 19 3

# design decision: When the argument for  the number of pieces to win is less than 3, the program shows a warning message to the user. It sets the "pieces2win" to the default value which is 3. We also set an upper bound to the dimensions that can be accepted where the lower bound is 3 (lab requirement) and the upper bound is 28. If the TA wants to test the program with a larger dimension than it can update the bounds in the "constants.h" file.

Test 16. When dimension is larger than the max dimension (28) than the program, set the defaut minimum dimensions.

$ lab4.exe GomokuGame 29 3
$ lab4.exe GomokuGame 2 3
Dimensions should be equal or larger than 3 and less than 28. Minimum dimensions (3x3) are set.

3
2
1
X 1 2 3

$ Turn #  1, B's turn...
Enter a comma-seperated coordinates in [1:3,1:3] or type 'quit'. Column first, then row

Test 17. When the 4th argument (pieces2win) is larger than the given dimension and less than the minimum default number (3), the program sets the "pieces2win" to minimum number which is 3.

lab4.exe GomokuGame 5 2
lab4.exe GomokuGame 5 7
The number of connecting pieces should be >=  3 and shouldn't be larger than dimensions (5x5). The number of pieces to win is set to 3.


## Part IV: 

Test 18.
# Bug fixed. We forgot the set the names of Black and White stones as "Black Stone" and "White Stone". We initially set them "B" and "W", respectively. We update their name on Game.cpp file.
The resulting game play for GomokuGame looks like at turn # 11:

$ lab4.exe GomokuGame 5 4

...
$ Turn #  11, Black Stone's turn...
Enter a comma-seperated coordinates in [1:5,1:5] or type 'quit'. Column first, then row
1,5

5           Black Stone Black Stone Black Stone Black Stone White Stone
4                                   White Stone
3                                   Black Stone
2                       White Stone White Stone
1           Black Stone White Stone
X           1           2           3           4           5

Player Black Stone : 1, 1; 3, 3; 4, 5; 3, 5; 2, 5; 1, 5;

We replaced pieces name to "B" and "W" again. The output of the game looks like:

5   W B   W
4     B W
3 W B B B B
2 B W W
1 B B W   W
X 1 2 3 4 5

Player B : 1, 1; 3, 3; 1, 2; 2, 1; 4, 3; 5, 3; 3, 4; 3, 5; 2, 3;
Won! The 1st Player is the winner! 17 turns have been played.

Test 19. We tested Gumoku with following arguments for a winning scenario, draw scenario and early quit scenario. All works fine as expected.
$ lab4.exe GomokuGame 5 4

# design decision:
As suggested in Piazza, we return the same error code for commandline errors.

Test 20. 0 and negative arguments

$ lab4.exe GomokuGame 0
usage: lab4.exe "TicTacToeGame"|"GomokuGame <nDims> <Pieces2Win>"
$ lab4.exe GomokuGame 0 0
usage: lab4.exe "TicTacToeGame"|"GomokuGame <nDims> <Pieces2Win>"
$ lab4.exe GomokuGame 0 -1
usage: lab4.exe "TicTacToeGame"|"GomokuGame <nDims> <Pieces2Win>"
$ lab4.exe GomokuGame -3 -1
usage: lab4.exe "TicTacToeGame"|"GomokuGame <nDims> <Pieces2Win>"


## Implementation details

We define the following functions in GameBase class to detect if there are enough same pieces in a row, column, and opposite diagonals.
- We also define a member variable "pieces2Win_" in GameBase class which is initialized in the constructor based on a user-specified argument.
Each method accepts four different parameters where the first two parameters are the coordinates of the last piece that has been recently played; the third parameter is the last piece's code. The last parameter is a vector that stores the pieces on the game board.
Each method first calculates the upper and lower bounds of indices that may lead to a winning case based on the last piece's coordinates. 
- We also define getMax(), getMin(), and getSub() methods to make appropriate casting between signed and unsigned numbers when computing bounds.
- After deciding the starting and ending row and column indices, we iterate over the pieces in that region and check if it can find K number of pieces in a row, column, and diagonal, where K is the number of pieces to win the game.

// common functions for arithmetic with unsigned integers
unsigned int getMax(unsigned int x, unsigned int y);
unsigned int getMin(unsigned int x, unsigned int y);
unsigned int getSub(unsigned int x, unsigned int y);

// check if there is any line in vertical, horizantal, diagonal directions
bool checkUpperDiagonal(unsigned int x, unsigned y, piece_code lastPieceCode, std::vector<game_piece> board);
bool checkBottomDiagonal(unsigned int x, unsigned y, piece_code lastPieceCode, std::vector<game_piece> board);
bool checkVertical(unsigned int x, unsigned y, piece_code lastPieceCode, std::vector<game_piece> board);
bool checkHorizontal(unsigned int x, unsigned y, piece_code lastPieceCode, std::vector<game_piece> board);
