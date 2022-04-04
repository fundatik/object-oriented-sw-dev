#pragma once
// TODO: declare your my_list_iterator class here

#ifndef MY_LIST_ITERATOR_H
#define MY_LIST_ITERATOR_H

#include "ListNode.h"
class my_list;

class my_list_iterator {

public:
	my_list_iterator(my_list*, bool end);
	my_list_iterator(const my_list_iterator&);
	int& operator*();
	bool operator==(const my_list_iterator compare_againts) const;
	bool operator!= (const my_list_iterator compare_againts) const;
	my_list_iterator& operator++();
	my_list_iterator& operator--();

	ListNode* get_mem();
	bool is_end();

private:
	ListNode* node_;
	my_list* list_;
	bool end_;
};

#endif