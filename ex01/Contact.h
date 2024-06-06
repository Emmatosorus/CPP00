#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact {
  public:
  	//Constructor
  	Contact();

	// Setters
	void set_index(int var);
	void set_creation(long var);
	void set_first_name(std::string var);
	void set_last_name(std::string var);
	void set_nickname(std::string var);
	void set_phone_number(std::string var);
	void set_secret(std::string var);

	// Getters
	int			get_index();
	long		get_creation();
	std::string	get_first_name(int size);
	std::string	get_last_name(int size);
	std::string	get_nickname(int size);
	std::string	get_phone_number();
	std::string	get_secret();

  private:
	int			index;
	long		creation;
	std::string	First_Name;
  	std::string	Last_Name;
  	std::string	Nickname;
  	std::string	Phone_Number;
  	std::string	Secret;
};

#endif
