#include <iostream>

int	main(int ac, char **av)
{
  if (ac < 2)
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  else
  {
	int i = 1;
	int j;
	char  c;
	while (av[i])
	{
	  j = 0;
	  while (av[i][j])
	  {
		c = static_cast <char> (std::toupper(av[i][j]));
		std::cout << c;
		j++;
	  }
	  i++;
	}
	std::cout << std::endl;
  }
  return 0;
}