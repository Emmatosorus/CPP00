# include <iostream>
# include <ctime>
# include <cmath>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <unistd.h>
# include "PhoneBook.h"
# include "Contact.h"

# include <stdio.h>

void	display_instructions()
{
	std::cout << "\x1b[34;1m/******************************************************************\\\x1b[0m\n";
	std::cout << "\t\t\t       \x1b[36;1mHello!\x1b[0m\n\t\t \x1b[34;1mWelcome to My Amazing Phone Book!\x1b[0m\n\n";
	std::cout << " \x1b[34;1mTo use this magnificent tool you can use the following commands :\x1b[0m\n";
	std::cout << " \x1b[32mADD\x1b[0m\t: \x1b[37mTo add a new contact to the phone book\x1b[0m\n";
	std::cout << " \x1b[32mSEARCH\x1b[0m\t: \x1b[37mTo look up a previously registered contact\x1b[0m\n";
	std::cout << " \x1b[32mEXIT\x1b[0m\t: \x1b[37mTo exit the program (Note that all contacts will be lost)\x1b[0m\n";
	std::cout << "\n\x1b[34;1m\\******************************************************************/\x1b[0m\n\n";
}

void	clear_window()
{
	std::cout << "\033[H\033[J";
	std::cout.flush();
	display_instructions();
}

void	clear_text(size_t size)
{
	struct winsize w;
	size_t nb;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (size == 0 || size <= w.ws_col)
		size = w.ws_col;
	nb = static_cast<int>(size / w.ws_col);
	if (size % w.ws_col != 0)
		nb++;
	while (nb-- > 0)
		std::cout << "\x1b[A" << '\r' << std::string(w.ws_col, ' ') << '\r' << std::flush;
}

int	get_correct_index(PhoneBook *book)
{
	int		j = 0;
	int		i = 0;
	long	oldest;

	while (book->contacts[j].get_creation() != 0 && j < 8)
		j++;
	if (j == 8)
	{
		j = 0;
		oldest = book->contacts[i].get_creation();
		while (i < 8)
		{
			if (book->contacts[i].get_creation() < oldest)
			{
				oldest = book->contacts[i].get_creation();
				j = i;
			}
			i++;
		}
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
	book->contacts[j].set_creation(ti->tm_sec + (ti->tm_min * 60) + (ti->tm_hour * 3600));
	txt[0] = "\x1b[37;1mFirst Name : \x1b[0m";
	txt[1] = "\x1b[37;1mLast Name : \x1b[0m";
	txt[2] = "\x1b[37;1mNickname : \x1b[0m";
	txt[3] = "\x1b[37;1mPhone Number : \x1b[0m";
	txt[4] = "\x1b[37;1mSecret : \x1b[0m";
	while (++i < 5)
	{
		do
		{
			std::cout << '\r' << txt[i] << std::flush;
			std::getline(std::cin, input);
			if (!std::cin)
				exit(1);
			clear_text(txt[i].size() + input.size());
			std::cout << '\r' << std::flush;
		}
		while (input.empty());
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
	}
}

void	print_all(PhoneBook *book)
{
	int	j = -1;
	std::string str;

	std::cout << "\x1b[34;1m/*******************************************\\\x1b[0m" << std::endl;
	std::cout << "\x1b[34;1m|  Index   |First Name| Last Name| Nickname |\x1b[0m" << std::endl;
	while (++j < 8)
	{
		str = "\x1b[34;1m|**********|**********|**********|**********|\x1b[0m";
		std::cout << str << std::endl;
		std::cout << "\x1b[34;1m|\x1b[0m";
		std::cout.width(10);
		std::cout << std::left << book->contacts[j].get_index() << "\x1b[34;1m|\x1b[0m";
		std::cout.width(10);
		std::cout << std::left << book->contacts[j].get_first_name(10) << "\x1b[34;1m|\x1b[0m";
		std::cout.width(10);
		std::cout << std::left << book->contacts[j].get_last_name(10) << "\x1b[34;1m|\x1b[0m";
		std::cout.width(10);
		std::cout << std::left << book->contacts[j].get_nickname(10) << "\x1b[34;1m|\x1b[0m" << std::endl;
		std::cout.width(45);
	}
	std::cout << "\x1b[34;1m\\*******************************************/" << std::endl;
}

void	search_contact(PhoneBook *book)
{
	std::string	input;
	long		index = 0;
	int8_t		i = 0;

	print_all(book);
	std::cout << "\x1b[32;1mTo exit this interface: Type \"EXIT\"\x1b[0m" << std::endl;
	while (index < 1 || index > 8 || input.size() != 1)
	{
		std::cout << "\x1b[37;1mIndex : \x1b[0m";
		std::getline(std::cin, input);
		if (!std::cin)
			exit(1);
		if (input == "EXIT")
			return ;
		index = atoi(input.c_str());
		if (index < 1 || index > 8 || input.size() != 1)
			std::cout << "\x1b[1mIncorrect index, try again :\x1b[0m" << std::endl;
	}
	while (book->contacts[i].get_index() != index)
		i++;
	clear_window();
	std::cout << "SEARCH" << std::endl;
	std::cout << "\x1b[34;1m|----------------------------------\x1b[0m" << std::endl;
	std::cout << "\x1b[37;1mFirst Name : \x1b[0m" << book->contacts[i].get_first_name(-1) << std::endl;
	std::cout << "\x1b[37;1mLast Name : \x1b[0m" << book->contacts[i].get_last_name(-1) << std::endl;
	std::cout << "\x1b[37;1mNickname : \x1b[0m" << book->contacts[i].get_nickname(-1) << std::endl;
	std::cout << "\x1b[37;1mPhone Number : \x1b[0m" << book->contacts[i].get_phone_number() << std::endl;
	std::cout << "\x1b[37;1mSecret : \x1b[0m" << book->contacts[i].get_secret() << std::endl;
	std::cout << "\x1b[34;1m|----------------------------------\x1b[0m" << std::endl;
	std::cout << "\x1b[32;1m      Press Enter to continue  \x1b[0m" << std::endl;
	std::getline(std::cin, input);
	if (!std::cin)
		exit(1);
}

int	main(void)
{
	PhoneBook	book;
	std::string	input;

	clear_window();
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
			clear_window();
		}
		else if (input == "SEARCH")
		{
			search_contact(&book);
			clear_window();
		}
		else
			clear_window();
	}
	while (input != "EXIT");
	std::cout << "\x1b[35;1mGoodbye! See you soon! ^^\x1b[0m\n";
	sleep(2);
	std::cout << "\033[H\033[J";
	std::cout.flush();
	return (0);
}
