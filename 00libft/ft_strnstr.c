/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:53:27 by abidaux           #+#    #+#             */
/*   Updated: 2024/10/22 15:24:45 by abidaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, t_size len)
{
	t_size	h;
	t_size	i;

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
