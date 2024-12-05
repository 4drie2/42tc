/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:53:27 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/26 23:44:39 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	h;
	size_t	i;

	h = 0;
	i = 0;
	if (little[h] == '\0')
		return ((char *)big);
	while (big[h] != '\0' && h < len)
	{
		i = 0;
		while (big[h + i] == little[i] && big[h + i] != '\0')
		{
			if (little[i + 1] == '\0' && (h + i) < len)
				return ((char *)big + h);
			++i;
		}
		++h;
	}
	return (0);
}
