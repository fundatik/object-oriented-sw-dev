Lab 5 Readme

Group Members:
- Funda Atik
- Will Wu

We solved all the bugs and errors and passed all unit tests.
We regularly met and synced up the code.


TestCases:

# Ls & touch commands: 
T1: Show names of all files, where the number of files is even
$ ls
output:
x.img                x.txt

T2: Show names of all files, where the number of files is odd
$   ls
output:
x.img                x.txt
y.txt

T3: ls command with invalid option -> it show all of files by ignoring the option
$   ls x.img
output:
x.img                x.txt
y.txt

T4: invalid command
$   clear
output:
The command did not exist.

T5: Show metadata of all files 
$   ls -m
output:
x.img image  9
x.txt text 0
y.txt text 0

T6:  Show metadata of all files, after appending new contents to an existing text file (x.txt)
$   ls -m
output:
x.img image  9
x.txt text 25
y.txt text 0

# Cat command: 
T7: Execute text file with no append option and save multiple lines 
$   cat y.txt
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
funda
will
\n
:wq
output: check if the size of the file is updated via "ls -m" command and check if the file content is updated via "cat y.txt -a" without changing the content
$   ls -m
output: (y.txt's size is updated)
x.img image  9
x.txt text 25
y.txt text 13

$   cat y.txt -a (y.txt's content is updated)
funda
will
\n
enter data to append to the existing file. Enter :wq to save the file and exist. Enter :q to exit without saving
:q

T8: Execute text file with no append option and save an empty content and check if the content of the file is cleared 
$   cat y.txt
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ls -m (y.txt's size is 0 now)
x.img image  9
x.txt text 25
y.txt text 0

T9: - add a new content to y.txt, check if the content is updated, then execute text file no append no saving 
$   cat y.txt
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
futurama
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cat y.txt
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
qwer
:q
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cat y.txt -a 
output: (the file's content is not changed)
futurama

T10: execute cat command with a bad option
$   cat greek.txt -ad
output:
The command failed.

T10: execute text file append and don't save it 

$   touch y.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   touch greek.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ls
output:
greek.txt            x.img
y.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cat greek.txt
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
helen
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cat greek.txt -a
helen
enter data to append to the existing file. Enter :wq to save the file and exist. Enter :q to exit without saving
agamemnon
:Wq
q
:q


Test 11: execute text file append and save it

$   touch y.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   touch greek.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ls
output:
greek.txt            x.img
y.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cat greek.txt
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
helen
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cat greek.txt -a (the content does not changed when no saving)
helen
enter data to append to the existing file. Enter :wq to save the file and exist. Enter :q to exit without saving
agamemnon
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cat greek.txt -a (the content is changed)
helenagamemnon 
enter data to append to the existing file. Enter :wq to save the file and exist. Enter :q to exit without saving
:q

T12: execute image file with no append and save good input, check the content with ds command
$   cat x.img
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
X X 2
:wq
$   ds x.img
output:
X
X

Test13: execute image file with no append and save bad input. In that case, the command failed when trying to write the content. The content of the image file is cleared.
$   ds x.img
XXX
 X
X X
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cat x.img
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
sdda
asdada
:wq
output:
The command failed.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds x.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

T13: Execute image file with no append and don't save good input. In that case, the content does not change.
T14: Execute image file with append and save a good input. In that case, the command is failed because ImageFile does not support the append functionality.
$   cat x.img -a
 X
XXX
X X
enter data to append to the existing file. Enter :wq to save the file and exist. Enter :q to exit without saving
X X 2
:wq
output:
The command failed.

T15: Execute file does not exist 
$   cat kora.img
output:
The command failed.

# Remove Command:
T16: delete an image file
$   ls
x.img                y.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   rm x.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ls
y.txt

T17: delete a text file
$   ls
y.txt
$   rm y.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ls
output:


T18. execute remove with bad option & execute remove with non-existed file
$   rm
The command failed.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   rm x.txt
The command failed.

# Display command: 
T19: Display text 
$   cat plato.txt
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
republic
laws
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds plato.txt
republic
laws
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds plato.txt -d
republic
laws

T20: Display image formatted 
$   touch x.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cat x.img
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
X XXXX X 3
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds x.img
 X
XXX
X X
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

T21: Display image unformatted 
$   ds x.img -d
X XXXX X

T22: Save an empty content to the image file. In that case, the content is cleared and cat command fails.
$   cat x.img
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
:wq
output:
The command failed.
$   cat x.img -a
enter data to append to the existing file. Enter :wq to save the file and exist. Enter :q to exit without saving
:wq
output:
The command failed.

# Copy command: 
T23: Valid copy 
$   touch file.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cat file.txt
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
123456
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cp file.txt file_copy
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds file.txt
123456
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds file_copy.txt
123456
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cat file_copy.txt
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
helloo
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds file.txt
123456
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds file_copy.txt
helloo

T23: Invalid copy, missing arguments
$   cp test_copy.txt
not enought arguments
The command failed.

T24: Copy password protected 
$   touch secret.txt -p
enter a password string: 1234
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cat secret.txt
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
istanbul
:wq
enter a password string: 1234
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds secret.txt
enter a password string: 1234
istanbul
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cp secret.txt secret2
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ls
file.txt             file_copy.txt
secret.txt           secret2.txt
x.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds secret2.txt
enter a password string: 1234
istanbul
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.$   touch secret.txt -p
enter a password string: 1234
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cat secret.txt
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
istanbul
:wq
enter a password string: 1234
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds secret.txt
enter a password string: 1234
istanbul
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cp secret.txt secret2
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ls
file.txt             file_copy.txt
secret.txt           secret2.txt
x.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds secret2.txt
enter a password string: 1234
istanbul

# Rename command: 
T25: Rename parsing strategy and rename with valid filename
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ls
x.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds x.img
XXX
 X
X X
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   rn x.img y
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ls
y.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds y.img
XXX
 X
X X

T26: Rename invalid filename 
$   rn x.img z
The command failed.

T27: Rename invalid new filename (alrady existing filename)
$   ls
file.txt             file2.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   rn file.txt file2
The command failed.

T28: Rename valid password protected 
$   ds secret.txt
enter a password string: 1234
izmir
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ls
secret.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   rn secret.txt secret_copy.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ls
secret_copy.txt.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   rn secrett_copy.txt secret_copy
The command failed.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   rn secret_copy.txt secret_copy
The command failed.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   rn secret_copy.txt.txt secret_copy
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ls
secret_copy.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds secret_copy.txt
enter a password string: 1234
izmir
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

## extra credit
# Grep command
- tested grep commmand with different txt 
$   cat file.txt
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
utah
colorado
san francisco
oregon
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   cat file2.txt
enter data to write to the file. Enter :wq to save the file and exist. Enter :q to exit without saving
neew york
arizona oregon
malibu
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds file.txt
utah
colorado
san francisco
oregon
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds file2.txt
neew york
arizona oregon
malibu
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ls
file.txt             file2.txt
x.img
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   ds x.img -d
X X X XXX
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   grep X
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   grep utah
file.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$   grep oregon
file.txt
file2.txt