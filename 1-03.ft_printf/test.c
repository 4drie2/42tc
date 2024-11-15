// #include <stdio.h>
// #include <stdarg.h>
#include <unistd.h>

int main()
{
	char *god = "Hello!";
	write(1, god, 6);
	return 0;
}
