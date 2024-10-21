#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char str[] = "Trouve le c(ici) dans la phrase";
	printf("%s", ft_strchr(str, 'c'));
}
