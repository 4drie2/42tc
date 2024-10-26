/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:57:08 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/26 16:29:21 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**make_dest(char const *str, char delim)
{
	int		count;
	int		in_word;
	int		i;
	char	**dest;

	if (!str)
		return (0);
	count = 0;
	in_word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != delim && in_word == 0)
		{
			++count;
			in_word = 1;
		}
		else if (str[i] == delim)
			in_word = 0;
		++i;
	}
	dest = (char **)malloc((count + 1) * sizeof(char *));
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	t_size	word_len;

	dest = make_dest(s, c);
	if (!dest || !s)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			dest[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	dest[i] = NULL;
	return (dest);
}

/* cc ft_split.c
ft_strlen.c ft_strchr.c ft_substr.c ft_strdup.c ft_memcpy.c ft_strlcpy.c

#include <stdio.h>
int main (void)
{
	int j = 0;
	char* str = ",,JAN,FEB,MAR,,,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC,,";
	char **dest = ft_split(str,',');
	while (dest[j])
	{
		printf("%s\n", dest[j]);
		++j;
	}
} */
