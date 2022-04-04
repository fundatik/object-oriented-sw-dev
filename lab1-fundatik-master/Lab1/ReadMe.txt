Assignment: Lab 1
Author: Funda Atik
E-mail: fatik@wustl.edu

Files: 
Lab1.cpp
Lab1.h
Lab1.exe
=======================
 
 * Part 12:
	- After building my project, I don't encounter any errors and warnings.

 * Part 13:

--------------------------------------
Desing Decisions & Issues & Test Cases
--------------------------------------

Q.	Do you consider negative numbers as integers?

A.	No. I consider negative numbers as strings because negative sign is not a digit (e.g., -23 => string).


Q. What happens if a file includes a non-ASCII chracter such as "€"?

A.  In that case, in the old version of the code, isdigit raises an assertion becuase isdigit(int) expects only ASCII characters 
	in the range stated [1]. To work around this, I cast to each chracter to unsigned char to avoid the assertion failure. After 
	this update, the program consider non-ASCII chracters as string.

	$ Lab1.exe input_file.txt

	Error in the old version of teh code
	------------------------------------
	Debug assertion failed! 
	File: isctype.cpp
	Line: 36
	Expression: c >= -1 && c <= 255

	Old version of the code
	-----------------------
	std::string word = words[i];
	isdigit(word[j])

	New Version of the code
	-----------------------
	std::string word = words[i];
	unsigned char ch = word[j];
	isdigit(ch)

	[1] The behavior of isdigit and _isdigit_l is undefined if c is not EOF or in the range 0 through 0xFF, inclusive. 
	When a debug CRT library is used and c is not one of these values, the functions raise an assertion.
	Ref: https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/isdigit-iswdigit-isdigit-l-iswdigit-l?redirectedfrom=MSDN&view=msvc-160


Q.	What happens if input file contains very big numbers, how to convert a very long string containing only numeric chracters into an integer?

A.	If string is very large, then "iss >> number" causes a logical error. To work around this, I consider a very large number as string since 
	string can be of any length. As an alternative, I can choose to give an error warning and return an error code whenever istringstream operation fails.

	Version 1 (Chosen)
	------------------
	std::istringstream iss(numeric_word)
	int number
	iss >> number
	if iss.fail():
		iss.clear()
		std::string dummy
		iss >> dummy
		
	Alternative version
	-------------------
	if iss.fail():
		std::cout << "String to integer conversion error\n"
		return StrToIntConversionFailure

## Test Case: Missing command-line argument

	$ Lab1.exe

	==Output==
	Lab1.exe requires 1 argument.
	usage: Lab1.exe <input_file_name>

## Test Case: Wrong filename

	$ Lab1.exe input_file

	==Output==
	Unable to open file
	Filename you entered: input_file

## Test Case: Well formed inputs
	
	$ Lab1.exe input_file.txt

	The program works as expected.

----------------------
Extra Credit: PART III
----------------------

I don't run into any errors and warnings on the Linux machine.

 * EC 1

	$ ls

	Output:

	Desktop  Downloads  Music  My Documents  Pictures  Public  Templates  Videos  WINDOWS  equeue  fatik  perl5  server  winprofile

 * EC 2

 ## Test Case: Missing command-line argument

	$ ./Lab1.exe

	==Output==
	Lab1.exe requires 1 argument.
	usage: Lab1.exe <input_file_name>

 ## Test Case: Wrong filename

	$ ./Lab1.exe input_file

	==Output==
	Unable to open file
	Filename you entered: input_file

 ## Test Case: Well formed inputs
	
	$ ./Lab1.exe input_file.txt

	The program works as expected.