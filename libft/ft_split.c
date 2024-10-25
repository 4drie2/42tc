/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:57:08 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/26 00:34:43 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		nb_tab;
	char	**dest;

	if (!s || !c)
		return (0);
	i = -1;
	nb_tab = -1;
	dest = (char **)malloc(ft_strlen(s + 1));
	if (!dest)
		return (0);
	while (s[++i])
	{
		if (s[i] == c)
		{
			++nb_tab;
			dest[nb_tab] = (char *)malloc(j);
			j = 0;
		}
		++j;
		++i;
	j = 0;
	i = 0;
	}
	while (s[i])
	{
		while (s[++i] != c && s[i])
			dest[j][i] = s[i];
		++j;
	}
	dest[j][i] = '\0';
	return (dest);
}
