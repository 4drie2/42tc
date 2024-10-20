#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int	main(void){
	int	c = 't';
	printf("ft_isprint : %d\n   isprint : %d\n",ft_isprint(c), isprint(c));
	return 0;
}
