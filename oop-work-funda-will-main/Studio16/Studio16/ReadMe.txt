Answer studio 16 questions here

1. Team Members: Funda Atik, Will Wu

2. An interface in C++ are defined by an abstract class. A class is made abstract by declaring at least one of its functions as pure virtual function. 

3. a. Interface inheritance
3. b. private

4.
Test cases:
case 1: check fileName() function returns the same given name
case 2: check getSize() function returns the same size of the the given vector

Both tests passed.

5. 

We used polymorphism. We defined an AbstractFile object and passed the address of a TextFile object to this object. 

Main Function:

// part 4
string fileName = "tfile1";
TextFile txt1(fileName);
std::vector<char> contents = { 'f','u','n', 'w', 'u' };
	
cout << "Write to the 1st file\n";
txt1.write(contents);

cout << "Read from the 1st file\n";
txt1.read();

assert(txt1.getName().compare(fileName) == 0);
assert(txt1.getSize() == contents.size());

// part 5
TextFile txt2;
AbstractFile* file = &txt2;

cout << "Write to the 2nd file\n";
file->write(contents);

cout << "Read from the 2nd file\n";
file->read();

6. The program passed all unit tests. 