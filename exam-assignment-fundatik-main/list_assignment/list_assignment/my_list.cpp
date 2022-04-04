// TODO: define your my_list class here
#include "my_list.h"
#include <cassert>
#include <iostream>

my_list::my_list(): size_(0), front_ptr_(nullptr), back_ptr_(nullptr){}

my_list::~my_list() {
	clear();
}

unsigned int my_list::get_size() { 
	// return the number of nodes in the list
	return size_; 
}

int& my_list::front() {
	if (front_ptr_ == 0 || size_ == 0) {
		throw std::exception("error while getting the value of front node");
	}
	return front_ptr_->getValue();
}

int& my_list::back() { 
	// return the value of the last node
	if (back_ptr_ == 0 || size_ == 0) {
		throw std::exception("error while getting the value of back node");
	}
	return back_ptr_->getValue();
}

void my_list::push_back(int value) {
	// add the integer value to the back of the list
	if (size_ == 0) { // empty list
		ListNode* new_node = new ListNode(0, 0, value);
		front_ptr_ = new_node;
		back_ptr_ = new_node;
		++size_;
	}
	else {
		// allocate a new node as the last node in the list
		ListNode* new_node = new ListNode(0, back_ptr_, value);
		// the previous last node's next should point to the new node
		back_ptr_->setNext(new_node);
		// the pointer to last node should point to the new node
		back_ptr_ = new_node;
		// increment the size of the list
		++size_;
	}
}

void my_list::push_front(int value) {
	// add the integer value to the front of the list
	if (size_ == 0) { // empty list
		ListNode* new_node = new ListNode(0,0,value);
		front_ptr_ = new_node;
		back_ptr_ = new_node;
		++size_;
	}
	else {
		// allocate a new node as the front node in the list
		ListNode* new_node = new ListNode(front_ptr_, 0, value);
		// the previous front node's previous should point the new node
		front_ptr_->setPrevious(new_node);
		// the pointer to last node should point to the new node
		front_ptr_ = new_node;
		// increment the size of the list
		++size_;
	}
}

void my_list::pop_back(){

		if (size_ == 0) {
			throw std::exception("Error occured while poping back");
		}
		// the front/back node is to be deleted
		else if (size_ == 1) {
			ListNode* temp = back_ptr_;
			front_ptr_ = 0;
			back_ptr_ = 0;
			size_ = 0;
			delete temp;
		}
		else {
			ListNode* temp = back_ptr_;
			// the previous of the last node should point to 0
			temp->getPrevious()->setNext(0);
			// the pointer to the last node should point the previous of the last node
			back_ptr_ = temp->getPrevious();
			// the last node's previous pointer shouldn't point anything
			temp->setPrevious(0);
			// deallocate the last node
			delete temp;
			// decrement the number of the nodes in the list
			--size_;
		}
	
}

void my_list::pop_front() {
	// remove the front node
	if (size_ == 0) {
		throw std::exception("Error occured while poping front");
	}
	else if (size_ == 1) {
		ListNode* temp = back_ptr_;
		front_ptr_ = 0;
		back_ptr_ = 0;
		size_ = 0;
		delete temp;
	}
	else {
		ListNode* temp = front_ptr_;
		// the previous of the front node's next should point to 0
		temp->getNext()->setPrevious(0);
		// the pointer to the front node should point the next of the front node
		front_ptr_ = temp->getNext();
		// the node which is to be deleted shouldn't point anything
		temp->setNext(0);
		// deallocate the last node
		delete temp;
		// decrement the number of the nodes in the list
		--size_;
	}
}

void my_list::clear() {
	// remove all the node in the list
	while (size_ > 0) {
		pop_back();
	}
}

ListNode* my_list::get_first() {
	return front_ptr_;
}

ListNode* my_list::get_last() {
	return back_ptr_;
}

// part II

my_list::my_list(const my_list& list): size_(0), front_ptr_(nullptr), back_ptr_(nullptr) {
	if (list.size_ >= 1) {
		// allocate a new node that don't reference any node
		ListNode* current = new ListNode(0, 0, list.front_ptr_->getValue());

		front_ptr_ = current;
		ListNode* list_head = list.front_ptr_;
		// copy list elements
		for (size_t i = 1; i< list.size_; i++) {
			// allocate a new node
			ListNode* next = new ListNode(0, 0, list_head->getNext()->getValue());
			current->setNext(next);
			next->setPrevious(current);
			current = next;
			list_head = list_head->getNext();
		}
		current->setNext(0);
		back_ptr_ = current;
		size_ = list.size_;
	}
}


my_list& my_list::operator=(const my_list& list) {
	if (&list != this) {
		my_list temp(list);
		std::swap(temp.size_, size_);
		std::swap(temp.front_ptr_, front_ptr_);
		std::swap(temp.back_ptr_, back_ptr_);
	}

	return *this;
}

// part IV

my_list_iterator my_list::begin() {
	if (size_ == 0) {
		my_list_iterator it(this, true);
		return it;
	}
	else {
		my_list_iterator it(this, false);
		ListNode *node = it.get_mem();
		node = front_ptr_;
		return it;
	}
}

my_list_iterator my_list::end() {
	my_list_iterator it(this, true);
	return it;
}

my_list_iterator my_list::insert(my_list_iterator it, int val) {
	// add a new node between the current node and the previous node
	ListNode* current = it.get_mem();
	if (current == front_ptr_) { // add new node to the beginning of the list
		push_front(val);
		it = begin();
	}
	else if (it.is_end()) { // add a new node to the end of the list 
		push_back(val);
		it = end();
		--it;
	}
	else{ // add a new node to the middle of the list
		ListNode* node = new ListNode(0, 0, val);
		node->setNext(current);
		node->setPrevious(current->getPrevious());
		current->getPrevious()->setNext(node);
		current->setPrevious(node);
		++size_;
		--it;
	}
	
	return it;
}

// after the deletion, the iterator points to the next node
my_list_iterator my_list::erase(my_list_iterator it) {
	// it should pass-the-end or invalid iterator
	if (it.is_end() || (it.is_end() ==false && it.get_mem() == 0)) { 
		throw std::exception("error occured while erasing");
	}

	ListNode* current = it.get_mem();
	if (current == front_ptr_) { // remove the first node in the list
		pop_front();
		it = begin();
	}
	else if (it.get_mem() == back_ptr_) { // remove the last node in the list
		pop_back();
		it = end();
	}
	else { // remove the node from the middle of the list
		++it;
		auto next_it = it; // keep the iterator pointing the next node after the one erased
		--it;
		current->getPrevious()->setNext(current->getNext());
		current->getNext()->setPrevious(current->getPrevious());
		current->setNext(0); // being cautious
		current->setPrevious(0);
		delete current;
		--size_;
		it = next_it;
	}
	return it;
	
}