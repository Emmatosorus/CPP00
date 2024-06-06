#include "Contact.h"

Contact::Contact() {
	this->index = 0;
	this->creation = 0;
	this->First_Name = "empty";
	this->Last_Name = "empty";
	this->Nickname = "empty";
	this->Phone_Number = "empty";
	this->Secret = "empty";
}

void Contact::set_index(int var) {
	this->index = var;
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

int Contact::get_index() {
	return (this->index);
}

long Contact::get_creation() {
	return (this->creation);
}

std::string Contact::get_first_name(int size) {
	std::string	New_First_Name;

	if (size == -1)
		return (this->First_Name);
	New_First_Name = this->First_Name;
	if (static_cast<int>(New_First_Name.length()) >= size)
	{
		New_First_Name.resize(size - 1);
		New_First_Name += '.';
	}
	return (New_First_Name);
}

std::string Contact::get_last_name(int size) {
	std::string	New_Last_Name;

	if (size == -1)
		return (this->Last_Name);
	New_Last_Name = this->Last_Name;
	if (static_cast<int>(New_Last_Name.length()) >= size)
	{
		New_Last_Name.resize(size - 1);
		New_Last_Name += '.';
	}
	return (New_Last_Name);
}

std::string Contact::get_nickname(int size) {
	std::string	New_Nickname;

	if (size == -1)
		return (this->Nickname);
	New_Nickname = this->Nickname;
	if (static_cast<int>(New_Nickname.length()) >= size)
	{
		New_Nickname.resize(size - 1);
		New_Nickname += '.';
	}
	return (New_Nickname);
}

std::string Contact::get_phone_number() {
	return (this->Phone_Number);
}

std::string Contact::get_secret() {
	return (this->Secret);
}
