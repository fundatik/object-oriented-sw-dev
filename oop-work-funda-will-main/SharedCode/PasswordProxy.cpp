#include "PasswordProxy.h"
#include <iostream>
#include <string>
#include <vector>

PasswordProxy::PasswordProxy(AbstractFile* file, std::string pass) :aFile_(file), pwd_(pass) {}

PasswordProxy::~PasswordProxy() {
	if (aFile_) {
		delete aFile_;
	}
}

std::string PasswordProxy::passwordPrompt() {
	std::string pwd;
	std::cout << "enter a password string: ";
	getline(std::cin, pwd);
	return pwd;
}

int PasswordProxy::checkPasswordMatch(std::string pwd) {
	return pwd.compare(pwd_);
}

std::vector<char> PasswordProxy::read() {
	std::string pwd = passwordPrompt();
	if (checkPasswordMatch(pwd) == 0) {
		return aFile_->read();
	}
	else {
		return std::vector<char>();
	}
}

int PasswordProxy::write(std::vector<char> text) {
	std::string pwd_input = passwordPrompt();
	if (checkPasswordMatch(pwd_input) == 0) {
		return aFile_->write(text);
	}
	else {
		return exit_code::PasswordFailure;
	}
}

int PasswordProxy::append(std::vector<char> content) {
	std::string pwd_input = passwordPrompt();
	if (checkPasswordMatch(pwd_input) == 0) {
		return aFile_->append(content);
	}
	else {
		return exit_code::PasswordFailure;
	}
}

unsigned int PasswordProxy::getSize() {
	return aFile_->getSize();
}

std::string PasswordProxy::getName() {
	return aFile_->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* afv) {
	std::string pwd_input = passwordPrompt();
	if (checkPasswordMatch(pwd_input) == 0) {
		return aFile_->accept(afv);
	}
}

AbstractFile* PasswordProxy::clone(std::string file_name)
{
	AbstractFile* file = this->aFile_->clone(file_name);
	PasswordProxy* copy_proxy = new PasswordProxy(file, this->pwd_);
	
	return copy_proxy;
}