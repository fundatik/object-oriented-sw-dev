Studio 21 ReadMe.txt 

2. It is because deleting a derived class object using a pointer of base class type that has a non-virtual destructor cause undefined behavior.

3. Yes, the command propt can be easily configured because it only depends on abstract version of the file system and the associated abstract factory object.

4. After the program prompts, we ran the following tests:

- enter "q", then the program terminates.
- enter "help", prints a list of commands (e.g., "touch")
- enter "help touch", prints a help message about "touch" command: touch creates a file, touch can be invoked with the command: touch <filename>
- enter "touch", prints a warning: The command failed.
- enter "touch file1", prints a warning: The command failed.
- enter "quit", prints a warning: The command did not exist.
- enter "touch file1.txt", the program can successfully open the file.
- enter "touch file1.txt" twice, the first program does not print any warning message. However, the second time when we enter the same command, the program prints: the command failed. And when the user enter "q", the program can still open the file.