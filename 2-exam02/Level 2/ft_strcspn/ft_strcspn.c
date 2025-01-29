#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t count;
    size_t i;

    count = 0;
    i = 0;
    while (*s)
    {
        while (reject[i] && *s != reject[i])
            i++;
        if (reject[i] != '\0')
            return (count);
        i = 0;
        count++;
        s++;
    }
    return (count);
}

size_t ab_strcspn(char *s, char *reject)
{
	int count = 0;
	int i;

	while(*s){
		i = 0;
		while(reject[i])
			if (*s == reject[i++])
				return count;
		count++;
		s++;	
	}
	return count;
}

#include <stdio.h>
#include <string.h>
#include <stddef.h>

int main(void){
	char s[] = "abcdef";
	char reject[] = "abcde";

	printf("Comparison using ft_strcspn: |%lu|\n", ft_strcspn(s, reject));
	printf("Comparison using ab_strcspn: |%lu|\n", ab_strcspn(s, reject));
	printf("Comparison using strcspn   : |%lu|\n", strcspn(s, reject));
}
