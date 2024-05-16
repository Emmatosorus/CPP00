#include "Contact.h"

Contact::Contact() {
	this->index = 0;
}

void Contact::set_creation(long var) {
	this->creation = var;
}

void Contact::set_first_name(std::string var) {
	this->First_Name = var;
}

void Contact::set_last_name(std::string var) {
	this->Last_Name = var;
}

void Contact::set_nickname(std::string var) {
	this->Nickname = var;
}

void Contact::set_phone_number(std::string var) {
	this->Phone_Number = var;
}

void Contact::set_secret(std::string var) {
	this->Secret = var;
}

long Contact::get_creation() {
	return (this->creation);
}

std::string Contact::get_first_name() {
	return (this->First_Name);
}

std::string Contact::get_last_name() {
	return (this->Last_Name);
}

std::string Contact::get_nickname() {
	return (this->Nickname);
}

std::string Contact::get_phone_number() {
	return (this->Phone_Number);
}

std::string Contact::get_secret() {
	return (this->Secret);
}
