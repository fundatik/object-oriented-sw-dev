// list_assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <list>

#include "my_list.h"
#include "my_list_iterator.h"

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <cassert>


int main()
{
    // TODO: implement code for question 1 and question 2 here. Answer the questions in the ReadMe.txt file
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

    // assign the second list with 
    std::list <int*> list2 = list1;

    // show lists
    std::cout << "The second list of pointers\n";
    for (auto it2 = list2.begin(); it2 != list2.end(); ++it2) {
        std::cout << '\t' << **it2 << "\t -" << *it2 << std::endl;
    }

    /*
    for (auto it2 = list2.begin(); it2 != list2.end(); ++it2) {
        delete *it2;
    }
    for (auto it2 = list1.begin(); it2 != list1.end(); ++it2) {
        delete* it2;
    }
    */

    // Question 2

    my_list mlist;
    mlist.push_back(10);
    mlist.push_back(20);
    mlist.push_back(30);
    std::cout << "List: ";
    for (auto it = mlist.begin(); it != mlist.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\nIsListSorted: "<< std::is_sorted(mlist.begin(),mlist.end()) << std::endl;

    mlist.clear();
    mlist.push_back(10);
    mlist.push_back(30);
    mlist.push_back(10);
    std::cout << "List: ";
    for (auto it = mlist.begin(); it != mlist.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\nIsListSorted: " << std::is_sorted(mlist.begin(), mlist.end()) << std::endl;

    return 0;
}


