#include <unistd.h>

/* int main(int argc, char **argv)
{
	int flag;
	int start;
	int end;
	int i = 0;

	if(argc == 2)
	{
		while(argv[1][i] != '\0')
			i++;
		while(i >= 0)
		{
			while( argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--;
			end = i;
			while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			start = i + 1;
			flag = start;
			while(start <= end)
				write (1, &argv[1][start++],1);
			if (flag !=0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
} */

int main(int ac, char **av){
	int flag;
	int start;
	int end;
	int i = 0;

	if (ac != 2)
		return 0;
	while (av[1][i])
		i++;
	while (i >= 0){
		while (av[1][i] == '\0' || av[1][i] == ' ' || av[1][i] == '\t')
			i--;
		end = i;
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
			i--;
		start = i + 1;
		flag = start;
		while (start <= end)
			write(1, &av[1][start++], 1);
		if (flag != 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}
