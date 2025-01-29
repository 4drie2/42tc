#include <unistd.h>

/* void	last_word(char *str)
{
	int j = 0;
	int i = 0;

	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] >= 33 && str[i + 1] <= 126)
			j = i + 1;
		i++;
	}
	while (str[j] >= 33 && str[j] <= 127)
	{
		write(1, &str[j], 1);
		j++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
} */

#include <stdio.h>
int main(int ac, char **av){
	int i = 0;

	if (ac != 2)
		return ((void)write(1, "\n", 1), 0);
	while (av[1][i])
		i++;
	i--;
	while (av[1][i] && (av[1][i] == ' ' || (av[1][i] >= 9 && av[1][i] <= 13)))
		i--;
	while (av[1][i] && av[1][i] != ' ' && (av[1][i] < 9 || av[1][i] > 13))
		i--;
	i++;
	while (av[1][i] && av[1][i] != ' ' && (av[1][i] < 9 || av[1][i] > 13))
		write(1, &av[1][i++], 1);
	write(1, "\n", 1);
	return (0);
}
