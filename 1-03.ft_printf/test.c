#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int main()
{
	char *god = "d";

	printf("%s\n", god);
	int i = 0;
	while (god[i])
	{
		write(1, &god[i++], 1);
	}
}
