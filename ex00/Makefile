NAME = megaphone

CPP = c++

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

all:
	$(CPP) $(CPP_FLAGS) $(SRC) -o $(NAME)

clean:

fclean:
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean flcean re