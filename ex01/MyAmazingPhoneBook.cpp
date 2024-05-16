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

void	add_contact(PhoneBook *book)
{
	std::string input;
	std::string txt[5];
	int			i = -1;
	time_t		tt;
	struct tm	*ti;

	time(&tt);
	ti = localtime(&tt);
	book->contacts[0].set_creation(ti->tm_sec + ti->tm_min + ti->tm_hour);
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
			book->contacts[0].set_first_name(input);
		std::cout << "\x1b[A" << '\r' << std::string(txt[i].size() + input.size(), ' ') << '\r' << std::flush;
	}
}

void	search_contact(PhoneBook *book)
{
	std::string f_name;

	f_name = book->contacts[0].get_first_name();
	printf("%ld\n", book->contacts[0].get_creation());
	std::cout << f_name << std::flush;
	sleep(2);
	std::cout << '\r' << std::string(f_name.size(), ' ') << '\r' << std::flush;
}

int	main(void)
{
	PhoneBook	book;
	display_instructions();
	std::string	input = "Hello, unstop!";

	do {
		std::getline(std::cin, input);
		if (!std::cin)
			exit(1);
		if (input == "ADD")
		{
			std::cout << "\x1b[A" << '\r' << std::string(input.size(), ' ') << '\r' << std::flush;
			add_contact(&book);
		}
		else if (input == "SEARCH")
		{
			std::cout << "\x1b[A" << '\r' << std::string(input.size(), ' ') << '\r' << std::flush;
			search_contact(&book);
		}
		else
			std::cout << "\x1b[A" << '\r' << std::string(input.size(), ' ') << '\r' << std::flush;
	}
	while (input != "EXIT");
	return (0);
}

/*
 * https://stackoverflow.com/questions/10058050/how-to-go-up-a-line-in-console-programs-c
 */