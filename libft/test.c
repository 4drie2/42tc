#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "aaabcd";
	char	s2[] = "aaabbd";

	printf("%d", ft_strncmp(s1, s2, 5));
}
