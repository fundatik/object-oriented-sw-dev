#pragma once
// TODO: declare your my_list class here

#ifndef MY_LIST_H
#define MY_LIST_H

#include "my_list_iterator.h"
#include "ListNode.h"

class my_list {
public:
	my_list();
	~my_list();
	unsigned int get_size();
	int &front();
	int& back();
	void push_back(int);
	void push_front(int);
	void pop_back();
	void pop_front();
	void clear();

	ListNode* get_first();
	ListNode* get_last();

	my_list(const my_list&);
	my_list& operator=(const my_list&);

	my_list_iterator begin();
	my_list_iterator end();

	my_list_iterator insert(my_list_iterator, int);
	my_list_iterator erase(my_list_iterator);

private:
	ListNode* front_ptr_;
	ListNode* back_ptr_;
	unsigned int size_;
};

#endif