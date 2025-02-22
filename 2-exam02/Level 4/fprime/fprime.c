#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	i = 1;
	int	number;

	if (argc != 2)
		return ((void)printf("\n"), 0);
	number = atoi(argv[1]);
	if (number == 1)
		printf("1");
	while (number >= ++i)
	{
		if (number % i == 0)
		{
			printf("%d", i);
			if (number == i)
				break ;
			printf("*");
			number /= i;
			i = 1;
		}
	}
	printf("\n");
	return (0);
}
