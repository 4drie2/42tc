/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:02:14 by abidaux           #+#    #+#             */
/*   Updated: 2024/11/08 14:14:36 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!dest && !src)
		return (0);
	while (++i < n)
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	len_s;

	len_s = ft_strlen((char *)s);
	cpy = (char *)malloc(len_s + 1);
	if (cpy == NULL)
		return (NULL);
	ft_memcpy(cpy, s, len_s);
	cpy[len_s] = '\0';
	return (cpy);
}

char	*ft_strchr(const char *string, int searchedChar)
{
	if (!string)
		return (NULL);
	while (*string)
	{
		if (*string == (unsigned char)searchedChar)
			return ((char *)string);
		string++;
	}
	if ((unsigned char)searchedChar == '\0')
		return ((char *)string);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_strdup("");
	temp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!temp)
		return (NULL);
	i = -1;
	while (s1[++i])
		temp[i] = s1[i];
	j = -1;
	while (s2[++j])
		temp[i++] = s2[j];
	temp[i] = '\0';
	return (free(s1), free(s2), temp);
}
