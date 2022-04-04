Assignment: Lab 2
Author: Funda Atik
E-mail: fatik@wustl.edu

Files: 
Lab02.cpp
Util.h
Util.cpp
Game.h
Game.cpp
GameBoard.h
GameBoard.cpp
ReadMe.txt

=======================
 
* Part 15:
	- After building my project, I don't encounter any errors and warnings.

* Part 17:

Case 1:		missing command argument
Command:	./Lab02.exe
Output:
			Lab02.exe requires 1 argument.
			usage: Lab02.exe <input file>

-------
Case 2:		wrong filname
Command:	./Lab02.exe temp
Output:
			Unable to open file

-------
Case 3:		wrong filname
Command:	./Lab02.exe temp
Output:
			Unable to open file

-------
Case 4:		correct filename
Command:	./Lab02.exe tic-tac-toe.txt
Input File: tic-tac-toe.txt
3 3
red Xs X 0 0	->ok
red Xs X 0 2	->ok
red Xs X 1 1	->ok
red Xs X 1 2	->ok
red Xs X 2 2	->ok
blue Os O 0 1	->notok
blue Os O 1 0	->notok
blue Os O 2 0	->notok
blue Os O 2 2	->notok

Output:
XXX
 X
X

-------
Case 5:		correct filename
Command:	./Lab02.exe gumoku.txt
Input File: gumoku.txt
8 8
black stone X 0 0
black stone X 0 2
black stone X 1 1
black stone X 2 0
black stone X 2 2
black stone X 3 1
black stone X 4 0
black stone X 4 2
black stone X 5 1
black stone X 6 0
black stone X 6 2
black stone X 7 1
white stone O 0 6
white stone O 1 5
white stone O 1 7
white stone O 2 6
white stone O 3 5
white stone O 3 7
white stone O 4 6
white stone O 5 5
white stone O 5 7
white stone O 6 6
white stone O 7 5
white stone O 7 7

Output:
 O O O O
O O O O
 O O O O


X X X X
 X X X X
X X X X


-------
Case 6: Dimensions are at the end of the file

Command:	 ./Lab02.exe tic-tac-toe.c6.txt
Output:			
			There is not any valid pieces on the game board.
			An error occured when reading pieces

-------
Case 7:	Add random spaces to tic-tac-toe.txt file. The program ignores random spaces.
Input File:

	3 	3

red Xs X 0 0
red Xs 		X 0 2
red Xs X 1 1
red	 Xs X 1 2 3
red Xs X 2 2
blue Os 		O 0 1 
blue Os O 1 0 
blue Os O 2 0 
blue Os O 2 2 

Command:  ./Lab02.exe tic-tac-toe.c7.txt
Output: 
XXX
 X
X

-------
Case 8:	Small dimensions but the input file includes pieces that are located in large dimensions. The program needs to discard those pieces.
Input File:
2 2
red Xs X 0 0
red Xs X 0 2
red Xs X 1 1
red Xs X 1 2
red Xs X 2 2
blue Os O 0 1 
blue Os O 1 0 
blue Os O 2 0 
blue Os O 2 2 

Command:	./Lab02.exe tic-tac-toe.c8.txt
Output:		
 X
X


--------
Case 9:				Negative Dimensions or positions
Question:			How to safely read an unsigned int from a stream?
Problem:			std::istringstream("-1 3") reads a signed value into an unsigned int without giving an error, silently producing a wrong result. 
Design Decision:	I read positions and dimensions as signed integer, and then check them if they are larger than zero. If yes, then I cast them as unsigned integers. Otherwis, I ignore them.

Case 10:			Dimensions are not in the beginning of the file. Until valid dimensions are found, the program ignores any lines.
Case 11:			File contains random spaces and texts. The program discards them.

Input File:
white Ws 0 0 1
-1 3

black Xs X 0 0

white Xs X 0 7


white Ts O 0 0

white Xs 	X 0 	2
				black 			Os O 2 1 
		
		3 -2
clear that 
...
zip zip zip zip zip zip zip
		red Xs X 1 -1
red Xs 			X 1 		-1
black Xs X 1 -1
black Xs X 0 0
	red Xs 		X 1 2 2

			white Xs X 1 	1 2
red Xs X 2 2
			white Os O 0 1 
3 3 
blue Os O 1 0 
blue Os O 2 0 
white Os O 2 2 
blue Os O 2 0 

Command:		./Lab02.exe tic-tac-toe.c9.txt
Output:
  O



--------
Case 13:	The input file does not include dimensions
Command:	./Lab02.exe tic-tac-toe.c13.txt
Output:		
			An error occured when reading dimensions
Error Level:
			echo %errorlevel%
			6
			GetLineFailure

** Extra Credit:

Case 14:	Correct input file
Command:	Lab02.exe gomoku.extra.txt
Output:
X
 X
X
show neighbors
0,0 black stone: 1,1 white stone;
1,1 white stone: 0,2 black stone; 0,0 black stone;
0,2 black stone: 1,1 white stone;

Case 15:	Corners, Edges, middle position => corners have at most 3 neighbors, edges 5 neighbors, the middle one 8 neighbors
Design:		Calculate neighbor indices and check if they are in the valid bounds (e.g. {i,j}>= 0 and j <= x and i <= y). If indices are valid, then check if there is valid piece in that position.
Command:	./Lab02.exe gomoku.extra2.txt
Input File:
3 3
black stone X 0 0
black stone X 0 1 
black stone X 0 2
white stone X 1 0
white stone X 1 1
white stone X 1 2
black stone X 2 0
black stone X 2 1
black stone X 2 2

Output:		
XXX
XXX
XXX
show neighbors
0,0 black stone: 0,1 black stone; 1,0 white stone; 1,1 white stone;
1,0 white stone: 1,1 white stone; 0,0 black stone; 2,0 black stone; 0,1 black stone; 2,1 black stone;
2,0 black stone: 2,1 black stone; 1,0 white stone; 1,1 white stone;
0,1 black stone: 0,0 black stone; 0,2 black stone; 1,1 white stone; 1,2 white stone; 1,0 white stone;
1,1 white stone: 1,0 white stone; 1,2 white stone; 0,1 black stone; 2,1 black stone; 0,2 black stone; 2,2 black stone; 2
,0 black stone; 0,0 black stone;
2,1 black stone: 2,0 black stone; 2,2 black stone; 1,1 white stone; 1,2 white stone; 1,0 white stone;
0,2 black stone: 0,1 black stone; 1,2 white stone; 1,1 white stone;
1,2 white stone: 1,1 white stone; 0,2 black stone; 2,2 black stone; 2,1 black stone; 0,1 black stone;
2,2 black stone: 2,1 black stone; 1,2 white stone; 1,1 white stone;
