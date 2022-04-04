// TODO: define your my_list_iterator here

#include "my_list_iterator.h"
#include "my_list.h"
#include <iostream>
my_list_iterator::my_list_iterator(my_list* list, bool end):list_(list),end_(end) {
	if (end_) { // past_the_end
		node_ = 0;
	}
	else {
		node_ = list->get_first();
	}
}

my_list_iterator::my_list_iterator(const my_list_iterator& it):list_(it.list_),node_(it.node_),end_(it.end_) {
	// shallow copy
}

int& my_list_iterator::operator*() {
	if (node_ != 0) {
		return node_->getValue();
	}
	throw std::exception("invalid state");
}

bool my_list_iterator::operator==(const my_list_iterator compare_againts) const {
	if (list_ != compare_againts.list_) {
		throw std::exception("comparing different lists");
	}
	if (node_ == compare_againts.node_) {
		return true;
	}

	return false;
}

bool my_list_iterator::operator!= (const my_list_iterator compare_againts) const {
	if (list_ != compare_againts.list_) {
		throw std::exception("comparing different lists");
	}
	if (node_ == compare_againts.node_) {
		return false;
	}

	return true;
}

my_list_iterator& my_list_iterator::operator++() {
	if (end_ || list_->get_size()==0) {
		throw std::exception("No next node exists");
	}
	if (node_ == list_->get_last()) {
		end_ = true;
		node_ = 0;

	}
	else {
		node_ = node_->getNext();
	}
	
	return *this;
}

my_list_iterator& my_list_iterator::operator--() {
	if (end_ == false && list_->get_size() < 2) {
		throw std::exception("No previous node exists");
	}


	if (end_) { // update to the last valid node
		node_ = list_->get_last();
		end_ = false;
	}
	else {
		node_ = node_->getPrevious();
	}

	return *this;
}

ListNode* my_list_iterator::get_mem() {
	return node_;
}

bool my_list_iterator::is_end() {
	return end_;
}


