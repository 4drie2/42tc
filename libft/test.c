#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char data[] = { 'H', 'e', 'l', 'l', 'o', '\0', 'W', 'o', 'r', 'l', 'd' };
    char *result = ft_memchr(data, 'o', 11);

    if (result)
        printf("Found 'o' at position: %ld\n", result - data);
    else
        printf("'o' not found\n");

    return 0;
}
