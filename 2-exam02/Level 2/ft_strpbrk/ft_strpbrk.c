#include <stdio.h>
#include <string.h>

char *ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;

	if (!s1 || !s2)
		return (0);
	while(*s1)
	{
		i = 0;
	   	while(s2[i])
		{
			if(*s1 == s2[i])
				return (char *) s1;
			i++;
		}
		s1++;
	}
	return (NULL);
}

char *ab_strpbrk(char *s, char *s2)
{
	int i;

	while(*s){
		i = 0;
		while(s2[i])
			if (*s == s2[i++])
				return (char *) s;
		s++;
	}
	return NULL;
}

int main(void){
	char s[] = "abdcefghijklmnopqrstuvwxyz";
	char s2[] = "z";

	printf("Comparison using ft_strpbrk: |%s|\n", ft_strpbrk(s, s2));
	printf("Comparison using ab_strpbrk: |%s|\n", ab_strpbrk(s, s2));
	printf("Comparison using strpbrk   : |%s|\n", strpbrk(s, s2));
}
