#include <stdio.h>
#include <unistd.h>


// int main(void)
// {
// 	char *root = "/tmp";
// 	printf("access: %d\n", access(root, F_OK));
// 	if (access(root, F_OK) == 0)
// 		printf("unlink: %d", unlink("tmp"));
// 	return (0);
// }

int main(void)
{
	if (access("/tmp", F_OK) == 0)
		printf("unlink: %d", unlink("tmp"));
	return (0);
}
