#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("%i", access("/bin/ls", X_OK));
}
