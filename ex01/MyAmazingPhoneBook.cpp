# include <iostream>
# include <ctime>

# include <stdlib.h>
# include <unistd.h>
# include "PhoneBook.h"
# include "Contact.h"

# include <stdio.h>

void	display_instructions()
{
	std::cout << "/******************************************************************\\\n";
	std::cout << "\t\t\t       Hello!\n\t\t Welcome to My Amazing Phone Book!\n\n";
	std::cout << " To use this magnificent tool you can use the following commands :\n";
	std::cout << " ADD\t: To add a new contact to the phone book\n";
	std::cout << " SEARCH\t: To look up a previously registered contact\n";
	std::cout << " EXIT\t: To exit the program (Note that all contacts will be lost)\n";
	std::cout << "\n\\******************************************************************/\n\n";
}

int	get_correct_index(PhoneBook *book)
{
	int		j = 0;
	long	oldest = 0;

	while (book->contacts[j].get_creation() != 0 && j < 9)
		j++;
	if (j > 8)
	{
		while (--j >= 0)
		{
			if (book->contacts[j].get_creation() > oldest)
				oldest = book->contacts[j].get_creation();
		}
		while (book->contacts[j].get_creation() == oldest)
			j++;
	}
	return (j);

}

void	add_contact(PhoneBook *book)
{
	std::string input;
	std::string txt[5];
	int			i = -1;
	int			j;
	time_t		tt;
	struct tm	*ti;

	time(&tt);
	ti = localtime(&tt);
	j = get_correct_index(book);
	book->contacts[j].set_creation(ti->tm_sec + ti->tm_min + ti->tm_hour);
	txt[0] = "First Name : ";
	txt[1] = "Last Name : ";
	txt[2] = "Nickname : ";
	txt[3] = "Phone Number : ";
	txt[4] = "Secret : ";
	while (++i < 5)
	{
		std::cout << '\r' << txt[i] << std::flush;
		std::getline(std::cin, input);
		if (!std::cin)
			exit(1);
		if (i == 0)
			book->contacts[j].set_first_name(input);
		if (i == 1)
			book->contacts[j].set_last_name(input);
		if (i == 2)
			book->contacts[j].set_nickname(input);
		if (i == 3)
			book->contacts[j].set_phone_number(input);
		if (i == 4)
			book->contacts[j].set_secret(input);
		std::cout << "\x1b[A" << '\r' << std::string(txt[i].size() + input.size(), ' ') << '\r' << std::flush;
	}
}

void	print_all(PhoneBook *book, unsigned long *w_clear)
{
	int	j = -1;
	std::string str;
	std::cout << "/*******************************************\\" << std::endl;
	std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
	while (++j < 8)
	{
		std::cout << "|**********|**********|**********|**********|" << std::endl;
		std::cout << "|";
		std::cout.width(10);
		std::cout << std::left << book->contacts[j].get_index() << "|";
		std::cout.width(10);
		str = book->contacts[j].get_first_name();
		std::cout << std::left << str << "|";
		if (str.size() > *w_clear)
			*w_clear = str.size();
		std::cout.width(10);
		std::cout << std::left << book->contacts[j].get_last_name() << "|";
		std::cout.width(10);
		std::cout << std::left << book->contacts[j].get_nickname() << "|" << std::endl;
		std::cout.width(45);
	}
	std::cout << "\\*******************************************/" << std::endl;

}

void	search_contact(PhoneBook *book)
{
	std::string	input;
	long			index = 0;
	unsigned long	w_clear = 45;
	long			h_clear = 19;

	print_all(book, &w_clear);
	while (index < 1 || index > 8)
	{
		std::getline(std::cin, input);
		if (!std::cin)
			exit(1);
		if (input.size() > w_clear)
			w_clear = input.size();
		index = atoi(input.c_str());
		if (index < 1 || index > 8)
		{
			std::cout << "Incorrect Index, try again :" << std::endl;
			h_clear += 2;
		}
	}
	for (int i = -1; i < h_clear; i++)
		std::cout << "\x1b[A" << '\r' << std::string(w_clear, ' ') << '\r' << std::flush;

}

int	main(void)
{
	PhoneBook	book;
	std::string	input;

	display_instructions();
	int	i = -1;
	while (++i < 9)
		book.contacts[i].set_index(i + 1);
	do {
		std::getline(std::cin, input);
		if (!std::cin)
			exit(1);
		if (input == "ADD")
		{
			add_contact(&book);
			std::cout << "\x1b[A" << '\r' << std::string(input.size(), ' ') << '\r' << std::flush;
		}
		else if (input == "SEARCH")
		{
			search_contact(&book);
			std::cout << "\x1b[A" << '\r' << std::string(input.size(), ' ') << '\r' << std::flush;
		}
		else
			std::cout << "\x1b[A" << '\r' << std::string(input.size(), ' ') << '\r' << std::flush;
	}
	while (input != "EXIT");
	return (0);
}

/*
 * https://stackoverflow.com/questions/10058050/how-to-go-up-a-line-in-console-programs-c
 *
 * 	std::cout << "\x1B[2J\x1B[H";
	std::cout.flush();
 *
 */