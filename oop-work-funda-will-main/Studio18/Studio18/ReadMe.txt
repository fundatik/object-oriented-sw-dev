studio 18 answers here

2. To create a new concrete file type used by many file system implementations, ideally the client code should be aware of the creation logic itself, and should use a common interface.
In the current Simple File System implementation, a new concrete file type can be added by extending the if-else logic in the createFile() method which would be a bit difficult to maintain when adding a new file type. Instead, we can create static method by adopting the Factory Design pattern.

3.	Advantages: 
	- At runtime, the abstract factory can be coupled with any concrete methods that can create objects of desired type. 
	- Single Responsibility Principle: the file creation code are extracted into one place, making the code easier to support.
	- Open/Closed Principle: New variants of files can be introduced without breaking existing client code.
	- We want to create a new concrete factory when we want to implement a new file system with files of desired types.
	- To introduce a new file type, we need to change the concrete factory class.
	- We think that we can use the same factory to create two file system implementations managing the same type of files.
	- We need a different factory for creating two file system implementations managing different type of files.

4. Output:
 X
 X
XO sunday funday

test: create an image
test: write a content to an image
test: read from an image
test: create an text
test: write a content to a text
test: append a text
test: read from a text
test: open an image
test: open a text
test: open a text that is already open

5. SimpleFileSystem only depends on AbstractFile interface only.
