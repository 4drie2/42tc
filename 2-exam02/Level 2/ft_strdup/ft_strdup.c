#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int	i = 0;
	int	length = 0;
	char	*strcpy;

	while (src[length])
		length++;
	strcpy = malloc(sizeof(*strcpy) * (length + 1));
	if (strcpy != NULL)
	{
		while (src[i])
		{
			strcpy[i] = src[i];
			i++;
		}
		strcpy[i] = '\0';
	}
	return (strcpy);
}

char *ab_strdup(char *s1){
	int count = 0;
	char *s2 = NULL;

	while (s1[count])
		count++;
	s2 = malloc(sizeof(char) * (count + 1));
	if (!s2)
		return (NULL);
	count = -1;
	while (s1[++count])
		s2[count] = s1[count];
	s2[count] = '\0';
	return s2;
}


#include <string.h>
#include <stdio.h>
int main(int argc, char **argv){
	char *dup;

	dup = ft_strdup(argv[1]);
	printf("Comparison using ft_strdup: |%s|\n", dup);
	free(dup);
	dup = ab_strdup(argv[1]);
	printf("Comparison using ab_strdup: |%s|\n", dup);
	free(dup);
	dup = strdup(argv[1]);
	printf("Comparison using strdup   : |%s|\n", dup);
	free(dup);
}
