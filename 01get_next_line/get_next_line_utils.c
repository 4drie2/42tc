/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:02:14 by abidaux           #+#    #+#             */
/*   Updated: 2024/11/04 17:07:20 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen( const char *theString )
{
	int	n;

	n = 0;
	while (theString[n])
		++n;
	return (n);
}

char	*ft_strchr(const char *string, int searchedChar)
{
	while (*string)
	{
		if (*string == (unsigned char)searchedChar)
			return ((char *)string);
		string++;
	}
	if ((unsigned char)searchedChar == '\0')
		return ((char *)string);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && (i < (dstsize - 1)))
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	res_d;
	unsigned int	res_s;

	i = ft_strlen(dest);
	j = 0;
	res_d = ft_strlen(dest);
	res_s = ft_strlen(src);
	if (size < 1)
		return (res_s + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < res_d)
		return (res_s + size);
	else
		return (res_d + res_s);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(s);
	cpy = (char *)malloc(len_s + 1);
	if (cpy == NULL)
		return (NULL);
	i = -1;
	if (!cpy && !cpy)
		return (0);
	while (++i < len_s)
		((unsigned char *)cpy)[i] = ((unsigned char *)s)[i];
	cpy[len_s] = '\0';
	return (cpy);
}
