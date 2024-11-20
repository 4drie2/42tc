/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:57:08 by abidaux           #+#    #+#             */
/*   Updated: 2024/11/05 19:07:39 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeall(char **result, size_t j)
{
	while (j--)
		free(result[j]);
	free(result);
}

static size_t	ft_countab(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**ft_splitinject(char const *s, char c, char **result)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[j] = ft_substr(s, start, i - start);
			if (!result[j])
				return (ft_freeall(result, j), NULL);
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc((ft_countab(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (ft_splitinject(s, c, result));
}

/* //cc ft_split.c
//ft_strlen.c ft_strchr.c ft_substr.c ft_strdup.c ft_memcpy.c ft_strlcpy.c
#include <stdio.h>
int main (void)
{
	int j = 0;
	char* str = ",,JAN,FEB,MAR,,,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC,,";
	char **dest = ft_split(str,'\0');
	while (dest[j])
	{
		printf("%s\n", dest[j]);
		++j;
	}
} */
