studio 19 answers here

Part 2:
c): Tests we ran:
- extract the content, modify the content, then write to the file
- read the content again to check the changes

Part 3: An AbstractFileVisitor object visits corresponding concrete file class objects and calls the appropriate functions.

AbstractFileVisitor -> Concrete File Objects -> BasicDisplayVisitor (?)

Part 4: Visitor pattern delegate the responsibility of implementing certain behaviour (e.g. read() function) to an associated object (BasicDisplayVisitor). We don't need to modify the concrete file classes when adding a certain behaviour that are commonly used by all of the file classes.

Part 5:
To add a new concrete file type, we need to modify AbstractDisplayVisitor and all of its children that needs to iimmplement a certain behaviour of this new concrete file class. When we need to add new concrete classes, (e.g., introducing new file types), a lot of code needs to be written to prepare the visitors: the visitor class with one abstract method per class, and a accept method per class. 