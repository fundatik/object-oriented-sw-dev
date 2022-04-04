Exam Assignment ReadMe

Name:
Student ID:

ToDo: Record your answers to questions 1 and 2 here. Code should be written in list_assignment.cpp

Question 1:

a. My code:

// question 1: deep copy vs shallow copy 

    std::list <int*> list1;
    int* ptr1;
    // populate the list with pointers to integer values
    for (int i = 0; i < 10; i++) {
        ptr1 = new int;
        *ptr1 = i * 2;
        list1.push_back(ptr1);
    }

    // show address and values of the pointers that point to
    std::cout << "The first list of pointers\n";
    for (auto it1 = list1.begin(); it1 != list1.end(); ++it1) {
        std::cout << '\t' << **it1 << "\t -" << *it1 << std::endl;
    }

    // construct the second list with the first list
    std::list <int*> list2 = list1;

    // show lists
    std::cout << "The second list of pointers\n";
    for (auto it2 = list2.begin(); it2 != list2.end(); ++it2) {
        std::cout << '\t' << **it2<< "\t -" << *it2 << std::endl;
    }

b: Output:

The first list of pointers
        0        -0000019B2C4FA5C0
        2        -0000019B2C4FA200
        4        -0000019B2C4FA240
        6        -0000019B2C4FA280
        8        -0000019B2C4F4E00
        10       -0000019B2C4F4E40
        12       -0000019B2C4F4E80
        14       -0000019B2C4F50B0
        16       -0000019B2C4F50F0
        18       -0000019B2C4F5130
The second list of pointers
        0        -0000019B2C4FA5C0
        2        -0000019B2C4FA200
        4        -0000019B2C4FA240
        6        -0000019B2C4FA280
        8        -0000019B2C4F4E00
        10       -0000019B2C4F4E40
        12       -0000019B2C4F4E80
        14       -0000019B2C4F50B0
        16       -0000019B2C4F50F0
        18       -0000019B2C4F5130

c: std::list provides shallow copy because copied elements allocated from heap section reference the same memory location.

Question 2:

a. It is bidirectional because it can access the sequence of elements in a range in both diirections (i.e., beginning to end and end to beginning).

Those 5 types are:
1. input iterators
2. output iterators
3. forward iterators
4. bidirectional iterators
5. random-access iterators

b. 
    The output:
    
    List: 10 20 30
    IsListSorted: 1
    List: 10 30 10
    IsListSorted: 0

c. std::sort expects random-access iterators as parameters; however my_list object does not support this due to the linked list structure.